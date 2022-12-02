#include "Testuj.h"

Testuj::Testuj(std::vector <std::vector <double>>& Y_in, std::vector <double> vahy_in, double prah_in)
{
    Y = Y_in;           //sem se vlozi vektor, ktery je v mainu pojmenovan jako YY, atd pro ostatni promenne
    vahy = vahy_in;
    pra=prah_in;

    porovnavej();       //inicializuji, aby se mi naplnil vektor "rozrazeni", myslim, ze to cele slo napsat rozumeji

    rozrazeni_out=rozrazeni;    //vektor nul a jednicek, podle toho jak neuron urcil jednotlivym bodum
    dopln(Y_in); //ctor
}

 double Testuj::pomocna(){

    return Y[poradi][0]*vahy[0]+Y[poradi][1]*vahy[1]-pra;       //vypocet ze vzorecku, ktery pak porovnavam oproti nule, viz dalsi radek
}

int Testuj::y(){            //zde neuron vyhodnocuje, zda priradi 0 nebo 1
    if (pomocna() < 0){
        return 0;
    }
    else {
        return 1;
    }
}

void Testuj::porovnavej(){
    poradi= 0;
    kontrola = false;
    do{
        rozrazeni.push_back(y());   //na konec vektoru prida 0 nebo 1, podle toho jak se urcilo v y()
        poradi++;
    } while(poradi < Y.size());     //dokud vsem bodum nepridelim hodnotu 0 nebo 1
}

void Testuj::dopln(std::vector <std::vector <double>>& Y_inn){  //primo ve vektoru vektoruu YY prepisuji 3. souradnici vektoru (to je ta nepotrebna jednica) na neuronem urcenou hodnotu, tj. 0 nebo 1

    for(int i=0; i<Y_inn.size(); i++){
        Y_inn[i][2]=rozrazeni_out[i];
        //std::cout << X[i][2] << "\n";
    }

}

Testuj::~Testuj()
{
    //dtor
}
