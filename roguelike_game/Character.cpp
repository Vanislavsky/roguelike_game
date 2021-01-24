#include"Character.h"

Point Character::get_position() {
	return position;
}

size_t Character::get_hp() {
	return hp;
}

size_t Character::get_max_hp() {
	return max_hp;
}

size_t Character::get_damage() {
	return damage;
}

char Character::get_symbol() {
	return symbol;
}

void Character::set_hp(size_t _hp) {
	hp = _hp;
}