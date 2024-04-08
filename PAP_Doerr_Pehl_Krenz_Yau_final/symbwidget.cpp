#include "symbwidget.h"

//-------------------------------------------------------------------------------------

//Dynamische Variablen fuer die Button Dimensionen
int btnWidth = 75;          //Breite des Buttons
int btnHeight = 30;         //Hoehe des Buttons

//-------------------------------------------------------------------------------------

symbWidget::symbWidget(QWidget *parent, QString directory)
    : QScrollArea{parent}
{
    //Widget Dimensionen Setup
    setMinimumSize(130,500);
    setMaximumSize(130,1000);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);        //Rahmen generieren

//-------------------------------------------------------------------------------------

    QVBoxLayout *btnLayout = new QVBoxLayout();                                     //Erstellung von Widgetlayout, wo vertikal verläuft (V) bei QVBoxLayout
    btnLayout->setSpacing(20);                                                      //Abstand zwischen den Buttons in px

    //Rectangle Button Setup
    QLabel *btnRect = new QLabel(this);                                             //Erstellung des Labels mit dem Namen btnRect mit QLabel als Textfeld
    btnRect->setPixmap(QPixmap(QString(directory + "/Symbols_pic/rect.png")));      //Pixmap aus Pfad suchen und in Button als Bild einfuegen
    btnRect->setScaledContents(true);                                               //Bild auf maximale Buttongroeße skalieren
    btnRect->setFixedSize(btnWidth,btnHeight);                                      //Bild auf definierte Groeße setzen
    btnLayout->addWidget(btnRect);                                                  //btnRect wird in das ausgesuchte Widget eingefuegt

    //Diamond Button Setup
    QLabel *btnDiamond = new QLabel(this);
    btnDiamond->setPixmap(QPixmap(QString(directory + "/Symbols_pic/diamond.png")));
    btnDiamond->setScaledContents(true);
    btnDiamond->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnDiamond);

    //Begin Button Setup
    QLabel *btnBegin = new QLabel(this);
    btnBegin->setPixmap(QPixmap(QString(directory + "/Symbols_pic/begin.png")));
    btnBegin->setScaledContents(true);
    btnBegin->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnBegin);

    //End Button Setup
    QLabel *btnEnd = new QLabel(this);
    btnEnd->setPixmap(QPixmap(QString(directory + "/Symbols_pic/end.png")));
    btnEnd->setScaledContents(true);
    btnEnd->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnEnd);

    //Input Button Setup
    QLabel *btnInput = new QLabel(this);
    btnInput->setPixmap(QPixmap(QString(directory + "/Symbols_pic/input.png")));
    btnInput->setScaledContents(true);
    btnInput->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnInput);

    //Output Button Setup
    QLabel *btnOutput = new QLabel(this);
    btnOutput->setPixmap(QPixmap(QString(directory + "/Symbols_pic/output.png")));
    btnOutput->setScaledContents(true);
    btnOutput->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnOutput);

    //Start Button Setup
    QLabel *btnStart = new QLabel(this);
    btnStart->setPixmap(QPixmap(QString(directory + "/Symbols_pic/start.png")));
    btnStart->setScaledContents(true);
    btnStart->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnStart);

    //End Oval Button Setup
    QLabel *btnEndOval = new QLabel(this);
    btnEndOval->setPixmap(QPixmap(QString(directory + "/Symbols_pic/end_round.png")));
    btnEndOval->setScaledContents(true);
    btnEndOval->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnEndOval);

    //Arrow Up Button Setup
    QLabel *btnArrowUp = new QLabel(this);
    btnArrowUp->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowUp.png")));
    btnArrowUp->setScaledContents(true);
    btnArrowUp->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowUp);

    //Arrow Down Button Setup
    QLabel *btnArrowDown = new QLabel(this);
    btnArrowDown->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowDown.png")));
    btnArrowDown->setScaledContents(true);
    btnArrowDown->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowDown);

    //Arrow Left Button Setup
    QLabel *btnArrowLeft = new QLabel(this);
    btnArrowLeft->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowLeft.png")));
    btnArrowLeft->setScaledContents(true);
    btnArrowLeft->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowLeft);

    //Arrow Right Button Setup
    QLabel *btnArrowRight = new QLabel(this);
    btnArrowRight->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowRight.png")));
    btnArrowRight->setScaledContents(true);
    btnArrowRight->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowRight);

    //Arrow Left AngleButton Setup
    QLabel *btnArrowLeftAngle = new QLabel(this);
    btnArrowLeftAngle->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowLeftAngle.png")));
    btnArrowLeftAngle->setScaledContents(true);
    btnArrowLeftAngle->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowLeftAngle);

    //Arrow Right Angle Button Setup
    QLabel *btnArrowRightAngle = new QLabel(this);
    btnArrowRightAngle->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowRightAngle.png")));
    btnArrowRightAngle->setScaledContents(true);
    btnArrowRightAngle->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowRightAngle);

    //Arrow Right Angle Down Button Setup
    QLabel *btnArrowLeftAngleDown = new QLabel(this);
    btnArrowLeftAngleDown->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowLeftAngleDown.png")));
    btnArrowLeftAngleDown->setScaledContents(true);
    btnArrowLeftAngleDown->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowLeftAngleDown);

    //Arrow Right Angle Down Button Setup
    QLabel *btnArrowRightAngleDown = new QLabel(this);
    btnArrowRightAngleDown->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowRightAngleDown.png")));
    btnArrowRightAngleDown->setScaledContents(true);
    btnArrowRightAngleDown->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowRightAngleDown);

    //Arrow to Left Button Setup
    QLabel *btnArrowtoLeft = new QLabel(this);
    btnArrowtoLeft->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowtoLeft.png")));
    btnArrowtoLeft->setScaledContents(true);
    btnArrowtoLeft->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowtoLeft);

    //Arrow Right Angle Down Button Setup
    QLabel *btnArrowtoRight = new QLabel(this);
    btnArrowtoRight->setPixmap(QPixmap(QString(directory + "/Symbols_pic/arrowtoRight.png")));
    btnArrowtoRight->setScaledContents(true);
    btnArrowtoRight->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowtoRight);

    //Button Widget Setup
    //Platzhalter existiert bereits und nun muss alles in das Widget geladen werden
    QWidget *btnWidget = new QWidget();                     //Fertiges Layout muss nun in einem Fenster angezeigt werden
    btnWidget->setLayout(btnLayout);                        //Uebergabe des Button-Layouts mit allen Labels
    btnWidget->setAttribute(Qt::WA_DeleteOnClose);          //Wenn Fenster geschlossen wird, alle abhaengigen Klassen entfernen
    setWidget(btnWidget);                                   //Widget wird angezeigt
}

//-------------------------------------------------------------------------------------

//Drag und Drop Methoden (von Qt Dokumentation & an Applikation angepasst)

void symbWidget::dragEnterEvent(QDragEnterEvent *event)
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

void symbWidget::dragMoveEvent(QDragMoveEvent *event)
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

void symbWidget::dropEvent(QDropEvent *event)
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
        newIcon->move(event->position().toPoint() - offset);
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

void symbWidget::mousePressEvent(QMouseEvent *event)
{
    // Konvertiere globale Koordinaten in lokale Koordinaten des symbWidget
    QPoint localPos = event->pos();

    // Finde das Kind-Widget an der Position
    QWidget *childWidget = childAt(localPos);

    // Ueberpruefe, ob das Kind-Widget ein QLabel ist
    QLabel *childLabel = qobject_cast<QLabel*>(childWidget);

    if (!childLabel)
    {
        return;
    }

    QPixmap pixmap = childLabel->pixmap();
    //pixmap = pixmap.scaled(150,60);
    pixmap = pixmap.scaled(180,80);
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(localPos - childLabel->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(localPos - childLabel->pos());

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
    {
        childLabel->close();
    }
    else
    {
        childLabel->show();
    }
}
