#include "FillCell.h"

// 4210191011 Alifian

FillCell::FillCell(Board& board, int a, int b, int val) {
	theBoard = &board;
	i = a;
	j = b;
	value = val;
}

void FillCell::Execute() {
	undoValue = theBoard->GetBoardData(i, j); theBoard->PushCommandStack(undoValue);
	theBoard->SetBoardData(i, j, value);
}
void FillCell::Undo() {
	theBoard->SetBoardData(i, j, undoValue); theBoard->PushUndoStack(value);
}
void FillCell::Redo() {
	theBoard->SetBoardData(i, j, value); theBoard->PushCommandStack(undoValue);
}
