#include "MonsterManage.h"

USING_NS_CC;

MonsterManage::MonsterManage(cocos2d::TMXTiledMap* tm, cocos2d::TMXLayer* wi, cocos2d::Size m, cocos2d::Size t, float w, float h){
	this->tmxMap = tm;
	this->wayinfo = wi;
	this->mSize = m;
	this->tSize = t;
	this->wScale = w;
	this->hScale = h; 
	this->monsters = Array::create();
	this->monsters->retain();
}

Monster* MonsterManage::createMonster(Point p){
	srand(time(NULL));
//	CCLog(std::to_string(p.x).c_str());
//	CCLog(std::to_string(p.y).c_str());
	p = Point(640,360);
	int type = rand()%4;
	Monster* monster = Monster::monsterCreate(type);
	this->monsters->addObject(monster);
	monster->setPosition(p);
	type = (rand()%4)+1;
	monster->setDirection(1);
	this->playMonster(monster);
	return monster;
}

void MonsterManage::playMonster(Monster* curMonster){
	curMonster->stopAllActions();
	ActionInterval* animate = curMonster->getAnimation();
	ActionInterval* move = curMonster->getMove();
	Action* actionmove = RepeatForever::create(move);
	ActionInterval* swq = Spawn::create(move, animate, NULL);
	Action* rep = RepeatForever::create(swq);
	curMonster->runAction(rep);
}

void MonsterManage::update(MonsterManage* mm) {
	Object* monster = NULL;
	CCARRAY_FOREACH(mm->monsters, monster)
	{
		Monster* curMonster = (Monster*)monster;
		Point p = curMonster->getPosition();
		int pX = p.x/(mm->wScale*mm->tSize.width); 
		int pY = (mm->hScale*mm->mSize.height*mm->tSize.height-p.y)/(mm->hScale*mm->tSize.height);
		int Gid = 1;
		int rGid;
		int lGid;
		int rDirection;
		int lDirection;
		int direction = curMonster->getDirection();
		switch(direction){
		case 1:
			if (p.x-pX*mm->wScale*mm->tSize.width<16){
				Gid = mm->wayinfo->getTileGIDAt(Point(pX-1,pY));
				rGid = mm->wayinfo->getTileGIDAt(Point(pX,pY-1));
				rDirection = 3;
				lDirection = 4;
			}
			break;
		case 2:
			if (pX*mm->wScale*mm->tSize.width-p.x<5){
				Gid = mm->wayinfo->getTileGIDAt(Point(pX+1,pY));
				rGid = mm->wayinfo->getTileGIDAt(Point(pX,pY+1));
				rDirection = 4;
				lDirection = 3;
			}
			break;
		case 3:
			CCLog(std::to_string(p.y).c_str());
			if ((mm->hScale*mm->mSize.height*mm->tSize.height-p.y)-(pY*mm->hScale*mm->tSize.height)<16){
				Gid = mm->wayinfo->getTileGIDAt(Point(pX,pY-1));
				rGid = mm->wayinfo->getTileGIDAt(Point(pX+1,pY));
				rDirection = 2;
				lDirection = 1;
			}
			break;
		case 4:
			if (p.y-pY*mm->hScale*mm->tSize.height<16){
				Gid = mm->wayinfo->getTileGIDAt(Point(pX,pY+1));
				rGid = mm->wayinfo->getTileGIDAt(Point(pX-2,pY));
				rDirection = 1;
				lDirection = 2;
			}
			break;
		}
		if (Gid){
		}
		else {
			if (rGid) {
				curMonster->setDirection(rDirection);
			}else {
				curMonster->setDirection(lDirection);
			}
			mm->playMonster(curMonster);
		}
	}
}

MonsterManage::~MonsterManage(){ 

}