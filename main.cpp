#include <iostream>
#include <vector>
#include <string>
#include "Investitor.h"

void remove_whitespaces(std::string str)
{ 
    int n = str.size();
    for(int i=0; i<n; i++)
    {
        if(str[i] == ' ')
            str.erase(i,i);
    }
}

void loop(int &varianta, Investitor &object) 
{
    std::cout << "----------------------" << std::endl;
    std::cout << "1 pentru Adaugare fonduri" << std::endl;
    std::cout << "2 pentru Retragere fonduri" << std::endl;
    std::cout << "3 pentru cumparare actiuni" << std::endl;
    std::cout << "4 pentru vanzare actiuni" << std::endl;
    std::cout << "5 pentru afisare statistici" << std::endl;
    std::cout << "6 pentru Exit" << std::endl;

    std::cout << "----------------------" << std::endl;
    std::cout << "Alege: ";
    std::string temp;
    std::cin >> temp;
    try{
        varianta = stoi(temp);
         if (varianta == 1)
        {
            int valoare = 0;
            std::cout << "Suma adugare: ";
            std::cin >> valoare;
            object.add_balance(valoare);
        }
        else if (varianta == 2)
        {
            int valoare = 0;
            std::cout << "Suma retragere: ";
            std::cin >> valoare;
            object.subtract_balance(valoare);
        }
        else if (varianta == 3)
        {
            std::string nume;
            int nr_actiuni;
            std::cout << "Lista actiuni--------------------" << std::endl;
            std::cout << "Tesla la pretul 120 usd cu dividende 2%" << std::endl;
            std::cout << "McDonald's la pretul 230 usd cu dividende 3%" << std::endl;
            std::cout << "Bitcoin la pretul 30000 usd cu dividende 0%" << std::endl;
            std::cout << "Ethereum la pretul 1200 usd cu dividende 0%" << std::endl;
            std::cout << "IBM la pretul 190 usd cu dividende 5%" << std::endl;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "Alege numele actiunii: ";
            std::cin >> nume;
            std::cout << "Alege nr de actiuni: ";
            std::cin >> nr_actiuni;
            if(nume == "Tesla" || nume == "tesla")
                object.add_actiune("Tesla",120,2,nr_actiuni);
            else if(nume == "McDonald's" || nume == "mcdonalds" || nume == "mcdonald's")
                object.add_actiune("McDonald's",230,3,nr_actiuni);
            else if(nume == "Bitcoin" || nume == "bitcoin")
                object.add_actiune("Bitcoin",30000,0,nr_actiuni);
            else if(nume == "Ethereum" || nume == "ethereum")
                object.add_actiune("Ethereum",1200,0,nr_actiuni);
            else if(nume == "IBM" || nume == "ibm")
                object.add_actiune("IBM",190,5,nr_actiuni);
            else
                std::cout << "Actiune inexistenta" << std::endl;
        }
        else if (varianta == 4)
        {
            std::string nume;
            int nr_actiuni;
            std::cout << "Lista actiuni--------------------" << std::endl;
            std::cout << "Tesla la pretul 300 usd" << std::endl;
            std::cout << "McDonald's la pretul 190 usd" << std::endl;
            std::cout << "Bitcoin la pretul 30200 usd" << std::endl;
            std::cout << "Ethereum la pretul 1050 usd" << std::endl;
            std::cout << "IBM la pretul 230 usd" << std::endl;
            std::cout << "---------------------------------" << std::endl;
            std::cout << "Alege numele actiunii: ";
            std::cin >> nume;
            std::cout << "Alege nr de actiuni: ";
            std::cin >> nr_actiuni;
            if(nume == "Tesla" || nume == "tesla")
                object.vinde_actiune("Tesla",300,nr_actiuni);
            else if(nume == "McDonald's" || nume == "mcdonalds" || nume == "mcdonald's")
                object.vinde_actiune("McDonald's",190,nr_actiuni);
            else if(nume == "Bitcoin" || nume == "bitcoin")
                object.vinde_actiune("Bitcoin",30200,nr_actiuni);
            else if(nume == "Ethereum" || nume == "ethereum")
                object.vinde_actiune("Ethereum",1050,nr_actiuni);
            else if(nume == "IBM" || nume == "ibm")
                object.vinde_actiune("IBM",230,nr_actiuni);
        }
        else if (varianta == 5)
        {
            std::cout << object;
        }
        else if (varianta != 6)
        {
            std::cout << "Input invalid" << std::endl;
        }
    }
    catch(...)
    {
        std::cout << "Input invalid" << std::endl;
    }
}

int main()
{
    Investitor investitor1;
    std::cin >> investitor1;
    int x = 0;
    while(x!=6)
    {
        loop(x,investitor1);
    }
    return 0;
}