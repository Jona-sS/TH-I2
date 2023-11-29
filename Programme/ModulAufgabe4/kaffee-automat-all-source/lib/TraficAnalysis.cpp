#include "TraficAnalysis.h"
#include "ui_TraficAnalysis.h"

TraficAnalysis::TraficAnalysis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TraficAnalysis)
{
    ui->setupUi(this);
}

TraficAnalysis::~TraficAnalysis()
{
    delete ui;
}

void TraficAnalysis::sendInputVector(const AutomatTypes::In &in)
{
    ui->inputVector->setText(
        QString().sprintf(
            "Becher:         %0d\n"
            "Muenze:         %0d\n"
            "Muenz-Wert:     %0d\n",
                in.becher, in.muenze, in.muenz_wert
        )
    );
}

void TraficAnalysis::receiveOutputVector(const AutomatTypes::Out &out)
{
    ui->outputVector->setText(
        QString().sprintf(
            "Display:        %0d\n"
            "Muenz-Rueck:    %0d\n"
            "Kaffee-Los:     %0d\n"
            "Guthaben:       %0d\n"
            "Display-String: %s\n",
                out.vector.display,
                out.vector.muenz_rueck,
                out.vector.kaffee_los,
                out.vector.guthaben,
                out.vector.display_string
        )
    );


}
