#include "GUI.h"

GUI::GUI(Tracking* mTracking) {
    if (mTracking == nullptr) {
        throw "Error in creating a GUI class object\n";
    }
    this->tracking = mTracking;
    
    cat = graphics.getCatBefore();
    
    window.setPosition(sf::Vector2i(260, 0));
    sf::Image icon;
    if (!icon.loadFromFile("image/heart.png"))
    {
        throw "Error";
    }
    window.setIcon(40, 40, icon.getPixelsPtr());

    
}



Commands GUI::startWin(){

    graphics.setBackground("Image/Start.png");
    

    sf::Font font;
    if (!font.loadFromFile("Image/vcrosdmonorusbyd.ttf"))
    {
        throw "Font loading error\n";
    }

    sf::Text text;
    sf::Color color(166, 162, 184);
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(color);

    text.setString("Score:" + std::to_string(tracking->getTotalScore()));
    text.setPosition(40.f, 40.f);

   




    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return EXIT;
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int newX = event.mouseButton.x;
                    int newY = event.mouseButton.y;
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << newX << std::endl;
                    std::cout << "mouse y: " << newY << std::endl;

                    if (750 < newX && newX < 1280 && 700 > newY && newY > 540) {
                        
                        
                        
                        return SELECT_LEVEL;
                    }
                    if (1205 < newX && newX < 1355 && 915 < newY && newY < 965) {
                        
                        window.close();
                        return EXIT;
                    }


                }
            }
        }

        window.clear();
        window.draw(graphics.getBackground());
        window.draw(text);
        window.display();
    }


}

Commands GUI::selectLevelWin(){
    

    graphics.setBackground("Image/ChoiceLevel(s).png");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                return EXIT;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int newX = event.mouseButton.x;
                    int newY = event.mouseButton.y;
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << newX << std::endl;
                    std::cout << "mouse y: " << newY << std::endl;

                    if (newX > 490 && newX < 910) {
                        if (newY > 375 && newY < 520) {
                            std::cout << "1 level!\n";
                            
                            return LEVEL_1;
                        }
                        if (newY > 610 && newY < 760) {
                            std::cout << "2 level!\n";
                            
                            return LEVEL_2;
                        }
                    }

                    if (newX > 26 && newX < 175 && newY > 24 && newY < 75) {
                        
                        return START;
                    }


                }
            }
        }
        window.clear();
        window.draw(graphics.getBackground());
        window.display();
    }

}

Commands GUI::titlesGUI()
{
    if (tracking->getLevel() == 1) {
        graphics.setBackground("Image/AfterChoice.png");
    }
    else {
        graphics.setBackground("Image/After1Level.png");
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return EXIT;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    return LEVEL;
                }
            }
        }

        window.clear();
        window.draw(graphics.getBackground());
        window.display();
    }
}

Commands GUI::afterLevelWin(int num_level, int max_level){
    
   
    graphics.setBackground("Image/Win.png");
    


    sf::Font font;
    if (!font.loadFromFile("Image/vcrosdmonorusbyd.ttf"))
    {
        throw "Font loading error\n";
    }

    sf::Text text;
    sf::Text textT;
    sf::Color color(166, 162, 184);
    text.setFont(font);
    text.setCharacterSize(70); 
    text.setFillColor(color);

    textT.setFont(font);
    textT.setCharacterSize(70);
    textT.setFillColor(color);

    text.setString("Score:" + std::to_string(tracking->getScore()));
    text.setPosition(530.f, 315.f);

    textT.setString("Total score:" + std::to_string(tracking->getTotalScore() + tracking->getScore() +tracking->getDoubleScore()));
    textT.setPosition(360.f, 455.f);
    


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return EXIT;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int newX = event.mouseButton.x;
                    int newY = event.mouseButton.y;
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << newX << std::endl;
                    std::cout << "mouse y: " << newY << std::endl;

                    if (newY > 812 && newY < 972) {
                        if (newX > 965 && newX < 1345) {//первая кнопка
                            if (num_level < max_level) {
                                tracking->setLevel(2);
                                return LEVEL;
                            }
                            else {
                                return END;
                            }
                        }
                        if (newX > 78 && newX < 460) {//вторая кнопка
                            return START;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(graphics.getBackground());
        window.draw(text);

        
        window.draw(textT);
        window.display();
    }
}

Commands GUI::endWin(){
    

    graphics.setBackground("Image/End.png");
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return EXIT;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int newX = event.mouseButton.x;
                    int newY = event.mouseButton.y;
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << newX << std::endl;
                    std::cout << "mouse y: " << newY << std::endl;

                    if (newX > 490 && newX < 910 && newY > 610 && newY < 760) {
                        return START;
                    }
                }
            }
        }

        window.clear();
        window.draw(graphics.getBackground());
        window.display();
    }

}

Commands GUI::gameOverWin(){
    graphics.setBackground("Image/Game Over.png");
    
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return EXIT;
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    
                    return START;
                }
            }
        }

        window.clear();
        window.draw(graphics.getBackground());
        window.display();
    }

}





Commands GUI::levelGame(int newX, int newY, Coord xyM, Coord xyR, Move move ) {
    auto fish = graphics.getFish();
    auto heart = graphics.getHeart();
    auto water = graphics.getWater();
    auto teleport = graphics.getTeleport();
    auto fishRed = graphics.getFishRed();
    auto enemyM = graphics.getEnemyM();
    auto enemyR = graphics.getEnemyR();
    
    sf::Event event;
    
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            window.close();
            return EXIT;
        }
        }
    
    window.draw(graphics.getLevel());

        Event tmp;
        for (int y = 0; y < MAX_HEIGHT; y++) {
            for (int x = 0; x < MAX_WIDTH; x++) {
                tmp = tracking->getEvent(x, y);
                switch (tmp) {
                case Reduced:
                    water.setPosition(100.f + x * 40.f, 105.f + y * 40.f);
                    window.draw(water);
                    break;

                case Collect:
                    fish.setPosition(100.f + x * 40.f, 105.f + y * 40.f);
                    window.draw(fish);
                    break;

                case Adding:
                    heart.setPosition(100.f + x * 40.f, 105.f + y * 40.f);
                    window.draw(heart);
                    break;
                case Teleport:
                    teleport.setPosition(100.f + x * 40.f, 105.f + y * 40.f);
                    window.draw(teleport);
                    break;
                case Double:
                    fishRed.setPosition(100.f + x * 40.f, 105.f + y * 40.f);
                    window.draw(fishRed);
                    break;
                default:
                    break;
                }
            }
        }
        for (int i = tracking->getDoubleScore() / 2; i > 0; i--) {
            fishRed.setPosition(1290.f - i * 40.f, 30.f);
            window.draw(fishRed);
        }
        for (int i = 0; i < tracking->getHealth(); i++) {
            heart.setPosition(100.f + i * 40.f, 40.f );
            window.draw(heart);
        }
        for (int i = tracking->getScore(); i > 0 ; i--) {
            fish.setPosition(1300.f - i * 40.f, 40.f);
            window.draw(fish);
        }
        
        moveCat(move);
        cat.setPosition(120.f + newX * 40.f, 125.f + newY * 40.f);
        enemyM.setPosition(120.f + xyM.x * 40.f, 125.f + xyM.y * 40.f);
        enemyR.setPosition(120.f + xyR.x * 40.f, 125.f + xyR.y * 40.f);

        window.draw(cat);
        window.draw(enemyM);
        window.draw(enemyR);
        window.display();
        }

        

    



void GUI::moveCat(Move move) {
    switch (move) {
    case move_up:
        
        cat = graphics.getCatBack();
        break;
    case move_down:

        cat = graphics.getCatBefore();
        break;
    case move_left:
        
        cat = graphics.getCatLeft();

        break;
    case move_right:
        
        cat = graphics.getCatRight();
        break;
    case Default:
        cat = graphics.getCatBack();
        break;
    

    }
}

