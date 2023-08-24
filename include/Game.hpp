#pragma once
#include "AssetManager.hpp"
#include "Visualiser.hpp"
#include "DataGeneration.hpp"

#include "BubbleSort.hpp"
#include "InsertionSort.hpp"
#include "SelectionSort.hpp"
#include "MergeSort.hpp"



class Game {
    private:

        sf::RenderWindow window;
        AssetManager assetManager;
        DataGeneration dataGen;
        Visualiser visualiser;

        BubbleSort bubbleSort;
        InsertionSort insertionSort;
        SelectionSort selectionSort;
        MergeSort mergeSort;




        void MoveFrameSlider(sf::RenderWindow& window, sf::Event& event);
        void Init();
        void ProcessEvents();
        void Update(sf::Time deltaTime);
        void Render();

        
        bool isRunning;
        bool isDragging;

        sf::Time timePerFrame;
        

        sf::Color backgroundColour;

        sf::Text fpsText;
        sf::Text mousePosText;

        sf::RectangleShape FRAME_SLIDER;
        sf::Color FRAME_SLIDER_COLOUR;

        sf::RectangleShape FRAME_SLIDER_POINTER;
        sf::Color FRAME_SLIDER_POINTER_COLOUR;

    public:
        Game();
        ~Game();

        void Run();

    
};