#ifndef PICKAXE_H
#define PICKAXE_H
#include"Tool.h"
class Pickaxe : public Tool
{
private:
    /* data */
public:
    Pickaxe();
    Pickaxe(std::string name, int durability, int efficiency);
    virtual ~Pickaxe();
    //Methods
    virtual void Sharpen() override;
    virtual void Hit() override;
};

Pickaxe::Pickaxe() : Tool()
{
    setName("Pickaxe");
    std::cout<<MAGENTA<<"-> Pickaxe default constructor called!"<<std::endl;
}

Pickaxe::Pickaxe(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{
    std::cout<<MAGENTA<<"-> Pickaxe custom constructor called!"<<std::endl;
}

Pickaxe::~Pickaxe()
{
    std::cout<<MAGENTA<<"-> Pickaxe destructor called!"<<std::endl;
}

//Methods
void Pickaxe::Sharpen()
{
    if (getEfficiency() < 5) {//change according to efficiency
            setEfficiency(getDurability() + 1);
            std::cout<<GREEN<<"-> "<<getName()<<" sharpened succesfully!"<<std::endl;
        } else {
            std::cout<<RED<<"-> "<<getName()<<" can't be sharpened anymore!"<<std::endl;
        }
}

void Pickaxe::Hit()
{
    setHits(getHits() + 1);
    if (getHits() > getDurability()) {
        setEfficiency(getEfficiency() - 1);
        std::cout<<RED<<"-> Efficiency redurced to "<<getEfficiency()<<std::endl;
        setHits(0);
    }
}

#endif