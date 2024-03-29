//*******************************//
//
// Name:			Texture.h
// Description:		Draw to the window (screen)				
//					OpenGL and DirectX will be implemented later....
//
// Author:			Edwin Chen
// Created:			Feb 17, 2016
// Last updated:	Mar 30, 2016
//
//*******************************//

#ifndef _TEXTURE_H
#define _TEXTURE_H

#ifndef _WINDOW
	#include "Window.h"
#endif

#ifndef _IOSTREAM
	#include <iostream>
#endif

#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Texture {
	struct DrawParams {
		int x;
		int y;
		float scale;
		SDL_Rect*clip;
		double angle;
		SDL_Point* center;
		SDL_RendererFlip flip;
	};
public:
	explicit Texture(SDL_Renderer* Renderer);
	~Texture();

	Texture(const Texture&) = delete;
	Texture(Texture&&) = delete;
	Texture& operator = (const Texture&) = delete;
	Texture& operator = (Texture&&) = delete;

	bool ImgLoad(const std::string& fileName);
	void SetTexture(SDL_Texture& SDLTexture_, const int width_, const int height_);
	void Destroy();

	void Draw(const DrawParams& params) const;
	void Draw(const int x = 0, const int y = 0, const float scale = 1, SDL_Rect* clip = nullptr,
		const double angle = 0, SDL_Point* center = nullptr,
		const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;

	void SetAlpha(const Uint8 a);
	void SetBlendMode(const SDL_BlendMode blendMode_);
	void SetColor(const SDL_Color& color_);
	void SetColor(const Uint8 r, const Uint8 g_, const Uint8 b_, const Uint8 a_);
	int  GetWidth() const;
	int  GetHeight() const;
private:
	SDL_Texture* SDLTexture;
	SDL_Renderer* SDLRenderer;
	int width;
	int height;
};


#endif