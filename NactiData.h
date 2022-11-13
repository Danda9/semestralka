#ifndef NACTIDATA_H
#define NACTIDATA_H
#include <vector>
#include <iostream>


class NactiData
{
public:
    NactiData();
    std::vector<std::vector <double>> v,vek;
    std::vector<double> ome;
    virtual ~NactiData();
        std::vector<std::vector <double>> data(), vektor();

protected:

private:
    bool testovaci;
    std::string fileName;

    std::vector<double> omega();
    void zeptejSe();
    //std::vector<std::vector<double>> rows;
};

#endif // NACTIDATA_H
