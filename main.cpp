#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Trenuj.h"
#include "Testuj.h"
#include "NactiData.h"



int main(){
    std::srand((unsigned) time(NULL));      //aby se mi pokazde tvorila zarucene tvorila pseudonahodna cisla


    std::vector <double> omega,ww, natrenovane_vahy,vysledek_testu;
    std::vector <std::vector <double>> XX,YY;
    double pocatecniPrah, natrenovany_prah, w1,w2;


    NactiData treninkovaData=NactiData();
    NactiData testovaciData=NactiData();


    w1=std::rand()%100;                //chci, aby vahy byly na 2 desetinna mista
    w2=std::rand()%100;
    pocatecniPrah = std::rand()%20+ (-10);  //nahodne cislo mezi cisli -10 a 10
    ww={w1/1,w2/1,pocatecniPrah};   //pocatencni hodnoty, na kterych se zacina ucit


    XX=treninkovaData.vektor_souradnic;          //nacteni treninkovych souradnic do vektoru vektoruu, ve forme [[souradnice x1, souradnice y1, 1],[souradnice x2, souradnice y2, 1],...
    omega=treninkovaData.omega_out;       //nactecni hodnot, ktere by neuron mel neuron urcit, resp. v jake polorovine bod lezi, vektor s cisli 0 a 1


    Trenuj lol = Trenuj(XX,omega,ww);   //samotne natrenovani/zjisteni hodnot vah a prahu neuronu
                                        //to "lol" je jakoby zbytecne, ale musel jsem ho vytvorit, abych mel pristup k tem hledanym hodnotam
    natrenovane_vahy=lol.vahy;
    natrenovany_prah=lol.prah;


    YY=testovaciData.vektor_souradnic;           //nacteni testovacich souradnic (kterym neuron urci, jejich hodnotu tj. 0 nebo 1) do vektoru vektoruu ve forme
                                    //[[souradnice x1, souradnice y1, 1],[souradnice x2, souradnice y2, 1],...  ty jednicky jsou tam zbytecny, nepotrebny, jsou tam, protoze pouzivam stejnou vec jako
                                    //na nacteni treninkovych dat

    Testuj lol2=Testuj(YY,natrenovane_vahy,natrenovany_prah);   //zjistovani jakou hodnotu (0 nebo 1) maji vektory
                                                                //to "lol2" je jakoby zbytecne, ale musel jsem ho vytvorit, abych mel pristup k tem hledanym hodnotam
    vysledek_testu=lol2.rozrazeni_out;      // vektor nul a jednicek




    //for(int i=0; i<YY.size(); i++){               //zde lze vypsat testovaci data spolecne s prirazenymi hodnotami
    //    for(int j=0; j<YY[i].size(); j++){
    //        std::cout << YY[i][j];
    //        std::cout << " ";
    //    }
    //    std::cout << "\n";
    //}

    std::cout << "\nPrirazene hodnoty: \n";
    for(int i=0;i<vysledek_testu.size();i++){
        std::cout << vysledek_testu[i] << "\n";
    }
    std::cout << "Hodnoty vah neuronu: " << natrenovane_vahy[0] << " " << natrenovane_vahy[1] << "\n";
    std::cout << "Hodnota prahu neuronu: " << natrenovany_prah << "\n";


    return 0;
}
