#pragma once
struct Sudoku {
	bool is_possible(int row, int column, int value) {
		int block_row = row / 3;
		int block_column = column / 3;
		for (int i = 0; i < 9; i++) {
			if (i != column && puzzle[row][i] == value)
				return 0;
			if (i != row && puzzle[i][column] == value)
				return 0;
			int i_row = i / 3 + block_row * 3;
			int i_column = i % 3 + block_column * 3;
			if ((i_row != row || i_column != column) && puzzle[i_row][i_column] == value)
				return 0;
		}
		return 1;
	}
	std::ostream& print(std::ostream& os) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				os << puzzle[i][j];
			}
			os << std::endl;
		}
		return os;
	}
	std::istream& read(std::istream& is) {
		char input;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				is >> input;
				puzzle[i][j] = input - '0';
			}
		}
		return is;
	}
	bool is_solved() {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (!puzzle[i][j])
					return 0;
			}
		}
		return 1;
	}
	int puzzle[9][9] = { {0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,3,0,8,5},
						 {0,0,1,0,2,0,0,0,0},
						 {0,0,0,5,0,7,0,0,0},
						 {0,0,4,0,0,0,1,0,0},
						 {0,9,0,0,0,0,0,0,0},
						 {5,0,0,0,0,0,0,7,3},
						 {0,0,2,0,1,0,0,0,0},
						 {0,0,0,0,4,0,0,0,9} };
	std::stack<std::pair<int, int> > history;
};