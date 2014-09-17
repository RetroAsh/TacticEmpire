#include "include/GUI/GUI.hpp"

GUI::GUI()
{

}

unsigned int GUI::AddWidget(Widget* a_Widget)
{
    std::shared_ptr<Widget> t_Widget(a_Widget);
    unsigned int t_WidgetID = ComputeNextID();
    m_WidgetList.push_back(std::make_pair(t_WidgetID, t_Widget));
    return t_WidgetID;
}

void GUI::DelWidget(unsigned int a_WidgetID)
{
    std::size_t t_ID = 0;
    bool t_bDelete = false;
    for(std::size_t i=0 ; (!t_bDelete) && i < m_WidgetList.size(); i++){
        if(m_WidgetList[i].first == a_WidgetID){
            t_ID = i;
            t_bDelete = true;
        }
    }
    if(t_bDelete){
        m_WidgetList.erase(m_WidgetList.begin() + t_ID);
    }
}

std::shared_ptr<Widget> GUI::getWidget(unsigned int a_WidgetID)
{
    for(std::size_t i=0 ; i < m_WidgetList.size(); i++){
        if(m_WidgetList[i].first == a_WidgetID){
            return m_WidgetList[i].second;
        }
    }
    throw std::out_of_range("Invalide ID");
}

void GUI::DrawGUI(sf::Window &a_Window)
{
    for(auto t_Widget : m_WidgetList){
        t_Widget.second->Draw(a_Window);
    }
}

bool GUI::ControlGUI(sf::Vector2i a_MousePos)
{
    for(auto t_Widget : m_WidgetList){
        if(t_Widget.second->Clicked(a_MousePos)){
            if(InputManager::Get().GetMousePhase() == InputManager::MOUSE_PHASE::DOWN){
                if(t_Widget.second->OnClicUp){
                    t_Widget.second->OnClicUp(t_Widget.first);
                }
            }else if(InputManager::Get().GetMousePhase() == InputManager::MOUSE_PHASE::DOWN){
                if(t_Widget.second->OnClicDown){
                    t_Widget.second->OnClicDown(t_Widget.first);
                }
            }
        }
    }
}

unsigned int GUI::ComputeNextID()
{
    return static_cast<unsigned int>(m_WidgetList.size());
}
