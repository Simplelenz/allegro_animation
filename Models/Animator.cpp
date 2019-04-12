//
//  Animator.cpp
//  Allegro Game
//
//  Created by Tharindu Chathurange on 4/7/19.
//  Copyright © 2019 Tharindu Chathurange. All rights reserved.
//

#include "Animator.hpp"

Animator::Animator()
{
    
}

Animator::Animator(ALLEGRO_BITMAP *animation, AnimationConfig *config)
{
    Animator::animation = animation;
    Animator::config = config;
    if (config->getMask().r > -1 && config->getMask().g > -1 && config->getMask().b > -1) {
        al_convert_mask_to_alpha(animation, al_map_rgb(config->getMask().r, config->getMask().g, config->getMask().b));
    }
}

Animator::~Animator()
{
//    al_destroy_bitmap(animation);
    config = nullptr;
}

void Animator::animate(AnimationConfig *config)
{
    if (config == nullptr)
    {
        config = Animator::config;
    }
    
    int frameCount = config->getFrameCount();
    config->setFrameCount(++frameCount);
    
    if(frameCount >= config->getFrameDelay())
    {
        int currentFrame = config->getCurrentFrame();
        config->setCurrentFrame(++currentFrame);
        if(currentFrame >= config->getMaxFrame())
        {
            config->setCurrentFrame(0);
        }
        
        config->setFrameCount(0);
    }
}

void Animator::drawAnimation(float x, float y, AnimationConfig *config)
{
    if (config == nullptr)
    {
        config = Animator::config;
    }
    
    al_draw_bitmap_region(animation, config->getCurrentFrame() * config->getFrameWidth(), 0, config->getFrameWidth(), config->getFrameHeight(), x, y, 0);
}

AnimationConfig *Animator::getAnimationConfig()
{
    return Animator::config;
}

void Animator::setAnimationConfig(AnimationConfig *config)
{
    Animator::config = config;
}




















