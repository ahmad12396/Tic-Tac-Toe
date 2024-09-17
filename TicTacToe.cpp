#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

char humanPlayer = 'X';
char computerPlayer = 'O';

bool isHumanTurn = true;

void displayBoard();
void playerTurn();
bool isGameOver();
void computerTurn();
//1 vs 1 Player
char turn = 'X';
int choice;
int Row, Column;
string n1;
string n2;
bool draw=false;

void display_board();
void player_turn();
bool gameover();

int main()
{


  int p;
do
{
    cout << "******************************\n";
    cout << "*  Welcome to Tic-Tac-Toe    *\n";
    cout << "******************************\n";
    cout << "*   Select one of Following  *\n";
    cout << "*   1: 1 Player vs 1 Player  *\n";
    cout << "*   2: 1 Player vs Computer  *\n";
    cout << "******************************\n";
    cin >> p;
} while (p == 1 && p == 2);

switch (p)
{
case 1:
    
    cout << "Enter Player 1 Name :";
    getline(cin>>ws, n1);
    cout << "Enter Player 2 Name :";
    getline(cin>>ws, n2);

    cout << "\n";
    cout << n1 << " : (X)\n" ;
    cout << n2 << " : (O)\n" ;
    cout << "\n";

    while (gameover()) {
        display_board();

        player_turn();
    }

    display_board();  // Display the final board after the game is over

    if (turn == 'O' && draw == false)
        cout << n1 << " Wins!! Congratulations!!" << endl;
    else if (turn == 'X' && draw == false)
        cout << n2 << " Wins!! Congratulations!!" << endl;
    else
        cout << "It's a tie!" << endl;

    return 0;
    break;
case 2:
    cout << "*******************************\n";
    cout << "* Welcome to Tic-Tac-Toe Game *\n";
    cout << "*******************************\n";
    cout << "\n";

    while (!isGameOver())
    {
        displayBoard();
        playerTurn();
        isHumanTurn = !isHumanTurn; // Switch turns after each move
    }

    displayBoard(); // Display the final board after the game is over

    if (isHumanTurn) // If it's the human player's turn, computer wins
        cout << "Computer Wins!! Better luck next time!" << endl;
    else
        cout << "Congratulations! You Win!!" << endl;

    return 0;

    
    break;

default:
    break;
}

   
}

void displayBoard()
{
    system("cls");
    cout << "\t\t     |     |     " << endl
         << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl
         << "\t\t_____|_____|_____" << endl
         << "\t\t     |     |     " << endl
         << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl
         << "\t\t_____|_____|_____" << endl
         << "\t\t     |     |     " << endl
         << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl
         << "\t\t     |     |     " << endl;
}

void playerTurn()
{
    if (isHumanTurn)
    {
        int choice;
        cout << "\nYour Turn (" << humanPlayer << "): ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Invalid move! Try again.\n";
            playerTurn();
            return;
        }

        board[row][col] = humanPlayer;
    }
    else
    {
        cout << "\nComputer's Turn (" << computerPlayer << "):\n";
        computerTurn();
    }
}

bool isGameOver()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return true;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return true;

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return true;

    // Check for draw
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false; // If any empty cell found, game is not over yet
            }
        }
        draw = false;
    }

    return true; // If no empty cells and no winner, it's a draw
}

void computerTurn()
{
    srand(time(0));
    int num;

    do
    {
        num = rand() % 9 + 1;
        int row = (num - 1) / 3;
        int col = (num - 1) % 3;
        if (board[row][col] != 'X' && board[row][col] != 'O')
        {
            board[row][col] = computerPlayer;
            break;
        }
    } while (true);
}
void display_board() {
    system("cls");
    cout << "\t\t     |     |     " << endl
         << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl
         << "\t\t_____|_____|_____" << endl
         << "\t\t     |     |     " << endl
         << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl
         << "\t\t_____|_____|_____" << endl
         << "\t\t     |     |     " << endl
         << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl
         << "\t\t     |     |     " << endl;
}

void player_turn() {
    if (turn == 'X')
        cout << "\n\t\t" << n1 << ":(X) Turn :";
    if (turn == 'O')
        cout << "\n\t\t" << n2 << ":(O) Turn :";
    cin >> choice;

    switch (choice) {
    case 1: Row = 0, Column = 0; break;
    case 2: Row = 0, Column = 1; break;
    case 3: Row = 0, Column = 2; break;
    case 4: Row = 1, Column = 0; break;
    case 5: Row = 1, Column = 1; break;
    case 6: Row = 1, Column = 2; break;
    case 7: Row = 2, Column = 0; break;
    case 8: Row = 2, Column = 1; break;
    case 9: Row = 2, Column = 2; break;
    default:
        cout << "Invalid Choice!\n" ;
        return;  // Add a return statement to exit the function for invalid choices
    }

    if (board[Row][Column] != 'X' && board[Row][Column] != 'O') {
        if (turn == 'X') {
            board[Row][Column] = 'X';
            turn = 'O';
        } else if (turn == 'O') {
            board[Row][Column] = 'O';
            turn = 'X';
        }
    } else {
        cout << "Already Taken!!\n"  << "Try Again\n" ;
        player_turn();
    }
}

bool gameover() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return false;

    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return false;

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
    draw = true;
    return false;
}