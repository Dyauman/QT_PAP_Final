/*

#include "menubar.h"
#include <QFileDialog>
#include <QPixmap>
#include <QGuiApplication>

menuBar::menuBar(QWidget *parent) : QObject{parent}
{
    // Erstellen der Menüleiste
    QMenuBar *menuBar = new QMenuBar;
    QMenu *fileMenu = menuBar->addMenu(tr("&Datei"));
    QAction *saveImageAction = fileMenu->addAction(tr("&Als Bild speichern"));
    QAction *savePdfAction = fileMenu->addAction(tr("&Als PDF speichern"));

    // Verknüpfen der Aktionen mit Slots
    connect(saveImageAction, &QAction::triggered, this, &menuBar::saveAsImage);
    connect(savePdfAction, &QAction::triggered, this, &menuBar::saveAsPDF);
}

menuBar::menuBar(QObject *parent) : QObject(parent)
{
    // Erstellen der Menüleiste
    QMenuBar *menuBar = new QMenuBar;
    QMenu *fileMenu = menuBar->addMenu(tr("&Datei"));
    QAction *saveImageAction = fileMenu->addAction(tr("&Als Bild speichern"));
    QAction *savePdfAction = fileMenu->addAction(tr("&Als PDF speichern"));

    // Verknüpfen der Aktionen mit Slots
    connect(saveImageAction, &QAction::triggered, this, &menuBar::saveAsImage);
    connect(savePdfAction, &QAction::triggered, this, &menuBar::saveAsPDF);
}



void menuBar::saveAsImage() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, tr("Bild speichern"), QString(), tr("Bilddateien (*.png)"));
    if (!filePath.isEmpty()) {
        QPixmap pixmap(QGuiApplication::primaryScreen()->grabWindow(0));
        pixmap.save(filePath);
    }
}

void menuBar::saveAsPDF() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, tr("PDF speichern"), QString(), tr("PDF-Dateien (*.pdf)"));
    if (!filePath.isEmpty()) {
        QTextDocument doc;
        doc.setHtml("<h1>Hello, PDF!</h1>");

        QPdfWriter pdfWriter(filePath);
        QPainter painter(&pdfWriter);
        doc.drawContents(&painter);
    }
}





#include "menubar.h"


menuBar::menuBar(QObject *parent) : QObject(parent)
{
    // Empty constructor for now
}



void menuBar::saveAsImage() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("Bild speichern"), QString(), QObject::tr("Bilddateien (*.png)"));
    if (!filePath.isEmpty()) {
        QPixmap pixmap(QGuiApplication::primaryScreen()->grabWindow(0));
        pixmap.save(filePath);
    }
}

void menuBar::saveAsPDF() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("PDF speichern"), QString(), QObject::tr("PDF-Dateien (*.pdf)"));
    if (!filePath.isEmpty()) {
        QWidget *widgetToSave = QApplication::activeWindow();
        if (!widgetToSave) {
            qDebug() << "Error: No active window to save.";
            return;
        }

        QPixmap pixmap(widgetToSave->size());
        QPainter painter(&pixmap);
        widgetToSave->render(&painter);
        painter.end();

        QImage image = pixmap.toImage();

        QPdfWriter pdfWriter(filePath);
        QPainter pdfPainter(&pdfWriter);
        pdfPainter.drawImage(0, 0, image);
        pdfPainter.end();
    }
}

*/
