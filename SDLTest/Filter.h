#pragma once
#ifndef FILTER_H
#define FILTER_H
#include "pch.h"
#include <string>
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
class Filter {
private:


public:
	Filter();
	SDL_Surface * Blur(SDL_Surface * surface, int blur_extent);
	SDL_Surface * Invert(SDL_Surface * surface);
};


#endif FILTER_H