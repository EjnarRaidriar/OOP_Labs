#ifndef FORESTER_H
#define FORESTER_H
#include"Worker.h"
#include"Axe.h"
#include"Wood.h"
#include<vector>
class Forester : public Worker
{
private:
    std::vector<Axe> tools;

public:
    Forester();
    Forester(std::string name, int age, int cargo);
    virtual ~Forester();
    //Getters
    int getToolAmount() const;
    //Methods
    bool collectResource(Resource* resource) override;
    void addTool(Axe &axe);
    void addNewTool();
    void removeTool(int index);
    //Output Methods
    void printResources() override;
    void printTools();
    void printData();
};

Forester::Forester() : Worker()
{
    setName("Nameless forester");
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

//Getters
int Forester::getToolAmount() const
{
    return tools.size();
}
//Methods
bool Forester::collectResource(Resource* resource)
{
    if (resources.size() < getCargo())
    {
        if (resource->getDurability() <= tools[tools.size()-1].getEfficiency()) {
                tools[tools.size()-1].Hit();
                Resource* wood = new Wood(*resource);
                resources.push_back(wood);
                std::cout<<"-> "<<getName()<<" collected "<<resource->getName()<<std::endl;
                return true;
            } else {
                resource->setDurability(resource->getDurability() - tools[tools.size()-1].getEfficiency());
                tools[tools.size()-1].Hit();
                std::cout<<"-> "<<getName()<<" strikes "<<resource->getName()<<std::endl;
                std::cout<<"   Resource durability: "<<resource->getDurability()<<std::endl;
                std::cout<<"   Tool efficiency: "<<tools[tools.size()-1].getEfficiency()<<std::endl;
                return false;
        }
    }
    else
    {
        std::cout<<"-> Forester "<<getName()<<"'s cargo is full\n   He can't collect more resources!"<<std::endl;
        return false;
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

void Forester::addNewTool()
{
    Axe* axe = new Axe("Axe", 100, 10);
    tools.push_back(*axe);
    std::cout<<"-> "<<getName()<<" created a new "<<getName()<<std::endl;
}

//Output Methods
void Forester::printResources()
{
    std::cout<<"-> Forester "<<getName()<<"'s resources:"<<std::endl;
    for (unsigned int i = 0; i < resources.size(); i++)
    {
        std::cout<<"   Resource nr. "<<i+1<<": "<<resources[i]->getName()<<std::endl;
    }
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