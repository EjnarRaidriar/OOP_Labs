#ifndef MINER_H
#define MINER_H
#include"Worker.h"
#include"Pickaxe.h"
#include<vector>
class Miner : public Worker
{
private:
    std::vector<Pickaxe> tools;

public:
    Miner();
    Miner(std::string name, int age, int cargo);
    virtual ~Miner();
    //Methods
    void collectResource(Resource* resource) override;
    void addTool(Pickaxe &pickaxe);
    void removeTool(int index);
    //Output Methods
    void printResources() override;
    void printTools();
    void printData();
};

Miner::Miner() : Worker()
{
    setName("Nameless Miner");
    std::cout<<"-> Miner default constructor called!"<<std::endl;
}

Miner::Miner(std::string name, int age, int cargo)
    : Worker(name, age, cargo)
{
    std::cout<<"-> Miner custom constructor called!"<<std::endl;
}

Miner::~Miner()
{
    std::cout<<"-> Miner destructor called!"<<std::endl;
}

//Methods
void Miner::collectResource(Resource* resource)
{
    if (resources.size() < getCargo())
    {
        if (resource->getDurability() <= tools[tools.size()-1].getEfficiency()) {
                tools[tools.size()-1].Hit();
                resources.push_back(resource);
                setCargo(getCargo()+1);
                std::cout<<"-> "<<getName()<<" collected "<<resource->getName()<<std::endl;
            } else {
                resource->setDurability(resource->getDurability() - tools[tools.size()-1].getEfficiency());
                tools[tools.size()-1].Hit();
                std::cout<<"-> "<<getName()<<" didn't manage to collect "<<resource->getName()<<std::endl;

        }
    }
    else
    {
        std::cout<<"-> Miner "<<getName()<<"'s cargo is full\n   He can't collect more resources!"<<std::endl;
    }
}

void Miner::addTool(Pickaxe &pickaxe)
{
    tools.push_back(pickaxe);
    std::cout<<"-> Miner picked up a "<<pickaxe.getName()<<std::endl;
}

void Miner::removeTool(int index)
{
    tools.erase(tools.begin()+index);
}

//Output Methods
void Miner::printResources()
{
    std::cout<<"-> Miner "<<getName()<<"'s resources:"<<std::endl;
    for (unsigned int i = 0; i < resources.size(); i++)
    {
        std::cout<<"   Resource nr. "<<i+1<<": "<<resources[i]->getName()<<std::endl;
    }
}

void Miner::printTools()
{
    std::cout<<"-> "<<getName()<<"'s tools:"<<std::endl;
    for (unsigned int i = 0; i < tools.size(); i++)
    {
        std::cout<<"   Tool nr. "<<i+1<<":"<<std::endl;
        tools[i].printData();
    }
}

void Miner::printData()
{
    std::cout<<"-> Miner's data:"<<std::endl;
    std::cout<<"   Name: "<<getName()<<std::endl;
    std::cout<<"   Age: "<<getAge()<<std::endl;
    std::cout<<"   Cargo: "<<getCargo()<<std::endl;
    std::cout<<"   Nr. of tools: "<<tools.size()<<std::endl;
}

#endif