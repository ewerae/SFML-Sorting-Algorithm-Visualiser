#pragma once

#include <algorithm> 
#include <iterator>

#include "SortAlgorithm.hpp"

#include "DataGeneration.hpp"

class SelectionSort : public SortAlgorithm {

    private:
        DataGeneration& dataGen;

        bool isSorted;
        int startIndex = 0;
        int index1 = 0;
        static bool CompareHeight(const std::unique_ptr<Bar>& height1, const std::unique_ptr<Bar>& height2);

    public:
        SelectionSort(DataGeneration& dataGen);
        ~SelectionSort();

        

        void SortStep() override;
        void Reset() override {startIndex = 0; isSorted =false;};
        bool IsSorted() const override {return isSorted;};

        
        int GetPosStart(){return dataGen.GetBars()[startIndex]->position;}
        int GetPosIndex(){return dataGen.GetBars()[index1]->position;}
};