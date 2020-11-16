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


class upload
{
public:
	void get_path();
	std::string current_path;
	void check_status();
	int row_amount;
	int column_amount;
	std::string get_content();
};

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

class predator : public living
{
public:
	predator(int c, int r);
	int hunger;
	state who();
	int age;
	int sex;
	living* next(world w);
	predator move(predator a, map& m);
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
	std::vector<predator> predators;
};

void eat_plant(world& w, map& m, int i);
void eat_prey(world& w, map& m, int c);
void new_prey(map& m);
bool is_any_prey(map m, int x, int y);
bool is_any_predator(map m, int x, int y);
void new_predator(map& m);
void next_step(world& w, map& m);
