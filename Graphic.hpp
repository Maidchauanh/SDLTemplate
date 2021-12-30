#pragma once 

#include "SDL.h"
#include "glm\vec2.hpp"
#include "glm\mat3x3.hpp"

#include "PriTypes.hpp"

class Graphic {
private:
	SDL_Renderer*  renderer;
public: 

	Graphic(SDL_Renderer*  renderer); 

	void fillRect(int x, int y, int width, int height); 

	void fillRect(glm::vec2 pos, glm::vec2 size); 

	void drawRect(int x, int y, int width, int height, ui32 r, ui32 g, ui32 b, ui32 a = 255); 

	void drawRect(glm::vec2 pos, glm::vec2 size); 
};
