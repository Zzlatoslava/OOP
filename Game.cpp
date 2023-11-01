#include "Game.h"

Game::Game(PlayerMovement* pmovement, CreateField* newMap) {
	if (pmovement == nullptr || newMap == nullptr) {
		throw "Error in creating a Game class object\n";
	}
	this->movement = pmovement;
	this->map = newMap;
     
}

void Game::startGame() {
    
    sf::Texture texture;
    if (!texture.loadFromFile("start.png"))
    {
        throw "Image loading error\n";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int newX = event.mouseButton.x;
                    int newY = event.mouseButton.y;
                    
                    if (750 < newX && newX < 1280 && 700 > newY && newY > 540 ) {
                        std::cout << "the left button was pressed" << std::endl;
                        std::cout << "mouse x: " << newX << std::endl;
                        std::cout << "mouse y: " << newY << std::endl;
                        this->selectLevel();
                    }
                    

                }
            }
        }
        
        window.clear();
        window.draw(sprite);
        window.display();
    }

 
}

void Game::selectLevel(){
    sf::Texture texture;
    if (!texture.loadFromFile("ChoiceLevel(s).png"))
    {
        throw "Image loading error\n";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

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
                            map->setLevel(1);
                            map->createLevel();
                            std::cout << "1 level!\n";
                            this->afterLevel();
                        }
                        if (newY > 610 && newY < 760) {
                            map->setLevel(2);
                            map->createLevel();
                            std::cout << "2 level!\n";
                            //this->afterLevel();
                            this->endGame();
                        }
                    }

                    if (newX > 26 && newX < 175 && newY > 24 && newY < 75) {
                        this->startGame();
                    }


                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

}

void Game::afterLevel(){
    sf::Texture texture;
    if (!texture.loadFromFile("Win.png"))
    {
        throw "Image loading error\n";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

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
                            if (map->getLevel() < MAX_LEVEL) {
                                map->setLevel(map->getLevel() + 1);
                                map->createLevel();
                                std::cout << map->getLevel() << " level!\n";
                            }
                            else {
                                this->endGame();
                                this->map->setLevel(1);
                            }
                        }
                        if (newY > 610 && newY < 760) {//вторая кнопка
                            this->startGame();
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

void Game::endGame(){
    sf::Texture texture;
    if (!texture.loadFromFile("End.png"))
    {
        throw "Image loading error\n";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

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
                        this->startGame();                        
                    }
                }
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}



