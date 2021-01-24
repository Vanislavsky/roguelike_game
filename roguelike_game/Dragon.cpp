#include"Dragon.h"

Dragon::Dragon(size_t _x, size_t _y, size_t _hp = 4, size_t _max_hp = 4, size_t _damage = 5) {
	position.set_x(_x);
	position.set_y(_y);
	max_hp = 4;
	hp = 4;
	damage = 5;
	symbol = 'D';
}

void Dragon::set_position(int _x, int _y) {
	if (_x < 0 || _x >= 20 || _y < 0 || _y >= 20)
		return;
	position.set_x(_x);
	position.set_y(_y);
}

void Dragon::set_position(Point p) {
	position.set_x(p.get_x());
	position.set_y(p.get_y());
}


void Dragon::collide(Character* mob) {}
void Dragon::collide(Knight* mob) {
	mob->set_hp(mob->get_hp() - damage);
	if (mob->get_hp() <= 0)
		GameLoop::set_game_over();

}
void Dragon::collide(Princess* mob) {}
void Dragon::collide(Dragon* mob) {}
void Dragon::collide(Zombie* mob) {}
void Dragon::collide(Wall* mob) {}