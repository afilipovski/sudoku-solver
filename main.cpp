#include<iostream>
#include<stack>
#include "Sudoku.h"
int main() {
	Sudoku s1;
	s1.read(std::cin);
	/*
	BACKTRACKING METHOD: This algorithm is based on a (reasonable) use of brute-force. It assigns the first possible option to the empty fields until
	it almost inevitably runs into a violation. It then goes back, looking for other possible options for the previously empty fields until it solves the puzzle.
	Although more time-consuming than the "one possible option" method, it will reliably yield results for all Sudoku puzzles.
	*/
	int k = 1;
	bool is_backtrack = 0;
	int solution_count = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (!s1.puzzle[i][j]) {
				if (!is_backtrack)
					k = 1;
				while (k <= 9) {
					if (s1.is_possible(i, j, k)) {
						s1.puzzle[i][j] = k;
						break;
					}
					++k;
				}
				if (s1.is_solved()) {
					++solution_count;
					std::cout << std::endl;
					s1.print(std::cout) << std::endl;
					s1.puzzle[i][j] = 0;
				}
				if (!s1.puzzle[i][j]) {
					if (!s1.history.empty()) {
						is_backtrack = 1;
						i = s1.history.top().first;
						j = s1.history.top().second;
						s1.history.pop();
						k = s1.puzzle[i][j] + 1;
						s1.puzzle[i][j] = 0;
						--j;
					}
					else {
						std::cout << (solution_count ? "All possible solutions found." : "No solution found.");
						return 0;
					}
				}
				else {
					is_backtrack = 0;
					s1.history.push(std::make_pair(i, j));
				}
			}
		}
	}
}
