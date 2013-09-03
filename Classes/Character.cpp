#include "Character.h"

USING_NS_CC;

Character::Character(){
	texture = TextureCache::sharedTextureCache()->addImage("enemy.png");
	character = Sprite::createWithTexture(texture, CCRectMake(32,0,32,32));
	downImage = Animation::create();
	upImage = Animation::create();
	rightImage = Animation::create();
	leftImage = Animation::create();

	downSpeed = Point(0,-40);
	downImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		downImage->addSpriteFrameWithTexture(texture, Rect(i*32,0*32,32,32));
	}
	leftSpeed = Point(-240,0);
	leftImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		leftImage->addSpriteFrameWithTexture(texture, CCRectMake(i*32,1*32,32,32));
	}
	rightSpeed = Point(40,0);
	rightImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		rightImage->addSpriteFrameWithTexture(texture, CCRectMake(i*32,2*32,32,32));
	}
	upSpeed = Point(0,40);
	upImage->setDelayPerUnit(0.3);
	for(int i=0; i<3; i++){
		upImage->addSpriteFrameWithTexture(texture, CCRectMake(i*32,3*32,32,32));
	}
}

Sprite* Character::getCaracter(){
	return character;
}

ActionInterval* Character::leftAnimation(){
	return Animate::create(leftImage);
}
ActionInterval* Character::downAnimation(){
	return Animate::create(downImage);
}
ActionInterval* Character::rightAnimation(){
	return Animate::create(rightImage);
}
ActionInterval* Character::upAnimation(){
	return Animate::create(upImage);
}

ActionInterval* Character::leftMove(){
	return  MoveBy::create(0.9,leftSpeed);
}
ActionInterval* Character::rightMove(){
	return  MoveBy::create(0.9,rightSpeed);
}
ActionInterval* Character::downMove(){
	return  MoveBy::create(0.9,downSpeed);
}
ActionInterval* Character::upMove(){
	return  MoveBy::create(0.9,upSpeed);
}