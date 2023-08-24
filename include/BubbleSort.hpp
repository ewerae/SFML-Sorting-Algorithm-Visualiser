#pragma once

#include "SortAlgorithm.hpp"

#include "DataGeneration.hpp"

class BubbleSort : public SortAlgorithm {

    private: 
        DataGeneration& dataGen;

        bool swap;
        bool isSorted;

    public:
        BubbleSort(DataGeneration& dataGen);
        ~BubbleSort();

        void SortStep() override;  
        void Reset() override {isSorted =false;}    
        bool IsSorted() const override{return isSorted;}  

        
};