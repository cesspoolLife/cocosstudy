#include "MonsterManage.h"

USING_NS_CC;

MonsterManage::MonsterManage(){
	monsters = Array::create();
}

int MonsterManage::createMonster(){
	Monster* monster = Monster::monsterCreate(0);
	monsters->addObject(monster);
}

void MonsterManage::playMonster(HelloWorld* scene){
	
}

MonsterManage::~MonsterManage(){ 

}