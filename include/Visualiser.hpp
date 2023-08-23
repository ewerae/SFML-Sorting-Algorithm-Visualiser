#pragma once
#include <SFML/Graphics.hpp>

#include "AssetManager.hpp"
#include "DataGeneration.hpp"
#include "BubbleSort.hpp"





class Visualiser {
    private:

        AssetManager& assetManager;
        DataGeneration& dataGen;

        BubbleSort bubSort;

        sf::RectangleShape RUN_BUTTON;
        sf::RectangleShape RESET_BUTTON;

        sf::Color BUTTON_COLOUR;

        sf::RectangleShape DATA_BACKGROUND;
        sf::Color DATA_BACKGROUND_COLOUR;

        sf::Color BAR_COLOUR;

        sf::Text RUN_TEXT;
        sf::Text RESET_TEXT;

        sf::RectangleShape SLIDER;
        sf::Color SLIDER_COLOUR;

        sf::RectangleShape SLIDER_POINTER;
        sf::Color SLIDER_POINTER_COLOUR;

        
        bool isDragging;
        std::vector<sf::Text> algorithmTexts;
        std::vector<sf::RectangleShape> algorithmButtons;

        sf::RectangleShape SELECT;

        bool bubbleSort;
        bool mergeSort;
        bool insertionSort;
        bool selectionSort;
        bool quickSort;
        bool heapSort;

        bool isRun;
        bool resetPressed;

        


    public:
        Visualiser(DataGeneration& dataGen, AssetManager& assetManager);
        ~Visualiser();

        void SelectAlgorithm(sf::RenderWindow& window, sf::Event& event);
        
        void MoveSlider(sf::RenderWindow& window, sf::Event& event);
        void RunPressed(sf::RenderWindow& window, sf::Event& event);
        void ResetPressed(sf::RenderWindow& window, sf::Event& event);

        void DrawBars(sf::RenderWindow& window);
        void Draw(sf::RenderWindow& window);

        bool GetBubbleSort(){return bubbleSort;}
        bool GetMergeSort(){return mergeSort;}
        bool GetInsertionSort(){return insertionSort;}
        bool GetSelectionSort(){return selectionSort;}
        bool GetQuickSort(){return quickSort;}
        bool GetHeapSort(){return heapSort;}

        bool GetRun(){return isRun;}
        bool reset(){return resetPressed;}
        void setreset(){resetPressed =false;}
};