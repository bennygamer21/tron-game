// Posiciones iniciales
int x1 = 100, y1 = 100;
int x2 = 200, y2 = 100;

while (running) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) running = 0;

        if (event.type == SDL_EVENT_KEYDOWN) {
            switch (event.key.keysym.sym) {
                // Jugador 1 (WASD)
                case SDLK_w: y1 -= 10; break;
                case SDLK_s: y1 += 10; break;
                case SDLK_a: x1 -= 10; break;
                case SDLK_d: x1 += 10; break;

                // Jugador 2 (flechas)
                case SDLK_UP:    y2 -= 10; break;
                case SDLK_DOWN:  y2 += 10; break;
                case SDLK_LEFT:  x2 -= 10; break;
                case SDLK_RIGHT: x2 += 10; break;
            }
        }
    }

    // Dibujar
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &(SDL_Rect){x1, y1, 50, 50});

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &(SDL_Rect){x2, y2, 50, 50});

    SDL_RenderPresent(renderer);
}
