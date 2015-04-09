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

void move(int rowSource, int columnSource, int rowDestination, int columnDestination, int &success, char board[8][8], int &player) {
  if (player == 1) {
    if (board[rowSource][columnSource] == 'b') {
      if (columnSource == 0 && columnDestination - columnSource == 1){
        success = 1;
        player = 0;
        board[rowSource][columnSource] = ' ';
        board[rowDestination][columnDestination] = 'b';
      }
      else if (columnSource == 7 && columnSource - columnDestination == 1){
        success = 1;
        player = 0;
        board[rowSource][columnSource] = ' ';
        board[rowDestination][columnDestination] = 'b';
      }
      else if (columnSource != 0 && columnSource != 7 && abs (columnDestination - columnSource) == 1) {
        if (rowDestination - rowSource == 1) {
          success = 1;
          player = 0;
          board[rowSource][columnSource] = ' ';
          board[rowDestination][columnDestination] = 'b';
        }
        else {
          success = 0;
        }
      }
      else {
        success = 0;
      }
    }
    else {
      success = 0;
    }
  }

  else {
    if (board[rowSource][columnSource] == 'r') {
      if (abs (columnDestination - columnSource) == 1) {
        if (columnSource == 0 && columnDestination - columnSource == 1){
          success = 1;
          player = 1;
          board[rowSource][columnSource] = ' ';
          board[rowDestination][columnDestination] = 'r';
        }
        else if (columnSource == 7 && columnSource - columnDestination == 1){
          success = 1;
          player = 1;
          board[rowSource][columnSource] = ' ';
          board[rowDestination][columnDestination] = 'r';
        }
        else if (rowSource - rowDestination == 1) {
          success = 1;
          player = 1;
          board[rowSource][columnSource] = ' ';
          board[rowDestination][columnDestination] = 'r';
        }
      }
      else if (columnDestination == columnSource) {
        success = 0;
      }
    }
    else {
      success = 0;
    }
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
    cout << "Illegal Move!" << endl;
  }

  displayDialogue(cin, player, rowSource, columnSource, rowDestination, columnDestination);
  move(rowSource, columnSource, rowDestination, columnDestination, success, board, player);

  if(success == 1) {
    displayBoard(cout, board);
  }
  else {
    cout << "Illegal Move!" << endl;
  }

  return 0;
}
