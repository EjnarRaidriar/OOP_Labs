#ifndef ROD_H
#define ROD_H
#include"Tool.h"
class Rod : public Tool
{
private:
    /* data */
public:
    Rod();
    Rod(std::string name, int durability, int efficiency);
    virtual ~Rod();
    //Methods
    virtual void Sharpen() override;
    virtual void Hit() override;
};

Rod::Rod() : Tool()
{
    setName("Rod");
    std::cout<<MAGENTA<<"-> Rod default constructor called!"<<std::endl;
}

Rod::Rod(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{
    std::cout<<MAGENTA<<"-> Rod custom constructor called!"<<std::endl;
}

Rod::~Rod()
{
    std::cout<<MAGENTA<<"-> Rod destructor called!"<<std::endl;
}

//Methods
void Rod::Sharpen()
{
    if (getEfficiency() < 5) {//change according to efficiency
            setEfficiency(getDurability() + 1);
            std::cout<<GREEN<<"-> "<<getName()<<" sharpened succesfully!"<<std::endl;
        } else {
            std::cout<<RED<<"-> "<<getName()<<" can't be sharpened anymore!"<<std::endl;
        }
}

void Rod::Hit()
{
    setHits(getHits() + 1);
    if (getHits() > getDurability()) {
        setEfficiency(getEfficiency() - 1);
        std::cout<<RED<<"-> Efficiency redurced to "<<getEfficiency()<<std::endl;
        setHits(0);
    }
}

#endif