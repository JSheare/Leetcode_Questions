#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <utility>
#include <queue>

bool dfs(std::vector<std::vector<char>>& board, std::vector<std::vector<int>>& visited, std::string& word, 
    int depth, int i, int j)
{
    if (depth == word.length())
        return true;

    if (i < 0 || j < 0 || i == board.size() || j == board[0].size() ||
        visited[i][j] || word[depth] != board[i][j])
        return false;

    visited[i][j] = 1;
    bool found{ dfs(board, visited, word, depth + 1, i + 1, j) ||
                dfs(board, visited, word, depth + 1, i - 1, j) ||
                dfs(board, visited, word, depth + 1, i, j + 1) ||
                dfs(board, visited, word, depth + 1, i, j - 1) };
    visited[i][j] = 0;
    return found;
}

bool exist(std::vector<std::vector<char>>& board, std::string word)
{
    if (word.length() > board.size() * board[0].size())
        return false;

    std::vector<int> freq(256, 0);
    std::queue<std::pair<int, int>> cells;
    for (int i{ 0 }; i < word.length(); ++i)
    {
        --freq[word[i]];
    }
    for (int i{ 0 }; i < board.size(); ++i)
    {
        for (int j{ 0 }; j < board[0].size(); ++j)
        {
            ++freq[board[i][j]];
            if (board[i][j] == word[0])
                cells.push({ i, j });
        }
    }
    for (auto& c : word)
    {
        if (freq[c] < 0)
            return false;
    }
    std::vector<std::vector<int>> visited(board.size(), std::vector<int>(board[0].size(), 0));
    while (!cells.empty())
    {
        std::pair<int, int> cell{ cells.front() };
        cells.pop();
        if (dfs(board, visited, word, 0, cell.first, cell.second))
            return true;
    }
    return false;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<char>> test1{ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    assert(exist(test1, "ABCCED") == true);

    std::vector<std::vector<char>> test2{ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    assert(exist(test2, "SEE") == true);

    std::vector<std::vector<char>> test3{ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} };
    assert(exist(test3, "ABCB") == false);

    std::cout << "Success!\n";

    return 0;
}
#endif