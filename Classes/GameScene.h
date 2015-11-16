//
//  GameScene.hpp
//  MemoryGames
//
//  Created by Inchul Park on 2015. 11. 2..
//
//

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public Layer
{
public:
    static Scene* createScene();
    
    virtual bool init();
    CREATE_FUNC(GameScene);
    
    Size winSize;
    
    int cardOK, life;
    int card[4];
    int countCard;
    
    void initGameData();
    
    void initBG();
    void initTopMenuLabel();
    void setLabelCard();
    void setLabelLife();
    void initCard();
};

#endif /* __GAME_SCENE_H__ */
