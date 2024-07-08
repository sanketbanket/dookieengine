#include "moves.h"

////////////////important/////////////////
// row = '8' - rank
// column = file - 'a'

char whichColor(char name)
{
    if (int(name - 'a' < 0))
    {
        return 'w';
    }
    return 'b';
}

vector<int> getYX(string square)
{
    vector<int> XY = {'8' - square[1], square[0] - 'a'};
    return XY;
}
string getSquare(int row, int column)
{
    string squ = "";
    squ.push_back(char(column + 'a'));
    squ.push_back(char('8' - row));
    return squ;
}
bool isValidSquare(int row, int column)
{
    return row >= 0 && row <= 7 && column >= 0 && column <= 7;
}
bool isValidSquare(string square)
{
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    return row >= 0 && row <= 7 && col >= 0 && col <= 7;
}

vector<string> getRookMoves(string square, char color, vector<vector<int>> board_array)
{
    vector<string> validSquares = {};
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    bool up = true;
    bool down = true;
    bool right = true;
    bool left = true;

    for (int i = 1; i < 8; i++)
    {
        string target;
        if (up && isValidSquare(row - i, col))
        {
            if (!board_array[row - i][col])
            {
                validSquares.push_back(getSquare(row - i, col));
            }
            else
            {
                if (whichColor(char(board_array[row - i][col])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col));
                    target.push_back(char('8' - (row - i)));
                    validSquares.push_back(target);
                    up = false;
                }
                else
                {
                    up = false;
                }
            }
            target.clear();
        }
        if (down && isValidSquare(row + i, col))
        {
            if (!board_array[row + i][col])
            {
                validSquares.push_back(getSquare(row + i, col));
            }
            else
            {
                if (whichColor(char(board_array[row + i][col])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col));
                    target.push_back(char('8' - (row + i)));
                    validSquares.push_back(target);
                    down = false;
                }
                else
                {
                    down = false;
                }
            }
            target.clear();
        }
        if (right && isValidSquare(row, col + i))
        {
            if (!board_array[row][col + i])
            {
                validSquares.push_back(getSquare(row, col + i));
            }
            else
            {
                if (whichColor(char(board_array[row][col + i])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col + i));
                    target.push_back(char('8' - row));
                    validSquares.push_back(target);
                    right = false;
                }
                else
                {
                    right = false;
                }
            }
            target.clear();
        }
        if (left && isValidSquare(row, col - i))
        {
            if (!board_array[row][col - i])
            {
                validSquares.push_back(getSquare(row, col - i));
            }
            else
            {
                if (whichColor(char(board_array[row][col - i])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col - i));
                    target.push_back(char('8' - row));
                    validSquares.push_back(target);
                    left = false;
                }
                else
                {
                    left = false;
                }
            }
            target.clear();
        }
    }
    return validSquares;
}

vector<string> getBishopMoves(string square, char color, vector<vector<int>> board_array)
{
    vector<string> validSquares = {};
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    bool NW = true;
    bool NE = true;
    bool SW = true;
    bool SE = true;
    for (int i = 1; i < 8; i++)
    {
        string target;
        if (NW && isValidSquare(row - i, col - i))
        {
            if (!board_array[row - i][col - i])
            {
                validSquares.push_back(getSquare(row - i, col - i));
            }
            else
            {
                if (whichColor(char(board_array[row - i][col - i])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col - i));
                    target.push_back(char('8' - (row - i)));
                    validSquares.push_back(target);
                    NW = false;
                }
                else
                {
                    NW = false;
                }
            }
            target.clear();
        }
        if (NE && isValidSquare(row - i, col + i))
        {
            if (!board_array[row - i][col + i])
            {
                validSquares.push_back(getSquare(row - i, col + i));
            }
            else
            {
                if (whichColor(char(board_array[row - i][col + i])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col + i));
                    target.push_back(char('8' - (row - i)));
                    validSquares.push_back(target);
                    NE = false;
                }
                else
                {
                    NE = false;
                }
            }
            target.clear();
        }
        if (SW && isValidSquare(row + i, col - i))
        {
            if (!board_array[row + i][col - i])
            {
                validSquares.push_back(getSquare(row + i, col - i));
            }
            else
            {
                if (whichColor(char(board_array[row + i][col - i])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col - i));
                    target.push_back(char('8' - (row + i)));
                    validSquares.push_back(target);
                    SW = false;
                }
                else
                {
                    SW = false;
                }
            }
            target.clear();
        }
        if (SE && isValidSquare(row + i, col + i))
        {
            if (!board_array[row + i][col + i])
            {
                validSquares.push_back(getSquare(row + i, col + i));
            }
            else
            {
                if (whichColor(char(board_array[row + i][col + i])) != color)
                {
                    target = "x";
                    target.push_back(char('a' + col + i));
                    target.push_back(char('8' - (row + i)));
                    validSquares.push_back(target);
                    SE = false;
                }
                else
                {
                    SE = false;
                }
            }
            target.clear();
        }
    }
    return validSquares;
}
vector<string> getQueenMoves(string square, char color, vector<vector<int>> board_array)
{
    vector<string> diags = getBishopMoves(square, color, board_array);
    vector<string> straights = getRookMoves(square, color, board_array);
    for (int i = 0; i < straights.size(); i++)
    {
        diags.push_back(straights[i]);
    }
    return diags;
}

vector<string> getKnightMoves(string square, char color, vector<vector<int>> board_array)
{
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    vector<string> validSquares = {};
    for (int i = -1; i < 2; i = i + 2)
    {
        for (int j = -1; j < 2; j = j + 2)
        {
            if (isValidSquare(row + (2 * i), col + j))
            {
                if (board_array[row + (2 * i)][col + j] == 0)
                {
                    validSquares.push_back(getSquare(row + (2 * i), col + j));
                }
                else
                {
                    if (whichColor(char(board_array[row + (2 * i)][ col + j])) != color)
                    {
                        string target = "x";
                        target.push_back(char('a' + col + j));
                        target.push_back(char('8' - (row + 2*i)));
                        validSquares.push_back(target);
                    }
                }
            }
            if (isValidSquare(row + i, col + 2*j))
            {
                if (board_array[row + i][col + 2*j] == 0)
                {
                    validSquares.push_back(getSquare(row + i, col + 2*j));
                }
                else
                {
                    if (whichColor(char(board_array[row + i][col + 2*j])) != color)
                    {
                        string target = "x";
                        target.push_back(char('a' + col + 2*j));
                        target.push_back(char('8' - (row + i)));
                        validSquares.push_back(target);
                    }
                }
            }
        }
    }
    return validSquares;
}
vector<string> getKingMoves(string square, vector<vector<int>> board_array)
{
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    vector<string> validSquares = {};
    for(int i = -1; i < 2; i++){
        for(int j = -1 ;j < 2; j++){
            continue;
        }
    }
    return validSquares;
}

vector<string> getPawnMoves(string square, char color, vector<vector<int>> board_array, char origin){
    int row = getYX(square)[0];
    int col = getYX(square)[1];
    vector<string> validSquares = {};
    bool at_origin = (square[0] == origin && square[1] == '2' && color == 'w') || (square[0] == origin && square[1] == '7' && color == 'b');
    int dir = color == 'w'? -1 : 1;
    if(isValidSquare(row + dir, col) && board_array[row + dir][col] == 0){
        validSquares.push_back(getSquare(row + dir, col));
        
    }
    if(isValidSquare(row + 2 * dir, col) && at_origin && board_array[row + 2 * dir][col] == 0){
        validSquares.push_back(getSquare(row + 2*dir, col));
    }
    if(isValidSquare(row + dir, col + 1) && board_array[row + dir][col + 1] != 0){
        string target = "x";
        target.push_back(char(col + 1 + 'a'));
        target.push_back(char('8' - (row + dir)));
        validSquares.push_back(target);
    }
    if(isValidSquare(row + dir, col - 1) && board_array[row + dir][col - 1] != 0){
        string target = "x";
        target.push_back(char(col - 1 + 'a'));
        target.push_back(char('8' - (row + dir)));
        validSquares.push_back(target);
    }
    return validSquares;

}