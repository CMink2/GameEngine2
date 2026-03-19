// GameEngine.cpp : 애플리케이션의 진입점을 정의합니다.
//
#include "GameEngine.h"
#include <iostream>

void Initialize()
{
	// 게임 엔진 초기화 코드 작성
	std::cout << "Game Engine Initialized." << std::endl;
}

void GameLoop()
{
	// 게임 루프 코드 작성
	bool isRunning = true;
	while(isRunning)
	{
		//입력
		//업데이트
		//랜더링
		//......etc
	}
}

void Shutdown()
{
	// 게임 엔진 종료 코드 작성
	std::cout << "Game Engine Shutdown." << std::endl;
}


int main()
{
	Initialize();
	GameLoop();
	Shutdown();
	return 0;
}
