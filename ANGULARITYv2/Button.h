#pragma once
#include "ScreenSaver.h"

class Button : public ScreenSaver
{
private:
    sf::Font font; //����� ������
    sf::Text buttonText; //����� �� ������. 
    void defaultSettings();//������������� ��������� ������ �� ���������
    
public:
   
    Button();
    Button(float, float, std::string);//������������� ������ �������
    Button(float, float, float, float, std::string);//������������� ������ � ��������������.
    void setFont(std::string);//������������� �����.    
    void setText(std::string);//������������� �����.
    void setTextColor(sf::Color);
    void setTextSize(int size);//������������� ������ ������.
    void setTextPosition(float x, float y);
    bool MouseInObject(sf::Vector2i localPosition);
    void ActivityButton(sf::Vector2i);//�������� ��������� ������.
    sf::Text getTextButton();
};

