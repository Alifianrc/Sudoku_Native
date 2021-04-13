#pragma once
#include "Board.h"
#include "Command.h"

// 4210191011 Alifian

class FillCell : public Command{
private:
	int i, j, value, undoValue;
	Board* theBoard;

public:
	FillCell() = default;
	FillCell(Board &board, int a, int b, int val);

	void Execute();
	void Undo();
	void Redo();
};
