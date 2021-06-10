#include "Button.h"

/*����� �������, ������� ���������� ������. �� ���������, �� ������� ������ � ������ ����� ���� (800�600)
* ������������� ��� ����� Sart, ������ ������ � ������ ������. ���� ���� �������, ������� ���������
* �������� ���������. 
*/


//����������� �����������
Button::Button() {
    defaultSettings();// ��������� �� ���������
 }

//����������� ������� ������ ������ ������
Button::Button(float x_size, float y_size, std::string text) {
    defaultSettings();
    setObjectSize(x_size, y_size);//��������� ���������� �� ������������ � ������������� ������ ������   
    buttonText.setString(text); //��������� ���������� text �� ������������ � ������������� ����� ������   
}

//����������� ������� ������ ������ � ����� ��������� ������
Button::Button(float x_size, float y_size, float x_pos, float y_pos, std::string text) {
    defaultSettings();
    setObjectSize(x_size, y_size);// ��������� ���������� �� ������������ � ������������� ������ ������    
    setObjectPosition(x_pos, y_pos);//��������� ���������� �� ������������ �  ������ ������� ������   
    buttonText.setString(text); // ��������� ���������� text �� ������������ � ������������� ����� ������   
}


//��������� ������ �� ���������
void Button::defaultSettings() {
   
    setObjectSize(400, 100);//������������� ������ ������ 
    setColorObject(sf::Color(100, 100, 100, 250));//���������� ������
    setObjectPosition(200, 450); // ������ ������� ������
    setFont("../fonts/Vivian.ttf"); // ��������� �����, �� ����� ������ � ������������� ����� � ��������� ����   
    setTextColor(sf::Color::Red); // ������������� ���� ������
    setText("Start"); // ������������� ����� ������
    setTextSize(62); // ������������� ������ ������
    setTextPosition(310, 460);// ������������� �������������� ������.
}

//������������� ����� ������
void Button::setFont(std::string puth) {
    font.loadFromFile(puth); //��������� ���� � ��������� �����.
    buttonText.setFont(font);//������������� ����� ������.
}

//������������� ����� ������
void Button::setText(std::string text) {
    buttonText.setString(text);
}

//������������� ������ ������
void Button::setTextSize(int size) {
    buttonText.setCharacterSize(size);
}

//������������� �������������� ������
void Button::setTextPosition(float x, float y) {
    buttonText.setPosition(sf::Vector2f(x, y));
}

//������ ���� ������
void Button::setTextColor(sf::Color color) {
    buttonText.setColor(color);
}

//���������� �����.
sf::Text Button::getTextButton() {
    return buttonText;
}

/*
* �������� ������� ��������� �������� �� ������� ������!
*/

//�����������, ��������� �� ��������� �����, ������ �������
bool Button::MouseInObject(sf::Vector2i localPosition) {
    if (localPosition.x >= getObjectPosition().x && localPosition.x <= (getObjectPosition().x + getObjectSize().x)
        && localPosition.y >= getObjectPosition().y && localPosition.y <= (getObjectPosition().y + getObjectSize().y))
    {
        return true;
    }
    else {
        return false;
    }
}
 
//������� ������������ ������, ���� ����� ������ �������. � ��� ������� ������ ����.
void Button::ActivityButton(sf::Vector2i localPosition) {
    
    //���� � if �������� ���������� ������ �� ���� 4 ��������. ���� ����� ��������� ������ ������, ����������� ������������ ��������.
    if (MouseInObject(localPosition))
    {
        setOutlineObject(5, sf::Color::Yellow); //������������� ������� ������� � ����

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            setOutlineObject(5, sf::Color::Red);//���� ������ ������, �� ������ ���� �� �������
        }
    }
    else
    {
        setOutlineObject(0, sf::Color::Yellow); 
    }
}



/*����� � ��������� � ���, ��� ����������� �����������, ����� ��������� ������ �����. ����� ���������� ��� ��������*/