//
//  GameScene.cpp
//  MemoryGames
//
//  Created by Inchul Park on 2015. 11. 2..
//
//

#include "GameScene.h"

enum class GameUITag
{
    TAG_LABEL_CARD,
    TAG_LABEL_LIFE,
    TAG_LABEL_READY,
    TAG_LABEL_START,
    TAG_SPRITE_O,
    TAG_SPRITE_X,
    TAG_LABEL_GAMEOVER,
    TAG_LABEL_GAMECLEAR,
    TAG_MENU,
    TAG_SPRITE_CARD = 10,
};


Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    
    auto layer = GameScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    initGameData();
    
    initBG();
    initTopMenuLabel();
    
    initCard();
    
    return true;
}

void GameScene::initBG()
{
    auto spr = Sprite::create("game/game-bg.png");
    spr->setPosition(Point(winSize.width / 2, winSize.height / 2));
    this->addChild(spr);
}

void GameScene::initGameData()
{
    winSize = Director::getInstance()->getWinSize();
    
    cardOK = 0;
    life = 3;
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    for (int i = 0; i < 4; i++) {
        card[i] = rand() % 6;
    }
}

void GameScene::initTopMenuLabel()
{
    auto label_0 = Label::createWithSystemFont("", "", 20);
    label_0->setAnchorPoint(Point(0, 1));
    label_0->setPosition(Point(10, winSize.height - 10));
    label_0->setTag(static_cast<int>(GameUITag::TAG_LABEL_CARD));
    label_0->setColor(Color3B::BLACK);
    
    this->addChild(label_0);
    
    auto label_1 = Label::createWithSystemFont("", "", 20);
    label_1->setAnchorPoint(Point(1, 1));
    label_1->setPosition(Point(winSize.width - 10, winSize.height - 10));
    label_1->setTag(static_cast<int>(GameUITag::TAG_LABEL_LIFE));
    label_1->setColor(Color3B::BLACK);
    this->addChild(label_1);
    
    setLabelCard();
    setLabelLife();
}

void GameScene::setLabelCard()
{
    auto label = dynamic_cast<Label*>(this->getChildByTag(static_cast<int>(GameUITag::TAG_LABEL_CARD)));
    label->setString(StringUtils::format("CARD : %d/4", cardOK));
}

void GameScene::setLabelLife()
{
    auto label = dynamic_cast<Label*>(this->getChildByTag(static_cast<int>(GameUITag::TAG_LABEL_LIFE)));
    label->setString(StringUtils::format("LIFE : %d", life));
}

void GameScene::initCard()
{
    for (int i = 0; i < 6; i++) {
        auto spr = Sprite::create("game/card-back.png");
        spr->setPosition(Point(winSize.width / 2 - 60 + 60 * 2 * (i % 2),
                               winSize.height / 2 + 120 - 120 * ( i / 2)));
        this->addChild(spr);
        
        auto sprFont = Sprite::create(StringUtils::format("game/card_%d.png", (i+1)));
        sprFont->setPosition(Point(winSize.width / 2 - 60 + 60 * 2 * (i % 2),
                                   winSize.height / 2 + 120 - 120 * (i / 2)));
        sprFont->setVisible(false);
        sprFont->setTag(static_cast<int>(GameUITag::TAG_SPRITE_CARD) + i);
        this->addChild(sprFont);
    }
}