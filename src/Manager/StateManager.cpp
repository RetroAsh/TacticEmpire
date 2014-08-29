#include "include/Manager/StateManager.hpp"

StateManager::StateManager() :
    m_stateStack()
{

}

std::shared_ptr<State> StateManager::GetState()
{
    return ((m_stateStack.empty()) ? nullptr : m_stateStack.top());
}

void StateManager::PushState(State *a_state)
{
    std::shared_ptr<State> t_state(a_state);
    t_state->SetManager(this);
    t_state->Init();
    m_stateStack.push(t_state);
}

void StateManager::SetState(State *a_state)
{
    PopState();
    PushState(a_state);
}

void StateManager::PopState()
{
    if(!m_stateStack.empty()){
        m_stateStack.top()->Free();
        m_stateStack.pop();
    }
}

