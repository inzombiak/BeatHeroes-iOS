#pragma once

#include <string>
#include <vector>
#include <memory>
#import <SpriteKit/SpriteKit.h>

#include "AnimationData.h"


class LuaObject;
class Enemy
{
public:
    int m_tempOffsetX = 0, m_tempOffsetY = 0;
    
	Enemy(unsigned int id, std::shared_ptr<LuaObject> obj, SKTexture* tex);
	~Enemy();

	void Init(SKScene* scene);
	void Kill();

	void Update();
	void UpdateRender();
	std::pair<int, int> GetPos() const;
	void SetPos(int newPosX, int newPosY);

	int GetHealth() const;
	void SetHealth(int amount);
	int GetDamage() const;
	const std::string& GetName() const;
	std::vector<std::pair<int, int>> GetPattern() const;

	void ContactWithStatic() const;

	bool IsAlive() const
	{
		return m_isAlive;
	}

private:
    int m_maxSprites = 0;
    
	void LoadSpriteSheet();
	void LoadAnimationFile();
	void UpdateAnimation();
    void UpdateSKSpriteTexture(SKSpriteNode* spr, Animation::IntRect rect);
    
    std::pair<int, int> m_pos;
	unsigned int m_id;
	int m_health;
	bool m_isAlive;
	std::shared_ptr<LuaObject> m_luaObj;

    std::vector<SKSpriteNode*> m_sprites;
    SKTexture* m_spriteSheet;
    
    CGRect m_texRect;
    int m_tileWidth = 32;
    int m_tileHeight = 32;
    double m_textureMarginX;
    double m_textureMarginY;
    int m_counter = 0; //Number of times Update has bee called
    const int m_maxCounter = 4; //Animations moves forward by a a frame when counters reaches this number
    
    Animation::Animation m_currentAnimation; //Current naimation being played
    std::map<std::string, std::string> m_messageToAnimation; //Mapping for message to animation name
    std::map<std::string, Animation::SpriteDefinition> m_spriteDefinitions; //Contains texture bounds for each sprite
    std::map<std::string, Animation::Animation> m_animations; //Contains animaitons
};
