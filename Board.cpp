//
// Created by Andrew on 1/21/2020.
//

#include <string>
#include <iostream>
#include "Board.h"

using namespace std;

Board::Board()
{
    turnNum = 0;
    for(int i = 0; i < SIZE; ++i)
    {
        for(int j = 0; j < SIZE; ++j)
        {
            if(i % 2 == 1 && j % 2 == 1)
            {
                board[i][j] = 197;
            }
            else if(i % 2 == 1)
            {
                board[i][j] = 196;
            }
            else if(j % 2 == 1)
            {
                board[i][j] = 179;
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}
bool Board::notValid(string input)
{
    if(input.size() == 2)
    {
        toupper(input[0]);
        if(input[0] == 'A' || input[0] == 'B' || input[0] == 'C')
        {
            if(input[1] == '1' || input[1] == '2' || input[1] == '3')
            {
                return false;
            }
        }
    }
    return true;
}
bool Board::notEmpty(string input)
{
    if(board[(input[0] - 'A') * 2][(input[1] - '0') * 2] == ' ')
    {
        return false;
    }
    return true;
}
void Board::writeToBoard(string input, char inChar)
{
    board[(input[0] - 'A') * 2][(input[1] - '0') * 2] = inChar;
    ++turnNum;
}
void Board::printBoard()
{
    cout << " A B C\n";
    for(int i = 0; i < Board::SIZE; ++i)
    {
        if(i % 2 == 0)
        {
            cout << i * 2 + 1;
        }
        else
        {
            cout << ' ';
        }
        cout << board[i] << endl;
    }
}
int Board::getTurnNum()
{
    return turnNum;
}
bool Board::winner()
{
    for(int i = 0; i < SIZE; i+=2)
    {
        if(board[i][0] == board[i][2] == board[i][4] || board[0][i] == board[2][i] == board[4][i])
        {
            return true;
        }
    }
    if(board[0][0] == board[2][2] == board[4][4] || board[0][4] == board[2][2] == board[4][0])
    {
        return true;
    }
    return false;
}
