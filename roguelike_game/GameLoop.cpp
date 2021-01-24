#include "GameLoop.h"
#include <fstream>

bool GameLoop::game_over = false;
bool GameLoop::game_success = false;

GameLoop::GameLoop() {
	map = new Map();

}

void GameLoop::read_map() {
	std::ifstream file("Map.txt");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			char s;
			file >> s;
			switch(s) {
			case 'K':
				k = new Knight(j, i);
				break;
			case 'Z':
				mobs.push_back(new Zombie(j, i));
				break;
			case'D':
				mobs.push_back(new Dragon(j, i));
				break;
			case'P':
				p = new Princess(j, i);
				mobs.push_back(p);
			case '#':
				mobs.push_back(new Wall(j, i));
				break;
			case'+':
				kits.push_back(new AidKit(j, i));
				break;
			}
		}
	}

	for (auto it = mobs.begin(); it != mobs.end(); it++) {
		map->set_mob(*it);
	}

	for (auto it = kits.begin(); it != kits.end(); it++) {
		map->set_mob(*it);
	}

	map->set_mob(k);
	map->set_mob(p);

}

void GameLoop::set_game_over() {
	game_over = true;
}

void GameLoop::set_game_success() {
	game_success = true;
}

void GameLoop::start() {
	while (!game_over && !game_success) {
		Sleep(50);
		std::cout << std::endl << "Helth: " << k->get_hp();
		map->fill();
		input();
	}
	end();
}

void GameLoop::end() {
	system("cls");
	if (game_over) {
		std::cout << "               " << "GAME OVER";
		std::cout << std::endl;
		std::cout << std::endl;
	}

	if (game_success) {
		std::cout << "               " << "GAME SUCCESS";
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

bool GameLoop::check_exit(size_t _x, size_t _y) {
	if (_x < 0 || _x >= map->get_height() || _y < 0 || _y >= map->get_width())
		return false;
	return true;
}

bool GameLoop::check_zombie(Character* mob) {
	Zombie* z = dynamic_cast<Zombie*>(mob);
	if (z == nullptr)
		return false;
	return true;
}
bool GameLoop::check_dragon(Character* mob) {
	Dragon* z = dynamic_cast<Dragon*>(mob);
	if (z == nullptr)
		return false;
	return true;
}

void GameLoop::input() {
	if (_kbhit()) {
		int coord_x = k->get_position().get_x();
		int coord_y = k->get_position().get_y();

		int x_addition = 0;
		int y_addition = 0;

		switch (_getch()) {

		case'a':
			x_addition = -1;
			break;

		case'd':
			x_addition = 1;
			break;

		case'w':
			y_addition = -1;
			break;

		case's':
			y_addition = 1;
			break;
		default:
			break;
		}

		bool check_mob = false;
		for (auto it = mobs.begin(); it != mobs.end(); it++) {
			if ((*it)->get_position().get_x() == coord_x + x_addition && (*it)->get_position().get_y() == coord_y + y_addition) {
				k->collide(*it);
				check_mob = true;
			}
		}

		for (auto it = kits.begin(); it != kits.end(); it++) {
			if ((*it)->get_position().get_x() == coord_x + x_addition && (*it)->get_position().get_y() == coord_y + y_addition) {
				k->collide(*it);
				kits.erase(it);
				break;
			}
		}

		if (check_exit(coord_x + x_addition, coord_y + y_addition) && !check_mob)
			k->set_position(coord_x + x_addition, coord_y + y_addition);

		map->clear_map();
		for (auto it = mobs.begin(); it != mobs.end(); it++) {
			if(check_dragon(*it) || check_zombie(*it))
				(*it)->set_position(random_move((*it)->get_position().get_x(), (*it)->get_position().get_y()));
			map->set_mob(*it);
		}

		for (auto it = kits.begin(); it != kits.end(); it++) {
			map->set_mob(*it);
		}


		map->set_mob(k);
		map->set_mob(p);
	}
}

Point GameLoop::random_move(int coord_x, int coord_y) {
	while (true) {
		int r = rand() % 3;

		int x_addition = 0;
		int y_addition = 0;

		switch (r) {
		case 0:
			x_addition = 1;
			break;

		case 1:
			x_addition = -1;
			break;

		case 2:
			y_addition = 1;
			break;

		case 3:
			y_addition = -1;
			break;
		}
		if (check_exit(coord_x + x_addition, coord_y + y_addition) && !map->check_mob(coord_x + x_addition, coord_y + y_addition))
			return { coord_x + x_addition, coord_y + y_addition };
	}

}