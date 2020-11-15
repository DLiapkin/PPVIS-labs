#include "living.cpp"
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <Windows.h>

void show(world w, map m) {
	for (int i = 0; i < m.amount_row; i++) {
		std::cout << "\n";
		for (int j = 0; j < m.amount_column; j++)
		{
			if (is_any_prey(m, i, j)) { std::cout << "2" << " "; }
			else
				std::cout << w[i][j]->who() << " ";
		}
	}
	std::cout << "\n";
}

int main()
{
	int rows = 5, columns = 10;
	std::string s =
	{ '2', '2', '0', '0', '0', '0', '0', '0', '0', '0',
	 '2', '0', '0', '0', '0', '0', '0', '0', '1', '0',
	 '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
	 '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
	 '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
	 '0', '1', '0', '0', '0', '0', '0', '0', '0', '0',
	 '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
	 '0', '0', '0', '0', '0', '0', '1', '0', '0', '0',
	 '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
	 '0', '0', '0', '0', '0', '0', '0', '0', '0', '0' };
	map m(s, rows, columns);
	srand(time(0));
	int automatic_delay;


	show(m.w_plant, m);

	std::string input;

	std::cout << "Chose mode ";
	std::cin >> automatic_delay;
	if (automatic_delay == 1) {
		while (true) {
			std::cin >> input;
			if (input == "q") {
				return 0;
			}
			else {
				system("cls");
				Sleep(automatic_delay);
				next_step(m.w_plant, m);
				show(m.w_plant, m);
			}
		}
	}
	else {
		while (true) {
			Sleep(3000);
			system("cls");
			next_step(m.w_plant, m);
			show(m.w_plant, m);
		}
	}
}
