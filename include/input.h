#ifndef INPUT_H
#define INPUT_H

#include "player.h"
#include <SDL3/SDL.h>

void handleInput(Player *player, SDL_Event *event);

#endif