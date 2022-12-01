#ifndef AXE_H
#define AXE_H
#include"Tool.h"
class Axe : public Tool
{
private:
    /* data */
public:
    Axe();
    Axe(std::string name, int durability, int efficiency);
    virtual ~Axe();
    //Methods
    virtual void Sharpen() override;
    virtual void Hit() override;
};

Axe::Axe() : Tool()
{
    setName("Axe");
    std::cout<<MAGENTA<<"-> Axe default constructor called!"<<std::endl;
}

Axe::Axe(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{
    std::cout<<MAGENTA<<"-> Axe custom constructor called!"<<std::endl;
}

Axe::~Axe()
{
    std::cout<<MAGENTA<<"-> Axe destructor called!"<<std::endl;
}

//Methods
void Axe::Sharpen()
{
    if (getEfficiency() < 5) {//change according to efficiency
            setEfficiency(getDurability() + 1);
            std::cout<<GREEN<<"-> "<<getName()<<" sharpened succesfully!"<<std::endl;
        } else {
            std::cout<<RED<<"-> "<<getName()<<" can't be sharpened anymore!"<<std::endl;
        }
}

void Axe::Hit()
{
    setHits(getHits() + 1);
    if (getHits() > getDurability()) {
        setEfficiency(getEfficiency() - 1);
        std::cout<<RED<<"-> Efficiency redurced to "<<getEfficiency()<<std::endl;
        setHits(0);
    }
}

#endif