#include "include/Manager/InputManager.hpp"

InputManager::InputManager() :
    m_bUsable(false)
{
}

InputManager::~InputManager()
{
    m_Window = nullptr;
}

InputManager& InputManager::Get()
{
    static InputManager t_Instance;
    return t_Instance;
}

void InputManager::SetEvent(sf::Event &a_Event)
{
    m_bUsable = true;
    m_Event = a_Event;
}

void InputManager::Reset()
{
    m_bUsable = false;
}

void InputManager::SetWindow(sf::Window& a_Window)
{
    m_Window = &a_Window;
}

bool InputManager::CanGetEvent()
{
    return m_bUsable;
}

sf::Uint32 InputManager::TextEntered()
{
    return m_Event.text.unicode;
}

int InputManager::KeyPressed()
{
    return m_Event.key.code;
}

int InputManager::KeyReleased()
{
    return m_Event.key.code;
}

int InputManager::MouseWheelMoved()
{
    return m_Event.mouseWheel.delta;
}

bool InputManager::MouseButtonPressed(short a_Button)
{
    bool t_bPressed = false;
    if(a_Button == 0){
        t_bPressed = (m_Event.mouseButton.button == sf::Mouse::Left);
    }else if(a_Button == 1){
        t_bPressed = (m_Event.mouseButton.button == sf::Mouse::Right);
    }
    return t_bPressed;
}

bool InputManager::MouseButtonReleased(short a_Button)
{
    bool t_bReleased = false;
    if(a_Button == 0){
        t_bReleased = (m_Event.mouseButton.button == sf::Mouse::Left);
    }else if(a_Button == 1){
        t_bReleased = (m_Event.mouseButton.button == sf::Mouse::Right);
    }
    return t_bReleased;
}

bool InputManager::LostFocus()
{
    return (m_Event.type == sf::Event::LostFocus);
}

bool InputManager::GainedFocus()
{
    return (m_Event.type == sf::Event::GainedFocus);
}

sf::Vector2i InputManager::GetMousePos()
{
    return sf::Mouse::getPosition(*m_Window);
}

