#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Character.h"

class HelloWorld : public cocos2d::LayerColor
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    //void menuCloseCallback(Object* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

	void checkPosition(float dt);

private:
	Character* character;

	cocos2d::TMXTiledMap* tmxMap;
	cocos2d::TMXLayer* building;
	cocos2d::TMXLayer* wayinfo;
	cocos2d::Sprite* sprite ;

	cocos2d::Size mSize;
	cocos2d::Size tSize;
	float wScale;
	float hScale;
};

#endif // __HELLOWORLD_SCENE_H__
