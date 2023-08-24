#include "DataGeneration.hpp"

DataGeneration::DataGeneration() : total(20) {

}

DataGeneration::~DataGeneration() {

}

void DataGeneration::GenerateBars(){

    
    std::mt19937 rng(std::time(0));
    std::uniform_int_distribution<int> distribution(20, 650);
    
    float BAR_WIDTH = 1050/total; 
    float BAR_START_WIDTH = 450.f;
    float BAR_START_HEIGHT = 770.f;
    
    for (int i = 0; i < total; ++i) {
        std::unique_ptr<Bar> bar = std::make_unique<Bar>();

        bar->position = i;
        int height = distribution(rng);  
        bar->HEIGHT = height; 
        bar->SHAPE  = sf::RectangleShape(sf::Vector2f(BAR_WIDTH, static_cast<float>(height)));
        bar->COLOUR = sf::Color::Blue;
        float diff = BAR_START_HEIGHT - height;
        bar->SHAPE.setPosition(BAR_START_WIDTH + i * BAR_WIDTH, diff);
        bar->SHAPE.setFillColor(bar->COLOUR); 
        bars.push_back(std::move(bar));    
    }
    
};
