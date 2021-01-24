#include"AidKit.h"

AidKit::AidKit(int _x, int _y) {
	position.set_x(_x);
	position.set_y(_y);;
	symbol = '+';
	damage = 0;
	hp = 0;
	max_hp = 0;
}

void AidKit::set_position(int _x, int _y) {}

void AidKit::set_position(Point p) {}

size_t AidKit::add_helth(size_t _hp, size_t _max_hp) {
	if (_hp + helth > _max_hp)
		return _max_hp;
	return _hp + helth;
}

void AidKit::collide(Character* mob) {
	mob->collide(this);
}

void AidKit::collide(Knight* mob) {
	mob->set_hp(add_helth(mob->get_hp(), mob->get_max_hp()));

}

void AidKit::collide(Princess* mob) {}
void AidKit::collide(Dragon* mob) {}
void AidKit::collide(Zombie* mob) {}
void AidKit::collide(Wall* mob) {}