#include <string>
#include <fstream>
#include <iostream>
#include <vector>

// 4210191011 Alifian

class GameData {
private:
	std::string data, name, board, mutan, question, endQuestion,close;
	
	std::string fileName, txtData;
	int MAX;
	char temp[1000];

	std::string questionData[5];
	int questionSum;

public:
	GameData();

	void LoadData();

	std::string GetLastGameName();
	int GetLastGameBoard(int dataNumber);
	int GetLastGameMutable(int dataNumber);

	void LoadQuestion();
	int GetQuestion(int questionNumber, int dataNumber);
};
