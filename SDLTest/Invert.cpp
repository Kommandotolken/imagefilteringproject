#include "pch.h"
#include "Invert.h"
SDL_Surface * Invert::Process(SDL_Surface * surface, int numb) {
	std::cout << "You do not need to enter a number";
	return surface;
}
SDL_Surface * Invert::Process(SDL_Surface * surface) {
	{

		for (int i = 0; i < surface->h; i++)
		{
			for (int j = 0; j < surface->w; j++)
			{
				Uint32 color = ((Uint32 *)surface->pixels)[(i * (surface->pitch / 4)) + j];
				Uint8 r = 0, g = 0, b = 0, a = 0;
				SDL_GetRGBA(color, surface->format, &r, &g, &b, &a);
				int invertedRed = abs(r - 255);
				int invertedGreen = abs(g - 255);
				int invertedBlue = abs(b - 255);
				r = invertedRed;
				g = invertedGreen;
				b = invertedBlue;
				color = (r) | (g << 8) | (b << 16) | (a << 24);
				((Uint32*)surface->pixels)[(i * (surface->pitch / 4)) + j] = color;
			}
		}
		return surface;

	}
}