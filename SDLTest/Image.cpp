#include "pch.h"
#include "Image.h"


bool Image::Initialize() {

	

	SDL_Init(SDL_INIT_EVERYTHING);

	Window = SDL_CreateWindow("SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		window_width, window_height, 0);
	if (NULL == Window) //Check if Window is NULL.
	{
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;
		return 0;
	}
	else
	{
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			std::cout << "SDL_image could not initialize! Error: " << IMG_GetError();
			return 0;
		}
		else
		{
			windowSurface = SDL_GetWindowSurface(Window);
		}
		return 1;
	}
}

SDL_Surface* Image::loadImage(char* fileName)
{
	
	imageSurface= IMG_Load(fileName);
	if (!imageSurface)
		std::cout << "Could not load image: " << IMG_GetError();
	return imageSurface;
}


void Image::Save()
{
	IMG_SavePNG(imageSurface, outputName.c_str());
}
void Image::displayImage() {

	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (SDL_QUIT == windowEvent.type)
			{
				break;
			}
		}
		SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);

		SDL_UpdateWindowSurface(Window);
		
	}

	}

void Image::applyFilter(std::string filterName) {
	if (filterName == "invert")
	{
		filter = new Invert;
		filter->Process(imageSurface);

	}
	else if (filterName == "blur")
	{
		filter = new Blur;
		filter->Process(imageSurface, blur_extent);
	}

	
}
void Image::Clear() {
	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(windowSurface);
	imageSurface = NULL;
	windowSurface = NULL;
}

			
		
		

