#pragma once
#include "ScreenSaver.h"

class Button : public ScreenSaver
{
private:
    sf::Font font; //шрифт текста
    sf::Text buttonText; //текст на кнопке. 
    void defaultSettings();//устанавливает параметры кнопки по умолчанию
    
public:
   
    Button();
    Button(float, float, std::string);//устанавливает размер конопки
    Button(float, float, float, float, std::string);//устанавливает размер и местоположение.
    void setFont(std::string);//устанавливает шрифт.    
    void setText(std::string);//устанавливаем текст.
    void setTextColor(sf::Color);
    void setTextSize(int size);//устанавливает размер текста.
    void setTextPosition(float x, float y);
    bool MouseInObject(sf::Vector2i localPosition);
    void ActivityButton(sf::Vector2i);//Включает подсветку кнопки.
    sf::Text getTextButton();
};

