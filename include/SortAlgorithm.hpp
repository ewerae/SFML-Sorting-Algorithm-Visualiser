#pragma once

class SortAlgorithm {
    public:
        virtual void SortStep() = 0;
        virtual void Reset() = 0;
        virtual bool IsSorted() const = 0;

        
        virtual ~SortAlgorithm() {} 
};