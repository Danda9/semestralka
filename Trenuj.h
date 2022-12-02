#ifndef TRENUJ_H
#define TRENUJ_H
#include <iostream>
#include <vector>

class Trenuj
{
    public:
        Trenuj(std::vector <std::vector <double>>& X_in, std::vector <double> om_in, std::vector <double> w_in);
        virtual ~Trenuj();
        double pomocna(), prah;
        std::vector <double> vysledek,vahy;
        int y();
        void porovnej();

    protected:

    private:
        std::vector <std::vector <double>> X, vektorUceni;
        std::vector <double> om, w, porovnavej();
        double yy;
        int poradi, pocitadlo, maxPoradi, w3;
        bool kontrola;
        void zapisDoVektoru(), UlozDoSouboru();
};

#endif // TRENUJ_H
