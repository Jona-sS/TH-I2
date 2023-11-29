#include "Output.h"
#include "Transaction.h"
#include <iostream>
#include <QHash>
#include <QStringList>

void Output::read()
{
    out = automat_output();
}

void Output::print(std::ostream & os) const
{
    os << "display("         << out.display     << ") "
       << "muenz_rueck("     << out.muenz_rueck << ") "
       << "kaffee_los("      << out.kaffee_los  << ") "
       << "guthaben("        << out.guthaben    << ") "
       << "display_string: " << out.display_string;
}

bool Output::operator==(const Output & o) const
{
    return out.display     == o.out.display &&
           out.muenz_rueck == o.out.muenz_rueck &&
           out.kaffee_los  == o.out.kaffee_los &&
           out.guthaben    == o.out.guthaben &&
           QString(out.display_string) == QString(o.out.display_string);
}

uint qHash(const Output & output)
{
    return output.out.display     * 1 +
           output.out.muenz_rueck * 2 +
           output.out.kaffee_los  * 4 +
           output.out.guthaben    * 8 +
           qHash(QString(output.out.display_string)) * 32;
}

QString Output::toString() const
{
    QStringList values;
    values << Transaction::boolToString(out.display);
    values << Transaction::boolToString(out.muenz_rueck);
    values << Transaction::boolToString(out.kaffee_los);
    values << QString::number(out.guthaben);
    values << "\"\"";
    return "{ " + values.join(", ") + " }";
}

QString Output::toPrettyString() const
{
    return QString("disp(%1) rueck(%2) los(%3) geld(%4): %5")
                .arg(out.display)
                .arg(out.muenz_rueck)
                .arg(out.kaffee_los)
                .arg(out.guthaben)
                .arg(out.display_string);
}
