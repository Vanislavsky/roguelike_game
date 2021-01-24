#pragma once

#ifndef WALL_H
#define WALL_H

#include"Character.h"
#include"Knight.h"
#include"Dragon.h"
#include"AidKit.h"
#include"Zombie.h"
#include"Princess.h"

class Wall : public Character {

public:
	Wall(int _x, int _y);

	void set_position(int _x, int _y) override;

	void set_position(Point p) override;

	void collide(Character* mob) override;
	virtual void collide(Knight* mob) override;
	virtual void collide(Princess* mob) override;
	virtual void collide(Dragon* mob) override;
	virtual void collide(Zombie* mob) override;
	virtual void collide(Wall* mob) override;
};

#endif // !KNIGHT_H
