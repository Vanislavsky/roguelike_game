#pragma once


#ifndef MAP_H
#define MAP_H

#include<iostream>
#include"windows.h"

class Knight;
class Character;

class Map {
private:
	size_t height;
	size_t width;
	char** map;

public:
	Map(size_t _height = 20, size_t _width = 20);

	~Map();

	size_t get_height();

	size_t get_width();

	void fill();

	void clear_map();

	void set_mob(Character* mob);

	char get_map_info(size_t x, size_t y);

	bool check_mob(size_t x, size_t y);
};

#endif // !1
