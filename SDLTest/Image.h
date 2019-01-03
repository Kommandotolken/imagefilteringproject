#pragma once
#ifndef IMAGE_H
#define IMAGE_H
#include "pch.h"
#include <string>
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "Filter.h"
#include "Blur.h"
#include "Invert.h"
class Image {
private:
	int window_width = 800;
	int window_height = 600;
	int blur_extent = 1;
	std::string outputName = "outputFile.png";
	std::string filterName = "";
	Filter* filter;
	SDL_Event windowEvent;

	SDL_Surface *windowSurface = NULL;
	SDL_Surface *imageSurface = NULL;
	SDL_Window * Window;

	
	
public:
	~Image() {
		delete filter;
	}
	bool Initialize();
	void applyFilter(std::string filterName);
	void displayImage();
	SDL_Surface* loadImage(char* fileName);
	void Save();
	void Clear();
};
#endif IMAGE_H