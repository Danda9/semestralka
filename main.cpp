#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Trenuj.h"
#include "NactiData.h"



int main(){

    std::vector <double> omega,ww;
    std::vector <std::vector <double>> XX;
    double pr;
    //int pomocne, y;
    //int poradi;
    NactiData neco = NactiData();
    pr = 8.4;
    //std::vector <vector> X;

    //XX = {{2.3,2.9,1},{-2.1,10.6,1},{20.8,21.7,1}};
    //omega = {0,0,1};
    ww = {5.9,-5.2,pr};
    XX=neco.vektor();

    omega=NactiData().ome;
    //Trenuj lol = Trenuj(XX,omega,ww);
    //int pokus = lol.pomocna();

    //std::cout << pokus;

    //for(int i=0; i<40; i++){
    //lol.porovnavej();
    //}
    std::cout << XX[0].size() << "haha\n";


        //std::cout << rows[1][3];
        //std::cout << " sakjfbkjasbfjasjfasjflasnfaslflkaslnflasnlfnaslnflkasnflaslnflsanfnsalnflaksnflksanfasknfaslkn";



    for(int i=0; i<XX.size(); i++){
        for(int j; j<3; j++){
            std::cout << XX[i][j] << " "<<" poly";
        }
        std::cout << "\n";
    }




//{-2,10,1}



    //bool kontrola = false;

        //for(int i; i < 4; i++){
        //poradi = 0; //poradi asi toto spatne funguje""""""""""
        //for(std:: vector v : X){
          //  std::cout << "poradi:" << poradi << "\n";
            //pomocne = v[0]*w[0]+v[1]*w[1]-prah;
            //if (pomocne<0){
              //  y=0;
            //}
            //else{
              //  y=1;
            //}
            //std::cout << y<< "\n";
            //if (y!=omega[poradi]){
            //    w[0] = w[0] + v[0]*(omega[poradi]-y);
            //    w[1] = w[1] + v[1]*(omega[poradi]-y);
            //    break;
            //}

            //poradi=1;
        //}

        //for (int ii : w) {
          //  std::cout << w[ii] << " ";
        //}
       // std::cout << "czklus\n";


    //}

//}
//    for (std::vector vv : w){
  //     for (int h : k) {
    //        std::cout << k[h] << " ";
        //std::cout << "\n" << std::endl;
    //}
      //  std::cout << "\n";
    //}


    return 0;
}

