#include "InsertionSort.hpp"

InsertionSort::InsertionSort(DataGeneration& dataGen) : dataGen(dataGen), isSorted(false) {

}

InsertionSort::~InsertionSort() {

}


void InsertionSort::SortStep(){
    float BAR_WIDTH = 1050/dataGen.GetTotal(); 
    float BAR_START_WIDTH = 450.f;
    float BAR_START_HEIGHT = 770.f;
    int currentHeight = dataGen.GetBars()[index]->HEIGHT;

    int j = index - 1;

    if(!isSorted){
        

        while(j>= 0 && currentHeight < dataGen.GetBars()[j]->HEIGHT ){
            dataGen.GetBars()[j]->COLOUR = sf::Color(168, 230, 168); //green
            dataGen.GetBars()[j+1]->COLOUR = sf::Color(245, 164, 188); //red

            dataGen.GetBars()[j+1]->SHAPE.setFillColor(dataGen.GetBars()[j+1]->COLOUR);
            dataGen.GetBars()[j]->SHAPE.setFillColor(dataGen.GetBars()[j]->COLOUR);
       
            std::swap(dataGen.GetBars()[j+1], dataGen.GetBars()[j]);

            dataGen.GetBars()[j]->position = j +1;
            dataGen.GetBars()[j+1]->position = j;

            float diff1 = BAR_START_HEIGHT - dataGen.GetBars()[j]->HEIGHT;
            float diff2 = BAR_START_HEIGHT - dataGen.GetBars()[j+1]->HEIGHT;
            
            dataGen.GetBars()[j]->SHAPE.setPosition(BAR_START_WIDTH + dataGen.GetBars()[j]->position * BAR_WIDTH, diff1);
            dataGen.GetBars()[j+1]->SHAPE.setPosition(BAR_START_WIDTH + (dataGen.GetBars()[j+1]->position) * BAR_WIDTH, diff2);

            j--;

        }

        
    }
        
    
    if(index == static_cast<int>(dataGen.GetBars().size()) - 1){
        isSorted = true;
    }

    index++;
    
}