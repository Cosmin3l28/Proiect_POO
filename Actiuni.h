#ifndef _ACTIUNI_H_
#define _ACTIUNI_H_

#include <string>

class Actiuni
{
private:
    std::string nume;
    int valoare;
    int numar_actiuni;
    int dividende;
public:
    std::string get_name();
    int get_valoare();
    void add_numar_actiune(const Actiuni &actiune);
    int get_numar_actiune();
    Actiuni operator-(const int &numar_actiuni) const;
    Actiuni(const std::string &nume, const int &valoare, const int &dividende = 0, const int &numar_actiuni = 0);
    Actiuni(const Actiuni &object);
    ~Actiuni();
    Actiuni operator=(const Actiuni &object);
};

Actiuni::Actiuni(const std::string &nume, const int &valoare, const int &dividende, const int &numar_actiuni) : nume{nume}, valoare{valoare}, numar_actiuni{numar_actiuni}, dividende{dividende}{}

Actiuni::Actiuni(const Actiuni &object) : Actiuni(object.nume, object.valoare, object.valoare, object.numar_actiuni){}

Actiuni::~Actiuni(){}

Actiuni Actiuni::operator-(const int &numar_actiuni) const
{
    if(numar_actiuni == 0)
        return *this;
    if(this->numar_actiuni > numar_actiuni)
    {
        Actiuni temp(this->nume,this->valoare,this->dividende,this->numar_actiuni-numar_actiuni);
        return temp;
    }
    else
    {
        std::cout << "Actiuni insuficiente" << std::endl;
        return *this;
    }
}

Actiuni Actiuni::operator=(const Actiuni &object)
{
    if(this == &object)
        return *this;
    else
    {
        this->nume = object.nume;
        this->valoare = object.valoare;
        this->numar_actiuni = object.numar_actiuni;
        this->dividende = object.dividende;
    }
    return *this;
}

std::string Actiuni::get_name()
{
    return this->nume;
}

int Actiuni::get_valoare()
{
    return this->valoare;
}

void Actiuni::add_numar_actiune(const Actiuni &actiune)
{
    this->numar_actiuni += actiune.numar_actiuni;
}

int Actiuni::get_numar_actiune()
{
    return this->numar_actiuni;
}

#endif