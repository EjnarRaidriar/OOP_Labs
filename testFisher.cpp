#include"Fisher.h"
#include<memory>
#include<unistd.h>

int main()
{
    Fisher* fisher = new Fisher("fisher", 30, 10);
    //fisher->printData();
    //fisher->printTools();
    Rod* rod = new Rod("Rod", 100, 10);
    fisher->addTool(*rod);
    //fisher->printTools();
    //Resource* resource = new Wood();
    //fisher->collectResource(resource);
    //fisher->printTools();
    std::vector<Resource*> resources;
    for (int i = 0; i < 2; i++)
    {
        resources.push_back(new Fish());
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
                if (fisher->getToolAmount() == 0)
                { 
                    fisher->addNewTool();
                    fisher->printTools();
                    usleep(500000);
                }
                while (true)
                {
                    //if (resource.get())
                    if (resources[i])
                    {
                        //if (fisher->collectResource(resource.get()))
                        if (fisher->collectResource(resources[i]))
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
        fisher->printData();
        fisher->printResources();
        sleep(1);
        break;
    }
    return 0;
}