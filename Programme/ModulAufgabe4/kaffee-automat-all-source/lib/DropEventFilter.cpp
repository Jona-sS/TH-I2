#include "DropEventFilter.h"
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>

DropEventFilter::DropEventFilter(const DataList & acceptList, QObject *parent) :
    QObject(parent),
    m_acceptList(acceptList)
{
}


bool DropEventFilter::eventFilter(QObject *, QEvent *event)
{
    if (event->type() == QEvent::DragEnter) {
        QDragEnterEvent * dragEvent = static_cast<QDragEnterEvent*>(event);
        const QMimeData * mimeData = dragEvent->mimeData();

        if (mimeData->hasFormat("application/object")) {
            QByteArray data = mimeData->data("application/object");

            if (m_acceptList.contains(data)) {
               dragEvent->acceptProposedAction();
               return true;
            } else {
               // qDebug() << "cannot drop data" << data << m_acceptList;
            }
        }
        return false;
    }

    if (event->type() == QEvent::Drop) {
        QDropEvent * dropEvent = static_cast<QDropEvent*>(event);
        const QMimeData * mimeData = dropEvent->mimeData();
        emit dropData(mimeData->data("application/object"));
        dropEvent->accept();
        return true;
    }

    return false;
}
