#ifndef TRENUJ_H
#define TRENUJ_H
#include <iostream>
#include <vector>

class Trenuj
{
    public:
        Trenuj(std::vector <std::vector <double>>& X_in, std::vector <double> om_in, std::vector <double> w_in);
        virtual ~Trenuj();
        double pomocna();
        int y();
        void porovnej();
        void porovnavej();

    protected:

    private:
        std::vector <std::vector <double>> X;
        std::vector <double> om, w;
        double v1,v2,w1,w2,yy, prah;
        int poradi;
        bool kontrola;
};

#endif // TRENUJ_H
