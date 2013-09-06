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


ActionInterval* Monster::leftAnimation(){
	return Animate::create(leftImage);
}
ActionInterval* Monster::downAnimation(){
	return Animate::create(downImage);
}
ActionInterval* Monster::rightAnimation(){
	return Animate::create(rightImage);
}
ActionInterval* Monster::upAnimation(){
	return Animate::create(upImage);
}

ActionInterval* Monster::leftMove(){
	return  MoveBy::create(0.9,leftSpeed);
}
ActionInterval* Monster::rightMove(){
	return  MoveBy::create(0.9,rightSpeed);
}
ActionInterval* Monster::downMove(){
	return  MoveBy::create(0.9,downSpeed);
}
ActionInterval* Monster::upMove(){
	return  MoveBy::create(0.9,upSpeed);
}