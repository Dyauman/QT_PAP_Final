#include "mainwindow.h"
#include "symbWidget.h"
#include "papWidget.h"
#include "deletewidget.h"

#include <QHBoxLayout>
#include <QApplication>
#include <QMenuBar>
#include <QFileDialog>
#include <QPainter>
#include <QTextDocument>
#include <QPdfWriter>
#include <QMessageBox>
//-------------------------------------------------------------------------------------
//Funktion Definition fuer Menueleiste (PAP-Bild als PDF oder Bild speichern)
void saveWidgetAsPdf(QWidget *widget)
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("PDF speichern"), QString(), QObject::tr("PDF-Dateien (*.pdf)"));
    if (!filePath.isEmpty())
    {
        QPdfWriter pdfWriter(filePath);
        QPainter painter(&pdfWriter);
        widget->render(&painter);
        painter.end();
    }
}

void saveWidgetAsImage(QWidget *widget)
{
    QString filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("Bild speichern"), QString(), QObject::tr("Bilddateien (*.png *.jpg *.bmp)"));
    if (!filePath.isEmpty())
    {
        QPixmap pixmap(widget->size());
        widget->render(&pixmap);
        pixmap.save(filePath);
    }
}
//-------------------------------------------------------------------------------------

//Start der Main Funktion, Widgets erzeugen
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Pfad fuer die Bilder in der sie gespeichert sind
    QString directory = QApplication::applicationDirPath();

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("PAP-Design");

    //MainWidget erzeugen, welches alle Widgets enthaelt
    QWidget *mainWidget = new QWidget(&mainWindow);
    QHBoxLayout *horizontalLayout = new QHBoxLayout(mainWidget);
    horizontalLayout->addWidget(new symbWidget(mainWidget,directory));
    horizontalLayout->addWidget(new papWidget);
    horizontalLayout->addWidget(new deleteWidget);

    //MainWidget in MainWindow zentriert einbinden
    mainWindow.setCentralWidget(mainWidget);

//-------------------------------------------------------------------------------------
    // Erstellen der Menueleiste
    QMenuBar *menuBar = new QMenuBar(&mainWindow);
    QMenu *fileMenu = menuBar->addMenu(QObject::tr("&Datei")); 

    //Aktionsimplementierung bei Betaetigung fuer PDF
    QAction *saveAsPdfAction = fileMenu->addAction(QObject::tr("&Save as PDF"));
    QObject::connect(saveAsPdfAction, &QAction::triggered, mainWidget, [=]()
    {
        saveWidgetAsPdf(mainWidget->findChild<papWidget*>());
    });

    //Aktionsimplementierung bei Betaetigung fuer Bild
    QAction *saveAsImageAction = fileMenu->addAction(QObject::tr("&Save as Image"));
    QObject::connect(saveAsImageAction, &QAction::triggered, mainWidget, [=]()
    {
        saveWidgetAsImage(mainWidget->findChild<papWidget*>());
    });

    //Aktionsimplementierung bei Betaetigung von Exit
    QAction *exitAction = fileMenu->addAction(QObject::tr("&Exit"));
    QObject::connect(exitAction, &QAction::triggered, &a, &QApplication::quit); // Schließt die Applikation
//-------------------------------------------------------------------------------------
    //Menueleiste setzen und MainWindow anzeigen
    mainWindow.setMenuBar(menuBar);
    mainWindow.show();
    return a.exec();
}
