#include "GUI.h"

GUI::GUI() {
    
}



Commands GUI::startWin(){


    if (!texture.loadFromFile("Image/Start.png"))
    {
        throw "Image loading error\n";
    }
    sprite.setTexture(texture);



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
        window.draw(sprite);
        window.display();
    }


}

Commands GUI::selectLevelWin(){
    

    if (!texture.loadFromFile("Image/ChoiceLevel(s).png"))
    {
        throw "Image loading error\n";
    }
    sprite.setTexture(texture);

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
        window.draw(sprite);
        window.display();
    }

}

Commands GUI::level(){
    if (!texture.loadFromFile("Image/flat.png"))
    {
        throw "Image loading error\n";
    }
    sprite.setTexture(texture);



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
                    return LEVEL_WIN;
                }
            }
            
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}

Commands GUI::afterLevelWin(int num_level, int max_level){
    
   
    if (!texture.loadFromFile("Image/Win.png"))
    {
        throw "Image loading error\n";
    }
    sprite.setTexture(texture);



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
        window.draw(sprite);
        window.display();
    }
}

Commands GUI::endWin(){
    

    if (!texture.loadFromFile("Image/End.png"))
    {
        throw "Image loading error\n";
    }
    sprite.setTexture(texture);

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
        window.draw(sprite);
        window.display();
    }

}

Commands GUI::gameOverWin(){
    if (!texture.loadFromFile("Image/Game Over.png"))
    {
        throw "Image loading error\n";
    }
    sprite.setTexture(texture);

    

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
        window.draw(sprite);
        window.display();
    }

}

