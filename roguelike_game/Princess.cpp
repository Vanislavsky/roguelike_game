#include"Princess.h"

Princess::Princess(int _x, int _y) {
	position.set_x(_x);
	position.set_y(_y);
	symbol = 'P';
	hp = 0;
	max_hp = 0;
	damage = 0;
}

void Princess::set_position(int _x, int _y) {}

void Princess::set_position(Point p) {}

void Princess::collide(Character* mob) {
	mob->collide(this);
}

void Princess::collide(Knight* mob) {
	GameLoop::set_game_success();
}

void Princess::collide(Princess* mob) {}
void Princess::collide(Dragon* mob) {}
void Princess::collide(Zombie* mob) {}
void Princess::collide(Wall* mob) {}