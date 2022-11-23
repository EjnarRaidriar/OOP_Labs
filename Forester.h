#ifndef FORESTER_H
#define FORESTER_H
#include"Worker.h"
#include"Axe.h"
#include<vector>
class Forester : public Worker
{
private:
    std::vector<Axe> tools;

public:
    Forester();
    Forester(std::string name, int age, int cargo);
    virtual ~Forester();
    //Methods
    void collectResource(Resource* resource) override;
    void addTool(Axe &axe);
    void removeTool(int index);
    void printTools();
    void printData();
};

Forester::Forester() : Worker()
{
    setName("Forester");
    std::cout<<"-> Forester default constructor called!"<<std::endl;
}

Forester::Forester(std::string name, int age, int cargo)
    : Worker(name, age, cargo)
{
    std::cout<<"-> Forester custom constructor called!"<<std::endl;
}

Forester::~Forester()
{
    std::cout<<"-> Forester destructor called!"<<std::endl;
}

//Methods
void Forester::collectResource(Resource* resource)
{
    if (resource->getDurability() <= tools[tools.size()-1].getEfficiency()) {
            tools[tools.size()-1].Hit();
            resource->~Resource();
            setCargo(getCargo()+1);
        } else {
            resource->setDurability(resource->getDurability() - tools[tools.size()-1].getEfficiency());
            tools[tools.size()-1].Hit();
    }
}

void Forester::addTool(Axe &axe)
{
    tools.push_back(axe);
    std::cout<<"-> Forester picked up a "<<axe.getName()<<std::endl;
}

void Forester::removeTool(int index)
{
    tools.erase(tools.begin()+index);
}

void Forester::printTools()
{
    std::cout<<"-> "<<getName()<<"'s tools:"<<std::endl;
    for (unsigned int i = 0; i < tools.size(); i++)
    {
        std::cout<<"   Tool nr. "<<i+1<<":"<<std::endl;
        tools[i].printData();
    }
}

void Forester::printData()
{
    std::cout<<"-> Forester's data:"<<std::endl;
    std::cout<<"   Name: "<<getName()<<std::endl;
    std::cout<<"   Age: "<<getAge()<<std::endl;
    std::cout<<"   Cargo: "<<getCargo()<<std::endl;
    std::cout<<"   Nr. of tools: "<<tools.size()<<std::endl;
}

#endif