#pragma once
#ifndef BLUR_H
#define BLUR_H
#include "Filter.h"
class Blur: public Filter {
private:

public:
	Blur() {
		std::cout << "Blur filter created.";
		filterName = "blur";
	}
	SDL_Surface * Process(SDL_Surface * surface, int blur_extent);
	SDL_Surface * Process(SDL_Surface * surface);

};
#endif BLUR_H