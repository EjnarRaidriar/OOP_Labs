#ifndef WORKER_H
#define WORKER_H

#include"Resource.h"
#include<iostream>
#include<vector>

class Worker
{
private:
    std::string name;
    int age;
    unsigned int cargo;
    std::string location;
protected:
    std::vector<Resource*> resources;
public:
    Worker();
    Worker(std::string name, int age, int cargo);
    virtual ~Worker();
    
    //Getters and Setters
    std::string getName();
    void setName(std::string name);
    int getAge();
    void setAge(int age);
    int getCargo();
    void setCargo(int cargo);
    std::string getLocation();
    void setLocation(std::string location);
    Resource* getResource();
    int getResourceAmount();
    void removeResource();

    //Methods
    virtual bool collectResource(Resource* resource) = 0;
    //Output Methods
    virtual void printResources() = 0;
};
//Change all cargo accurances
Worker::Worker()
{
    name = "Nameless worker";
    age = 14;
    cargo = 10;
    std::cout<<"-> Worker default constructor called!"<<std::endl;
}

Worker::Worker(std::string name, int age, int cargo)
{
    this->name = name;
    this->age = age;
    this->cargo = cargo;
    std::cout<<"-> Worker custom constructor called!"<<std::endl;
}

Worker::~Worker()
{
    std::cout<<"-> Worker destructor called!"<<std::endl;
}

std::string Worker::getName()
{
    return name;
}

void Worker::setName(std::string name)
{
    this->name = name;
}

int Worker::getAge()
{
    return age;
}

void Worker::setAge(int age)
{
    this->age = age;
}

int Worker::getCargo()
{
    return cargo;
}

void Worker::setCargo(int cargo)
{
    this->cargo = cargo;
}

std::string Worker::getLocation()
{
    return location;
}

void Worker::setLocation(std::string location)
{
    this->location = location;
}

Resource* Worker::getResource()
{
    if (resources.size() > 0)
    {
        return resources.back();
    }
    else
    {
        return NULL;
    }
}

int Worker::getResourceAmount()
{
    return resources.size();
}

void Worker::removeResource()
{
    resources.pop_back();
}

#endif