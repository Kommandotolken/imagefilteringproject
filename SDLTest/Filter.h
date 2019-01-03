#pragma once
#ifndef FILTER_H
#define FILTER_H
#include "pch.h"
#include <string>
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
class Filter {
protected:
	std::string filterName;

public:
	virtual SDL_Surface * Process(SDL_Surface* surface) = 0;
	virtual SDL_Surface * Process(SDL_Surface * surface, int numb) = 0;
	
};


#endif FILTER_H