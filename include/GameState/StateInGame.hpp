#ifndef STATEINGAME_HPP
#define STATEINGAME_HPP

#include "include/GameState/State.hpp"

class StateInGame : public State
{
public:
    StateInGame();

    virtual void Init();
    virtual void Free();
    virtual void Draw(sf::RenderWindow &a_window);
    virtual void Event();
    virtual void Update();
};

#endif // STATEINGAME_HPP
