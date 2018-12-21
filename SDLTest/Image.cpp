#include "pch.h"
#include "Image.h"
	bool Image::Initialize() {
		//SDL_Event event;
		SDL_Surface *windowSurface = NULL;
		SDL_Surface *imageSurface = NULL;

		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_Window * Window = SDL_CreateWindow("SDL WINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			640, 900, 0);
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

		}



		

		
	
	

		SDL_Event windowEvent;

		imageSurface = SDL_LoadBMP("MARBLES.BMP");
	
		if (NULL == imageSurface) //Check if imageSurface is NULL.
			{
			std::cout << "Could not create surface: " << SDL_GetError() << std::endl;
			return 1;
			}
			
		
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
			SDL_FreeSurface(imageSurface);
			SDL_FreeSurface(windowSurface);
			imageSurface = NULL;
			windowSurface = NULL;
		}
		return 1;
	}
	

