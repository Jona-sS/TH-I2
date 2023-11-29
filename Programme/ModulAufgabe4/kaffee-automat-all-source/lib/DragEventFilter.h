#ifndef DRAGEVENTFILTER_H
#define DRAGEVENTFILTER_H

#include <QObject>

class DragEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit DragEventFilter(const QByteArray & data, bool hide, QObject *parent = 0);

protected:
    bool eventFilter(QObject * obj, QEvent * event);

private:
    QByteArray m_data;
    bool m_hide;
};

#endif // DRAGEVENTFILTER_H
