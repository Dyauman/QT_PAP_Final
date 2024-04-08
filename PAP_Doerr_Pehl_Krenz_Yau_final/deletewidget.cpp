#include "deletewidget.h"
//-------------------------------------------------------------------------------------

//DeleteWidget Setup
deleteWidget::deleteWidget(QWidget *parent) : QFrame{parent}
{
    setMinimumSize(100,50);
    setMaximumSize(100,1600);
    setStyleSheet("border: 1px solid black");
    setAcceptDrops(true);
}

//-------------------------------------------------------------------------------------

//"Delete" Text in das Widget einzeichnen
void deleteWidget::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event); // Zuerst den Rahmen malen
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 12)); // Schriftart und Größe festlegen
    painter.drawText(rect(), Qt::AlignCenter, "Delete"); // Text in der Mitte des Widgets zeichnen
    painter.end();
}

//-------------------------------------------------------------------------------------

//Drag und Drop Methoden (von Qt Dokumentation & an Applikation angepasst)

void deleteWidget::dragEnterEvent(QDragEnterEvent *event)
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

void deleteWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        // Wenn das Drag-and-Drop-Ereignis von der ScrollArea stammt,dann soll dies ignoriert werden
        QWidget *sourceWidget = qobject_cast<QWidget*>(event->source());
        if (qobject_cast<QScrollArea*>(sourceWidget))
        {
            event->ignore();
            return;
        }
        else
        {
            // MIME-Daten aus dem Ereignis abrufen
            const QMimeData *mimeData = event->mimeData();

            // Den Objektnamen aus den MIME-Daten abrufen
            QString objName = mimeData->property("objectName").toString();

            QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);

            QPixmap pixmap;
            QPoint offset;
            dataStream >> pixmap >> offset;

            QLabel *newIcon = new QLabel(this);
            newIcon->setPixmap(pixmap);
            newIcon->move(event->position().toPoint() - offset);
            newIcon->show();
            newIcon->setAttribute(Qt::WA_DeleteOnClose);

            // QLabel wird aus dem ursprünglichen Widget entfernt
            QWidget *sourceWidget = qobject_cast<QWidget*>(event->source());

            // Überprüfen, ob das Drag-and-Drop-Ereignis von symbWidget stammt
            QLabel *originalLabel = sourceWidget->findChild<QLabel *>(objName);

            if (originalLabel)
            {
                originalLabel->deleteLater(); // QLabel wird später geloescht, um sicherzustellen, dass die Ereignisse korrekt verarbeitet werden
            }

            // QTimer wird verwendet, um das QLabel im deleteWidget nach einer gewissen Zeit zu loeschen
            QTimer::singleShot(1, newIcon, &QWidget::deleteLater);
            event->accept();
        }
    }
    else
    {
        event->ignore();
    }
}
