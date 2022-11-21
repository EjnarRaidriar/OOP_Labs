#ifndef TOOL_H
#define TOOL_H

#include<string>

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
};


#endif