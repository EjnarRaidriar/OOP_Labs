#ifndef FISH_H
#define FISH_H

#include"Resource.h"

class Fish : public Resource
{
private:
    /* data */
public:
    Fish();
    Fish(std::string name, int durability);
    ~Fish();
    //Methods
    void makeAbstarct() override;
};

Fish::Fish() : Resource("Fish", 100)
{
    std::cout<<"-> Fish default constructor called!"<<std::endl;
}

Fish::Fish(std::string name, int durability) : Resource(name, durability)
{
    std::cout<<"-> Fish custom constructor called!"<<std::endl;
}

Fish::~Fish()
{
    std::cout<<"-> Fish destructor called!"<<std::endl;
}

//Methods
void Fish::makeAbstarct()
{
}

#endif