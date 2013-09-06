#include "Monster.h"

USING_NS_CC;

Monster* Monster::monsterCreate(int type) {
	Monster* monster = NULL;
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage("enemy.png");
	monster = (Monster*)Sprite::createWithTexture(texture, CCRectMake(32,0,32,32));
	monster->initSprite(texture);
	return monster;
}

void Monster::initSprite(Texture2D* t){
	this->downImage = Animation::create();
	this->upImage = Animation::create();
	this->rightImage = Animation::create();
	this->leftImage = Animation::create();
/*
	this->downImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		this->downImage->addSpriteFrameWithTexture(t, Rect(i*32,0*32,32,32));
	}
	this->rightImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		this->rightImage->addSpriteFrameWithTexture(t, Rect(i*32,2*32,32,32));
	}
	this->upImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		this->upImage->addSpriteFrameWithTexture(t, Rect(i*32,3*32,32,32));
	}
	this->leftImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		this->leftImage->addSpriteFrameWithTexture(t, Rect(i*32,1*32,32,32));
	}
	this->downImage->retain();
	this->rightImage->retain();
	this->leftImage->retain();
	this->upImage->retain();*/
}

void Monster::initMove(int s){
	this->speed = s;
	this->upSpeed = Point(0,(s));
	this->downSpeed = Point(0,-(s));
	this->leftSpeed = Point(-(s),0);
	this->rightSpeed = Point((s),0);
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