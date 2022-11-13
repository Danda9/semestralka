#include "NactiData.h"
#include <fstream>
#include <vector>
#include <iostream>

NactiData::NactiData()
{
    v=data();//ctor

    //vek=vektor();
    //ome=omega();
}

std::vector<std::vector <double>> NactiData::data()
{
    zeptejSe();
    std::ifstream file;
    file.open(fileName);
    std::vector<std::vector <double>> radky;
    std::string line;
    int pocitadlo=0;
    char znak;
    while (std::getline(file,line))
    {
        int pocitadlo2=0;
        std::vector<double> row(3);
        radky.push_back(row);
        while (!line.empty())
        {

            for(int i=0; i<line.size(); i++)
            {
                znak=line.at(i);
                if(znak!=32)
                {
                    line.erase(0,i);
                    break;
                }
            }
            //std::cout << line << "\n";
            int spaceIndex = line.find(" ");
            if(spaceIndex == -1)
            {
                spaceIndex = line.size();
            }
            std::string cislo;
            cislo= line.substr(0,spaceIndex);
            radky[pocitadlo][pocitadlo2]=std::stod(cislo);
            //radky[pocitadlo].push_back(std::stod(cislo));
            //row[pocitadlo2]=std::stod(cislo);
            //row.push_back(cislo);
            line.erase(0,spaceIndex+1);
            pocitadlo2=pocitadlo2+1;
        }
        for(int i=0; i<row.size(); i++)
        {
            //std::cout << row[i] << " ";
            //std::cout << "\n";
        }
        //radky.push_back(row);
        //rows[pocitadlo]=row;
        //std::cout << row[0]<<" "<<row[1]<< " "<<row[2] << "\n";
        pocitadlo=pocitadlo+1;
    }
    for(int i=1; i<radky.size(); i++)
    {
        for(int j; j<3; j++)
        {
            std::cout << radky[i][j] << " "<<" poly";
        }
        std::cout << "\n";
    }
    return radky;
}

void NactiData::zeptejSe()
{
    std::cout << "Pro nacteni treninkovych dat stiknete '1', pro testovaci stiknete '2': ";
    int typ;
    std::cin >> typ;
    if(typ==1)
    {
        fileName="trset.txt";
    }
    else
    {
        fileName="testset";
    }


    //if(typ==1){
    //    testovaci=false;
    //}
    //else{
    //    testovaci=true;
    //}
    //std::cout << "\nZadej nazev souboru: ";
    //std::cin >> fileName;
}

std::vector<std::vector <double>> NactiData::vektor()
{
    std::vector <std::vector <double>> pomocnyVektor;

    //if (testovaci==false){
    for(int i=0; i<v.size(); i++)
    {
        std::vector<double> pomocny;
        pomocny.push_back(v[i][1]);
        pomocny.push_back(v[i][2]);
        pomocny.push_back(1);
        pomocnyVektor.push_back(pomocny);
    }
    //}
    return pomocnyVektor;
}

std::vector<double> NactiData::omega()
{
    std::vector<double> pomocny;
    for(int i=0; i<v.size(); i++)
    {
        pomocny.push_back(v[i][0]);
    }
    //}
    return pomocny;
}

NactiData::~NactiData()
{
    //dtor
}
