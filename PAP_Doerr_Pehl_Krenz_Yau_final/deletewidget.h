#ifndef DELETEWIDGET_H
#define DELETEWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QPainter>
#include <QtWidgets>

class deleteWidget : public QFrame
{
    Q_OBJECT

public:
    explicit deleteWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};

#endif // DELETEWIDGET_H


