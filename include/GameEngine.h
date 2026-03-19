// GameEngine.h: 표준 시스템 포함 파일
#pragma once

#include <iostream>
#include <SDL2/SDL.h>

// when you need to reference additional headers, you can add them here
// 예: #include "MyHeader.h"
#ifdef GAMEENGINE_H
#define GAMEENGINE_H

// 게임엔진 클래스

class GameEngine
{
public:
	GameEngine() {};
	~GameEngine() {};
	void Initialize();
	void GameLoop();
	void Shutdown();
	 
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
};



#endif // GAMEENGINE_H


