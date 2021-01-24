#pragma once

#ifndef DRAGON_H
#define DRAGON_H

#include"Character.h"
#include"Knight.h"
#include"Wall.h"
#include"AidKit.h"
#include"Zombie.h"
#include"Princess.h"


class Dragon : public Character {
public:
	Dragon(size_t _x, size_t _y, size_t _hp = 4, size_t _max_hp = 4, size_t _damage = 5);

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
