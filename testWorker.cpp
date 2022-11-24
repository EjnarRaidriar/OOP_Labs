#include"Forester.h"
#include"Wood.h"

int main()
{
    Forester* forester = new Forester("Forester", 30, 0);
    forester->printData();
    forester->printTools();
    Axe axe("Axe", 100, 10);
    forester->addTool(axe);
    forester->printTools();
    Resource* resource = new Wood();
    forester->collectResource(resource);
    forester->printTools();
    return 0;
}