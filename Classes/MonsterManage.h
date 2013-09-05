#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"
#include "Monster.h"
#include "HelloWorldScene.h"

class MonsterManage
{
private:
	cocos2d::Array* monsters;
public: 
	MonsterManage();
	int createMonster();
	void playMonster(HelloWorld* scene);
	~MonsterManage();
};
#endif