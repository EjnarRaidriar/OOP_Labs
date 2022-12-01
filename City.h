#ifndef CITY_H
#define CITY_H

#include<string>
#include<vector>
#include"Resource.h"

class City
{
private:
    std::string name;
    int maxWorkers;
public:
    std::vector<Resource*> warehouse;
    City();
    City(std::string name, int maxWorkers);
    virtual ~City();
    //Getters
    std::string getName();
    int getMaxWorkers();
    //Setters
    void setName(std::string name);
    void setMaxWorkers(int maxWorkers);
    //Output Methods
    void printWarehouse();
};

City::City()
{
    name = "City";
    maxWorkers = 10;
}

City::City(std::string name, int maxWorkers)
{
    this->name = name;
    this->maxWorkers = maxWorkers;
}

City::~City()
{
}

std::string City::getName()
{
    return name;
}

int City::getMaxWorkers()
{
    return maxWorkers;
}

void City::setName(std::string name)
{
    this->name = name;
}

void City::setMaxWorkers(int maxWorkers)
{
    this->maxWorkers = maxWorkers;
}

void City::printWarehouse()
{
    std::cout<<RESET<<"Warehouse data:"<<std::endl;
    int resourceCount[3] = {0, 0, 0};
    for (int i = 0; i < warehouse.size(); i++)
    {
        if (warehouse[i]->getName() == "Wood")
        {
            resourceCount[0]++;
        }
        else if (warehouse[i]->getName() == "Mineral")
        {
            resourceCount[1]++;
        }
        else if (warehouse[i]->getName() == "Fish")
        {
            resourceCount[2]++;
        }
    }
    std::cout<<"      Wood: "<<resourceCount[0]<<std::endl;
    std::cout<<"   Mineral: "<<resourceCount[1]<<std::endl;
    std::cout<<"      Fish: "<<resourceCount[2]<<std::endl;
}

#endif