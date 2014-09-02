#ifndef INPUTMANAGER
#define INPUTMANAGER

#include <memory>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

class InputManager
{
public:
    static InputManager& Get();
    void SetEvent(sf::Event& a_Event);
    void Reset();
    void SetWindow(sf::Window& a_Window);

    bool CanGetEvent();

    sf::Uint32 TextEntered();
    int KeyPressed();
    int KeyReleased();
    int MouseWheelMoved();
    bool MouseButtonPressed(short a_Button);
    bool MouseButtonReleased(short a_Button);
    bool LostFocus();
    bool GainedFocus();
    sf::Vector2i GetMousePos();

private:
    InputManager();
    ~InputManager();

private:
    bool m_bUsable;
    sf::Window* m_Window;
    sf::Event m_Event;
};

#endif
