#include"Miner.h"
#include<memory>
#include<unistd.h>

int main()
{
    Miner* miner = new Miner("miner", 30, 20);
    //miner->printData();
    //miner->printTools();
    Pickaxe* pickaxe = new Pickaxe("pickaxe", 100, 10);
    miner->addTool(*pickaxe);
    //miner->printTools();
    //Resource* resource = new Wood();
    //miner->collectResource(resource);
    //miner->printTools();
    std::vector<Resource*> resources;
    for (int i = 0; i < 20; i++)
    {
        resources.push_back(new Mineral());
    }
    
    // std::vector<std::unique_ptr<Resource>> resources;
    // for (int i = 0; i<2; i++)
    // {
    //     resources.push_back(std::make_unique<Wood>());
    // }

    while (true)
    {
        //for (const auto& resource : resources)
        for (int i = 0; i < 20; i++)
        {
            //if (resource.get())
            if (resources[i])
            {
                if (miner->getToolAmount() == 0)
                { 
                    miner->addNewTool();
                    miner->printTools();
                    usleep(500000);
                }
                while (true)
                {
                    //if (resource.get())
                    if (resources[i])
                    {
                        //if (miner->collectResource(resource.get()))
                        if (miner->collectResource(resources[i]))
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
            else std::cout<<RED<<"-> No resources left!"<<std::endl;
        }
        miner->printData();
        miner->printResources();
        sleep(1);
        break;
    }
    return 0;
}