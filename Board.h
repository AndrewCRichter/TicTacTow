//
// Created by Andrew on 1/21/2020.
//

#ifndef TICTACTOW_BOARD_H
#define TICTACTOW_BOARD_H



class Board
{
private:
    static const int SIZE = 5;
    int turnNum;
    char board[SIZE][SIZE];
public:
    Board();
    static bool notValid(std::string input);
    bool notEmpty(std::string input);
    void writeToBoard(std::string input, char inChar);
    void printBoard();
    int getTurnNum();
    bool winner();
};


#endif //TICTACTOW_BOARD_H
