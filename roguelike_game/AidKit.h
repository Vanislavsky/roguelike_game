#pragma once

#ifndef KIT_H
#define KIT_H

#include<conio.h>
#include<vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Character.h"
#include"Knight.h"
#include"Dragon.h"
#include"AidKit.h"
#include"Zombie.h"


class AidKit : public Character {
private:
	size_t helth;
public:
	AidKit(int _x = 1, int _y = 1);

	void set_position(int _x, int _y) override;

	void set_position(Point p) override;

	size_t add_helth(size_t _hp, size_t _max_hp);

	void collide(Character* mob) override;
	void collide(Knight* mob) override;
	void collide(Princess* mob) override;
	void collide(Dragon* mob) override;
	void collide(Zombie* mob) override;
	void collide(Wall* mob) override;

};

#endif // !KNIGHT_H
