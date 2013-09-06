#ifndef __MONSTERMANAGE_H__
#define __MONSTERMANAGE_H__

#include "cocos2d.h"
#include "Monster.h"

class MonsterManage
{
private:
	cocos2d::Array* monsters;
public: 
	MonsterManage();
	Monster* createMonster(cocos2d::Point p);
	void playMonster();
	~MonsterManage();
};
#endif