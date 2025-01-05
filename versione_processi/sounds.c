
#include "sounds.h"




/* Inizializza SDL2_mixer */
int initAudio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Errore SDL: %s\n", SDL_GetError());
        return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Errore SDL_mixer: %s\n", Mix_GetError());
        return 1;
    }
    return 0; // Successo
}

/* Carica una musica di sottofondo */
Mix_Music* loadMusic(const char *filePath) {
    Mix_Music *music = Mix_LoadMUS(filePath);
    if (!music) {
        printf("Errore caricamento musica: %s\n", Mix_GetError());
    }
    return music;
}

/* Carica un effetto sonoro */
Mix_Chunk* loadSound(const char *filePath) {
    Mix_Chunk *sound = Mix_LoadWAV(filePath);
    if (!sound) {
        printf("Errore caricamento suono: %s\n", Mix_GetError());
    }
    return sound;
}

/* Avvia la riproduzione della musica */
void startMusic(Mix_Music *music) {
    if (music) {
        Mix_VolumeMusic(13); 
        if (Mix_PlayMusic(music, -1) == -1) { // -1 per il loop infinito
            printf("Errore riproduzione musica: %s\n", Mix_GetError());
        }
    }
}

/* Ferma la riproduzione della musica */
void stopMusic() {
    Mix_HaltMusic();
}

/* Riproduce un effetto sonoro */
void playSound(Mix_Chunk *sound) {
    Mix_VolumeChunk(sound, 10);
    if (sound) {
        if (Mix_PlayChannel(-1, sound, 0) == -1) { // Usa qualsiasi canale disponibile
            printf("Errore riproduzione suono: %s\n", Mix_GetError());
        }
    }
}

/* Ferma e libera le risorse audio */
void stopAudio(Mix_Music *music, Mix_Chunk *sound) {
    stopMusic(); // Ferma la musica se in riproduzione
    if (sound) {
        Mix_FreeChunk(sound);
    }
    if (music) {
        Mix_FreeMusic(music);
    }
    Mix_CloseAudio();
    SDL_Quit();
}

