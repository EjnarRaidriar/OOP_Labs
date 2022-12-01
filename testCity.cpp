#include"City.h"
#include"Forester.h"
#include"Miner.h"
#include"Fisher.h"

int main()
{
    City *city = new City("City", 10);
    city->printWarehouse();
    Forester* forester = new Forester("Forester", 30, 10);
    Miner* miner = new Miner("Miner", 30, 10);
    Fisher* fisher = new Fisher("Fisher", 30, 10);
    std::vector<Resource*> minerals;
    std::vector<Resource*> wood;
    std::vector<Resource*> fish;
    for (int i = 0; i < 3; i++)
    {
        minerals.push_back(new Mineral());
        wood.push_back(new Wood());
        fish.push_back(new Fish());
    }
    while (true)
    {
        if (city->getMaxWorkers() > 0)
        {
            if (forester->getResourceAmount() > 0)
            {
                city->warehouse.push_back(forester->getResource());
                forester->removeResource();
            }
            if (miner->getResourceAmount() > 0)
            {
                city->warehouse.push_back(miner->getResource());
                miner->removeResource();
            }
            if (fisher->getResourceAmount() > 0)
            {
                city->warehouse.push_back(fisher->getResource());
                fisher->removeResource();
            }
            if (forester->getToolAmount() == 0)
            {
                forester->addNewTool();
                forester->printTools();
            }
            if (miner->getToolAmount() == 0)
            {
                miner->addNewTool();
                miner->printTools();
            }
            if (fisher->getToolAmount() == 0)
            {
                fisher->addNewTool();
                fisher->printTools();
            }
            while (true)
            {
                if ((wood.size() <= 0) && (minerals.size() <= 0) && (fish.size() <= 0))
                {
                    break;
                }
                if (wood.size() > 0)
                {
                    if (forester->collectResource(wood.back()))
                    {
                        wood.pop_back();
                        break;
                    }
                }
                if (minerals.size() > 0)
                {
                    if (miner->collectResource(minerals.back()))
                    {
                        minerals.pop_back();
                        break;
                    }
                }
                if (fish.size() > 0)
                {
                    if (fisher->collectResource(fish.back()))
                    {
                        fish.pop_back();
                        break;
                    }
                }
            }
        }
        else
        {
            break;
        }
        if ((wood.size() <= 0) && 
            (minerals.size() <= 0) && 
            (fish.size() <= 0) &&
            (forester->getResourceAmount() <= 0) &&
            (miner->getResourceAmount() <= 0) &&
            (fisher->getResourceAmount() <= 0))
        {
            city->printWarehouse();
            break;
        }
    }
}