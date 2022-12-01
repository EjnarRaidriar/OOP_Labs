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
    Wood(Resource &wood);
    ~Wood();
    //Methods
    void makeAbstarct() override;
};

Wood::Wood() : Resource("Wood", 100) {}

Wood::Wood(std::string name, int durability) : Resource(name, durability) {}

Wood::Wood(Resource &wood) : Resource(wood.getName(), wood.getDurability()) {}

Wood::~Wood()
{
    std::cout<<MAGENTA<<"-> Wood destructor called!"<<std::endl;
}

//Methods
void Wood::makeAbstarct()
{
}

#endif