#include <iostream>
using namespace std;
#include <vector>

vector<vector<char>> board;
string word;
int rows, cols;

vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // north east south west

bool isValid(int i, int j)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        return false;

    return true;
}

bool solver(int i, int j, vector<vector<bool>> &visited, int idx)
{

    if (visited[i][j] == true || board[i][j] != word[idx])
        return false;
    if (board[i][j] == word[idx] && idx == word.size() - 1)
        return true;

    // mark it visited
    visited[i][j] = true;

    // now explore
    for (vector<int> dir : directions)
    {
        int newi = dir[0] + i;
        int newj = dir[1] + j;

        if (isValid(newi, newj))
            if (solver(newi, newj, visited, idx + 1))
                return true;
    }

    // upon exiting
    visited[i][j] = false;
    return false;
}

bool exist(vector<vector<char>> &b, string w)
{
    board = b;
    word = w;

    rows = board.size();
    cols = board[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (board[i][j] == word[0])
            {
                vector<vector<bool>> visited(rows, vector<bool>(cols, false));
                if (solver(i, j, visited, 0))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board{
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
    };
    string word = "abed";

    cout << exist(board, word) << endl;
}