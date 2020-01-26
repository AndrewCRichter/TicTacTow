#include "Board.cpp"

int main() {
    Board board;
    bool playing = true;
    bool invalid = true;
    char player = 'X';
    string move;
    while(playing)
    {
        cout << "turn" << board.getTurnNum() << endl;
        cout << "player" << player << "Enter your move: ";
        cin >> move;
        while(invalid)
        {
            if(Board::notValid(move))
            {
                cout << "You must enter A, B, or C followed by 1, 2, or 3: ";
                cin >> move;
            }
            else if(board.notEmpty(move))
            {
                cout << "You must enter an empty slot: ";
                cin >> move;
            }
            else
            {
                invalid = false;
            }
        }
        board.writeToBoard(move, player);
        board.printBoard();
        if(board.winner())
        {
            cout << "player" << player << "Wins!";
            playing = false;
        }
        else if(board.getTurnNum() == 9)
        {
            cout << "Draw game.";
            playing = false;
        }
        if(player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'x';
        }
    }
    return 0;
}