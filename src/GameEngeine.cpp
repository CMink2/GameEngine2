#include "GameEngine.h"

// 게임 엔진 초기화
GameEngine::GameEngine()
{
	window = nullptr;
	renderer = nullptr;
	isRunning = false;
}

GameEngine::~GameEngine()
{
	ShutDown();
}

GameEngine::Initialize()
{	
	// SDL 초기화
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// SDL 비디오 시스템 초기화 실패
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}
	window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		// 창 생성 실패
		std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		// 렌더러 생성 실패
		std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}
	isRunning = true;
	std::cout << "Game Engine Initialized." << std::endl;
}

// 게임 루프
GameEngine::void GameLoop()
{
	// 게임 루프 코드 작성
	while (isRunning)
	{
		//sdl 이벤트 처리
		SDL_Event event;
		// 이벤트 큐에서 이벤트를 처리 (이벤트 있는지 유무 반환 중임)
		while (SDL_PollEvent(&event) != 0)
		{
			// 종료 이벤트 처리
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
			}
		}
		// 업데이트 (랜더링 될 Context R,G,B Alpha값 입력)
		// 배경색을 흰색으로 설정하고 화면을 지웁니다.
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		// 화면을 지웁니다.
		SDL_RenderClear(renderer);
		// 여기서 게임 오브젝트를 업데이트하고 렌더링하는 코드를 추가할 수 있습니다.
		SDL_RenderPresent(renderer);
	}
}

GameEngine::void ShutDown()
{
	// SDL 리소스 해제
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
		renderer = nullptr;
	}
	//window 리소스 해제
	if (window != nullptr)
	{
		SDL_DestroyWindow(window);
		window = nullptr;
	}
	SDL_Quit();
	std::cout << "Game Engine Shutdown." << std::endl;
}

