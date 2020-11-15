#include "living.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <fstream>


void living::sums(world w, int sm[]) {
	int i, j;
	sm[PLANT] = sm[PREY] = sm[PREDATOR] = sm[EMPTY] = 0;


	if (row == 0 && column == 0) {
		for (i = 0; i <= 1; i++) {
			for (j = 0; j <= 1; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row == 0 && column == 29) {
		for (i = 0; i <= 1; i++) {
			for (j = -1; j <= 0; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row == 29 && column == 29) {
		for (i = -1; i <= 0; i++) {
			for (j = -1; j <= 0; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row == 29 && column == 0) {
		for (i = -1; i <= 0; i++) {
			for (j = 0; j <= 1; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row == 0 && column != 0 && column != 29) {
		for (i = 0; i <= 1; i++) {
			for (j = -1; j <= 1; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row != 0 && column == 0 && row != 29) {
		for (i = -1; i <= 1; i++) {
			for (j = 0; j <= 1; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row == 29 && column != 0 && column != 29) {
		for (i = -1; i <= 0; i++) {
			for (j = -1; j <= 1; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row != 0 && column == 29 && row != 29) {
		for (i = -1; i <= 1; i++) {
			for (j = -1; j <= 0; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}

	if (row > 0 && row < 29 && column < 29 && column>0) {
		for (i = -1; i <= 1; i++) {
			for (j = -1; j <= 1; j++) {
				sm[w[row + i][column + j]->who()]++;
			}
		}
	}
}

state plant::who() {
	return PLANT;
}

plant::plant(int c, int r) {
	column = c;
	row = r;
}

empty::empty(int c, int r) {
	column = c;
	row = r;
}

prey::prey(int c, int r) {
	column = c;
	row = r;
	hunger = 6;
	age = 10;
	sex = rand() % 2;
}

state empty::who() {
	return EMPTY;
}

living* empty::next(world w) {
	int sum[STATES];
	sums(w, sum);
	if (sum[PLANT] >= 1 && (rand() % 2 == 1)) return(new plant(column, row)); else return(new empty(column, row));
}

living* plant::next(world w) {
	return(new plant(column, row));
}

living* prey::next(world w) {
	return(new empty(column, row));
}

state prey::who() {
	return PREY;
}

map::map(std::string s, int row_amount, int column_amount) {
	char buff = 0;
	int k = 0;
	amount_row = row_amount;
	amount_column = column_amount;

	int i = 0; int j = 0;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			w_plant[i][j] = new empty(j, i);


	while (i < row_amount) {
		buff = s[k];
		k++;
		if (buff == '0') {
			w_plant[i][j] = new empty(j, i); 
			j++;
		}
		if (buff == '1') {
			w_plant[i][j] = new plant(j, i); 
			j++;
		}
		if (buff == '2') {
			preys.push_back(prey(j, i));
			w_plant[i][j] = new empty(j, i);
			j++;
		}
		if (j >= column_amount) { j = 0; i++; }
	}
}

prey prey::move(prey a, map& m) {
	bool alredy_move = 0;

	if (a.row == 0 && a.column == 0 && alredy_move == 0) {
		a.row += rand() % 2;
		a.column += rand() % 2;
		alredy_move = 1;
	}

	if (a.row == 0 && a.column == m.amount_column - 1 && alredy_move == 0) {
		a.row += rand() % 2;
		a.column -= rand() % 2;
		alredy_move = 1;
	}

	if (a.row == m.amount_row - 1 && a.column == m.amount_column - 1 && alredy_move == 0) {
		a.row -= rand() % 2;
		a.column -= rand() % 2;
		alredy_move = 1;
	}

	if (a.row == m.amount_row - 1 && a.column == 0 && alredy_move == 0) {
		a.row -= rand() % 2;
		a.column += rand() % 2;
		alredy_move = 1;
	}

	if (a.row == 0 && a.column != 0 && a.column != m.amount_column - 1 && alredy_move == 0) {
		a.row += rand() % 2;
		a.column += rand() % 3 - 1;
		alredy_move = 1;
	}

	if (a.row != 0 && a.column == 0 && a.row != m.amount_row - 1 && alredy_move == 0) {
		a.row += rand() % 3 - 1;
		a.column += rand() % 2;
		alredy_move = 1;
	}

	if (a.row == m.amount_row - 1 && a.column != 0 && a.column != m.amount_column - 1 && alredy_move == 0) {
		a.row -= rand() % 2;
		a.column += rand() % 3 - 1;
		alredy_move = 1;
	}

	if (a.row != 0 && a.column == m.amount_column - 1 && a.row != m.amount_row - 1 && alredy_move == 0) {
		a.row += rand() % 3 - 1;
		a.column -= rand() % 2;
		alredy_move = 1;
	}

	if (a.row > 0 && a.row < m.amount_row - 1 && a.column < m.amount_column - 1 && a.column>0 && alredy_move == 0) {
		a.row += rand() % 3 - 1;
		a.column += rand() % 3 - 1;
		alredy_move = 1;
	}

	return a;
}

void eat_plant(world& w, map& m, int i) {
	if (w[m.preys[i].column][m.preys[i].row]->who() == 1) {
		w[m.preys[i].column][m.preys[i].row] = new empty(m.preys[i].column, m.preys[i].row);
		if (m.preys[i].hunger < 6) m.preys[i].hunger++;
	}
	if (m.preys[i].column < m.amount_column - 1) {
		if (w[m.preys[i].column + 1][m.preys[i].row]->who() == 1) {
			w[m.preys[i].column + 1][m.preys[i].row] = new empty(m.preys[i].column + 1, m.preys[i].row);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
	if (m.preys[i].column > 0) {
		if (w[m.preys[i].column - 1][m.preys[i].row]->who() == 1) {
			w[m.preys[i].column - 1][m.preys[i].row] = new empty(m.preys[i].column - 1, m.preys[i].row);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
	if (m.preys[i].row > 0) {
		if (w[m.preys[i].column][m.preys[i].row - 1]->who() == 1) {
			w[m.preys[i].column][m.preys[i].row - 1] = new empty(m.preys[i].column, m.preys[i].row - 1);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
	if (m.preys[i].row < m.amount_row - 1) {
		if (w[m.preys[i].column][m.preys[i].row + 1]->who() == 1) {
			w[m.preys[i].column][m.preys[i].row + 1] = new empty(m.preys[i].column, m.preys[i].row + 1);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
	if (m.preys[i].column < m.amount_column - 1 && m.preys[i].row < m.amount_row - 1) {
		if (w[m.preys[i].column + 1][m.preys[i].row + 1]->who() == 1) {
			w[m.preys[i].column + 1][m.preys[i].row + 1] = new empty(m.preys[i].column + 1, m.preys[i].row + 1);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
	if (m.preys[i].column > 0 && m.preys[i].row > 0) {
		if (w[m.preys[i].column - 1][m.preys[i].row - 1]->who() == 1) {
			w[m.preys[i].column - 1][m.preys[i].row - 1] = new empty(m.preys[i].column - 1, m.preys[i].row - 1);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
	if (m.preys[i].column > 0 && m.preys[i].row < m.amount_row - 1) {
		if (w[m.preys[i].column - 1][m.preys[i].row + 1]->who() == 1) {
			w[m.preys[i].column - 1][m.preys[i].row + 1] = new empty(m.preys[i].column - 1, m.preys[i].row + 1);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
	if (m.preys[i].column < m.amount_column - 1 && m.preys[i].row > 0) {
		if (w[m.preys[i].column + 1][m.preys[i].row - 1]->who() == 1) {
			w[m.preys[i].column + 1][m.preys[i].row - 1] = new empty(m.preys[i].column + 1, m.preys[i].row);
			if (m.preys[i].hunger < 6) m.preys[i].hunger++;
		}
	}
}

void new_prey(map& m) {
	if (m.preys.size()) {
		for (int i = 0; i < m.preys.size() - 1; i++)
			if (m.preys[i].column == m.preys[i + 1].column
				&& m.preys[i].row == m.preys[i + 1].row
				&& m.preys[i].hunger >= 3
				&& m.preys[i].sex != m.preys[i + 1].sex) m.preys.push_back(prey(m.preys[i].column, m.preys[i].row));
	}
};

bool is_any_prey(map m, int x, int y) {
	for (int i = 0; i < m.preys.size(); i++)
	{
		if (m.preys[i].column == y && m.preys[i].row == x)
		{
			return true;
		}
	}
	return false;
}

void next_step(world& w, map& m) {
	world w1;
	bool alredy_move = 0;

	for (int i = 0; i < m.amount_row; i++) {
		for (int j = 0; j < m.amount_column; j++) {
			if (w[i][j]->who() == 0)
				w1[i][j] = w[i][j]->next(w);
			else w1[i][j] = w[i][j];
		}
	}

	for (int i = 0; i < m.amount_row; i++) {
		for (int j = 0; j < m.amount_column; j++)
			w[i][j] = w1[i][j];
	}

	for (int i = 0; i < m.amount_row; i++) {
		for (int j = 0; j < m.amount_column; j++) {
			if (w[i][j]->who() == 1)
				w1[i][j] = w[i][j]->next(w);
			else w1[i][j] = w[i][j];
		}
	}

	for (int i = 0; i < m.amount_row; i++) {
		for (int j = 0; j < m.amount_column; j++)
			w[i][j] = w1[i][j];
	}


	if (m.preys.size()) {
		for (int i = 0; i < m.preys.size(); i++)
		{
			m.preys[i] = m.preys[i].move(m.preys[i], m);
			m.preys[i].age--;
			m.preys[i].hunger--;
			eat_plant(w, m, i);
		}

		new_prey(m);
	}

	std::cout << "-------------PREYS--------------------\n";

	for (int i = 0; i < m.preys.size(); i++) {
		std::cout << m.preys[i].age << "age left ";
		std::cout << m.preys[i].hunger << "hunger left ";
		std::cout << m.preys[i].sex << "sex ";
		std::cout << m.preys[i].row << " " << m.preys[i].column;
		std::cout << "\n";
		if (m.preys[i].age <= 0 || m.preys[i].hunger <= 0) m.preys.erase(m.preys.begin() + i);
	}

	std::cout << "--------------------------------------\n";
}
