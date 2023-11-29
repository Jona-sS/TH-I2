#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QMessageBox>
#include <stdint.h>

extern "C" {
#include "checker.h"
}

#include "CoffeeMachine.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->coffeeMachine, SIGNAL(sendInputVector(AutomatTypes::In)), ui->traficAnalysis, SLOT(sendInputVector(AutomatTypes::In)));
    connect(ui->coffeeMachine, SIGNAL(receiveOutputVector(AutomatTypes::Out)), ui->traficAnalysis, SLOT(receiveOutputVector(AutomatTypes::Out)));

    ui->traficAnalysisDockWidget->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset_pressed()
{
    // qDebug() << __func__;
    ui->coffeeMachine->reset();
}

void MainWindow::check_statemachine()
{
    if (checker_check()) {
        QMessageBox::information(this, "Zustandsmaschinentest", "Test war erfolgreich");
    } else {
        QMessageBox::critical(this, "Zustandsmaschinentest", "Test schlug fehl:\n" + QString::fromUtf8(checker_error_string()));
    }
    reset_pressed();
}
