#include "BubbleSort.hpp"

BubbleSort::BubbleSort(DataGeneration& dataGen) : dataGen(dataGen), isSorted(false){

}

BubbleSort::~BubbleSort() {

}

void BubbleSort::SortStep() {

    float BAR_WIDTH = 1050/dataGen.GetTotal(); 
    float BAR_START_WIDTH = 450.f;
    float BAR_START_HEIGHT = 770.f;
    swap = false;
    // dataGen.GetBars()[i+1]->COLOUR = sf::Color(168, 230, 168); green
    // dataGen.GetBars()[i]->COLOUR = sf::Color(245, 164, 188);   red

    for(std::vector<std::unique_ptr<Bar>>::size_type  i = 0; i < dataGen.GetBars().size() - 1; i++){
        if(dataGen.GetBars()[i]->HEIGHT > dataGen.GetBars()[i + 1]->HEIGHT){

            dataGen.GetBars()[i]->COLOUR = sf::Color(168, 230, 168);
            dataGen.GetBars()[i+1]->COLOUR = sf::Color(245, 164, 188);

            dataGen.GetBars()[i]->SHAPE.setFillColor(dataGen.GetBars()[i]->COLOUR);
            dataGen.GetBars()[i+1]->SHAPE.setFillColor(dataGen.GetBars()[i+1]->COLOUR);

            dataGen.GetBars()[i]->position = i +1;
            dataGen.GetBars()[i+1]->position = i;
            
            std::swap(dataGen.GetBars()[i], dataGen.GetBars()[i+1]);
            float diff1 = BAR_START_HEIGHT - dataGen.GetBars()[i]->HEIGHT;
            float diff2 = BAR_START_HEIGHT - dataGen.GetBars()[i+1]->HEIGHT;
            
            dataGen.GetBars()[i]->SHAPE.setPosition(BAR_START_WIDTH + dataGen.GetBars()[i]->position * BAR_WIDTH, diff1);
            dataGen.GetBars()[i+1]->SHAPE.setPosition(BAR_START_WIDTH + (dataGen.GetBars()[i+1]->position) * BAR_WIDTH, diff2);

            
            
            swap = true;
    
        } else {
            dataGen.GetBars()[i]->COLOUR = sf::Color(168, 230, 168);
            
            
        }
    }
        
    if(!swap){
        isSorted = true;
    }

    
}


