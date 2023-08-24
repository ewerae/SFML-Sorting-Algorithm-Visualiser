#include "SelectionSort.hpp"

SelectionSort::SelectionSort(DataGeneration& dataGen) : dataGen(dataGen), isSorted(false) {

}

SelectionSort::~SelectionSort() {

}

bool SelectionSort::CompareHeight(const std::unique_ptr<Bar>& height1, const std::unique_ptr<Bar>& height2) {
    return height1->HEIGHT < height2->HEIGHT;
}

void SelectionSort::SortStep() {
    float BAR_WIDTH = 1050/dataGen.GetTotal(); 
    float BAR_START_WIDTH = 450.f;
    float BAR_START_HEIGHT = 770.f;

    auto minElement = std::min_element(dataGen.GetBars().begin() + startIndex, dataGen.GetBars().end(), CompareHeight);
    // i automatically find the min element and this is not shown through the visualisation.
    // online sorting visualisers show each element being compared to the other to find the minimum, however i do not showcase it this by using the code above

    size_t index = std::distance(dataGen.GetBars().begin(), minElement);
    index1 = index;

    if((*minElement)->HEIGHT != dataGen.GetBars()[startIndex]->HEIGHT){
        dataGen.GetBars()[index]->COLOUR = sf::Color(168, 230, 168); //green
        dataGen.GetBars()[startIndex]->COLOUR = sf::Color(245, 164, 188); //red

        dataGen.GetBars()[startIndex]->SHAPE.setFillColor(dataGen.GetBars()[startIndex]->COLOUR);
        dataGen.GetBars()[index]->SHAPE.setFillColor(dataGen.GetBars()[index]->COLOUR);

        std::swap(dataGen.GetBars()[startIndex], dataGen.GetBars()[index]);
        

        dataGen.GetBars()[startIndex]->position = startIndex;
        dataGen.GetBars()[index]->position = index;

        float diff1 = BAR_START_HEIGHT - dataGen.GetBars()[startIndex]->HEIGHT;

        float diff2 = BAR_START_HEIGHT - dataGen.GetBars()[index]->HEIGHT;
        
        dataGen.GetBars()[startIndex]->SHAPE.setPosition(BAR_START_WIDTH + dataGen.GetBars()[startIndex]->position * BAR_WIDTH, diff1);

        dataGen.GetBars()[index]->SHAPE.setPosition(BAR_START_WIDTH + (dataGen.GetBars()[index]->position) * BAR_WIDTH, diff2);
        

    }

    startIndex++;
    
    if(startIndex == static_cast<int>(dataGen.GetBars().size()) ){
        isSorted = true;
    }
    // if(startIndex == 1){
    //     isSorted = true;
    // }


}


