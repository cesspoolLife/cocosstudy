#include "MonsterManage.h"

USING_NS_CC;

MonsterManage::MonsterManage(){
	monsters = Array::create();
}

Monster* MonsterManage::createMonster(Point p){
	Monster* monster = Monster::monsterCreate(0);
	monsters->addObject(monster);
	monster->setPosition(p);
	return monster;
}

void MonsterManage::playMonster(){
	Object* monster = NULL;
	CCARRAY_FOREACH(monsters, monster)
	{
		Monster* curMonster = (Monster*)monster;
		ActionInterval* animate = curMonster->leftAnimation();
		ActionInterval* move = curMonster->leftMove();
		Action* actionmove = RepeatForever::create(move);
		ActionInterval* swq = Spawn::create(move, animate, NULL);
		Action* rep = RepeatForever::create(swq);
		curMonster->runAction(rep);
	}
}

MonsterManage::~MonsterManage(){ 

}