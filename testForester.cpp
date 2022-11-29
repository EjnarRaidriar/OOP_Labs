#include"Forester.h"
#include<memory>
#include<unistd.h>

int main()
{
    Forester* forester = new Forester("Forester", 30, 10);
    //forester->printData();
    //forester->printTools();
    Axe* axe = new Axe("Axe", 100, 10);
    forester->addTool(*axe);
    //forester->printTools();
    //Resource* resource = new Wood();
    //forester->collectResource(resource);
    //forester->printTools();
    std::vector<Resource*> resources;
    for (int i = 0; i < 2; i++)
    {
        resources.push_back(new Wood());
    }
    
    // std::vector<std::unique_ptr<Resource>> resources;
    // for (int i = 0; i<2; i++)
    // {
    //     resources.push_back(std::make_unique<Wood>());
    // }

    while (true)
    {
        //for (const auto& resource : resources)
        for (int i = 0; i < 2; i++)
        {
            //if (resource.get())
            if (resources[i])
            {
                if (forester->getToolAmount() == 0)
                { 
                    forester->addNewTool();
                    forester->printTools();
                    usleep(500000);
                }
                while (true)
                {
                    //if (resource.get())
                    if (resources[i])
                    {
                        //if (forester->collectResource(resource.get()))
                        if (forester->collectResource(resources[i]))
                        {
                            //resources.pop_back();
                            resources.pop_back();
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
            else std::cout<<"-> No resources left!"<<std::endl;
        }
        forester->printData();
        forester->printResources();
        sleep(1);
        break;
    }
    return 0;
}