#include "pch.h"
#include "Blur.h"

SDL_Surface * Blur::Process(SDL_Surface * surface) {
	int blur_extent = 1;
	for (int y = 0; y < surface->h; y++)
	{
		for (int x = 0; x < (surface->pitch / 4); x++)
		{
			Uint32 color = ((Uint32*)surface->pixels)[(y * (surface->pitch / 4)) + x];


			Uint8 r = 0, g = 0, b = 0, a = 0;
			SDL_GetRGBA(color, surface->format, &r, &g, &b, &a);

			Uint32 rBlur = 0, gBlur = 0, bBlur = 0, aBlur = 0;



			for (int yo = -blur_extent; yo <= blur_extent; yo++)
			{
				for (int xo = -blur_extent; xo <= blur_extent; xo++) {
					if (y + yo >= 0 && x + xo >= 0
						&& y + yo < surface->h && x + xo < (surface->pitch / 4)
						)
					{
						Uint32 colOth = ((Uint32*)surface->pixels)[((y + yo)
							* (surface->pitch / 4)) + (x + xo)];

						Uint8 ro = 0, go = 0, bo = 0, ao = 0;
						SDL_GetRGBA(colOth, surface->format, &ro, &go, &bo, &ao);

						rBlur += ro;
						gBlur += go;
						bBlur += bo;
						aBlur += ao;
					}
				}
			}



			r = (Uint8)(rBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			g = (Uint8)(gBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			b = (Uint8)(bBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
			a = (Uint8)(aBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));


			color = (r) | (g << 8) | (b << 16) | (a << 24);
			((Uint32*)surface->pixels)[(y * (surface->pitch / 4)) + x] = color;
		}
	}
	return surface;
}
SDL_Surface* Blur::Process(SDL_Surface * surface, int blur_extent) {
	for (int intensity = 0; intensity < 50; intensity++)
	{
		for (int y = 0; y < surface->h; y++)
		{
			for (int x = 0; x < (surface->pitch / 4); x++)
			{
				Uint32 color = ((Uint32*)surface->pixels)[(y * (surface->pitch / 4)) + x];


				Uint8 r = 0, g = 0, b = 0, a = 0;
				SDL_GetRGBA(color, surface->format, &r, &g, &b, &a);

				Uint32 rBlur = 0, gBlur = 0, bBlur = 0, aBlur = 0;



				for (int yo = -blur_extent; yo <= blur_extent; yo++)
				{
					for (int xo = -blur_extent; xo <= blur_extent; xo++) {
						if (y + yo >= 0 && x + xo >= 0
							&& y + yo < surface->h && x + xo < (surface->pitch / 4)
							)
						{
							Uint32 colOth = ((Uint32*)surface->pixels)[((y + yo)
								* (surface->pitch / 4)) + (x + xo)];

							Uint8 ro = 0, go = 0, bo = 0, ao = 0;
							SDL_GetRGBA(colOth, surface->format, &ro, &go, &bo, &ao);

							rBlur += ro;
							gBlur += go;
							bBlur += bo;
							aBlur += ao;
						}
					}
				}



				r = (Uint8)(rBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
				g = (Uint8)(gBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
				b = (Uint8)(bBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));
				a = (Uint8)(aBlur / (((blur_extent * 2) + 1) * ((blur_extent * 2) + 1)));


				color = (r) | (g << 8) | (b << 16) | (a << 24);
				((Uint32*)surface->pixels)[(y * (surface->pitch / 4)) + x] = color;
			}
		}
	}
	return surface;
}