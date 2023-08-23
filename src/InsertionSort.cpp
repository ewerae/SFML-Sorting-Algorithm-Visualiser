#include "InsertionSort.hpp"

InsertionSort::InsertionSort(DataGeneration& dataGen) : dataGen(dataGen), isSorted(false) {

}

InsertionSort::~InsertionSort() {

}


// void InsertionSort::SortStep(){
//     float BAR_WIDTH = 1050/dataGen.GetTotal(); 
//     float BAR_START_WIDTH = 450.f;
//     float BAR_START_HEIGHT = 770.f;

//     if(!isSorted){
        

//         while(j>= 0 && dataGen.GetBars()[temp]->HEIGHT < dataGen.GetBars()[j]->HEIGHT ){
       
            
//         }

        
//     }
        

//     if(index == static_cast<int>(dataGen.GetBars().size()) - 1){
//         isSorted = true;
//     }
// }