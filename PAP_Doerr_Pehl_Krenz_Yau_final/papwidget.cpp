#include "papwidget.h"

//-------------------------------------------------------------------------------------

//Dynamische Variablen fuer Symbol Name und Dimensionen
int symbCnt = 0;
int symbH = 80;
int symbW = 180;

//-------------------------------------------------------------------------------------

papWidget::papWidget(QWidget *parent)
    : QFrame{parent}
{
    //Widget Setup
    setMinimumSize(300,500);
    setStyleSheet("border: 1px solid black");
    setAcceptDrops(true);
}

//-------------------------------------------------------------------------------------

//Drag und Drop Methoden (von Qt Dokumentation & an Applikation angepasst)

void papWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void papWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void papWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->setFixedSize(symbW,symbH);
        newIcon->setScaledContents(true);
        newIcon->move(event->position().toPoint() - offset);
        newIcon->setObjectName(QString("SymbIcon_%1").arg(symbCnt));
        symbCnt++;
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

//Methode wenn auf ein QLabel ein Doppelklick stattfindet => Per Eingabe ein Text in Pixmap erzeugen (aus Foren & ChatGPT)
void papWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    QLabel *clickedLabel = qobject_cast<QLabel*>(childAt(event->pos())); //Pruefen ob auf ein Label geklickt wurde

    if (clickedLabel)
    {
        //Variable ok einfuehren, dient zur Eingabe bestaetigung
        bool ok;
        QString text = QInputDialog::getText(this, tr("Enter text"), tr("Please enter the text:"), QLineEdit::Normal, QString(), &ok);

        if (ok && !text.isEmpty())
        {
            //Pixmap von angeklickten QLabel speichern
            QPixmap pixmap = clickedLabel->pixmap(Qt::ReturnByValue);

            //Text Setup
            QFont font("Arial", 48);
            QFontMetrics metrics(font);

            QStringList lines;
            QString currentLine;

            for (const QChar& ch : text)
            {
                // Pruefen, ob die Breite des aktuellen Teils des Textes die Breite der Pixmap ueberschreitet
                if (metrics.horizontalAdvance(currentLine + ch) > pixmap.width())
                {
                    lines.append(currentLine); // Zeile abschließen
                    currentLine.clear(); // Aktuelle Zeile leeren
                }
                currentLine = currentLine + ch;
            }

            //Fuege die aktuelle Zeile in die String Liste lines
            if (!currentLine.isEmpty())
            {
                lines.append(currentLine);
            }

            // Ueberpruefen, ob der Text mehr als zwei Zeilenumbrueche hat und falls ja, die Schriftgroeße anpassen
            if (lines.count() > 4)
            {
                // Schriftgroeße verkleinern
                int newFontSize = font.pointSize() - 2; // neue Schrittgroeße zur Schriftgroeßenanpassung

                 //Ausfuehren sofern die Schriftgroeße nicht zu klein ist
                while (newFontSize >= 6)
                {
                    QFont newFont("Arial", newFontSize);
                    QFontMetrics newMetrics(newFont);
                    QStringList newLines;
                    QString newCurrentLine;
                    for (const QChar& ch : text)
                    {
                        // Pruefen, ob die Breite des aktuellen Teils des Textes die Breite der Pixmap ueberschreitet
                        if (newMetrics.horizontalAdvance(newCurrentLine + ch) > pixmap.width())
                        {
                            newLines.append(newCurrentLine); // Zeile abschließen
                            newCurrentLine.clear(); // Aktuelle Zeile leeren
                        }
                        newCurrentLine += ch;
                    }

                    if (!newCurrentLine.isEmpty())
                    {
                        newLines.append(newCurrentLine);
                    }

                    if (newLines.count() <= 2)
                    {
                        // Text passt mit neuer Schriftgroeße
                        font = newFont;
                        lines = newLines;
                        break;
                    }
                    newFontSize = newFontSize - 2;
                }
            }

            // Text zentriert in der Höhe zeichnen
            QTextDocument textDocument;
            textDocument.setDefaultFont(font);
            textDocument.setPlainText(lines.join("\n"));
            QSizeF size = textDocument.size();

            // Ueberprüfen, ob der Text die Pixmap-Hoehe ueberschreitet
            if (size.height() > pixmap.height())
            {
                // Pixmap-Hoehe an Texthoehe anpassen
                pixmap = pixmap.scaledToHeight(size.height(), Qt::SmoothTransformation);
            }

            QPixmap pixmapCopy(pixmap);
            QPainter painter(&pixmapCopy);
            painter.setPen(Qt::black);
            painter.setFont(font);

            // Berechne Y-Position, um den Text vertikal zu zentrieren
            int textY = (pixmap.height() - size.height()) / 2;

            painter.drawText(QRectF(0, textY, pixmap.width(), pixmap.height()), Qt::AlignCenter, lines.join("\n"));
            painter.end();
            clickedLabel->setPixmap(pixmapCopy);
        }
    }
    QFrame::mouseDoubleClickEvent(event);
}


void papWidget::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->position().toPoint()));
    if (!child)
    {
        return;
    }
    QPixmap pixmap = child->pixmap();
    pixmap = pixmap.scaled(symbW,symbH);
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->position().toPoint() - child->pos());
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
    mimeData->setProperty("objectName", child->objectName());

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->position().toPoint() - child->pos());

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
    {
        child->close();
    }
    else
    {
        child->show();
        child->setPixmap(pixmap);
    }
}
