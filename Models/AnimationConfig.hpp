//
//  AnimationConfig.hpp
//  Allegro Game
//
//  Created by Tharindu Chathurange on 4/7/19.
//  Copyright © 2019 Tharindu Chathurange. All rights reserved.
//

#ifndef AnimationConfig_hpp
#define AnimationConfig_hpp

#include <stdio.h>
#include "allegro5/allegro.h"

struct Color
{
    float r, g, b;
};

class AnimationConfig
{
private:
    int maxFrame;
    int currentFrame;
    int frameCount;
    int frameDelay;
    int frameWidth;
    int frameHeight;
    Color mask;
    
public:
    AnimationConfig();
    ~AnimationConfig();
    int getMaxFrame();
    void setMaxframe(int maxFrame);
    int getCurrentFrame();
    void setCurrentFrame(int currentFrame);
    int getFrameCount();
    void setFrameCount(int frameCount);
    int getFrameDelay();
    void setFrameDelay(int frameDelay);
    int getFrameWidth();
    void setFrameWidth(int frameWidth);
    int getFrameHeight();
    void setFrameHeight(int frameHeight);
    Color getMask();
    void setMask(Color mask);
};

#endif /* AnimationConfig_hpp */
