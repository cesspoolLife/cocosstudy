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
	Monster* monster = Monster::monsterCreate(0);
	this->monsters->addObject(monster);
	monster->setPosition(p);
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
	CCLog(std::to_string(mm->hScale).c_str());
	CCARRAY_FOREACH(mm->monsters, monster)
	{
		Monster* curMonster = (Monster*)monster;
		Point p = curMonster->getPosition();
		int pX = p.x/(mm->wScale*mm->tSize.width); 
		int pY = (mm->hScale*mm->mSize.height*mm->tSize.height-p.y)/(mm->hScale*mm->tSize.height);
		int Gid = mm->wayinfo->getTileGIDAt(Point(pX-1,pY));
		if (Gid){
			Dictionary* properties = mm->tmxMap->propertiesForGID(Gid);
			if(properties) {
				String* way = (String*)properties->objectForKey("is_way");
				if (way&&(way->compare("YES")==0)) {
				}
				else {
					curMonster->setDirection(4);
					mm->playMonster(curMonster);
				}
			}
			else {
				curMonster->setDirection(4);
				mm->playMonster(curMonster);
			}
		}
		else {
			curMonster->setDirection(4);
			mm->playMonster(curMonster);
		}
	}
}

MonsterManage::~MonsterManage(){ 

}