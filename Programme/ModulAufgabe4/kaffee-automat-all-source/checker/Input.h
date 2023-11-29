#pragma once

#include <ostream>
#include <QtGlobal>

class Input
{
    public:
        static const int POSSIBILITIES = 9;

        Input();

        QString toString() const;

        QString toPrettyString() const;

        int getId() const {
            if (reset) return 1 << 3;
            else       return (becher << 2) | (muenze << 1) | (muenz_wert << 0);
        }

        void randomize();
        void propagate() const;

        void print(std::ostream & os) const;

        bool operator==(const Input & o) const;

    private:
        unsigned int seed;

        bool reset;
        bool muenz_wert;
        bool muenze;
        bool becher;

        int random(int max);
};

inline uint qHash(const Input & in) { return in.getId(); }
