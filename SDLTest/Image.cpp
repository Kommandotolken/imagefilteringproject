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
	
	imageSurface = IMG_Load(fileName);
	if (!imageSurface)
		std::cout << "Could not load image: " << IMG_GetError();
	return imageSurface;
}

void Image::Invert() {
	

	for (int i = 0; i < imageSurface->h; i++)
	{
		for (int j = 0; j < imageSurface->w; j++)
		{
			Uint32 color = ((Uint32 *)imageSurface->pixels)[(i * (imageSurface->pitch / 4)) + j];
			Uint8 r = 0, g = 0, b = 0, a = 0;
			SDL_GetRGBA(color, imageSurface->format, &r, &g, &b, &a);
			int invertedRed = abs(r - 255);
			int invertedGreen = abs(g - 255);
			int invertedBlue = abs(b - 255);
		    r = invertedRed;
			g = invertedGreen;
			b = invertedBlue;
			color = (r) | (g << 8) | (b << 16) | (a << 24);
			((Uint32*)imageSurface->pixels)[(i * (imageSurface->pitch / 4)) + j] = color;
		}
	}
}

void Image::blur() //This manipulates with SDL_Surface and gives it box blur effect
{
	for (int y = 0; y < imageSurface->h; y++)
	{
		for (int x = 0; x < (imageSurface->pitch / 4); x++)
		{
			Uint32 color = ((Uint32*)imageSurface->pixels)[(y * (imageSurface->pitch / 4)) + x];

			//SDL_GetRGBA() is a method for getting color
			//components from a 32 bit color
			Uint8 r = 0, g = 0, b = 0, a = 0;
			SDL_GetRGBA(color, imageSurface->format, &r, &g, &b, &a);

			Uint32 rb = 0, gb = 0, bb = 0, ab = 0;

			//Within the two for-loops below, colors of adjacent pixels are added up

			for (int yo = -blur_extent; yo <= blur_extent; yo++)
			{
				for (int xo = -blur_extent; xo <= blur_extent; xo++) {
					if (y + yo >= 0 && x + xo >= 0
						&& y + yo < imageSurface->h && x + xo < (imageSurface->pitch / 4)
						)
					{
						Uint32 colOth = ((Uint32*)imageSurface->pixels)[((y + yo)
							* (imageSurface->pitch / 4)) + (x + xo)];

						Uint8 ro = 0, go = 0, bo = 0, ao = 0;
						SDL_GetRGBA(colOth, imageSurface->format, &ro, &go, &bo, &ao);

						rb += ro;
						gb += go;
						bb += bo;
						ab += ao;
					}
				}
			}

			//The sum is then, divided by the total number of
			//pixels present in a block of blur radius

			//For blur_extent 1, it will be 9
			//For blur_extent 2, it will be 25
			//and so on...

			//In this way, we are getting the average of
			//all the pixels in a block of blur radius

			//(((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)) calculates
			//the total number of pixels present in a block of blur radius

			r = (Uint8)(rb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			g = (Uint8)(gb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			b = (Uint8)(bb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			a = (Uint8)(ab / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));

			//Bit shifting color bits to form a 32 bit proper colour
			color = (r) | (g << 8) | (b << 16) | (a << 24);           ((Uint32*)imageSurface->pixels)[(y * (imageSurface->pitch / 4)) + x] = color;
		}
	}


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
void Image::Clear() {
	SDL_FreeSurface(imageSurface);
	SDL_FreeSurface(windowSurface);
	imageSurface = NULL;
	windowSurface = NULL;
}

			
		
		

