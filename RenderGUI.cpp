#include "RenderGUI.h"

RenderGUI::RenderGUI()
{
    cat_Before();
    cat_Back();
    cat_Left();
    cat_Right();

    water();
    level();
    fish();
    heart();
    teleport();
}

void RenderGUI::setBackground(std::string filename)
{
    if (!texture.loadFromFile(filename))
    {
        throw "Image loading error\n";
    }
    background.setTexture(texture);
}

void RenderGUI::level()
{
    if (!textureL.loadFromFile("Image/flat.png"))
    {
        throw "Image loading error\n";
    }
    backgroundL.setTexture(textureL);
}

void RenderGUI::cat_Before()
{

    if (!textureCBefore.loadFromFile("Image/cat_1.png"))
    {
        throw "Image loading error\n";
    }

    catBefore.setTexture(textureCBefore);
    catBefore.setOrigin(35.f, 35.f);
}

void RenderGUI::cat_Back()
{
    if (!textureCBack.loadFromFile("Image/cat_2.png"))
    {
        throw "Image loading error\n";
    }

    catBack.setTexture(textureCBack);
    catBack.setOrigin(35.f, 35.f);
}

void RenderGUI::cat_Left()
{
    if (!textureCLeft.loadFromFile("Image/cat_3.png"))
    {
        throw "Image loading error\n";
    }

    catLeft.setTexture(textureCLeft);
    catLeft.setOrigin(35.f, 35.f);
}

void RenderGUI::cat_Right()
{
    if (!textureCRight.loadFromFile("Image/cat_4.png"))
    {
        throw "Image loading error\n";
    }

    catRight.setTexture(textureCRight);
    catRight.setOrigin(35.f, 35.f);
}

void RenderGUI::water()
{
    if (!textureWater.loadFromFile("Image/water.png"))
    {
        throw "Image loading error\n";
    }

    waterS.setTexture(textureWater);
}

void RenderGUI::heart()
{
    if (!textureHeart.loadFromFile("Image/heart.png"))
    {
        throw "Image loading error\n";
    }

    heartS.setTexture(textureHeart);
}

void RenderGUI::fish()
{
    if (!textureFish.loadFromFile("Image/fish.png"))
    {
        throw "Image loading error\n";
    }

    fishS.setTexture(textureFish);
}

void RenderGUI::teleport()
{
    if (!textureTeleport.loadFromFile("Image/teleport.png"))
    {
        throw "Image loading error\n";
    }

    teleportS.setTexture(textureTeleport);
}

sf::Sprite RenderGUI::getBackground()
{
    return background;
}

sf::Sprite RenderGUI::getLevel()
{
    return backgroundL;
}

sf::Sprite RenderGUI::getCatBefore()
{
    return catBefore;
}

sf::Sprite RenderGUI::getCatBack()
{
    return catBack;
}

sf::Sprite RenderGUI::getCatLeft()
{
    return catLeft;
}

sf::Sprite RenderGUI::getCatRight()
{
    return catRight;
}

sf::Sprite RenderGUI::getWater()
{
    return waterS;
}

sf::Sprite RenderGUI::getHeart()
{
    return heartS;
}

sf::Sprite RenderGUI::getFish()
{
    return fishS;
}

sf::Sprite RenderGUI::getTeleport()
{
    return teleportS;
}



