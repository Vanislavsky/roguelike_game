#include"Zombie.h"

Zombie::Zombie(int _x, int _y, size_t _hp = 2, size_t _max_hp = 2, size_t _damage = 2) {
	position.set_x(_x);
	position.set_y(_y);
	hp = _hp;
	max_hp = _max_hp;
	damage = _damage;
	symbol = 'Z';
}

void Zombie::set_position(int _x, int _y) {
	if (_x < 0 || _x >= 20 || _y < 0 || _y >= 20)
		return;
	position.set_x(_x);
	position.set_y(_y);
}

void Zombie::set_position(Point p) {
	position.set_x(p.get_x());
	position.set_y(p.get_y());
}

void Zombie::collide(Character* mob) {}
void Zombie::collide(Knight* mob) {
	mob->set_hp(mob->get_hp() - damage);
	if (mob->get_hp() <= 0)
		GameLoop::set_game_over();
}
void Zombie::collide(Princess* mob) {}
void Zombie::collide(Dragon* mob) {}
void Zombie::collide(Zombie* mob) {}
void Zombie::collide(Wall* mob) {}