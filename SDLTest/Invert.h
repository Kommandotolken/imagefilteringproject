#pragma once
#ifndef INVERT_H
#define INVERT_H
#include "Filter.H"
class Invert : public Filter {
private:
	
public:
	Invert() {
		std::cout << "Invert filter created.";
		filterName = "invert";
	}
	SDL_Surface * Process(SDL_Surface * surface);
	SDL_Surface * Process(SDL_Surface * surface, int numb);
};
#endif INVERT_H