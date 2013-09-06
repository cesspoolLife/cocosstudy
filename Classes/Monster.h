#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"

class Monster : public cocos2d::Sprite
{
public:
	int hp;
	int speed;
	cocos2d::Animation* downImage;
	cocos2d::Point downSpeed;
	cocos2d::Animation* upImage;
	cocos2d::Point upSpeed;
	cocos2d::Animation* leftImage;
	cocos2d::Point leftSpeed;
	cocos2d::Animation* rightImage;
	cocos2d::Point rightSpeed;
public:
	static Monster* monsterCreate(int type);
	cocos2d::ActionInterval* leftAnimation();
	cocos2d::ActionInterval* rightAnimation();
	cocos2d::ActionInterval* downAnimation();
	cocos2d::ActionInterval* upAnimation();
	cocos2d::ActionInterval* leftMove();
	cocos2d::ActionInterval* rightMove();
	cocos2d::ActionInterval* upMove();
	cocos2d::ActionInterval* downMove();
	void initSprite(cocos2d::Animation* d, cocos2d::Animation* u, cocos2d::Animation* r, cocos2d::Animation* l);
	void initMove(int s);
};

#endif