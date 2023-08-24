#pragma once

#include "SortAlgorithm.hpp"

#include "DataGeneration.hpp"

class MergeSort : public SortAlgorithm{
    private:
        DataGeneration& dataGen;

        bool isSorted;

        


    public:
        MergeSort(DataGeneration& dataGen);
        ~MergeSort();

        void SortStep() override;
        void Reset() override {isSorted =false;};
        bool IsSorted() const override {return isSorted;};
};