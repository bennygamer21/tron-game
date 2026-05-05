#include <SDL3/SDL.h>
#include <stdio.h>
#include "score.h"
#include "player.h"
#include "input.h"
#include "ai.h"


int score1 = 0, score2 = 0;

int main (int argc, char *argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("TRON", 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    int running = 1;
    SDL_Event event;

    Player player = {100, 100, 3};
    Player enemy = {100, 100, 3};

    while (running){

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            running = 0;

            handleInput(&player, &event);
        }
        
        updateAI(&enemy);

        // aqui ira el movimiento, render, colisiones

        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }



    SDL_Delay(3000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    loadScore(&score1, &score2);

    printf("Score: %d - %d\n", score1, score2);

    return 0;
}