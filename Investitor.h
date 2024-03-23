#ifndef _INVESTITOR_H_
#define _INVESTITOR_H_

#include <vector>
#include <string>
#include <iostream>
#include "Actiuni.h"
#include "Tranzactii.h"

class Investitor
{
private:
    int balanta;
    std::vector<class Actiuni> actiuni;
    std::vector<class Tranzactii> tranzactii;
    std::string nume;

public:
    Investitor(const std::string &nume = "None", const int &balanta = 0);
    Investitor(const Investitor &object);
    ~Investitor();
    Investitor operator=(const Investitor &object);
    friend std::ostream &operator<<(std::ostream &os, Investitor &object);
    friend std::istream &operator>>(std::istream &is, Investitor &object);
    void stergere(Investitor &object, int index);
    void print_actiuni();
    void print_tranzactii();
    void add_actiune(const std::string &nume, const int &valoare, const int &dividende, const int &numar_actiuni);
    void vinde_actiune(const std::string &nume, const int &valoare, int numar_actiuni);
    void tranzactie(const std::string &nume, const int &valoare, const bool &semn, const int &numar_actiuni);
    void add_balance(const int &value);
    void subtract_balance(const int &value);
};

Investitor::Investitor(const std::string &nume, const int &balanta) : balanta{balanta}, nume{nume}{}

Investitor::Investitor(const Investitor &object) : Investitor(object.nume){}

Investitor::~Investitor(){}

Investitor Investitor::operator=(const Investitor &object)
{
    if (this == &object)
        return *this;
    else
    {
        this->actiuni = object.actiuni;
        this->balanta = object.balanta;
        this->tranzactii = object.tranzactii;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, Investitor &object)
{
    os << "----------------------" << std::endl;
    os << "Nume:" << object.nume << std::endl;
    os << "Balanta:" << object.balanta << std::endl;
    os << "Actiuni: " << std::endl;
    object.print_actiuni();
    os << "Istoric tranzactii: " << std::endl;
    object.print_tranzactii();
    os << "----------------------" << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Investitor &object)
{
    std::cout << "Nume: ";
    is >> object.nume;
    std::cout << std::endl;
    return is;
}

void Investitor::add_actiune(const std::string &nume, const int &valoare, const int &dividende, const int &numar_actiuni)
{
    if(this->balanta >= valoare*numar_actiuni)
    {
        this->balanta -= valoare*numar_actiuni;
        Actiuni actiune{nume, valoare, dividende, numar_actiuni};
        int n = this->actiuni.size();
        bool existenta = false;
        for (int i = 0; i < n; i++)
        {
            if (this->actiuni[i].get_name() == actiune.get_name())
            {
                this->actiuni[i].add_numar_actiune(actiune);
                existenta = true;
            }
        }
        if (!existenta)
            this->actiuni.push_back(actiune);
        this->tranzactie(nume, valoare, true, numar_actiuni);
    }
    else
        std::cout << "Fonduri insuficiente" << std::endl;
}

void Investitor::vinde_actiune(const std::string &nume, const int &valoare, int numar_actiuni)
{
    bool ok = false;
    int n = this->actiuni.size();
    for (int i = 0; i < n; i++)
    {
        if (this->actiuni[i].get_name() == nume)
        {
            if (this->actiuni[i].get_numar_actiune() == numar_actiuni)
            {
                numar_actiuni = this->actiuni[i].get_numar_actiune();
                for (int j = i; j < n - 1; j++)
                {
                    this->actiuni[j] = this->actiuni[j + 1];
                }
                this->actiuni.pop_back();
            }
            else if (this->actiuni[i].get_numar_actiune() > numar_actiuni)
                this->actiuni[i] = this->actiuni[i] - numar_actiuni;
            else
                std::cout << "Actiuni insuficiente" << std::endl;
            ok = true;
        }
    }
    if (!ok)
        std::cout << "Actiune inexistenta in portofoliu" << std::endl;
    else
    {
        this->tranzactie(nume, valoare, false, numar_actiuni);
        this->balanta += valoare*numar_actiuni;
    }
}

void Investitor::print_tranzactii()
{
    int n = this->tranzactii.size();
    for (int i = 0; i < n; i++)
    {
        if (this->tranzactii[i].semn == true)
            std::cout << "-" << this->tranzactii[i].valoare * this->tranzactii[i].numar_actiuni << " din cumpararea a " << this->tranzactii[i].numar_actiuni << " actiuni " << this->tranzactii[i].nume << std::endl;
        else
            std::cout << "+" << this->tranzactii[i].valoare * this->tranzactii[i].numar_actiuni << " din vanzarea a " << this->tranzactii[i].numar_actiuni << " actiuni " << this->tranzactii[i].nume << std::endl;
    }
}

void Investitor::print_actiuni()
{
    int n = this->actiuni.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << this->actiuni[i].get_name() << " " << this->actiuni[i].get_numar_actiune() << std::endl;
    }
}

void Investitor::tranzactie(const std::string &nume, const int &valoare, const bool &semn, const int &numar_actiuni)
{
    Tranzactii tranzactie_curenta{valoare, semn, nume, numar_actiuni};
    tranzactii.push_back(tranzactie_curenta);
}

void Investitor::add_balance(const int &value)
{
    this->balanta += value;
}

void Investitor::subtract_balance(const int &value)
{
    if (this->balanta >= value)
        this->balanta -= value;
    else
        std::cout << "Fonduri insuficiente" << std::endl;
}

#endif