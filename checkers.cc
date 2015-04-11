#include <iostream>
#include <cmath>

using namespace std;
const int ROWS = 8;
const int COLS = 8;


void displayBoard(ostream& stream, char board[8][8]) {
  stream << " ";

  for (int column = 0; column < COLS; column++){
    stream << column << " |";
  }

  stream << endl;

  for (int row = 0; row < ROWS; row++){
    stream << row;
    for (int column = 0; column < COLS; column++) {
      if (board[row][column] == ' '){
        stream << " *|";
      }
      else {
        stream << " " << board[row][column] << "|";
      }
    }
    stream << endl;
  }
}

void displayDialogue(istream & in, int player, int &rowSource, int &columnSource, int &rowDestination, int &columnDestination){
  if (player == 1) {
    cout << "Black Move" << endl;
    cout << "Select the piece to be moved:" << endl;
    cout << "Move piece from" << endl;
    cout << "Row: ";
    in >> rowSource;
    cout << "Column: ";
    in >> columnSource;
    cout << "To box" << endl;
    cout << "Row: ";
    in >> rowDestination;
    cout << "Column: ";
    in >> columnDestination;
  }

  else {
    cout << "Red Move" << endl;
    cout << "Select the piece to be moved:" << endl;
    cout << "Move piece from" << endl;
    cout << "Row: ";
    cin >> rowSource;
    cout << "Column: ";
    cin >> columnSource;
    cout << "To box" << endl;
    cout << "Row: ";
    cin >> rowDestination;
    cout << "Column: ";
    cin >> columnDestination;
  }

}

void verify_contains_piece(int rowSource, int columnSource, char board[8][8], int &player, int &success) {
  if (player == 1 && board[rowSource][columnSource] == 'b') {
    success = 1;
  }
  else if (player == 0 && board[rowSource][columnSource] == 'r') {
    success = 1;
  }
  else {
    success = 0;
  }
}

void verify_forward_move(int rowSource, int rowDestination, int &player, int &success) {
  if (player == 1 && rowDestination - rowSource == 1) {
    success = 1;
  }
  else if (player == 0 && rowSource - rowDestination == 1) {
    success = 1;
  }
  else {
    success = 0;
  }
}

void verify_diagonal_move(int columnSource, int columnDestination, int &success) {
  if (columnSource == 0 && columnDestination - columnSource == 1) {
    success =1;
  }
  else if (columnSource == 7 && columnSource - columnDestination == 1) {
    success = 1;
  }
  else if (columnSource > 0 && columnSource < 7 && abs(columnSource - columnDestination) == 1) {
    success = 1;
  }
  else {
    success = 0;
  }
}

void verify_empty_destination(int rowDestination, int columnDestination, char board[8][8], int &success) {
  if (board[rowDestination][columnDestination] == ' ') {
    success = 1;
  }
  else {
    success = 0;
  }
}

/*
void verify_opponent_capture() {

}
*/

void switch_players(int &player) {
  if (player == 1) {
    player = 0;
  }
  else {
    player = 1;
  }
}

void update_board(int rowSource, int columnSource, int rowDestination, int columnDestination, char board[8][8], int &player) {
  if (player == 1) {
    board[rowSource][columnSource] = ' ';
    board[rowDestination][columnDestination] = 'b';
  }
  else {
    board[rowSource][columnSource] = ' ';
    board[rowDestination][columnDestination] = 'r';
  }
}

void move(int rowSource, int columnSource, int rowDestination, int columnDestination, int &success, char board[8][8], int &player) {
  verify_contains_piece(rowSource, columnSource, board, player, success);
  verify_forward_move(rowSource, rowDestination, player, success);
  verify_diagonal_move(columnSource, columnDestination, success);
  verify_empty_destination(rowDestination, columnDestination, board, success);

  if (success == 1) {
    update_board(rowSource, columnSource, rowDestination, columnDestination, board, player);
    switch_players(player);
  }
  else {
    cout << "Illegal Move!" << endl;
  }

}


int main() {

  char board[ROWS][COLS]= {
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '}
  };

  int rowSource, columnSource, rowDestination, columnDestination;
  int success = 1;
  int player = 1;

  displayBoard(cout, board);

  displayDialogue(cin, player, rowSource, columnSource, rowDestination, columnDestination);
  move(rowSource, columnSource, rowDestination, columnDestination, success, board, player);

  if(success == 1) {
    displayBoard(cout, board);
  }
  else {
    displayDialogue(cin, player, rowSource, columnSource, rowDestination, columnDestination);
    move(rowSource, columnSource, rowDestination, columnDestination, success, board, player);
  }

  displayDialogue(cin, player, rowSource, columnSource, rowDestination, columnDestination);
  move(rowSource, columnSource, rowDestination, columnDestination, success, board, player);

  if(success == 1) {
    displayBoard(cout, board);
  }
  else {
    displayDialogue(cin, player, rowSource, columnSource, rowDestination, columnDestination);
    move(rowSource, columnSource, rowDestination, columnDestination, success, board, player);
  }

  return 0;
}
