#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <random>  
#include <ctime> 
#include <memory>

struct Bar{
    sf::RectangleShape SHAPE;
    sf::Color COLOUR;
    int HEIGHT;
    int position;

};


class DataGeneration {
    private:
        int total;

        std::vector<std::unique_ptr<Bar>> bars;
        

    public:
        DataGeneration();
        ~DataGeneration();  

        void GenerateBars();
        void SetTotal(int num){total = num;}
        int GetTotal(){return total;}
        std::vector<std::unique_ptr<Bar>>& GetBars(){return bars;}


};