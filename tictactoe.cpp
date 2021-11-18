#include <iostream>

using namespace std;

class TicTacToe{
    
    private:
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    int player = 0;
    char marker = 'x';

    void drawBoard() {
        cout << "" << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "---|---|---" << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "" << endl;
    }

    bool positionAvailable(int pos) {
        int row, col;

        if (pos % 3 == 0) {
            row = (pos/3) - 1;
            col = 2;
        }
        else {
            row = pos/3;
            col = pos % 3 - 1;
        }

        if(board[row][col] == 'x' || board[row][col] == 'O') {
            cout << "Idiot";
            return false;
        }

        return true;

    }

    void placeMarker(int slot) {
        int row, col;

        if (slot % 3 == 0) {
            row = (slot/3) - 1;
            col = 2;
        }
        else {
            row = slot/3;
            col = slot % 3 - 1;
        }



        board[row][col] = marker;

    }

    int checkWinner() {
    
        for(int i = 0; i < 3; i++) {
            // rows
            if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return player;
            // columns
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return player;
        }

        // Diagnonals
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return player;
        if(board[2][0] == board[1][1] && board[1][1] == board[0][2]) return player;

        return 3;
    }

    public:

    void startGame() {
        while(checkWinner() == 3) {

            drawBoard();

            if(player == 0) {
                marker = 'x';
                int pos;
                cout << "(Player 1)Position To Place Marker -> " ;
                cin >> pos;
                if(positionAvailable(pos) == false) {
                    cout << "POSITION NOT AVAILABLE IDIOT!";
                    player = 0;
                }
                else {
                    placeMarker(pos);
                    player = 1;
                }
            }
            else {
                marker = 'O';
                int pos;
                cout << "(Player 2)Position To Place Marker -> " ;
                cin >> pos;
                if(positionAvailable(pos) == false) {
                    cout << "POSITION NOT AVAILABLE IDIOT!";
                    player = 1;
                }
                else {
                    placeMarker(pos);
                    player = 0;
                }
            }

        }
        if(checkWinner() != 3) {
            // Weird Things I Did because i am lazy 
            if (player == 0) cout << "Player 2 has Won." << endl;
            else cout << "Player 1 has Won." << endl;
        }
    }

};

int main() {

    cout << "Welcome To TicTacToe!!\n" << endl;
    char response;
    cout << "Type y to contine : ";
    cin >> response;
    cout << "" << endl;

    if (response != 'y') {
        cout << "\nBye Bye!!" << endl;
        return 0;
    }


    TicTacToe board;

    board.startGame();

    return 0;
}
