#include "Visualiser.hpp"

Visualiser::Visualiser(DataGeneration& dataGen, AssetManager& assetManager) : assetManager(assetManager), dataGen(dataGen), bubSort(dataGen), isDragging(false),
    bubbleSort(false), mergeSort(false), insertionSort(false), selectionSort(false), quickSort(false), heapSort(false), isRun(false), resetPressed(false){

    assetManager.LoadFont("font1", "assets/fonts/playfair/PlayfairDisplay-VariableFont_wght.ttf");

    DATA_BACKGROUND = sf::RectangleShape(sf::Vector2f(1150.f, 770.f));
    DATA_BACKGROUND_COLOUR = sf::Color(252, 204, 255);
    DATA_BACKGROUND.setFillColor(DATA_BACKGROUND_COLOUR);
    DATA_BACKGROUND.setPosition(400.f, 20.f);

    BUTTON_COLOUR = sf::Color(157, 163, 245);
    SLIDER_COLOUR = sf::Color(225, 227, 245);
    SLIDER_POINTER_COLOUR = sf::Color(42, 46, 82);

    SLIDER = sf::RectangleShape(sf::Vector2f(690.f, 10.f));
    SLIDER.setFillColor(SLIDER_COLOUR);
    SLIDER.setPosition(760.f, 70.f);

    

    SLIDER_POINTER = sf::RectangleShape(sf::Vector2f(10.f, 50.f));
    SLIDER_POINTER.setFillColor(SLIDER_POINTER_COLOUR);
    SLIDER_POINTER.setPosition(760.f, 50.f);

    RUN_BUTTON = sf::RectangleShape(sf::Vector2f(100.f, 50.f));
    RUN_BUTTON.setFillColor(BUTTON_COLOUR);
    RUN_BUTTON.setPosition(450.f, 50.f);

    RESET_BUTTON = sf::RectangleShape(sf::Vector2f(100.f,50.f));
    RESET_BUTTON.setFillColor(BUTTON_COLOUR);
    RESET_BUTTON.setPosition(590.f, 50.f);
    

    BAR_COLOUR = sf::Color(102, 148, 189);

    RUN_TEXT.setFont(assetManager.GetFont("font1"));
    RUN_TEXT.setString("Run");
    RUN_TEXT.setCharacterSize(16);   
    RUN_TEXT.setFillColor(sf::Color::Black);
    RUN_TEXT.setPosition(467.0f, 65.0f);

    RESET_TEXT.setFont(assetManager.GetFont("font1"));
    RESET_TEXT.setString("Reset");
    RESET_TEXT.setCharacterSize(16);   
    RESET_TEXT.setFillColor(sf::Color::Black);
    RESET_TEXT.setPosition(605.0f, 65.0f);

    SELECT = sf::RectangleShape(sf::Vector2f(15.f, 15.f));
    SELECT.setFillColor(sf::Color(149, 173, 149));
    


    for(int i = 0; i < 6; ++i){
        algorithmButtons.push_back(sf::RectangleShape(sf::Vector2f(30.f, 30.f)));
        algorithmButtons[i].setFillColor(sf::Color(195, 227, 195));
        algorithmButtons[i].setPosition(310.f, 200.f + 90.f *i);

    }
    for(int i = 0; i < 6; ++i){
        sf::Text text;
        text.setFont(assetManager.GetFont("font1"));
        text.setCharacterSize(24);
        text.setPosition(90.f, 200.f + 90.f *i);
        
        if(i == 0){
            text.setString("Bubble Sort");
        } else if(i == 1){
            text.setString("Insertion Sort");
        } else if(i == 2){
            text.setString("Selection Sort");
        } else if(i == 3){
            text.setString("Merge Sort");
        } else if(i == 4){
            text.setString("Quick Sort");
        } else if(i == 5){
            text.setString("Heap Sort");
        }
        
        algorithmTexts.push_back(text);

    }

    
}

Visualiser::~Visualiser() {

}



void Visualiser::RunPressed(sf::RenderWindow& window, sf::Event& event){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (RUN_BUTTON.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            isRun = true;
        }
    }
}

void Visualiser::ResetPressed(sf::RenderWindow& window, sf::Event& event){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (RESET_BUTTON.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            if(!dataGen.GetBars().empty()){
                dataGen.GetBars().clear();
                dataGen.GenerateBars();
            }
            
            bubbleSort=false;
            insertionSort = false;
            selectionSort = false;
            mergeSort = false;
            quickSort = false;
            heapSort = false;
            
            isRun = false;

            resetPressed = true;
            
        }
    }
}

void Visualiser::MoveSlider(sf::RenderWindow& window, sf::Event& event){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (SLIDER_POINTER.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            isDragging =true;
        }
    } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        isDragging = false;
    }
    if (isDragging) {
            
        float min = 760.f; 
        float max = 1450.f; 

        float pos = std::max(min, std::min(max, static_cast<float>(mousePosition.x)));
        SLIDER_POINTER.setPosition(pos - 5.f, 50.f);
        dataGen.GetBars().clear();
        dataGen.SetTotal(SLIDER_POINTER.getPosition().x - min + 20.f);
        dataGen.GenerateBars();
        bubbleSort=false;
        insertionSort = false;
        selectionSort = false;
        mergeSort = false;
        quickSort = false;
        heapSort = false;
        
        isRun = false;

        resetPressed = true;
        
    }
}

void Visualiser::SelectAlgorithm(sf::RenderWindow& window, sf::Event& event){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

        for(std::vector<sf::RectangleShape>::size_type i = 0; i < algorithmButtons.size(); i++){
            if (algorithmButtons[i].getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                if(i == 0){
                    bubbleSort =true;
                    SELECT.setPosition(317.f, 208.f + i * 90.f);

                    insertionSort = false;
                    selectionSort = false;
                    mergeSort = false;
                    quickSort = false;
                    heapSort = false;
                } else if(i == 1){
                    insertionSort = true;
                    SELECT.setPosition(317.f, 208.f + i * 90.f);

                    bubbleSort = false;
                    selectionSort = false;
                    mergeSort = false;
                    quickSort = false;
                    heapSort = false;
                } else if(i == 2){
                    selectionSort = true;
                    SELECT.setPosition(317.f, 208.f + i * 90.f);

                    bubbleSort = false;
                    insertionSort = false;
                    mergeSort = false;
                    quickSort = false;
                    heapSort = false;
                } else if(i == 3){
                    mergeSort = true;
                    SELECT.setPosition(317.f, 208.f + i * 90.f);

                    bubbleSort = false;
                    insertionSort = false;
                    selectionSort = false;
                    quickSort = false;
                    heapSort = false;
                } else if(i == 4){
                    quickSort = true;
                    SELECT.setPosition(317.f, 208.f + i * 90.f);

                    bubbleSort = false;
                    insertionSort = false;
                    selectionSort = false;
                    mergeSort = false;
                    heapSort = false;
                } else if(i == 5){
                    heapSort = true;
                    SELECT.setPosition(317.f, 208.f + i * 90.f);

                    bubbleSort = false;
                    insertionSort = false;
                    selectionSort = false;
                    mergeSort = false;
                    quickSort = false;
                }
                
            }
        }
        
    }

    
}


void Visualiser::DrawBars(sf::RenderWindow& window){
    for (const auto& bar : dataGen.GetBars()) {
            window.draw(bar->SHAPE);
    }
}

void Visualiser::Draw(sf::RenderWindow& window){
    window.draw(DATA_BACKGROUND);
    window.draw(SLIDER);
    window.draw(SLIDER_POINTER);
    window.draw(RUN_BUTTON);
    window.draw(RESET_BUTTON);

    for (const auto& button : algorithmButtons) {
            window.draw(button);
    }
    for (const auto& text : algorithmTexts) {
            window.draw(text);
    }

    if(mergeSort || quickSort || heapSort || bubbleSort || selectionSort || insertionSort){
        window.draw(SELECT);
    }
    
    
    window.draw(RUN_TEXT);
    window.draw(RESET_TEXT);

    DrawBars(window);
}

