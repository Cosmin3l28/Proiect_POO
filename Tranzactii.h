#ifndef _TRANZACTII_H_
#define _TRANZACTII_H_
#include "Investitor.h"

#include <vector>
class Tranzactii
{
private:
    friend class Investitor;
    std::string nume;
    int valoare;
    bool semn;
    int numar_actiuni;
public:
    Tranzactii(const int &valoare, const bool &semn, const std::string &nume, const int &numar_actiuni);
    ~Tranzactii();
};

Tranzactii::Tranzactii(const int &valoare, const bool &semn, const std::string &nume, const int &numar_actiuni) :  nume{nume}, valoare{valoare}, semn{semn}, numar_actiuni{numar_actiuni}{}

Tranzactii::~Tranzactii(){}

#endif