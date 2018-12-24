#include "pch.h"
#include "Filter.h"
Filter::Filter() {
	std::cout << "Filter created";
}
SDL_Surface * Filter::Blur(SDL_Surface * surf, int blur_extent) {

	for (int y = 0; y < surf->h; y++)
	{
		for (int x = 0; x < (surf->pitch / 4); x++)
		{
			Uint32 color = ((Uint32*)surf->pixels)[(y * (surf->pitch / 4)) + x];


			Uint8 r = 0, g = 0, b = 0, a = 0;
			SDL_GetRGBA(color, surf->format, &r, &g, &b, &a);

			Uint32 rb = 0, gb = 0, bb = 0, ab = 0;



			for (int yo = -blur_extent; yo <= blur_extent; yo++)
			{
				for (int xo = -blur_extent; xo <= blur_extent; xo++) {
					if (y + yo >= 0 && x + xo >= 0
						&& y + yo < surf->h && x + xo < (surf->pitch / 4)
						)
					{
						Uint32 colOth = ((Uint32*)surf->pixels)[((y + yo)
							* (surf->pitch / 4)) + (x + xo)];

						Uint8 ro = 0, go = 0, bo = 0, ao = 0;
						SDL_GetRGBA(colOth, surf->format, &ro, &go, &bo, &ao);

						rb += ro;
						gb += go;
						bb += bo;
						ab += ao;
					}
				}
			}



			r = (Uint8)(rb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			g = (Uint8)(gb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			b = (Uint8)(bb / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			a = (Uint8)(ab / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));


			color = (r) | (g << 8) | (b << 16) | (a << 24);           
			((Uint32*)surf->pixels)[(y * (surf->pitch / 4)) + x] = color;
		}
	}
	return surf;
}

SDL_Surface * Filter::Invert(SDL_Surface * surf) {

	for (int i = 0; i < surf->h; i++)
	{
		for (int j = 0; j < surf->w; j++)
		{
			Uint32 color = ((Uint32 *)surf->pixels)[(i * (surf->pitch / 4)) + j];
			Uint8 r = 0, g = 0, b = 0, a = 0;
			SDL_GetRGBA(color, surf->format, &r, &g, &b, &a);
			int invertedRed = abs(r - 255);
			int invertedGreen = abs(g - 255);
			int invertedBlue = abs(b - 255);
		    r = invertedRed;
			g = invertedGreen;
			b = invertedBlue;
			color = (r) | (g << 8) | (b << 16) | (a << 24);
			((Uint32*)surf->pixels)[(i * (surf->pitch / 4)) + j] = color;
		}
	}
	return surf;

}