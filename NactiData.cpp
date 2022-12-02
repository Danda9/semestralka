#include "NactiData.h"
#include <fstream>
#include <vector>
#include <iostream>

NactiData::NactiData()
{
    dataZeSouboru=data();       //do tohoto vektoru nactu ciselna data ze souboru
    vektor_souradnic=vektor();
    omega_out=omega_inside();
}

std::vector<std::vector <double>> NactiData::data() //princip: vezmu radek ze souboru a hledam mezeru, podle ni totiz poznam, kde je konec prvniho cisla na radku.
{
    zeptejSe();
    std::ifstream file;
    file.open(fileName);
    std::vector<std::vector <double>> rows;
    std::string line;
    char znak;
    while (std::getline(file,line))             //cyklus kde si beru radek po radku, dokud nedojdu na konec souboru
    {
        std::vector<double> row;                //vektor, do ktereho budu davat cisla z daneho radku, "definovat" tady, aby se pri kazdem opakovani na zacatku cyklu vyprazdnil
        while (!line.empty())                   //dokud nebudu na konci radku
        {
            for(int i=0; i<line.size(); i++)    //jdu znak po znaku v danem radku a dokud nenajdu znak, ktery neni mezera, nalezene mezery odstranim, a tim se dostanu k zacatku cisla
            {
                znak=line.at(i);
                if(znak!=32)                    //cislo 32 je v ascii tabulce mezera
                {
                    line.erase(0,i);            //zde se odstranim ty mezery na zacatku radku, "uzeru radek zepredu" a skoncim cyklus for
                    break;
                }
            }
            int spaceIndex = line.find(" ");    //hledam, kde se nachazi dalsi mezera, a tim najdu konec cisla
            if(spaceIndex == -1)                //kdyz uz zadnou mezeru nenajdu
            {
                spaceIndex = line.size();
            }
            std::string cislo;
            cislo= line.substr(0,spaceIndex);   //vezmu si znaky od zacatku radku k mezeru
            row.push_back(std::stod(cislo));    //ulozim do vektoru, ale nejprve ty znaky musim prevest na cisla (konkretne double)-zajistuje metoda stod()
            line.erase(0,spaceIndex+1);         //uzeru radek o to cislo, protoze jsem si ho uz ulozil a chci nacist dalsi cisla z daneho radku
        }
        rows.push_back(row);                    //po ukonceni cyklu while ulozim vektor row do vektoru vektoruu rows a jedu to cele znova pro dalsi radek
    }
    return rows;
}

void NactiData::zeptejSe()      //Tady jen urcim, ktera data budu nacitat. Nevim, proc jsem to udelal takle, je to zbytecny, lepsi by bylo to udelat "natvrdo" bez otravneho vyptavani, ale uz se mi to
                                //nechce menit.
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
        fileName="testset.txt";
    }
}

std::vector<std::vector <double>> NactiData::vektor()   //zde ziskavam format [[souradnice x1, souradnice y1, 1],[souradnice x2, souradnice y2, 1],...
{
    std::vector <std::vector <double>> pomocnyVektor;
    for(int i=0; i<dataZeSouboru.size(); i++)
    {
        std::vector<double> pomocny;
        pomocny.push_back(dataZeSouboru[i][1]);
        pomocny.push_back(dataZeSouboru[i][2]);
        pomocny.push_back(1);
        pomocnyVektor.push_back(pomocny);
    }
    return pomocnyVektor;
}

std::vector<double> NactiData::omega_inside()              //vytvorim vektor nul a jednicek pro prislusne body
{
    std::vector<double> pomocnyOmega;
    for(int i=0; i<dataZeSouboru.size(); i++)
    {
        pomocnyOmega.push_back(dataZeSouboru[i][0]);
    }
    return pomocnyOmega;
}

NactiData::~NactiData()
{
    //dtor
}
