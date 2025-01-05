#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Mix_Music* loadMusic(const char *filePath);

Mix_Chunk* loadSound(const char *filePath);

int initAudio();

void startMusic(Mix_Music *music);

void stopMusic();

void playSound(Mix_Chunk *sound);

void stopAudio(Mix_Music *music, Mix_Chunk *sound);

