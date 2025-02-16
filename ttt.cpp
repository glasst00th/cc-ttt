#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

int main() {

// vectors to contain tic-tac-toe board
	std::vector<char> row0 = {' ', '0', ' ', '1', ' ', '2'};
	std::vector<char> row1 = {'a', '_', '|', '_', '|', '_'};
	std::vector<char> row2 = {'b', '_', '|', '_', '|', '_'};
	std::vector<char> row3 = {'c', '_', '|', '_', '|', '_'};

// bool party
	bool game_won = false;
	bool answer_valid = false;
	bool space_empty = false;
	bool P1turn = false;
	bool P2turn = true;
	bool cats_game = false;
	char letter = 'X';

	std::string answer;

// begin
	welcome();

	show_board(row0, row1, row2, row3);

	while(!game_won && !cats_game) {

		toggle_player(P1turn, P2turn, letter);
		
		// gets answer and checks valid + space empty
		answer = get_answer();
		answer_valid = is_valid_answer(answer);
		space_empty = is_empty_space(answer, row1, row2, row3);

		// suspends play until valid + empty answer
		while (!answer_valid || !space_empty) {

			if (!answer_valid) {

				std::cout << "\n\n" << "'" << answer << "'" << " is invalid. Try again." << "\n\n";
				answer = get_answer();
				answer_valid = is_valid_answer(answer);

			}
			else if (!space_empty) {

				std::cout << "\n\n" << "Destination occupied. Try again." << "\n\n";
				answer = get_answer();
				space_empty = is_empty_space(answer, row1, row2, row3);

			}

		}

		// mark space, show board, check if won
		space_marker(letter, answer, row1, row2, row3);
		std::cout << "\n";
		show_board(row0, row1, row2, row3);
		game_won = win_condition_met(row0, row1, row2, row3);
		cats_game = is_cats(row1, row2, row3);

	}


	if (cats_game && !game_won) {

		std::cout << "\n\n" << "Cat's Game! Everyone loses (or wins, depending on your general outlook on life)!";
		return 0;
	}

	else if (P1turn) {

		std::cout << "\n\n" << "Game over. Player one wins!";
		return 0;

	}
	else if (P2turn) {

		std::cout << "\n\n" << "Game over. Player two wins!";
		return 0;
		
	}



}