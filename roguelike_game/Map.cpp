#include "Map.h"
#include "Character.h"

Map::Map(size_t _height, size_t _width) {
	height = _height;
	width = _width;
	map = new char* [width];
	for (int i = 0; i < width; i++) {
		map[i] = new char[height];
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map[i][j] = '.';
		}
	}
}

Map::~Map() {
	for (int i = 0; i < width; i++) {
		delete map[i];
	}

	delete[] map;
}

size_t Map::get_height() {
	return height;
}

size_t Map::get_width() {
	return width;
}

void Map::fill() {
	system("cls");
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::clear_map() {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map[i][j] = '.';
		}
	}
}

void Map::set_mob(Character* mob) {
	map[mob->get_position().get_y()][mob->get_position().get_x()] = mob->get_symbol();
}

char Map::get_map_info(size_t x, size_t y) {
	return map[y][x];
}

bool Map::check_mob(size_t x, size_t y) {
	return map[y][x] != '.';
}