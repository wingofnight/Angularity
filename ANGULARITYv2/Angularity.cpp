#include "Header.h"
#include <string>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#pragma warning(disable : 4996)
#include "Button.h"
#include "ScreenSaver.h"


int main() {    
    
    sf::RenderWindow gameWindow(sf::VideoMode(800, 600), "ANGULARITY", sf::Style::None);

    
    ScreenSaver test;
    test.setObjectTexture("../images/BackGroundMul.png");
    Button start;

    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();
        }

        if (event.type == sf::Event::MouseMoved)
        {           
            start.ActivityButton(sf::Mouse::getPosition(gameWindow));
        }

        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (start.MouseInObject(sf::Mouse::getPosition(gameWindow)))
            {           
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                   start.setOutlineObject(5, sf::Color::Red);
                }
                else {
                    //startGame - обновит изображение
                    //разметит поле. Создаст матрицу из 64 объектов кнопка.
                    //метод ход игрока и ходи ии
                    //проверка на условия победы
                }
            }
        }

        gameWindow.clear();
        gameWindow.draw(test.getObject());
        gameWindow.draw(start.getObject());
        gameWindow.draw(start.getTextButton());
        gameWindow.display();
    }
    
    return 0;
}

