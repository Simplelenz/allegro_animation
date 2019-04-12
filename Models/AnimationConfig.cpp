//
//  AnimationConfig.cpp
//  Allegro Game
//
//  Created by Tharindu Chathurange on 4/7/19.
//  Copyright © 2019 Tharindu Chathurange. All rights reserved.
//

#include <iostream>
#include "AnimationConfig.hpp"

AnimationConfig::AnimationConfig()
{
    maxFrame = 0;
    currentFrame = 0;
    frameCount = 0;
    frameDelay = 0;
    frameWidth = 0;
    frameHeight = 0;
    mask.r = -1;
    mask.g = -1;
    mask.b = -1;
}

AnimationConfig::~AnimationConfig()
{
    maxFrame = NULL;
    currentFrame = NULL;
    frameCount = NULL;
    frameDelay = NULL;
    frameWidth = NULL;
    frameHeight = NULL;
    mask.r = NULL;
    mask.r = NULL;
    mask.r = NULL;
}

void AnimationConfig::setMask(Color mask)
{
    AnimationConfig::mask = mask;
}

Color AnimationConfig::getMask()
{
    return AnimationConfig::mask;
}

void AnimationConfig::setMaxframe(int maxFrame)
{
    if (maxFrame < 1)
    {
        throw std::invalid_argument("maxFrame must be greater than 0");
    }
    
    AnimationConfig::maxFrame = maxFrame;
}

int AnimationConfig::getMaxFrame()
{
    return AnimationConfig::maxFrame;
}

void AnimationConfig::setFrameDelay(int frameDelay)
{
    if (frameDelay < 0)
    {
        frameDelay = 0;
    }
    
    AnimationConfig::frameDelay = frameDelay;
}

int AnimationConfig::getFrameDelay()
{
    return AnimationConfig::frameDelay;
}

void AnimationConfig::setFrameWidth(int frameWidth)
{
    if (frameWidth < 0)
    {
        throw std::invalid_argument("frameWidth can not be negative");
    }
    
    AnimationConfig::frameWidth = frameWidth;
}

int AnimationConfig::getFrameWidth()
{
    return AnimationConfig::frameWidth;
}

void AnimationConfig::setFrameHeight(int frameHeight)
{
    if (frameHeight < 0)
    {
        throw std::invalid_argument("frameHeight can not be negative");
    }
    
    AnimationConfig::frameHeight = frameHeight;
}

int AnimationConfig::getFrameHeight()
{
    return AnimationConfig::frameHeight;
}

void AnimationConfig::setFrameCount(int frameCount)
{
    if (frameCount < 0)
    {
        throw std::invalid_argument("frameCount can not be negative");
    }
    
    AnimationConfig::frameCount = frameCount;
}

int AnimationConfig::getFrameCount()
{
    return AnimationConfig::frameCount;
}

void AnimationConfig::setCurrentFrame(int currentFrame)
{
    if (currentFrame < 0)
    {
        throw std::invalid_argument("currentFrame can not be negative");
    }
    
    AnimationConfig::currentFrame = currentFrame;
}

int AnimationConfig::getCurrentFrame()
{
    return AnimationConfig::currentFrame;
}
