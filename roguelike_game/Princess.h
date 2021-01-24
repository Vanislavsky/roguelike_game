#pragma once

#ifndef PRINCESS_H
#define PRINCESS_H

#include"Character.h"
#include"Knight.h"
#include"Dragon.h"
#include"AidKit.h"

class Princess : public Character {

public:
	Princess(int _x, int _y);

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