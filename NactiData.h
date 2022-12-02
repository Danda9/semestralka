#ifndef NACTIDATA_H
#define NACTIDATA_H
#include <vector>
#include <iostream>


class NactiData
{
public:
    NactiData();
    std::vector<std::vector <double>> dataZeSouboru,vektor_souradnic;
    std::vector<double> omega_out;
    virtual ~NactiData();

protected:

private:
    std::string fileName;
    std::vector<std::vector <double>> data(), vektor();
    std::vector<double> omega_inside();
    void zeptejSe();

};

#endif // NACTIDATA_H
