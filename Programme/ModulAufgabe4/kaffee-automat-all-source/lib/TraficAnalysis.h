#ifndef TRAFICANALYSIS_H
#define TRAFICANALYSIS_H

#include <QWidget>
#include "AutomatTypes.h"

namespace Ui {
class TraficAnalysis;
}

class TraficAnalysis : public QWidget
{
    Q_OBJECT

public:
    explicit TraficAnalysis(QWidget *parent = 0);
    ~TraficAnalysis();

public slots:
    void sendInputVector(const AutomatTypes::In &in);
    void receiveOutputVector(const AutomatTypes::Out &out);


private:
    Ui::TraficAnalysis *ui;
};

#endif // TRAFICANALYSIS_H
