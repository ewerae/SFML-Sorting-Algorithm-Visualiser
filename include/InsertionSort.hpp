#pragma once

#include "SortAlgorithm.hpp"

#include "DataGeneration.hpp"

class InsertionSort: public SortAlgorithm {

    private:
        DataGeneration& dataGen;
        
        int index = 1;
        bool isSorted;

    public:
        InsertionSort(DataGeneration& dataGen);
        ~InsertionSort();

        void SortStep() override;
        void Reset() override {index = 1; isSorted =false;};
        bool IsSorted() const override {return isSorted;};
};