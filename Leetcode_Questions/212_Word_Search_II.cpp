#include <iostream>
#include <cassert>
#include <vector>
#include <string>

#include "WSTrie.h"

WSTrie* buildTrie(std::vector<std::string>& words)
{
    WSTrie* root{ new WSTrie() };
    for (int i{ 0 }; i < words.size(); ++i)
    {
        WSTrie* node{ root };
        for (char c : words[i])
        {
            int child{ c - 'a' };
            if (!node->children[child])
                node->children[child] = new WSTrie();

            node = node->children[child];
            ++node->count;
        }
        node->wordIdx = i;
    }
    return root;
}

void decrementPath(WSTrie* node, const std::string& word)
{
    for (char c : word)
    {
        int child{ c - 'a' };
        node = node->children[child];
        --node->count;
    }
}

void wordSearchDFS(std::vector<std::vector<char>>& board, std::vector<std::string>& words, WSTrie* root, std::vector<std::string>& found, WSTrie* node, int i, int j)
{
    char c{ board[i][j] };
    if (c == '*' || !node->children[c - 'a'])
        return;

    node = node->children[c - 'a'];
    if (node->count == 0)
        return;

    if (node->wordIdx != -1)
    {
        found.push_back(words[node->wordIdx]);
        decrementPath(root, words[node->wordIdx]);
        node->wordIdx = -1;
    }

    board[i][j] = '*';
    static constexpr int dx[4]{ -1, 1, 0, 0 };
    static constexpr int dy[4]{ 0, 0, -1, 1 };
    for (int d{ 0 }; d < 4; ++d)
    {
        int di{ i + dx[d] };
        int dj{ j + dy[d] };
        if (di >= 0 && di < board.size() && dj >= 0 && dj < board[0].size())
            wordSearchDFS(board, words, root, found, node, di, dj);
    }
    board[i][j] = c;
}

std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
{
    WSTrie* root{ buildTrie(words) };
    std::vector<std::string> found;
    for (int i{ 0 }; i < board.size(); ++i)
    {
        for (int j{ 0 }; j < board[0].size(); ++j)
        {
            wordSearchDFS(board, words, root, found, root, i, j);
        }
    }
    delete root;
    return found;
}

#if 0
int main()
{
    // Provided test cases
    std::vector<std::vector<char>> board1{ {'o','a','a','n'},
                                           {'e','t','a','e'},
                                           {'i','h','k','r'},
                                           {'i','f','l','v'} };
    std::vector<std::string> words1{ "oath", "pea", "eat", "rain" };
    std::vector<std::string> answer1{ "oath", "eat" };
    assert(findWords(board1, words1) == answer1);

    std::vector<std::vector<char>> board2{ {'a', 'b'},
                                           {'c', 'd'} };
    std::vector<std::string> words2{ "abcb" };
    std::vector<std::string> answer2{};
    assert(findWords(board2, words2) == answer2);

    std::cout << "Success!\n";

    return 0;
}
#endif