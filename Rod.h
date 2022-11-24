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
    std::cout<<"-> Rod default constructor called!"<<std::endl;
}

Rod::Rod(std::string name, int durability, int efficiency) 
    : Tool(name, durability, efficiency)
{
    std::cout<<"-> Rod custom constructor called!"<<std::endl;
}

Rod::~Rod()
{
    std::cout<<"-> Rod destructor called!"<<std::endl;
}

//Methods
void Rod::Sharpen()
{
    if (getEfficiency() < 5) {//change according to efficiency
            setEfficiency(getDurability() + 1);
            std::cout<<"-> "<<getName()<<" sharpened succesfully!"<<std::endl;
        } else {
            std::cout<<"-> "<<getName()<<" can't be sharpened anymore!"<<std::endl;
        }
}

void Rod::Hit()
{
    setHits(getHits() + 1);
    if (getHits() > getDurability()) {
        setEfficiency(getEfficiency() - 1);
        std::cout<<"-> Efficiency redurced to "<<getEfficiency()<<std::endl;
        setHits(0);
    }
}

#endif