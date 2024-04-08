/*
#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QFileDialog>
#include <QPixmap>
#include <QPainter>
#include <QTextDocument>
#include <QPdfWriter>

class menuBar : public QObject
{
    Q_OBJECT

public:
    explicit menuBar(QObject *parent = nullptr);

public slots:
    void saveAsImage();
    void saveAsPDF();
};

#endif // MENUBAR_H



#ifndef MENUBAR_H
#define MENUBAR_H

#include <QObject>
#include <QFileDialog>
#include <QPixmap>
#include <QGuiApplication>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>
#include <QApplication>

class menuBar : public QObject
{
    Q_OBJECT

public:
    explicit menuBar(QObject *parent = nullptr);

public slots:
    void saveAsImage();
    void saveAsPDF();
};

#endif // MENUBAR_H
*/
