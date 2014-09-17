#ifndef GUI_SYSTEM
#define GUI_SYSTEM

#include <vector>
#include <memory>
#include <utility>
#include <functional>
#include <exception>
#include <SFML/Graphics.hpp>

#include "include/GUI/Widget/Widget.hpp"
#include "include/Manager/InputManager.hpp"

class InputManager;

class GUI
{
public:
    GUI();

    unsigned int AddWidget(Widget* a_Widget);
    void DelWidget(unsigned int a_WidgetID);
    std::shared_ptr<Widget> getWidget(unsigned int a_WidgetID);

    void DrawGUI(sf::Window &a_Window);
    bool ControlGUI(sf::Vector2i a_MousePos);

private:
    unsigned int ComputeNextID();


private:
    std::vector<std::pair<unsigned int,std::shared_ptr<Widget>>> m_WidgetList;
};

#endif
