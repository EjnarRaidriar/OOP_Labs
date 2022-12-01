#include"Biom.h"
#include"Forester.h"
#include<unistd.h>

int main()
{
    Forester *forester = new Forester("forester", 30, 20);
    Biom *biom = new Biom("Forest");
    for (int i = 0; i < 5; i++)
    {
        biom->addResource(new Wood());
    }
    while (true)
    {
        if (biom->getResource())
        {
            if (forester->getToolAmount() == 0)
            {
                forester->addNewTool();
                forester->printTools();
                usleep(500000);
            }
            while (true)
            {
                if (biom->getResource())
                {
                    if (forester->collectResource(biom->getResource()))
                    {
                        biom->removeResource();
                        break;
                    }
                    usleep(500000);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
}