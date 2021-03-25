#include "GameData.h"

// 4210191011 Alifian

GameData::GameData() {
	data = "<Data>";
	name = "<Name>";
	board = "<Board>";
	mutan = "<Mutable>";
	question = "<Question>";
	endQuestion = "<EndQuestion>";
	close = "<Close>";

	fileName = "Game_Data.txt";
	MAX = 1000;

	questionSum = 5;
}

void GameData::LoadData() {
	// Open 
	std::ifstream file;
	file.open(fileName);
	if (!file) {
		std::cout << "Error In Opening File!!!\n";
		exit(0);
	}

	// Copy
	while (!file.eof()) {
		file.getline(temp, MAX);
		txtData = txtData + temp;
	}

	// Close
	file.close();
}

std::string GameData::GetLastGameName() {
	int findFront = 0, findBack = 0, lenght;
	std::string dataName;

	findFront = txtData.find(name, findFront + 1) + name.size();
	findBack = txtData.find(board, findBack + 1);
	lenght = findBack - findFront;
	dataName = txtData.substr(findFront, lenght);

	return dataName;
}
int GameData::GetLastGameBoard(int dataNumber) {
	int findFront = 0;

	findFront = txtData.find(board, findFront + 1) + 10 + dataNumber;
	int data = stoi(txtData.substr(findFront, 1));

	return data;
}
int GameData::GetLastGameMutable(int dataNumber) {
	int findFront = 0;

	findFront = txtData.find(mutan, findFront + 1) + 10 + dataNumber;
	int data = stoi(txtData.substr(findFront, 1));

	return data;
}

void GameData::LoadQuestion() {
	int findFront = 0, findBack = 0, lenght;

	for (int i = 0; i < questionSum; i++) {
		findFront = txtData.find(question, findFront + 1) + question.size();
		findBack = txtData.find(endQuestion, findBack + 1);
		lenght = findBack - findFront;
		questionData[i] = txtData.substr(findFront, lenght);
	}
}
int GameData::GetQuestion(int questionNumber, int dataNumber) {
	int data = stoi(questionData[questionNumber].substr(dataNumber, 1));
	return data;
}

