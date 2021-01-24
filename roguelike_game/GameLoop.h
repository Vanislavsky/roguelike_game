#pragma once


#ifndef GAMELOOP_H
#define GAMELOOP_H

#include<conio.h>
#include<vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"Map.h"
#include "Knight.h"
#include "Princess.h"
#include"Wall.h"
#include"Zombie.h"
#include"Dragon.h"
#include"AidKit.h"


class GameLoop {
private:
	Map* map;
	Knight* k;
	Princess* p;
	std::vector<Character*> mobs;
	std::vector<AidKit*> kits;
	static bool game_over;
	static bool game_success;
public:
	GameLoop();

	void read_map();

	void start();

	void end();

	static void set_game_over();
	static void set_game_success();

	bool check_exit(size_t _x, size_t _y);
	bool check_zombie(Character* mob);
	bool check_dragon(Character* mob);

	void input();

	Point random_move(int coord_x, int coord_y);
};

#endif // !GAMELOOP_H
