#ifndef FISHER_H
#define FISHER_H
#include"Worker.h"
#include"Rod.h"
#include<vector>
class Fisher : public Worker
{
private:
    std::vector<Rod> tools;

public:
    Fisher();
    Fisher(std::string name, int age, int cargo);
    virtual ~Fisher();
    //Methods
    void collectResource(Resource* resource) override;
    void addTool(Rod &rod);
    void removeTool(int index);
    //Output Methods
    void printResources() override;
    void printTools();
    void printData();
};

Fisher::Fisher() : Worker()
{
    setName("Nameless Fisher");
    std::cout<<"-> Fisher default constructor called!"<<std::endl;
}

Fisher::Fisher(std::string name, int age, int cargo)
    : Worker(name, age, cargo)
{
    std::cout<<"-> Fisher custom constructor called!"<<std::endl;
}

Fisher::~Fisher()
{
    std::cout<<"-> Fisher destructor called!"<<std::endl;
}

//Methods
void Fisher::collectResource(Resource* resource)
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
        std::cout<<"-> Fisher "<<getName()<<"'s cargo is full\n   He can't collect more resources!"<<std::endl;
    }
}

void Fisher::addTool(Rod &rod)
{
    tools.push_back(rod);
    std::cout<<"-> Fisher picked up a "<<rod.getName()<<std::endl;
}

void Fisher::removeTool(int index)
{
    tools.erase(tools.begin()+index);
}

//Output Methods
void Fisher::printResources()
{
    std::cout<<"-> Fisher "<<getName()<<"'s resources:"<<std::endl;
    for (unsigned int i = 0; i < resources.size(); i++)
    {
        std::cout<<"   Resource nr. "<<i+1<<": "<<resources[i]->getName()<<std::endl;
    }
}

void Fisher::printTools()
{
    std::cout<<"-> "<<getName()<<"'s tools:"<<std::endl;
    for (unsigned int i = 0; i < tools.size(); i++)
    {
        std::cout<<"   Tool nr. "<<i+1<<":"<<std::endl;
        tools[i].printData();
    }
}

void Fisher::printData()
{
    std::cout<<"-> Fisher's data:"<<std::endl;
    std::cout<<"   Name: "<<getName()<<std::endl;
    std::cout<<"   Age: "<<getAge()<<std::endl;
    std::cout<<"   Cargo: "<<getCargo()<<std::endl;
    std::cout<<"   Nr. of tools: "<<tools.size()<<std::endl;
}

#endif