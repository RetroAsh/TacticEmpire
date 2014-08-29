#ifndef RESOURCESSINGLETON
#define RESOURCESSINGLETON

#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class ResourcesSingleton
{
public:
    static ResourcesSingleton& Get();

    // Font cache
    void SetFont(const std::string &a_sName, const sf::Font &a_font);
    sf::Font& GetFont(const std::string &a_sName);

    // Texture cache
    void SetTexture(const std::string &a_sName, const sf::Texture &a_font);
    sf::Texture& GetTexture(const std::string &a_sName);

private:
    ResourcesSingleton();
    ~ResourcesSingleton();

private:
    std::map<std::string, sf::Texture> m_textureCache;
    std::map<std::string, sf::Font> m_fontCache;
};

#endif
