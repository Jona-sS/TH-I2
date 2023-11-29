#include "CoffeeMachine.h"
#include "ui_CoffeeMachine.h"
#include <QDebug>
#include "DragEventFilter.h"
#include "DropEventFilter.h"

namespace {

const QByteArray CAN = "can";
const QByteArray FILLED_CAN = "filled_can";
// the EURO_* names must match with resource aliases
const QByteArray EURO_1 = "1_euro";
const QByteArray EURO_2 = "2_euro";

} /* end of anonymous namespace */

CoffeeMachine::CoffeeMachine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CoffeeMachine)
{
    ui->setupUi(this);

    ui->can_on_plate->installEventFilter(new DragEventFilter(CAN, true, this));
    ui->can_in_machine->installEventFilter(new DragEventFilter(CAN, true, this));
    ui->filled_can_in_machine->installEventFilter(new DragEventFilter(FILLED_CAN, true, this));

    ui->euro_1->installEventFilter(new DragEventFilter(EURO_1, false, this));
    ui->euro_2->installEventFilter(new DragEventFilter(EURO_2, false, this));

    DropEventFilter * machineFilter = new DropEventFilter(DropEventFilter::DataList() << CAN << FILLED_CAN, this);
    ui->drop_on_machine->installEventFilter(machineFilter);
    connect(machineFilter, SIGNAL(dropData(QByteArray)), this, SLOT(machineDrop(QByteArray)));

    DropEventFilter * plateFilter = new DropEventFilter(DropEventFilter::DataList() << CAN << FILLED_CAN, this);
    ui->drop_on_plate->installEventFilter(plateFilter);
    connect(plateFilter, SIGNAL(dropData(QByteArray)), this, SLOT(plateDrop(QByteArray)));

    DropEventFilter * moneyFilter = new DropEventFilter(DropEventFilter::DataList() << EURO_1 << EURO_2, this);
    ui->drop_money->installEventFilter(moneyFilter);
    connect(moneyFilter, SIGNAL(dropData(QByteArray)), this, SLOT(moneyDrop(QByteArray)));

    // forward mouse press to widgets positioning below drop-widgets
    ui->drop_on_plate->addWidget(ui->can_on_plate);

    ui->drop_on_machine->addWidget(ui->filled_can_in_machine);
    ui->drop_on_machine->addWidget(ui->can_in_machine);

    // setup hide timer
    m_hideCoinOut.setSingleShot(true);
    m_hideCoinOut.setInterval(1500);
    m_hideCoffeeSplat.setSingleShot(true);
    m_hideCoffeeSplat.setInterval(1500);

    connect(&m_hideCoinOut, SIGNAL(timeout()), ui->coin_out, SLOT(hide()));
    connect(&m_hideCoffeeSplat, SIGNAL(timeout()), ui->coffee_splat, SLOT(hide()));

    reset();
}

CoffeeMachine::~CoffeeMachine()
{
    delete ui;
}

void CoffeeMachine::reset()
{
   ui->can_on_plate->setVisible(true);
   ui->filled_can_in_machine->setVisible(false);
   ui->can_in_machine->setVisible(false);

   ui->coffee_splat->setVisible(false);
   ui->coin_out->setVisible(false);

   m_hideCoinOut.stop();
   m_hideCoffeeSplat.stop();

   emit sendInputVector(AutomatTypes::In(false, false, false));
   automat_reset();
   output_state_machine();
}

void CoffeeMachine::machineDrop(const QByteArray & data)
{
    if  (data == CAN)        ui->can_in_machine->setVisible(true);
    if  (data == FILLED_CAN) ui->filled_can_in_machine->setVisible(true);

    input_state_machine(false, false);
}

void CoffeeMachine::plateDrop(const QByteArray & data)
{
    if  (data == CAN || data == FILLED_CAN) ui->can_on_plate->setVisible(true);
    input_state_machine(false, false);
}

void CoffeeMachine::moneyDrop(const QByteArray & data)
{
    // qDebug() << "dropped money" << data;
    m_money_in_machine = data;

    if      (data == EURO_1) input_state_machine(true, false);
    else if (data == EURO_2) input_state_machine(true, true);
    else qDebug() << "unkown drop data" << data;
}

bool CoffeeMachine::has_can_in_machine()
{
   return ui->can_in_machine->isVisible() ||
          ui->filled_can_in_machine->isVisible();
}

void CoffeeMachine::input_state_machine(bool muenze, bool muenz_wert)
{
    bool becher = has_can_in_machine();

    emit sendInputVector(AutomatTypes::In(becher, muenze, muenz_wert));
    automat_transition(becher, muenze, muenz_wert);

    // just for debug
    // fsm_action_t output = automat_output();
    // uint32_t input_vector = (becher << 2) | (muenze << 1) | (muenz_wert << 0);
    // uint32_t output_vector = (output.display << 2) | (output.muenz_rueck << 1) | (output.kaffee_los << 0);
    // 
    // qDebug() << "state machine: in" << QString::number(input_vector, 2) << "--> out" << QString::number(output_vector, 2);

    output_state_machine();
}

void CoffeeMachine::output_state_machine()
{
    fsm_action_t output = automat_output();
    emit receiveOutputVector(AutomatTypes::Out(output));

    ui->light_on_money->setVisible(!output.display);
    ui->light_on_can->setVisible(output.display);
   
    ui->money_number->display(output.guthaben);
    ui->display_label->setText(QString::fromUtf8(output.display_string));

    if (output.muenz_rueck) {

        QByteArray pixmap;
        if (m_money_in_machine.size() == 0) pixmap = "spider_web";
        else                                pixmap = m_money_in_machine;
        m_money_in_machine.clear();

        // qDebug() << "geld zurück:" << pixmap;

        ui->coin_out->setPixmap(QPixmap(":/coffee/" + pixmap));
        ui->coin_out->setVisible(true);
        m_hideCoinOut.start();
    }

    if (output.kaffee_los)  {
        // qDebug() << "starte kaffee";
        if (has_can_in_machine()) {

            ui->filled_can_in_machine->setVisible(true);
            ui->can_in_machine->setVisible(false);
            ui->coffee_splat->setVisible(false);

        } else {

            ui->coffee_splat->setVisible(true); 
            m_hideCoffeeSplat.start();
        }
    }
}
