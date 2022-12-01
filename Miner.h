#ifndef MINER_H
#define MINER_H
#include"Worker.h"
#include"Pickaxe.h"
#include"Mineral.h"
#include<vector>
class Miner : public Worker
{
private:
    std::vector<Pickaxe> tools;

public:
    Miner();
    Miner(std::string name, int age, int cargo);
    virtual ~Miner();
    //Getters
    int getToolAmount() const;
    //Methods
    bool collectResource(Resource* resource) override;
    void addTool(Pickaxe &pickaxe);
    void addNewTool();
    void removeTool(int index);
    //Output Methods
    void printResources() override;
    void printTools();
    void printData();
};

Miner::Miner() : Worker()
{
    setName("Nameless Miner");
    std::cout<<MAGENTA<<"-> Miner default constructor called!"<<std::endl;
}

Miner::Miner(std::string name, int age, int cargo)
    : Worker(name, age, cargo)
{
    std::cout<<MAGENTA<<"-> Miner custom constructor called!"<<std::endl;
}

Miner::~Miner()
{
    std::cout<<MAGENTA<<"-> Miner destructor called!"<<std::endl;
}

//Getters
int Miner::getToolAmount() const
{
    return tools.size();
}
//Methods
bool Miner::collectResource(Resource* resource)
{
    if (resource == NULL)
    {
        std::cout<<RED<<"-> No resource to collect!"<<std::endl;
        return false;
    }
    if (resources.size() < getCargo())
    {
        if (resource->getDurability() <= tools[tools.size()-1].getEfficiency()) {
                tools[tools.size()-1].Hit();
                resources.push_back(resource);
                //Resource* mineral = new Mineral(*resource);
                //resources.push_back(mineral);
                std::cout<<GREEN<<"-> "<<getName()<<" collected "<<resource->getName()<<std::endl;
                return true;
            } else {
                resource->setDurability(resource->getDurability() - tools[tools.size()-1].getEfficiency());
                tools[tools.size()-1].Hit();
                std::cout<<RESET<<"-> "<<getName()<<" strikes "<<resource->getName()<<std::endl;
                std::cout<<"   Resource durability: "<<resource->getDurability()<<std::endl;
                std::cout<<"   Tool efficiency: "<<tools[tools.size()-1].getEfficiency()<<std::endl;
                return false;
        }
    }
    else
    {
        std::cout<<RED<<"-> Miner "<<getName()<<"'s cargo is full\n   He can't collect more resources!"<<std::endl;
        return false;
    }
}

void Miner::addTool(Pickaxe &pickaxe)
{
    tools.push_back(pickaxe);
    std::cout<<YELLOW<<"-> Miner picked up a "<<pickaxe.getName()<<std::endl;
}

void Miner::removeTool(int index)
{
    tools.erase(tools.begin()+index);
}

void Miner::addNewTool()
{
    Pickaxe* pickaxe = new Pickaxe("Pickaxe", 100, 10);
    tools.push_back(*pickaxe);
    std::cout<<YELLOW<<"-> "<<getName()<<" created a new "<<pickaxe->getName()<<std::endl;
}

//Output Methods
void Miner::printResources()
{
    std::cout<<RESET<<"-> Miner "<<getName()<<"'s resources:"<<std::endl;
    for (unsigned int i = 0; i < resources.size(); i++)
    {
        std::cout<<"   Resource nr. "<<i+1<<": "<<resources[i]->getName()<<std::endl;
    }
}

void Miner::printTools()
{
    std::cout<<RESET<<"-> "<<getName()<<"'s tools:"<<std::endl;
    for (unsigned int i = 0; i < tools.size(); i++)
    {
        std::cout<<"   Tool nr. "<<i+1<<":"<<std::endl;
        tools[i].printData();
    }
}

void Miner::printData()
{
    std::cout<<RESET<<"-> Miner's data:"<<std::endl;
    std::cout<<"   Name: "<<getName()<<std::endl;
    std::cout<<"   Age: "<<getAge()<<std::endl;
    std::cout<<"   Cargo: "<<getCargo()<<std::endl;
    std::cout<<"   Nr. of tools: "<<tools.size()<<std::endl;
}

#endif