#include "living.cpp"
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <Windows.h>

void show(world w, map m) {
	for (int i = 0; i < m.amount_row; i++) {
		std::cout << "\n";
		for (int j = 0; j < m.amount_column; j++) {
			if (is_any_predator(m, i, j)) {
				std::cout << "3" << " ";
			}
			else {
				if (is_any_prey(m, i, j)) { std::cout << "2" << " "; }
				else
					std::cout << w[i][j]->who() << " ";
			}
		}
	}
	std::cout << "\n";
}



int main()
{
	upload map_f;
	map_f.get_path();
	map_f.get_content();
	map m(map_f.get_content(), map_f.row_amount, map_f.column_amount);
	
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
