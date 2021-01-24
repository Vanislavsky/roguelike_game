#pragma once

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include"Character.h"
#include"Knight.h"
#include"Dragon.h"
#include"AidKit.h"
#include"Wall.h"
#include"Princess.h"

class Zombie : public Character {

public:
	Zombie(int _x, int _y, size_t _hp = 2, size_t _max_hp = 2, size_t _damage = 2);

	void set_position(int _x, int _y) override;

	void set_position(Point p) override;

	void collide(Character* mob) override;
	void collide(Knight* mob) override;
	void collide(Princess* mob) override;
	void collide(Dragon* mob) override;
	void collide(Zombie* mob) override;
	void collide(Wall* mob) override;
};

#endif // !KNIGHT_H
