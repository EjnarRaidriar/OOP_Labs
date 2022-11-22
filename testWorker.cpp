#include"Forester.h"

int main()
{
    Forester forester("Forester", 30, 0);
    forester.printData();
    forester.printTools();
    Axe axe("Axe", 100, 10);
    forester.addTool(axe);
    forester.printTools();
    Resource resource("Wood", 100);
    forester.collectResource(&resource);
    forester.printTools();
    return 0;
}