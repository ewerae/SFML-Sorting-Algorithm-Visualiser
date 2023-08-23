#include "Game.hpp"


Game::Game() : window(sf::VideoMode(1600, 800), "SFML Game", sf::Style::Titlebar | sf::Style::Close), 
            dataGen(), visualiser(dataGen, assetManager),bubbleSort(dataGen), insertionSort(dataGen), 
            isRunning(true), isDragging(false), timePerFrame(sf::seconds(1.0f / 10.0f)){
    Init();
}

Game::~Game() {
    
}


void Game::Init() {
    
    assetManager.LoadFont("font1", "assets/fonts/playfair/PlayfairDisplay-VariableFont_wght.ttf");

    
    fpsText.setFont(assetManager.GetFont("font1"));
    fpsText.setCharacterSize(20);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(10.0f, 10.0f);

    mousePosText.setFont(assetManager.GetFont("font1"));
    mousePosText.setCharacterSize(20);
    mousePosText.setFillColor(sf::Color::White);
    mousePosText.setPosition(10.f, 35.f);

    backgroundColour =  sf::Color(204, 161, 207);

    FRAME_SLIDER_COLOUR = sf::Color(225, 227, 245);
    FRAME_SLIDER_POINTER_COLOUR = sf::Color(42, 46, 82);

    FRAME_SLIDER = sf::RectangleShape(sf::Vector2f(320.f, 10.f));
    FRAME_SLIDER.setFillColor(FRAME_SLIDER_COLOUR);
    FRAME_SLIDER.setPosition(30.f, 100.f);

    FRAME_SLIDER_POINTER = sf::RectangleShape(sf::Vector2f(10.f, 50.f));
    FRAME_SLIDER_POINTER.setFillColor(FRAME_SLIDER_POINTER_COLOUR);
    FRAME_SLIDER_POINTER.setPosition(30.f, 80.f);
    

    
    dataGen.GenerateBars();
    

}

void Game::MoveFrameSlider(sf::RenderWindow& window, sf::Event& event){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (FRAME_SLIDER_POINTER.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            isDragging =true;
        }
    } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        isDragging = false;
    }
    if (isDragging) {
            
        float min = 35.f; 
        float max = 350.f; 

        float pos = std::max(min, std::min(max, static_cast<float>(mousePosition.x)));
        FRAME_SLIDER_POINTER.setPosition(pos - 5.f, 80.f);
        timePerFrame = sf::seconds(1.0f / (FRAME_SLIDER_POINTER.getPosition().x));

        
    }
}


void Game::Run() {
    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;
    unsigned int frameCount = 0;
    

    while (isRunning) {
        sf::Time deltaTime = clock.restart();
        elapsedTime += deltaTime;
        
        ProcessEvents();
        

        while (elapsedTime >= timePerFrame) {
            float fps = static_cast<float>(frameCount) / elapsedTime.asSeconds();
            fpsText.setString("FPS: " + std::to_string(static_cast<int>(fps)));

            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            std::string mousePositionString = "(" + std::to_string(mousePosition.x) + ", " + std::to_string(mousePosition.y) + ")";
            mousePosText.setString(mousePositionString);
            frameCount = 0;
            frameCount++;

            elapsedTime -= timePerFrame;

            Update(timePerFrame);
            Render();
            
        }

        
    }
}

void Game::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed){
            isRunning = false;

        }
        MoveFrameSlider(window, event);
        visualiser.MoveSlider(window, event);
        visualiser.SelectAlgorithm(window, event);
        visualiser.RunPressed(window, event);
        visualiser.ResetPressed(window, event);

        if(visualiser.reset()){
            bubbleSort.Reset();
            insertionSort.Reset();
            visualiser.setreset();
        }
    }
    
}

void Game::Update(sf::Time deltaTime) {

    if(visualiser.GetRun() && visualiser.GetBubbleSort() && !bubbleSort.IsSorted()){
        bubbleSort.SortStep();
        
    }

    if(visualiser.GetRun() && visualiser.GetInsertionSort() && !insertionSort.IsSorted()){
        insertionSort.SortStep();
        
    }
    
}

void Game::Render() {
    window.clear(backgroundColour);
    window.draw(fpsText);
    window.draw(mousePosText);
    window.draw(FRAME_SLIDER);
    window.draw(FRAME_SLIDER_POINTER);

    // sf::Text text;
    // text.setFont(assetManager.GetFont("font1"));
    // text.setString("Hi");
    // text.setCharacterSize(20);
    // text.setFillColor(sf::Color::White);
    // text.setPosition(100.f, 40.f);
    
    // if(visualiser.GetRun() && visualiser.GetBubbleSort() && !bubbleSort.IsSorted()){
        
    //     window.draw(text);
    // }
    
    

    visualiser.Draw(window);

    
    window.display();
}