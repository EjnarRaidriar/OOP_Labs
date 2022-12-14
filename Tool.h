#ifndef TOOL_H
#define TOOL_H

#include<string>
#include<iostream>
#include"colors.h"

class Tool
{
private:
    std::string name;
    int durability;
    int efficiency;
    int hits;
public:
    //Construnctors and Destructors
    Tool();
    Tool(std::string name, int durability, int efficiency);
    virtual ~Tool();
    //Getters and Setters
    void setName(std::string name);
    void setDurability(int durability);
    void setEfficiency(int efficiency);
    void setHits(int hits);
    std::string getName();
    int getDurability();
    int getEfficiency();
    int getHits();
    //Methods
    virtual void Sharpen() = 0;
    virtual void Hit() = 0;
    //Output Methods
    virtual void printData();
};

//Construnctor and Destructors
Tool::Tool()
{
    name = "Tool";
    durability = -1;
    efficiency = -1;
    hits = -1;
    std::cout<<MAGENTA<<"-> Tool default constructor called!"<<std::endl;
}

Tool::Tool(std::string name, int durability, int efficiency)
{
    this->name = name;
    this->durability = durability;
    this->efficiency = efficiency;
    this->hits = 0;
    std::cout<<MAGENTA<<"-> Tool custom construnctor"<<std::endl;
}

Tool::~Tool()
{
    std::cout<<MAGENTA<<"-> Tool destructor called!"<<std::endl;
}

//Getters and Setters
void Tool::setName(std::string name)
{
    this->name = name;
}

void Tool::setDurability(int durability)
{
    this->durability = durability;
}

void Tool::setEfficiency(int efficiency)
{
    this->efficiency = efficiency;
}

void Tool::setHits(int hits)
{
    this->hits = hits;
}

std::string Tool::getName()
{
    return this->name;
}

int Tool::getDurability()
{
    return this->durability;
}

int Tool::getEfficiency()
{
    return this->efficiency;
}

int Tool::getHits()
{
    return this->hits;
}

//Output Methods
void Tool::printData()
{
    std::cout<<RESET<<"   Tool name: "<<name<<std::endl;
    std::cout<<"   Tool durability: "<<durability<<std::endl;
    std::cout<<"   Tool efficiency: "<<efficiency<<std::endl;
    std::cout<<"   Tool's hit number: "<<hits<<std::endl;
}

#endif