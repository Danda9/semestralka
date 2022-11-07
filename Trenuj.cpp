#include "Trenuj.h"

Trenuj::Trenuj(std::vector <std::vector <double>>& X_in, std::vector <double> om_in, std::vector <double> w_in)
{
    X = X_in;
    om = om_in;
    w = w_in;
    prah = 1;
    poradi= 0;
    kontrola = false;
    //ctor
}

 double Trenuj::pomocna(){

    return X[poradi][0]*w[0]+X[poradi][1]*w[1]+w[2];
}

int Trenuj::y(){
    if (pomocna() < 0){
        return 0;
    }
    else {
        return 1;
    }
}

void Trenuj::porovnej(){
    yy = y();
    if (y() != om[poradi]){
        w[0] = w[0] + X[poradi][0]*(om[poradi]-yy);
        w[1] = w[1] + X[poradi][1]*(om[poradi]-yy);
        w[2] = w[2] + X[poradi][2]*(om[poradi]-yy);
        kontrola = false;
        poradi = 0;
    }
    else{
        kontrola = true;
        poradi = poradi+1;
    }
    std::cout << w[0] << " " << w[1] << " " << w[2] << "\n";
}

void Trenuj::porovnavej(){
    do{
        porovnej();
    } while(poradi < X.size());

}

Trenuj::~Trenuj()
{
    //dtor
}
