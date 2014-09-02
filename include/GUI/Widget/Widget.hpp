#ifndef WIDGET
#define WIDGET

#include <functional>
#include <SFML/Graphics.hpp>

class Widget
{
public:
    Widget();

    virtual void Draw(sf::Window &a_Window)=0;
    virtual void Control(sf::Event &a_Event)=0;

public:
    sf::Rect<float> Position;
    std::function<void(int)> OnClicUp;
    std::function<void(int)> OnClicDown;
};

#endif
