#include "Player.h"

// 4210191024 Andhika

std::string Player::GetName() {
	return name;
}
void Player::SetPlayerName(std::string nam) {
	name = nam;
}

int Player::GetScore() {
	return score;
}
void Player::SetScore(int value) {
	score = value;
}