#include "Graphic.hpp"

Graphic::Graphic(SDL_Renderer*  renderer) {
	this->renderer = renderer;
}

void Graphic::fillRect(int x, int y, int width, int height) {

}

void Graphic::fillRect(glm::vec2 pos, glm::vec2 size) {
	
}

void Graphic::drawRect(int x, int y, int width, int height, ui32 r, ui32 g, ui32 b, ui32 a) {
	SDL_Rect rect = { x, y, width, height };
	SDL_SetRenderDrawColor(this->renderer, r, b, g, a); 
	SDL_RenderFillRect(this->renderer, &rect); 
}

void Graphic::drawRect(glm::vec2 pos, glm::vec2 size) {
	
}

