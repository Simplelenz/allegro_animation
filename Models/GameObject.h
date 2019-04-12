//
//  GameObject.h
//  Allegro Game
//
//  Created by Tharindu Chathurange on 3/11/19.
//  Copyright © 2019 Tharindu Chathurange. All rights reserved.
//

#ifndef GameObject_h
#define GameObject_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Animator.hpp"

class GameObject
{
private:
    float x, y;
    ALLEGRO_BITMAP *bitmap;
    Animator *animator;
//    AnimationConfig *config;
    
public:
    GameObject();
    ~GameObject();
    void init(float x, float y, ALLEGRO_BITMAP *bitmap, AnimationConfig *config);
    float getX();
    void setX(float x);
    float getY();
    void setY(float y);
    void render();
    void setAnimator(Animator *animator);
    Animator *getAnimator();
};

#endif /* GameObject_h */
