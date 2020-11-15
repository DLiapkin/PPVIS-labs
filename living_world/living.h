#pragma once
#include <iostream>
#include <vector>
#include <string>

class living;
class map;
class prey;
class plant;
class empty;
class upload;
enum state { EMPTY, PLANT, PREY, PREDATOR, STATES };
typedef living* world[30][30];



class living
{
public:
	virtual state who() = 0;
	virtual living* next(world w) = 0;
	void sums(world w, int sm[]);
	int column, row;
};

class plant : public living
{
public:
	plant(int c, int r);
	state who();
	living* next(world w);
};

class empty : public living
{
public:
	empty(int c, int r);
	state who();
	living* next(world w);
};


class prey : public living
{
public:
	prey(int c, int r);
	int age;
	int hunger;
	prey move(prey a, map& m);
	state who();
	int sex;
	living* next(world w);
};

class map {

public:

	map(std::string s, int row_amount, int column_amount);
	int amount_row;
	int amount_column;
	living* w_plant[30][30];
	std::vector<prey> preys;
};

void eat_plant(world& w, map& m, int i);
void new_prey(map& m);
void next_step(world& w, map& m);
