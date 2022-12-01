#ifndef BIOM_H
#define BIOM_H

#include<string>
#include<vector>
#include"Resource.h"

class Biom
{
private:
    std::string name;
    std::vector<Resource*> resources;
public:
    Biom();
    Biom(std::string name);
    virtual ~Biom();
    Resource* getResource();
    void addResource(Resource* resource);
    std::string getName();
    void setName(std::string name);
    void removeResource();
};

Biom::Biom()
{
    name = "Biom";
}

Biom::Biom(std::string name)
{
    this->name = name;
}

Biom::~Biom()
{
}

Resource* Biom::getResource()
{
    if (resources.size() > 0)
    {
        return resources.back();
    }
    else
    {
        return nullptr;
    }
}

void Biom::addResource(Resource* resource)
{
    resources.push_back(resource);
}

std::string Biom::getName()
{
    return name;
}

void Biom::setName(std::string name)
{
    this->name = name;
}

void Biom::removeResource()
{
    resources.pop_back();
}

#endif