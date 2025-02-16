#include <iostream>
#include <vector>

// welcome screen
void welcome() {

	std::cout << "=======================" << "\n";
	std::cout << "Welcome to Tic-Tac-Toe!" << "\n";
	std::cout << "=======================" << "\n";

	std::cout << "\n\n" << "Ready Player One." << "\n\n";

}

// prints row (used in show_board)
void print_row(std::vector<char> row) {

	for(int i = 0; i < row.size(); i++) {

		std::cout << row[i];

	}

	std::cout << "\n";

}

// prints board
void show_board(std::vector<char> row0, std::vector<char> row1, std::vector<char> row2, std::vector<char> row3) {
	
	print_row(row0);
	print_row(row1);
	print_row(row2);
	print_row(row3);

	std::cout << "\n";

}

// toggles player
void toggle_player(bool& P1turn, bool& P2turn, char& letter) {

	if (P1turn) {

		P1turn = false;
		P2turn = true;
		letter = 'O';
		std::cout << "\nReady player two.\n\n";

	}
	else if (P2turn) {

		P2turn = false;
		P1turn = true;
		letter = 'X';
		std::cout << "\nReady player one.\n\n";

	}

}

// gets answer from player
std::string get_answer() {

	std::string answer;

	std::cout << "Enter your square selection by row and column." << "\n";
	std::cout << "Example 'a0' for top left square." << "\n";
	std::cout << "Square: ";

	std::cin >> answer;

	return answer;


}

// checks answer is valid
bool is_valid_answer(std::string answer) {

	if (answer.size() == 2 && (answer[0] == 'a' || answer[0] == 'b' || answer[0] == 'c') && (answer[1] == '0' || answer[1] == '1' || answer[1] == '2')) {

		return true;

	}
	else {

		return false;

	}

}

bool is_cats (std::vector<char> row1, std::vector<char> row2, std::vector<char> row3) {

	int space_counter = 0;

	for (int i = 0; i < row1.size(); i++) {

		if (row1[i] != '_') {

			space_counter++;

		}
	}

	for (int j = 0; j < row2.size(); j++) {

		if (row2[j] != '_') {

			space_counter++;

		}

	}

	for (int k = 0; k < row3.size(); k++) {

		if (row3[k] != '_') {

			space_counter++;

		}

	}

	if (space_counter++ == 18) {

		return true;

	}
	else {

		return false;

	}

}

// checks destination space is empty
bool is_empty_space(std::string answer, std::vector<char>row1, std::vector<char>row2, std::vector<char>row3) {

	// row1 checks 
	if (answer[0] == 'a') {

		// space a0
		if (answer[1] == '0') {

			if (row1[1] == '_') {

				return true;

			}
			else {

				return false;

			}


		} 
		// space a1
		else if (answer[1] == '1') {

			if (row1[3] == '_') {

				return true;

			}
			else {

				return false;

			}

		}
		// space a2
		else {

			if (row1[5] == '_') {

				return true;

			}
			else {

				return false;

			}

		}

	}
	// row2 checks
	else if (answer[0] == 'b') {

		// space b0
		if (answer[1] == '0') {

			if (row2[1] == '_') {

				return true;

			}
			else {

				return false;

			}


		} 
		// space b1
		else if (answer[1] == '1') {

			if (row2[3] == '_') {

				return true;

			}
			else {

				return false;

			}

		}
		// space b2
		else {

			if (row2[5] == '_') {

				return true;

			}
			else {

				return false;

			}

		}
	}
	// row 3 checks
	else {

		// space c0
		if (answer[1] == '0') {

			if (row3[1] == '_') {

				return true;

			}
			else {

				return false;

			}


		} 
		// space c1
		else if (answer[1] == '1') {

			if (row3[3] == '_') {

				return true;

			}
			else {

				return false;

			}

		}
		// space c2
		else {

			if (row3[5] == '_') {

				return true;

			}
			else {

				return false;

			}

		}

	}

}

void space_marker(char letter, std::string answer, std::vector<char>& row1, std::vector<char>& row2, std::vector<char>& row3) {

	// row 1 placements
	if (answer[0] == 'a') {

		// space a0
		if (answer[1] == '0') {

			row1[1] = letter;


		} 
		// space a1
		else if (answer[1] == '1') {

			row1[3] = letter;

		}
		// space a2
		else {

			row1[5] = letter;

		}

	}
	//row 2 placements
	else if (answer[0] == 'b') {

		// space b0
		if (answer[1] == '0') {

			row2[1] = letter;


		} 
		// space b1
		else if (answer[1] == '1') {

			row2[3] = letter;

		}

		// space b2
		else {

			row2[5] = letter;

		}
	}
	// row 3 placements
	else {

		// space c0
		if (answer[1] == '0') {

			row3[1] = letter;


		} 
		// space c1
		else if (answer[1] == '1') {

			row3[3] = letter;

		}
		// space c2
		else {

			row3[5] = letter;

		}

	}

}

// checks if win conditions met
bool win_condition_met (std::vector<char> row0, std::vector<char> row1, std::vector<char> row2, std::vector<char> row3) {

	// row 1 across
	if(row1[1]!= '_' && row1[1] == row1[3] && row1[1] == row1[5]) {

		return true;

	}
	// row 2 across
	else if (row2[1]!= '_' && row2[1] == row2[3] && row2[1] == row2[5]) {

		return true;

	}
	// row 3 across
	else if (row3[1]!= '_' && row3[1] == row3[3] && row3[1] == row3[5]) {

		return true;

	}
	// column 1 down
	else if (row1[1]!= '_' && row1[1] == row2[1] && row1[1] == row3[1]) {

		return true;
	}
	// column 2 down
	else if (row1[3]!= '_' && row1[3] == row2[3] && row1[3] == row3[3]) {

		return true;

	}
	// column 3 down
	else if (row1[5]!= '_' && row1[5] == row2[5] && row1[5] == row3[5]) {

		return true;

	}
	// LR negative diag
	else if (row1[1]!= '_' && row1[1] == row2[3] && row1[1] == row3[5]) {

		return true;

	}
	// LR positive diag
	else if (row1[5]!= '_' && row1[5] == row2[3] && row1[5] == row3[1]) {

		return true;

	}
	else {

		return false;

	}
}