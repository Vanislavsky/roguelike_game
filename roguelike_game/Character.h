#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

class Knight;
class Princess;
class Dragon;
class Zombie;
class AidKit;
class Wall;

class Point {
private:
	int x;
	int y;

public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	void set_x(int _x) {
		x = _x;
	}

	size_t get_x() {
		return x;
	}

	void set_y(int _y) {
		y = _y;
	}

	size_t get_y() {
		return y;
	}

	void set_point(const Point& point) {
		x = point.x;
		y = point.y;
	}


};

class Character {
protected:
	size_t max_hp;
	size_t hp;
	size_t damage;
	char symbol;
	Point position;

public:

	virtual void set_position(int _x, int _y) = 0;

	virtual void set_position(Point p) = 0;

	Point get_position();

	char get_symbol();

	size_t get_hp();

	size_t get_max_hp();

	size_t get_damage();

	void set_hp(size_t _hp);

	virtual void collide(Character* mob) = 0;
	virtual void collide(Knight* mob) = 0;
	virtual void collide(Princess* mob) = 0;
	virtual void collide(Dragon* mob) = 0;
	virtual void collide(Zombie* mob) = 0;
	virtual void collide(Wall* mob) = 0;
};

#endif // 
