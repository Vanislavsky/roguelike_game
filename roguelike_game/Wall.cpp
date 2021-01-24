#include"Wall.h"

Wall::Wall(int _x, int _y) {
	position.set_x(_x);
	position.set_y(_y);
	symbol = '#';
	damage = 0;
	hp = 0;
	max_hp = 0;
}

void Wall::set_position(int _x, int _y) {}

void Wall::set_position(Point p) {}

void Wall::collide(Character* mob) {
}

void Wall::collide(Knight* mob) {}

void Wall::collide(Princess* mob) {}
void Wall::collide(Dragon* mob) {}
void Wall::collide(Zombie* mob) {}
void Wall::collide(Wall* mob) {}