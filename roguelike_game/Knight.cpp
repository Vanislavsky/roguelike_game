#include"Knight.h"

Knight::Knight(int _x, int _y, size_t _hp = 5, size_t _max_hp = 5) {
	position.set_x(_x);
	position.set_y(_y);
	symbol = 'K';
	max_hp = _max_hp;
	hp = _hp;
	damage = 0;
}

void Knight::set_position(int _x, int _y) {
	if (_x < 0 || _x >= 20 || _y < 0 || _y >= 20)
		return;
	position.set_x(_x);
	position.set_y(_y);
}

void Knight::collide(Knight*) {}

void Knight::collide(Character* mob) {
	mob->collide(this);
}

void Knight::collide(Princess* mob) {}

void Knight::collide(Dragon* mob) {}

void Knight::collide(Zombie* mob) {}

void Knight::collide(Wall* mob) {}