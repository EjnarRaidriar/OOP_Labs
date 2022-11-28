#ifndef RESOURCE_H
#define RESOURCE_H

#include<iostream>
#include<string>
class Resource
{
private:
    std::string name;
    int durability;
public:
    //Construncotrs and Destructors
    Resource();
    Resource(std::string name, int durability);
    virtual ~Resource();
    //Getters and Setters
    void setName(std::string name);
    void setDurability(int durability);
    std::string getName();
    int getDurability();
    virtual void makeAbstarct() = 0;
};

Resource::Resource(std::string name, int durability)
{
    this->name = name;
    this->durability = durability;
}

Resource::Resource() {}

Resource::~Resource()
{
    std::cout<<"-> Resource destructor called!"<<std::endl;
}
//Getters and Setters
void Resource::setName(std::string name)
{
    this->name = name;
}

void Resource::setDurability(int durability)
{
    this->durability = durability;
}

int Resource::getDurability()
{
    return this->durability;
}

std::string Resource::getName()
{
    return this->name;
}

#endif