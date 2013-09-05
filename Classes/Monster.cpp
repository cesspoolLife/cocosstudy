#include "Monster.h"

USING_NS_CC;


Monster* Monster::monsterCreate(int type) {
	Texture2D* texture = TextureCache::sharedTextureCache()->addImage("enemy.png");
	Monster* monster = (Monster*)Sprite::createWithTexture(texture, CCRectMake(32,0,32,32));
	monster->downImage = Animation::create();
	monster->upImage = Animation::create();
	monster->rightImage = Animation::create();
	monster->leftImage = Animation::create();

	monster->downImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		monster->downImage->addSpriteFrameWithTexture(texture, Rect(i*32,0*32,32,32));
	}
	monster->leftImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		monster->leftImage->addSpriteFrameWithTexture(texture, CCRectMake(i*32,1*32,32,32));
	}
	monster->rightImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		monster->rightImage->addSpriteFrameWithTexture(texture, CCRectMake(i*32,2*32,32,32));
	}
	monster->upImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		monster->upImage->addSpriteFrameWithTexture(texture, CCRectMake(i*32,3*32,32,32));
	}
	monster->downImage->retain();
	monster->rightImage->retain();
	monster->leftImage->retain();
	monster->upImage->retain();
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