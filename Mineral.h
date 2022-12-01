#ifndef MINERAL_H
#define MINERAL_H

#include"Resource.h"

class Mineral : public Resource
{
private:
    /* data */
public:
    Mineral();
    Mineral(std::string name, int durability);
    Mineral(Resource &mineral);
    ~Mineral();
    //Methods
    void makeAbstarct() override;
};

Mineral::Mineral() : Resource("Mineral", 100)
{
    std::cout<<MAGENTA<<"-> Mineral default constructor called!"<<std::endl;
}

Mineral::Mineral(std::string name, int durability) : Resource(name, durability)
{
    std::cout<<MAGENTA<<"-> Mineral custom constructor called!"<<std::endl;
}

Mineral::Mineral(Resource &mineral) : Resource(mineral.getName(), mineral.getDurability()) {}

Mineral::~Mineral()
{
    std::cout<<MAGENTA<<"-> Mineral destructor called!"<<std::endl;
}

//Methods
void Mineral::makeAbstarct()
{
}

#endif