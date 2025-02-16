#include <vector>

void welcome();
void print_row(std::vector<char> row);
void show_board(std::vector<char> row0, std::vector<char> row1, std::vector<char> row2, std::vector<char> row3);
void toggle_player(bool& P1turn, bool& P2turn, char& letter);
std::string get_answer();
bool is_valid_answer(std::string answer);
void space_marker(char letter, std::string answer, std::vector<char>& row1, std::vector<char>& row2, std::vector<char>& row3);
bool win_condition_met (std::vector<char> row0, std::vector<char> row1, std::vector<char> row2, std::vector<char> row3);
bool is_cats (std::vector<char> row1, std::vector<char> row2, std::vector<char> row3);
bool is_empty_space(std::string answer, std::vector<char>row1, std::vector<char>row2, std::vector<char>row3);