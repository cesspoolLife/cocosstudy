#ifndef __MONSTERMANAGE_H__
#define __MONSTERMANAGE_H__

#include "cocos2d.h"
#include "Monster.h"

class MonsterManage
{
public:
	cocos2d::TMXTiledMap* tmxMap;
	cocos2d::TMXLayer* wayinfo;
	cocos2d::Size mSize;
	cocos2d::Size tSize;
	float wScale;
	float hScale;
	cocos2d::Array* monsters;
public: 
	MonsterManage(cocos2d::TMXTiledMap* tm, cocos2d::TMXLayer* wi, cocos2d::Size m, cocos2d::Size t, float w, float h);
	Monster* createMonster(cocos2d::Point p);
	void playMonster(Monster* curMonster);
	static void update(MonsterManage* mm);
	~MonsterManage();
};
#endif