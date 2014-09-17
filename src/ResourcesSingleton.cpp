#include "include/ResourcesSingleton.hpp"

ResourcesSingleton::ResourcesSingleton() :
    m_textureCache(),
    m_fontCache()
{

}

ResourcesSingleton::~ResourcesSingleton()
{

}

ResourcesSingleton& ResourcesSingleton::Get()
{
    static ResourcesSingleton t_Instance;
    return t_Instance;
}

void ResourcesSingleton::SetFont(const std::string &a_sName, const sf::Font &a_font)
{
    m_fontCache[a_sName] = a_font;
}

sf::Font& ResourcesSingleton::GetFont(const std::string &a_sName)
{
    if(m_fontCache.find(a_sName) == m_fontCache.end()){
        sf::Font t_TmpFont;
        t_TmpFont.loadFromFile(a_sName);
        m_fontCache[a_sName] = t_TmpFont;
    }
    return m_fontCache.at(a_sName);
}

void ResourcesSingleton::SetTexture(const std::string &a_sName, const sf::Texture &a_font)
{
    m_textureCache[a_sName] = a_font;
}

sf::Texture& ResourcesSingleton::GetTexture(const std::string &a_sName)
{
    return m_textureCache.at(a_sName);
}
