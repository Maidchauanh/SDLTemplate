#include "Game.hpp"

// RENDER 
void Game::render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer); // clear the renderer to 

	g->drawRect(50, 50, 50, 50, 100, 200, 100);

	SDL_RenderPresent(renderer); // draw to the screen
}

void Game::update() {
	// TODOOOOO: implement zooming and panning, panning first and then zooming using matrices 
}

Game::Game(std::string title, int xpos, int ypos, int width, int height, int flags) {
	this->title = title;
	this->xpos = xpos;
	this->ypos = ypos;
	this->width = width;
	this->height = height;
	this->flags = flags;
}

Game::~Game() {
	delete g;
}

void Game::run() {
	init(title.c_str(), xpos, ypos, width, height, flags);
	g = new Graphic(renderer);

	while (isRunning())
	{
		handleEvents();
		update();
		render();
	}
	clean();
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		window = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);

		if (window != 0) // window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);

			if (renderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	std::cout << "init success\n";
	running = true; // everything inited successfully, 
	return true;
}	

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;

		default:
			break;
		}
	}
}


void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	exit(0);
}

bool Game::isRunning() {
	return this->running;
}

