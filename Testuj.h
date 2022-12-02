#ifndef TESTUJ_H
#define TESTUJ_H
#include <iostream>
#include <vector>

class Testuj
{
    public:
        Testuj(std::vector <std::vector <double>>& Y_in, std::vector <double> vahy_in, double prah_in);
        virtual ~Testuj();
        std::vector <double> rozrazeni_out;
        std::vector <std::vector <double>> X_out;
    protected:

    private:
        std::vector <std::vector <double>> Y;
        std::vector <double> vahy,rozrazeni;
        double pomocna(),pra,om;
        int y(),poradi;
        void porovnavej(),dopln(std::vector <std::vector <double>>& X_inn);
        bool kontrola;
};

#endif // TESTUJ_H
