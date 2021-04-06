#include <iostream>
#include <conio.h> 
#include <stdlib.h>
#include <stack>

// 4210191024 Andhika Arista

class Board {
private:
	int boardSize;
	int boardData[10][10];
	bool mutableBoard[10][10]; // mutable = true = 1, immutable = false = 0
	int cursorPosition[2];

	struct TheData {
		int x, y, value;
	};

	std::stack<TheData> undo;
	std::stack<TheData> redo;
public:
	Board();

	int GetBoardSize();

	int GetBoardData(int x, int y);
	void SetBoardData(int x, int y, int value);
	void ResetBoardData();

	bool GetMutableBoard(int x, int y);
	void SetMutableBoard(int x, int y, bool value);

	int GetCursorPosition(int a);
	void SetCursorPosition(int a, int value);
	void ResetCursorPosition();

	void DrawBoard();

	bool CheckBoardColumn();
	bool CheckBoardRow();
	bool CheckBoardEach3x3();

	void PushUndoData(int i, int j, int val);
	void PushRedoData(int i, int j, int val);

	bool PopUndoData();
	bool PopRedoData();

	void ResetUndoData();
	void ResetRedoData();
};
