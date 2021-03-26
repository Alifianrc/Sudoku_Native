#include "Board.h"

// 4210191011 Alifian

Board::Board() {
	boardSize = 9;
	ResetBoardData();
	ResetCursorPosition();
}

int Board::GetBoardSize() {
	return boardSize;
}

int Board::GetBoardData(int x, int y) {
	return boardData[x][y];
}
void Board::SetBoardData(int x, int y, int value) {
	boardData[x][y] = value;
}
void Board::ResetBoardData() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			boardData[i][j] = 0;
		}
	}
}

bool Board::GetMutableBoard(int x, int y) {
	return mutableBoard[x][y];
}
void Board::SetMutableBoard(int x, int y, bool value) {
	mutableBoard[x][y] = value;
}

int Board::GetCursorPosition(int a) {
	return cursorPosition[a];
}
void Board::SetCursorPosition(int a, int value) {
	cursorPosition[a] = value;
}
void Board::ResetCursorPosition() {
	cursorPosition[0] = 0;
	cursorPosition[1] = 0;
}

void Board::DrawBoard() {
	system("cls");
	
	// Margin Top
	std::cout << "\n\n";

	for (int i = 0; i < boardSize; i++) {
		// Margin Left
		std::cout << "     ";

		if (i % 3 == 0 && i != 0) {
			std::cout << " #";
			for (int j = 0; j < boardSize; j++) {
				std::cout << "####";
			}
			std::cout << "\n";
			std::cout << "     ";
		}

		// Number
		for (int j = 0; j < boardSize; j++) {
			
			// Dividers between boxes
			if (j % 3 == 0 && j != 0) {
				std::cout << " # ";
			}
			else {
				std::cout << " | ";
			}
			
			// Box contain
			if (boardData[i][j] == 0) {
				std::cout << " ";
			}
			else {
				std::cout << boardData[i][j];
			}
		} 
		// Close Box 
		std::cout << " | ";

		// For User Interface ( right side of the screen )
		if (i == 1) {
			std::cout << "           Press p to exit";
		}

		// Next Line
		std::cout << std::endl;

		// Margin Left
		std::cout << "     ";

		// Cursor
		for (int j = 0; j < boardSize; j++) {

			// Dividers between boxes
			if (j % 3 == 0 && j != 0) {
				std::cout << " # ";
			}
			else {
				std::cout << "   ";
			}

			// The Cursor
			if (cursorPosition[0] == i && cursorPosition[1] == j) {
				std::cout << "^";
			}
			else {
				std::cout << " ";
			}
		}

		// Next Line
		std::cout << std::endl;
	}
}