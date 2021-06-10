#include "Button.h"

/*Класс конопка, создает экземпляры кнопок. По умолчанию, он создает кнопку в нижней части окна (800х600)
* устанавнивает там текст Sart, размер текста и размер кнопки. Ниже идут функции, которые позволяют
* изменять настройки. 
*/


//Стандартный конструктор
Button::Button() {
    defaultSettings();// настройки по умолчанию
 }

//конструктор который задает размер кнопки
Button::Button(float x_size, float y_size, std::string text) {
    defaultSettings();
    setObjectSize(x_size, y_size);//принимает переменные из конструктора и Устанавливает размер кнопки   
    buttonText.setString(text); //принимает переменную text из конструктора и устанавливает текст кнопки   
}

//конструктор который задает размер и место положение кнопки
Button::Button(float x_size, float y_size, float x_pos, float y_pos, std::string text) {
    defaultSettings();
    setObjectSize(x_size, y_size);// принимает переменные из конструктора и Устанавливает размер кнопки    
    setObjectPosition(x_pos, y_pos);//принимает переменные из конструктора и  задает позицию кнопке   
    buttonText.setString(text); // принимает переменную text из конструктора и устанавливает текст кнопки   
}


//Настройки кнопки по умолчанию
void Button::defaultSettings() {
   
    setObjectSize(400, 100);//Устанавливает размер кнопки 
    setColorObject(sf::Color(100, 100, 100, 250));//окрашивает кнопку
    setObjectPosition(200, 450); // задает позицию кнопке
    setFont("../fonts/Vivian.ttf"); // загружает шрифт, из файла шрифта и Устанавливает шрифт в текстовый блок   
    setTextColor(sf::Color::Red); // устанавливает цвет шрифта
    setText("Start"); // устанавливает текст кнопки
    setTextSize(62); // устанавливает размер текста
    setTextPosition(310, 460);// устанавливает местоположение текста.
}

//устанавливает шрифт кнопки
void Button::setFont(std::string puth) {
    font.loadFromFile(puth); //принимает путь и загружает шрифт.
    buttonText.setFont(font);//устанавливает шрифт кнопки.
}

//устанавливаем текст кнопки
void Button::setText(std::string text) {
    buttonText.setString(text);
}

//устанавливаем размер текста
void Button::setTextSize(int size) {
    buttonText.setCharacterSize(size);
}

//устанавливаем местоположение текста
void Button::setTextPosition(float x, float y) {
    buttonText.setPosition(sf::Vector2f(x, y));
}

//Меняем цвет текста
void Button::setTextColor(sf::Color color) {
    buttonText.setColor(color);
}

//Возвращаем текст.
sf::Text Button::getTextButton() {
    return buttonText;
}

/*
* Незабыть расшить фунционал сеттеров на предмет ошибок!
*/

//Опеределяет, находится ли указатель мышки, внутри объекта
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
 
//Функция подсвечивает кнопку, если мышка внутри объекта. И при нажатии меняет цвет.
void Button::ActivityButton(sf::Vector2i localPosition) {
    
    //Блок в if получает координаты кнопки по всем 4 вершинам. Если мышка находится внутри кнопки, совершается определенное действие.
    if (MouseInObject(localPosition))
    {
        setOutlineObject(5, sf::Color::Yellow); //устанавливаем толщину обводки и цвет

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            setOutlineObject(5, sf::Color::Red);//если кнопка нажата, то меняет цвет на красный
        }
    }
    else
    {
        setOutlineObject(0, sf::Color::Yellow); 
    }
}



/*Здесь я задумался о том, что переизбыток коментариев, может оказаться дурным тоном. Далее постараюсь это изменить*/