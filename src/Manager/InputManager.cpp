#include "include/Manager/InputManager.hpp"

InputManager::InputManager() :
    m_bUsable(false)
{
    m_MousePhase = NO_PHASE;
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
    ComputeInputPhase();
    ComputeMousePos();
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

void InputManager::ComputeInputPhase()
{
    m_MousePhase = NO_PHASE;
    if(m_Event.type == sf::Event::MouseButtonPressed){
        if(m_Event.mouseButton.button == sf::Mouse::Left){
            m_MousePhase = DOWN;
        }
    }else if(m_Event.type == sf::Event::MouseButtonReleased){
        if(m_Event.mouseButton.button == sf::Mouse::Left){
            m_MousePhase = UP;
        }
    }
}

void InputManager::ComputeMousePos()
{
    if(m_MousePhase != NO_PHASE){
        m_MousePos = sf::Mouse::getPosition(*m_Window);
        SignalDelegat();
    }else{
        m_MousePos = sf::Vector2i(0,0);
    }
}

void InputManager::SignalDelegat()
{
    for(auto t_Delegat : m_RegistredApp){
        if(t_Delegat(m_MousePos)){
            break;
        }
    }
}

void InputManager::SignInDelegat(const GUI& a_Obj)
{
    using std::placeholders::_1;
    m_RegistredApp.push_back(std::bind(&GUI::ControlGUI, a_Obj, _1));
}

InputManager::MOUSE_PHASE InputManager::GetMousePhase()
{
    return m_MousePhase;
}
