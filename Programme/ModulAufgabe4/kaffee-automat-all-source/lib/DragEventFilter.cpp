#include "DragEventFilter.h"
#include <QMouseEvent>
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QLabel>

DragEventFilter::DragEventFilter(const QByteArray & data, bool hide, QObject *parent) :
    QObject(parent), m_data(data), m_hide(hide)
{
}

bool DragEventFilter::eventFilter(QObject * obj, QEvent * event)
{
    if (event->type() != QEvent::MouseButtonPress) return false;

    QMouseEvent * mouseEvent = static_cast<QMouseEvent*>(event);
    QLabel * label = qobject_cast<QLabel * >(obj);

    if (! label) return false;

    QDrag *drag = new QDrag(label);
    QMimeData *mimeData = new QMimeData;

    mimeData->setData("application/object", m_data);
    drag->setMimeData(mimeData);

    drag->setHotSpot(mouseEvent->pos());
    drag->setPixmap(*label->pixmap());

    if (m_hide) label->setVisible(false);

    Qt::DropAction dropAction = drag->exec(Qt::MoveAction);

    if (m_hide && dropAction != Qt::MoveAction) label->setVisible(true);

    return true;
}
