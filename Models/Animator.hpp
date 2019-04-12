//
//  Animator.hpp
//  Allegro Game
//
//  Created by Tharindu Chathurange on 4/7/19.
//  Copyright © 2019 Tharindu Chathurange. All rights reserved.
//

#ifndef Animator_hpp
#define Animator_hpp

#include <stdio.h>
#include "AnimationConfig.hpp"
#include <allegro5/allegro.h>

class Animator
{
private:
    ALLEGRO_BITMAP *animation;
    AnimationConfig *config;
    
public:
    Animator();
    Animator(ALLEGRO_BITMAP *animation, AnimationConfig *config);
    ~Animator();
    void animate(AnimationConfig *config = NULL);
    void drawAnimation(float x, float y, AnimationConfig *config = NULL);
    AnimationConfig *getAnimationConfig();
    void setAnimationConfig(AnimationConfig *config);
};

#endif /* Animator_hpp */
