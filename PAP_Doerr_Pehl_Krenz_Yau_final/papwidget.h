#ifndef PAPWIDGET_H
#define PAPWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QtWidgets>

class papWidget : public QFrame
{
    Q_OBJECT
public:
    explicit papWidget(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
};

#endif // PAPWIDGET_H
