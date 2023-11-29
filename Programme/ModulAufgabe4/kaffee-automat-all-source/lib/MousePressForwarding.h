#ifndef MOUSEPRESSFORWARDING_H
#define MOUSEPRESSFORWARDING_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QCoreApplication>

class MousePressForwarding : public QWidget
{
    public:
        MousePressForwarding(QWidget * parent = 0) : QWidget(parent) {}

        void addWidget(QWidget * w) { m_widgets.push_back(w); }

    protected:
        virtual void mousePressEvent(QMouseEvent * event)
        {
            for (int i = 0; i < m_widgets.size(); i++) {
                QWidget * w = m_widgets.at(i);

                if (!w->isVisible()) continue;

                QMouseEvent newMouseEvent(event->type(), w->mapFromGlobal(event->globalPos()),
                                          event->globalPos(), event->button(), event->buttons(), event->modifiers());
                bool received = qApp->sendEvent(w, &newMouseEvent);

                if (received) break;
            }
        }

    private:
        QList<QWidget*> m_widgets;
};

#endif // MOUSEPRESSFORWARDING_H
