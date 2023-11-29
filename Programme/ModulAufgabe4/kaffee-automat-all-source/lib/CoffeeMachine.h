#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

#include <QWidget>
#include <QTimer>
#include "AutomatTypes.h"

namespace Ui {
class CoffeeMachine;
}

class CoffeeMachine : public QWidget
{
    Q_OBJECT

public:
    explicit CoffeeMachine(QWidget *parent = 0);
    ~CoffeeMachine();

    void reset();

signals:
    void sendInputVector(const AutomatTypes::In &in);
    void receiveOutputVector(const AutomatTypes::Out &out);

public slots:
    void machineDrop(const QByteArray & data);
    void plateDrop(const QByteArray & data);
    void moneyDrop(const QByteArray & data);

private:
    Ui::CoffeeMachine *ui;

    QTimer m_hideCoinOut;
    QTimer m_hideCoffeeSplat;

    QByteArray m_money_in_machine;

    bool has_can_in_machine();
    void input_state_machine(bool muenze, bool muenz_wert);
    void output_state_machine();
};

#endif // COFFEEMACHINE_H
