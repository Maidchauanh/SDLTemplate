#pragma once 

#include<iostream> 
#include "SDL.h"
#include "glm\vec2.hpp"
#include "glm\mat3x3.hpp"
#include "PriTypes.hpp"
#include "Graphic.hpp"


class Game {

public: 
	Game(std::string title, int xpos, int ypos, int width, int height, int flags); 
	~Game(); 

	void run(); 

private: 
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags); 	

	void handleEvents(); 
	void drawRect(int x, int y, int width, int height, ui32 r, ui32 g, ui32 b, ui32 a = 255); 
	// RENDER 
	void render(); 

	void update(); 

	void clean(); 
	bool isRunning(); 

private: 
	SDL_Window* window;
	SDL_Renderer* renderer;
	Graphic *g;
	bool running;

	std::string title;
	int xpos, ypos;
	int width, height; 
	int flags; 
};
