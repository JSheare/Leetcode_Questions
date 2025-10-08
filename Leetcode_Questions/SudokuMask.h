#ifndef H_SUDOKUMASK
#define H_SUDOKUMASK

#include <vector>

class SudokuMask
{
public:
	SudokuMask();
	void mark(int i, int j, int val);
	void unmark(int i, int j, int val);
	int numPossibilities(int i, int j);
	std::vector<int> getPossibilities(int i, int j);

private:
	int row[9]{};
	int column[9]{};
	int box[9]{};
};
#endif