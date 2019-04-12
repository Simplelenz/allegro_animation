//
//  main.cpp
//  Allegro Game
//
//  Created by Tharindu Chathurange on 3/10/19.
//  Copyright © 2019 Tharindu Chathurange. All rights reserved.
//

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "GameObject.h"

#include "AnimationConfig.hpp"
#include "Animator.hpp"

const float FPS = 60;

int main(int argc, char** argv)
{
    ALLEGRO_DISPLAY *display = nullptr;
    ALLEGRO_EVENT_QUEUE *eventQueue = nullptr;
    ALLEGRO_TIMER *timer = nullptr;
    ALLEGRO_BITMAP *spriteSheet = nullptr;
    
    al_init();
    al_init_image_addon();
    
    timer = al_create_timer(1.0 / FPS);
    
    display = al_create_display(640, 480);
    
    if(!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }
    
    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(timer));
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    
    spriteSheet = al_load_bitmap("/Users/tharindu/Downloads/Projects/Allegro/Game_v1.0/Allegro Game/sprite_sheet.png");
    assert(spriteSheet != nullptr);
    
    AnimationConfig *config = new AnimationConfig();
    config->setMaxframe(4);
    config->setCurrentFrame(0);
    config->setFrameCount(0);
    config->setFrameDelay(5);
    config->setFrameWidth(64);
    config->setFrameHeight(64);
    config->setMask({103, 51, 51});
    GameObject *gameObj = new GameObject();
    gameObj->init(40, 40, spriteSheet, config);
    
    ALLEGRO_EVENT event;
    
    bool play = true;
    
    al_start_timer(timer);
    int frameDelay;
    
    while (play)
    {
        
        al_wait_for_event(eventQueue, &event);
        
        if(event.type == ALLEGRO_EVENT_TIMER)
        {
            gameObj->getAnimator()->animate(config);
        }
        else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            play = false;
        }
        else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    frameDelay = gameObj->getAnimator()->getAnimationConfig()->getFrameDelay();
                    gameObj->getAnimator()->getAnimationConfig()->setFrameDelay(--frameDelay);
                    break;
                    
                case ALLEGRO_KEY_DOWN:
                    frameDelay = gameObj->getAnimator()->getAnimationConfig()->getFrameDelay();
                    gameObj->getAnimator()->getAnimationConfig()->setFrameDelay(++frameDelay);
                    break;
            }
        }
        else if(event.type == ALLEGRO_EVENT_KEY_UP) {
            switch(event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    break;
                    
                case ALLEGRO_KEY_DOWN:
                    break;
            }
        }
        
        gameObj->render();
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));

    }
    al_destroy_timer(timer);
    al_destroy_event_queue(eventQueue);
    al_destroy_display(display);
    al_destroy_bitmap(spriteSheet);
    delete gameObj;
    
    return 0;
}
