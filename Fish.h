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
    Fish(Resource &fish);
    ~Fish();
    //Methods
    void makeAbstarct() override;
};

Fish::Fish() : Resource("Fish", 100)
{
    std::cout<<MAGENTA<<"-> Fish default constructor called!"<<std::endl;
}

Fish::Fish(std::string name, int durability) : Resource(name, durability)
{
    std::cout<<MAGENTA<<"-> Fish custom constructor called!"<<std::endl;
}

Fish::Fish(Resource &fish) : Resource(fish.getName(), fish.getDurability()) {}

Fish::~Fish()
{
    std::cout<<MAGENTA<<"-> Fish destructor called!"<<std::endl;
}

//Methods
void Fish::makeAbstarct()
{
}

#endif