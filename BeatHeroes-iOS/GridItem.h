#ifndef GRIDITEM_H
#define GRIDITEM_H

//#include "IHero.h"

#import <SpriteKit/SpriteKit.h>

class GridItem
{
public:
	GridItem(int x, int y, int w, int h, SKSpriteNode *sprite);
	~GridItem();

	void Update()
	{
	//	if (!m_hero)
		//	m_cell.setFillColor(sf::Color::Transparent);
	}
	//void AddHero(IHero* hero)
	//{
		//m_hero = hero;
	//}
	//bool HasHero() const
	//{
	//	return m_hero != 0;
	//}
	//void RemoveHero()
	//{
	//	m_hero = 0;
	//}
private:
    SKSpriteNode *m_sprite;
    SKTexture* m_spriteSheet;
	//IHero* m_hero = 0;
	//sf::RectangleShape m_cell;
};

#endif
