#ifndef SYMBWIDGET_H
#define SYMBWIDGET_H

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDir>
#include <QFrame>
#include <QPixmap>
#include <QLabel>
#include <QtWidgets>

class symbWidget : public QScrollArea
{
    Q_OBJECT
public:
    explicit symbWidget(QWidget *parent = nullptr,QString s = "");

signals:

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SYMBWIDGET_H
