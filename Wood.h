#ifndef WOOD_H
#define WOOD_H

#include"Resource.h"

class Wood : public Resource
{
private:
    /* data */
public:
    Wood();
    Wood(std::string name, int durability);
    ~Wood();
    //Methods
    void makeAbstarct() override;
};

Wood::Wood() : Resource("Wood", 100)
{
    std::cout<<"-> Wood default constructor called!"<<std::endl;
}

Wood::Wood(std::string name, int durability) : Resource(name, durability)
{
    std::cout<<"-> Wood custom constructor called!"<<std::endl;
}

Wood::~Wood()
{
    std::cout<<"-> Wood destructor called!"<<std::endl;
}

//Methods
void Wood::makeAbstarct()
{
}

#endif