#include <time.h>
#include <conio.h>
#include "Player.h"
#include "Board.h"
#include "GameData.h"

// 4210191011 Alifian

class GameSudoku {
private:
	Player player;
	Board board;
	GameData data;

	bool mainLoop;
	bool menuLoop;
	bool gameLoop;
	bool gameIsOver;

	int menuValue;

public:
	GameSudoku();

	char GetUserInput();

	void GetPlayerInputName();

	void MainMenu();
	void DrawMenu(int value);

	bool GetLastGameData();
	void GetNewQuestionData();

	void ResumeGame();
	void NewGame();

	void GameManager();
	bool GameInput();

	bool CheckBoardColumn();
	bool CheckBoardRow();
	bool CheckBoardEach3x3();

	void GameOver();

	void Play();
};
