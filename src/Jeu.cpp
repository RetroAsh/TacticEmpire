#include "include/Jeu.hpp"

Jeu::Jeu() :
    m_window()
{
    m_manager.PushState(new StateInGame);
}

void Jeu::launch()
{
    m_window.create(sf::VideoMode(640, 480, 32), "Tactic empire");
    m_window.setFramerateLimit(60);

    InputManager& t_Input = InputManager::Get();
    t_Input.SetWindow(m_window);

    bool t_bIsOpen = true;

    while(t_bIsOpen)
    {
        sf::Event t_event;
        while(m_window.pollEvent(t_event))
        {
            switch (t_event.type) {
                case sf::Event::Closed:
                {
                    t_bIsOpen = false;
                    break;
                }
                default:
                {
                    t_Input.SetEvent(t_event);
                    m_manager.GetState()->Event();
                    break;
                }
            }
        }

        m_window.clear();
        m_manager.GetState()->Draw(m_window);
        m_window.display();
    }
}
