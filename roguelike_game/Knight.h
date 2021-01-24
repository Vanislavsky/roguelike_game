#pragma once

#ifndef KNIGHT_H
#define KNIGHT_H

#include"Character.h"
#include"Princess.h"
#include"Dragon.h"
#include"Wall.h"
#include"Zombie.h"
#include"GameLoop.h"

class Knight : public Character {

public:
	Knight(int _x, int _y, size_t _hp = 5, size_t _max_hp = 5);

	void set_position(int _x, int _y) override;

	void set_position(Point p) override {
		position.set_x(p.get_x());
		position.set_y(p.get_y());
	}

	void collide(Knight*) override;

	void collide(Character* mob) override;

	void collide(Princess* mob) override;

	void collide(Dragon* mob) override;

	void collide(Zombie* mob) override;

	void collide(Wall* mob) override;

};

#endif // !KNIGHT_H
