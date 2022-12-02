#include "Trenuj.h"
#include <fstream>

Trenuj::Trenuj(std::vector <std::vector <double>>& X_in, std::vector <double> om_in, std::vector <double> w_in)
{
    X = X_in;       //sem se vlozi vektor, ktery je v mainu pojmenovan jako XX, atd pro ostatni promenne
    om = om_in;     //asi by slo pracovat rovnou se samotnymi _in promennymi
    w = w_in;
    w.push_back(0);
    vektorUceni.push_back(w);

    vysledek = porovnavej();

    vahy = {vysledek[0],vysledek[1]};   //abych mel snadny pristup k hodnotam
    prah = vysledek[2];
    UlozDoSouboru();
    //ctor
}

 double Trenuj::pomocna(){

    return X[poradi][0]*w[0]+X[poradi][1]*w[1]+w[2];    //vypocet ze vzorecku, ktery pak porovnavam oproti nule, viz dalsi radek
}

int Trenuj::y(){            //zde neuron vyhodnocuje, zda priradi 0 nebo 1
    if (pomocna() < 0){
        return 0;
    }
    else {
        return 1;
    }
}

void Trenuj::porovnej(){
    yy = y();
    if (y() != om[poradi]){                         //zjistuji, zda neuron spravne priradil 0 ci 1 danemu bodu, pokud ne, vypoctu nove vahy a prah podle vzorecku
        w[0] = w[0] + X[poradi][0]*(om[poradi]-yy); //pouzivam yy, protoze pri zmene vah by se nove prepocitalo y(), takze bych do w[0], w[1] a w[2] dosazoval jina cisla
        w[1] = w[1] + X[poradi][1]*(om[poradi]-yy);
        w[2] = w[2] + X[poradi][2]*(om[poradi]-yy);
        kontrola = false;
        poradi = 0;                                 //pokud jsem vypocital nove vahy, musim zkontrolovat, ze vyhovuji i predchozim bodum, proto jdu zase od zacatku
    }
    else{
        kontrola = true;        //kdyz neuron priradil spravne, mohu se posunout na dalsi bod
        poradi = poradi+1;
    }
    if (poradi>maxPoradi){
        maxPoradi=poradi;
        w3 = 1;
    }
    else{
        w3 = 0;
    }
    zapisDoVektoru();
    //std::cout << w[0] << " " << w[1] << " " << w[2] << " /n"; //<< w3 << " " << maxPoradi << "\n";        //vypisovani jak se uci
}

std::vector <double> Trenuj::porovnavej(){
    poradi= 0;
    maxPoradi;
    pocitadlo = 0;
    kontrola = false;
    do{
        porovnej();
    } while(poradi < X.size()); //dokud neprojede vsechny vektory (body) v X
    return w;
}

void Trenuj::zapisDoVektoru(){                      //zde ukladam jak se perceptron uci
    if(vektorUceni[pocitadlo][0] != w[0] || vektorUceni[pocitadlo][1] != w[1] || vektorUceni[pocitadlo][2] != w[2] || w3==1){
        std::vector <double> pomocnyVektor;
        pomocnyVektor.push_back(w[0]);
        pomocnyVektor.push_back(w[1]);
        pomocnyVektor.push_back(w[2]);
        pomocnyVektor.push_back(w3);
        vektorUceni.push_back(pomocnyVektor);
        pocitadlo++;
    }
}

void Trenuj::UlozDoSouboru(){                       //ulozim do souboru, jak se perceptron ucil
    std::ofstream zapis("Data_ProcesUceni.txt");
    for(int i=0; i<vektorUceni.size(); i++){
        zapis << vektorUceni[i][0] << " " << vektorUceni[i][1] << " " << vektorUceni[i][2] << " " << vektorUceni[i][3] << "\n";
    }

}

Trenuj::~Trenuj()
{
    //dtor
}
