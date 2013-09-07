#include "Monster.h"

USING_NS_CC;

Monster* Monster::monsterCreate(int type) {
	Monster* monster = NULL;
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage("enemy.png");
	monster = (Monster*)Sprite::createWithTexture(texture, CCRectMake(32,0,32,32));
	Animation* downAni = Animation::create();
	Animation* upAni = Animation::create();
	Animation* rightAni = Animation::create();
	Animation* leftAni = Animation::create();
	downAni->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		downAni->addSpriteFrameWithTexture(texture, Rect(i*32,0*32,32,32));
	}
	rightAni->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		rightAni->addSpriteFrameWithTexture(texture, Rect(i*32,2*32,32,32));
	}
	upAni->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		upAni->addSpriteFrameWithTexture(texture, Rect(i*32,3*32,32,32));
	}
	leftAni->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		leftAni->addSpriteFrameWithTexture(texture, Rect(i*32,1*32,32,32));
	}
	monster->initSprite(downAni, upAni, rightAni, leftAni);
	monster->initMove(40);

	return monster;
}

void Monster::initSprite(Animation* d, Animation* u, Animation* r, Animation* l){
	this->downImage = d;
	this->upImage = u;
	this->rightImage = r;
	this->leftImage = l;
	this->downImage->retain();
	this->rightImage->retain();
	this->leftImage->retain();
	this->upImage->retain();
}

void Monster::initMove(int s){
	this->speed = s;
	this->upSpeed = Point(0,s);
	this->downSpeed = Point(0,(0-s));
	this->leftSpeed = Point((0-s),0);
	this->rightSpeed = Point(s,0);
}

void Monster::setDirection(int d){
	this->direction = d;
}

ActionInterval* Monster::getAnimation(){
	switch (this->direction)
	{
	case 1:
		return Animate::create(leftImage);
	case 2:
		return Animate::create(rightImage);
	case 3:
		return Animate::create(upImage);
	case 4:
		return Animate::create(downImage);
	}
	return NULL;
}

ActionInterval* Monster::getMove(){
	switch (this->direction)
	{
	case 1:
		return MoveBy::create(0.9,leftSpeed);
	case 2:
		return MoveBy::create(0.9,rightSpeed);
	case 3:
		return MoveBy::create(0.9,upSpeed);
	case 4:
		return MoveBy::create(0.9,downSpeed);
	}
	return NULL;
}
