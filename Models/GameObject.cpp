//
//  GameObject.cpp
//  Allegro Game
//
//  Created by Tharindu Chathurange on 3/11/19.
//  Copyright © 2019 Tharindu Chathurange. All rights reserved.
//

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "GameObject.h"

GameObject::GameObject()
{
    x = 0;
    y = 0;
    bitmap = nullptr;
}

void GameObject::init(float x, float y, ALLEGRO_BITMAP *bitmap, AnimationConfig *config)
{
    GameObject::x = x;
    GameObject::y = y;
    GameObject::bitmap = bitmap;
//    GameObject::config = config;
    GameObject::animator = new Animator(bitmap, config);
}

GameObject::~GameObject()
{
    x = NULL;
    y = NULL;
//    al_destroy_bitmap(bitmap);
//    config->~AnimationConfig();
    animator->~Animator();
}

void GameObject::render()
{
    animator->drawAnimation(x, y);
}

float GameObject::getX()
{
    return x;
}

void GameObject::setX(float x)
{
    GameObject::x = x;
}

float GameObject::getY()
{
    return y;
}

void GameObject::setY(float y)
{
    GameObject::y = y;
}

Animator *GameObject::getAnimator()
{
    return GameObject::animator;
}

void GameObject::setAnimator(Animator *animator)
{
    GameObject::animator = animator;
}











