#ifndef DROPEVENTFILTER_H
#define DROPEVENTFILTER_H

#include <QObject>
#include <QList>
#include <QByteArray>

class DropEventFilter : public QObject
{
    Q_OBJECT
public:
    typedef QList<QByteArray> DataList;
    explicit DropEventFilter(const DataList & acceptList, QObject *parent = 0);

signals:
    void dropData(const QByteArray & data);

protected:
    bool eventFilter(QObject *, QEvent * event);

private:
    DataList m_acceptList;
};

#endif // DROPEVENTFILTER_H
