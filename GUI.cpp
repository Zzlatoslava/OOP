#include "GUI.h"

GUI::GUI(Tracking* mTracking) {
    if (mTracking == nullptr) {
        throw "Error in creating a GUI class object\n";
    }
    this->tracking = mTracking;
    cat_Before();
    cat_Back();
    cat_Left();
    cat_Right();
    cat = catBack;
    water();
    level();
    fish();

    
}



Commands GUI::startWin(){


    if (!texture.loadFromFile("Image/Start.png"))
    {
        throw "Image loading error\n";
    }
    background.setTexture(texture);



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
                    

                    if (750 < newX && newX < 1280 && 700 > newY && newY > 540) {
                        
                        std::cout << "the left button was pressed" << std::endl;
                        std::cout << "mouse x: " << newX << std::endl;
                        std::cout << "mouse y: " << newY << std::endl;
                        
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
        window.draw(background);
        window.display();
    }


}

Commands GUI::selectLevelWin(){
    

    if (!texture.loadFromFile("Image/ChoiceLevel(s).png"))
    {
        throw "Image loading error\n";
    }
    background.setTexture(texture);

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
        window.draw(background);
        window.display();
    }

}

Commands GUI::afterLevelWin(int num_level, int max_level){
    
   
    if (!texture.loadFromFile("Image/Win.png"))
    {
        throw "Image loading error\n";
    }
    background.setTexture(texture);



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

                    if (newX > 490 && newX < 910) {
                        if (newY > 375 && newY < 520) {//первая кнопка
                            if (num_level < max_level) {
                                return LEVEL_2;
                            }
                            else {
                                return END;
                            }
                        }
                        if (newY > 610 && newY < 760) {//вторая кнопка
                            
                            return START;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(background);
        window.display();
    }
}

Commands GUI::endWin(){
    

    if (!texture.loadFromFile("Image/End.png"))
    {
        throw "Image loading error\n";
    }
    background.setTexture(texture);

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
        window.draw(background);
        window.display();
    }

}

Commands GUI::gameOverWin(){
    if (!texture.loadFromFile("Image/Game Over.png"))
    {
        throw "Image loading error\n";
    }
    background.setTexture(texture);

    

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
        window.draw(background);
        window.display();
    }

}




void GUI::level()
{
    if (!textureL.loadFromFile("Image/flat.png"))
    {
        throw "Image loading error\n";
    }
    backgroundL.setTexture(textureL);
    


}

void GUI::cat_Before()
{

    if (!textureCBefore.loadFromFile("Image/cat_1.png"))
    {
        throw "Image loading error\n";
    }

    catBefore.setTexture(textureCBefore);
    catBefore.setOrigin(35.f, 35.f);


}

void GUI::cat_Back()
{
    if (!textureCBack.loadFromFile("Image/cat_2.png"))
    {
        throw "Image loading error\n";
    }

    catBack.setTexture(textureCBack);
    catBack.setOrigin(35.f, 35.f);
}

void GUI::cat_Left()
{
    if (!textureCLeft.loadFromFile("Image/cat_3.png"))
    {
        throw "Image loading error\n";
    }

    catLeft.setTexture(textureCLeft);
    catLeft.setOrigin(35.f, 35.f);

}

void GUI::cat_Right()
{
    if (!textureCRight.loadFromFile("Image/cat_4.png"))
    {
        throw "Image loading error\n";
    }

    catRight.setTexture(textureCRight);
    catRight.setOrigin(35.f, 35.f);
}

Commands GUI::levelGame(Move move) {


    //cat.setPosition(x, y);
    //Move GUIMove;
    
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return EXIT;
            }


        }

        window.draw(backgroundL);

        Event tmp;
        for (int y = 0; y < MAX_HEIGHT; y++) {
            for (int x = 0; x < MAX_WIDTH; x++) {
                tmp = tracking->getEvent(x, y);
                switch (tmp) {
                case Reduced:
                    waterS.setPosition(90.f + x * 40.f, 95.f + y * 40.f);
                    window.draw(waterS);
                    break;

                case Collect:
                    fishS.setPosition(90.f + x * 40.f, 95.f + y * 40.f);
                    window.draw(fishS);
                    break;

                default:
                    break;
                }
            }
        }
        moveCat(move);
        cat.setPosition(x, y);


        window.draw(cat);
        window.display();
       
}


void GUI::moveCat(Move move) {
    switch (move) {
    case move_up:
        y -= 40.f;
        cat = catBack;
        break;
    case move_down:

        y += 40.f;
        cat = catBefore;
        break;
    case move_left:
        x -= 40.f;
        cat = catLeft;

        break;
    case move_right:
        x += 40.f;
        cat = catRight;
        break;
    case Default:
        cat = catBack;
        break;
    

    }
}

void GUI::water()
{

    if (!textureWater.loadFromFile("Image/water.png"))
    {
        throw "Image loading error\n";
    }

    waterS.setTexture(textureWater);
    //waterS.setOrigin(20.f, 21.f);
}

void GUI::fish()
{
    if (!textureFish.loadFromFile("Image/fish.png"))
    {
        throw "Image loading error\n";
    }

    fishS.setTexture(textureFish);
}














