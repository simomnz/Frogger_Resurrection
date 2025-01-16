
#include "sounds.h"

/*
 ▗▄▄▖ ▗▄▖ ▗▖ ▗▖▗▖  ▗▖▗▄▄▄ 
▐▌   ▐▌ ▐▌▐▌ ▐▌▐▛▚▖▐▌▐▌  █
 ▝▀▚▖▐▌ ▐▌▐▌ ▐▌▐▌ ▝▜▌▐▌  █
▗▄▄▞▘▝▚▄▞▘▝▚▄▞▘▐▌  ▐▌▐▙▄▄▀

*/


/* Initialize SDL2_mixer */
int initAudio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Errore SDL: %s\n", SDL_GetError());
        return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Errore SDL_mixer: %s\n", Mix_GetError());
        return 1;
    }
    return 0; /* Success*/
}


