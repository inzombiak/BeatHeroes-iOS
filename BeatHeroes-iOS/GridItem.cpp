#include "GridItem.h"

GridItem::GridItem(int x, int y, int w, int h, SKSpriteNode *sprite) : m_sprite(sprite)
{
    m_sprite = sprite;

    [m_sprite setPosition:CGPointMake(x, y)];
}

GridItem::~GridItem()
{

}

