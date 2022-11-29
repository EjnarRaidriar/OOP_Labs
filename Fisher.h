#ifndef FISHER_H
#define FISHER_H
#include"Worker.h"
#include"Rod.h"
#include"Fish.h"
#include<vector>
class Fisher : public Worker
{
private:
    std::vector<Rod> tools;

public:
    Fisher();
    Fisher(std::string name, int age, int cargo);
    virtual ~Fisher();
    //Getters
    int getToolAmount() const;
    //Methods
    bool collectResource(Resource* resource) override;
    void addTool(Rod &rod);
    void addNewTool();
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

//Getters
int Fisher::getToolAmount() const
{
    return tools.size();
}

//Methods
bool Fisher::collectResource(Resource* resource)
{
    if (resources.size() < getCargo())
    {
        if (resource->getDurability() <= tools[tools.size()-1].getEfficiency()) {
                tools[tools.size()-1].Hit();
                resources.push_back(resource);
                //Resource* fish = new Fish(*resource);
                //resources.push_back(fish);
                std::cout<<"-> "<<getName()<<" collected "<<resource->getName()<<std::endl;
                return true;
            } else {
                resource->setDurability(resource->getDurability() - tools[tools.size()-1].getEfficiency());
                tools[tools.size()-1].Hit();
                std::cout<<"-> "<<getName()<<" didn't manage to collect "<<resource->getName()<<std::endl;
                std::cout<<"   Resource durability: "<<resource->getDurability()<<std::endl;
                std::cout<<"   Tool efficiency: "<<tools[tools.size()-1].getEfficiency()<<std::endl;
                return false;
        }
    }
    else
    {
        std::cout<<"-> Fisher "<<getName()<<"'s cargo is full\n   He can't collect more resources!"<<std::endl;
        return false;
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

void Fisher::addNewTool()
{
    Rod* rod = new Rod("Rod", 100, 10);
    tools.push_back(*rod);
    std::cout<<"-> Fisher created a new "<<rod->getName()<<std::endl;
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