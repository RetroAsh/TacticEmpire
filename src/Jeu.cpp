#include "include/Jeu.hpp"

Jeu::Jeu() :
    m_window()
{
    m_window.setFramerateLimit(60);
    m_manager.PushState(new StateInGame);
}

void Jeu::launch()
{
    m_window.create(sf::VideoMode(640, 480, 32), "Tactic empire");

    sf::Clock t_Time;

    sf::Time t_Previous = t_Time.restart();
    sf::Time t_Lag(0);

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
                    m_manager.GetState()->Event(t_event);
                    break;
                }
            }
        }

        m_window.clear();
        m_manager.GetState()->Draw(m_window);
        m_window.display();
    }
}
