#ifndef __TILEMAP_H__
#define __TILEMAP_H__

#include "cocos2d.h"

class TileMap{
public:
	cocos2d::TMXTiledMap* tmxMap;
	cocos2d::TMXLayer* building;
	cocos2d::TMXLayer* wayinfo;

	cocos2d::Size mSize;
	cocos2d::Size tSize;
	int xSpawn;
	int ySpawn;
	float wScale;
	float hScale;
public:
	TileMap(char* file);
	void setScale(cocos2d::Size p);
};

#endif