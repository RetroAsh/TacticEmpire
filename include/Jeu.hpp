#ifndef JEU
#define JEU

#include <SFML/Graphics.hpp>
#include "include/Manager/InputManager.hpp"
#include "include/Manager/StateManager.hpp"
#include "include/GameState/StateInGame.hpp"

class Jeu
{
public:
    Jeu();

    void launch();

private:
    sf::RenderWindow m_window;
    StateManager m_manager;
};

#endif
