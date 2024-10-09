#include<iostream>
#include<string>
#include<iomanip>
#include <cstdlib>						// Including Libraries
#include <ctime>
#include <vector>


using namespace std;

void grid(string chess[8][8]);
int option();
void systemMove(string chess[8][8]);
bool bishopcheck(int row, int column, int row1, int column1);				// Declaring Functions
vector<pair<int, int>> get_bishop_moves(int row, int column);
void start();

int main() {


	start();						// Main Function

	return 0;
}

int option() {

	int option1;

	cout << "Please select among the following options:";
	cout << endl << endl;
	cout << "[1] King" << endl;
	cout << "[2] Queen" << endl;
	cout << "[3] Bishop 1" << endl;
	cout << "[4] Bishop 2" << endl;								// Function for Selecting the Piece user wants to Play
	cout << "[5] Rook 1" << endl;
	cout << "[6] Rook 2" << endl;
	cout << "[7] Knight 1" << endl;
	cout << "[8] Knight 2" << endl;

	cout << endl;
	cout << "Please select one of the above options (1, 2, 3, 4, 5, 6, 7 or 8) :   ";
	cin >> option1;

	return option1;

}

void grid(string chess[8][8]) {
	int k = 0;
	cout << "       0       1       2       3       4       5       6       7" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << k << "  ";
		for (int j = 0; j < 8; j++)
		{																	// Function for Printing Updated Grid
			;
			cout << "|" << chess[i][j];


		}
		cout << endl;
		k = k + 1;
	}

}

void systemMove(string chess[8][8]) {



	// Function for the System (Not Completed)


}

vector<pair<int, int>> get_bishop_moves(int row, int column) {

	vector<pair<int, int>> moves;

	for (int i = 1; i < 8; i++)
	{
		if (row + i < 8 && column + i < 8)
		{
			moves.push_back(make_pair(row + i, column + i));
		}

		if (row + i < 8 && column - i >= 0)
		{
			moves.push_back(make_pair(row + i, column - i));			// Function for Bishop Moves
		}

		if (row - i >= 0 && column + i < 8)
		{
			moves.push_back(make_pair(row - i, column + i));
		}

		if (row - i >= 0 && column - i >= 0)
		{
			moves.push_back(make_pair(row - i, column - i));
		}
	}

	return moves;
}

bool bishopcheck(int row, int column, int row1, int column1) {

	if (abs(row1 - row) != abs(column1 - column))
	{
		return false;
	}

	if ((row1 == row) && (column1 == column))
	{
		return false;										// Bool Function to check whether move of Bishop is Valid or Not
	}

	if ((row1 < 0) || (row1 > 7) || (column1 > 7) || (column1 < 0))
	{
		return false;
	}

	return true;
}

void start() {

	string chess[8][8];
	int row = 0, column = 0, option1, row1, column1;
	string temp;

	//---------------------------------------------------------------------------------------


	cout << endl << endl << endl;
	chess[0][0] = "  aR1  ";
	chess[0][1] = "  aK1  ";
	chess[0][2] = "  aB1  ";
	chess[0][3] = "  aQ   ";
	chess[0][4] = "  aK   ";
	chess[0][5] = "  aB2  ";
	chess[0][6] = "  aK2  ";
	chess[0][7] = "  aR2  ";						// Initializing Chess Array (8x8)

	chess[1][0] = "   *   ";
	chess[1][1] = "   -   ";
	chess[1][2] = "   *   ";
	chess[1][3] = "   -   ";
	chess[1][4] = "   *   ";
	chess[1][5] = "   -   ";
	chess[1][6] = "   *   ";
	chess[1][7] = "   -   ";

	chess[2][0] = "   -   ";
	chess[2][1] = "   *   ";
	chess[2][2] = "   -   ";
	chess[2][3] = "   *   ";
	chess[2][4] = "   -   ";
	chess[2][5] = "   *   ";
	chess[2][6] = "   -   ";
	chess[2][7] = "   *   ";

	chess[3][0] = "   *   ";
	chess[3][1] = "   -   ";
	chess[3][2] = "   *   ";
	chess[3][3] = "   -   ";						// Initializing Chess Array (8x8)
	chess[3][4] = "   *   ";
	chess[3][5] = "   -   ";
	chess[3][6] = "   *   ";
	chess[3][7] = "   -   ";

	chess[4][0] = "   -   ";
	chess[4][1] = "   *   ";
	chess[4][2] = "   -   ";
	chess[4][3] = "   *   ";
	chess[4][4] = "   -   ";
	chess[4][5] = "   *   ";
	chess[4][6] = "   -   ";
	chess[4][7] = "   *   ";

	chess[5][0] = "   *   ";
	chess[5][1] = "   -   ";
	chess[5][2] = "   *   ";						// Initializing Chess Array (8x8)
	chess[5][3] = "   -   ";
	chess[5][4] = "   *   ";
	chess[5][5] = "   -   ";
	chess[5][6] = "   *   ";
	chess[5][7] = "   -   ";

	chess[6][0] = "   -   ";
	chess[6][1] = "   *   ";
	chess[6][2] = "   -   ";
	chess[6][3] = "   *   ";
	chess[6][4] = "   -   ";
	chess[6][5] = "   *   ";
	chess[6][6] = "   -   ";
	chess[6][7] = "   *   ";

	chess[7][0] = "  bR1  ";
	chess[7][1] = "  bK1  ";
	chess[7][2] = "  bB1  ";
	chess[7][3] = "  bQ   ";
	chess[7][4] = "  bK   ";
	chess[7][5] = "  bB2  ";						// Initializing Chess Array (8x8)
	chess[7][6] = "  bK2  ";
	chess[7][7] = "  bR2  ";

	//-----------------------------------------------------------------------------------------------

	cout << "The Initial Starting Grid:";
	cout << endl << endl << endl;

	grid(chess);								// Printing the Starting Grid on Start of Game

	cout << endl << endl;

	//-----------------------------------------------------------------------------------------------
	int score = 0;
	while (score == 0)
	{
		cout << endl << endl;

		cout << "---------------------------------------------------   PLAYER 01   ---------------------------------------------------";
		cout << endl << endl;

		option1 = option();

		if (option1 == 1 || option1 == 2 || option1 == 3 || option1 == 4 || option1 == 5 || option1 == 6 || option1 == 7 || option1 == 8)
		{
			// Checking which Piece User wants to Play

			if (option1 == 1)		// As Option 1 was For the King
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aK   ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your possible Next moves are:  (" << row - 1 << "," << column - 1 << ") , (" << row - 1 << "," << column << ") , (" << row - 1 << "," << column + 1 << ") , (" << row << "," << column - 1 << ") , (" << row << "," << column + 1 << ") , (" << row + 1 << "," << column - 1 << ") , (" << row + 1 << "," << column << ") , (" << row + 1 << "," << column + 1 << ")";
				cout << endl << endl;

				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;


				if ((row1 == row - 1 && column1 == column - 1) || (row1 == row - 1 && column1 == column) || (row1 == row - 1 && column1 == column + 1) || (row1 == row && column1 == column - 1) || (row1 == row && column1 == column + 1) || (row1 == row + 1 && column1 == column - 1) || (row1 == row + 1 && column1 == column) || (row1 == row + 1 && column1 == column + 1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
					{

						if (chess[row1][column1] == "  bK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 1 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}
					else
					{
						cout << "The King cannot be replaced on an Already Filled Space!";


						cout << "The Old Grid is:";
						cout << endl << endl;
						grid(chess);
					}
				}
				else
				{
					cout << "Wrong options selected!";
				}
			}

			else if (option1 == 2)			// As Option 2 was For the Queen
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aQ   ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your Next Possible positions are: ";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{

						if ((row == i) || (column == j))
						{
							if ((chess[i][j] != "  aR1  ") && (chess[i][j] != "  aK1  ") && (chess[i][j] != "  aB1  ") && (chess[i][j] != "  aQ   ") && (chess[i][j] != "  aK   ") && (chess[i][j] != "  aB2  ") && (chess[i][j] != "  aK2  ") && (chess[i][j] != "  aR2  "))
							{

								cout << "(" << i << "," << j << ")  ";

							}
						}

					}

				}


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
				{

					cout << "The Queen cannot be Placed on an Already Filled Space.";
					cout << endl;

				}

				else if ((chess[row1][column1] == "   *   ") || (chess[row1][column1] == "   -   "))
				{
					temp = chess[row][column];
					chess[row][column] = chess[row1][column1];
					chess[row1][column1] = temp;

					cout << "The new grid will be:";
					cout << endl << endl;
					grid(chess);
				}

				else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
				{

					if (chess[row1][column1] == "  bK   ")
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						grid(chess);
						cout << endl << endl;
						cout << "The King is Killed. Game Over!";
						cout << endl << endl << endl;
						cout << "----------------  PLAYER 1 WON  ----------------";
						cout << endl << endl << endl;

						score = 1;

					}
					else
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}
				}
			}

			else if (option1 == 3)			// As Option 3 was For the Bishop - 1
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aB1  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;


				//-------------------------------------------------------------------------------------------


				vector<pair<int, int>> moves = get_bishop_moves(row, column);
				cout << "Your possible Next moves are:  ";
				for (auto move : moves)
				{
					cout << "(" << move.first << ", " << move.second << ")" << ",";
				}

				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if (bishopcheck(row, column, row1, column1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
					{

						if (chess[row1][column1] == "  bK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 1 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}

				}
				else
				{
					cout << "Wrong options selected!";
				}



			}

			else if (option1 == 4)			// As Option 4 was For the Bishop - 2
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aB2  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;

				vector<pair<int, int>> moves = get_bishop_moves(row, column);
				cout << "Your possible Next moves are:  ";
				for (auto move : moves)
				{
					cout << "(" << move.first << ", " << move.second << ")" << ",";
				}

				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if (bishopcheck(row, column, row1, column1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
					{

						if (chess[row1][column1] == "  bK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 1 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}

				}
				else
				{
					cout << "Wrong options selected!";
				}



			}

			else if (option1 == 5)			// As Option 5 was For the Rook - 1
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aR1  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your Next Possible positions are: ";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{

						if ((row == i) || (column == j))
						{
							if ((chess[i][j] != "  aR1  ") && (chess[i][j] != "  aK1  ") && (chess[i][j] != "  aB1  ") && (chess[i][j] != "  aQ   ") && (chess[i][j] != "  aK   ") && (chess[i][j] != "  aB2  ") && (chess[i][j] != "  aK2  ") && (chess[i][j] != "  aR2  "))
							{

								cout << "(" << i << "," << j << ")  ";

							}
						}

					}

				}


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
				{

					cout << "The rook cannot be Placed on an Already Filled Space.";
					cout << endl;

				}

				else if ((chess[row1][column1] == "   *   ") || (chess[row1][column1] == "   -   "))
				{
					temp = chess[row][column];
					chess[row][column] = chess[row1][column1];
					chess[row1][column1] = temp;

					cout << "The new grid will be:";
					cout << endl << endl;
					grid(chess);
				}

				else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
				{

					if (chess[row1][column1] == "  bK   ")
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						grid(chess);
						cout << endl << endl;
						cout << "The King is Killed. Game Over!";
						cout << endl << endl << endl;
						cout << "----------------  PLAYER 1 WON  ----------------";
						cout << endl << endl << endl;

						score = 1;

					}
					else
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}
				}

			}

			else if (option1 == 6)						// As Option 6 was For the Rook - 2	
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aR2  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your Next Possible positions are: ";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{

						if ((row == i) || (column == j))
						{
							if ((chess[i][j] != "  aR1  ") && (chess[i][j] != "  aK1  ") && (chess[i][j] != "  aB1  ") && (chess[i][j] != "  aQ   ") && (chess[i][j] != "  aK   ") && (chess[i][j] != "  aB2  ") && (chess[i][j] != "  aK2  ") && (chess[i][j] != "  aR2  "))
							{

								cout << "(" << i << "," << j << ")  ";

							}
						}

					}

				}


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
				{

					cout << "The rook cannot be Placed on an Already Filled Space.";
					cout << endl;

				}

				else if ((chess[row1][column1] == "   *   ") || (chess[row1][column1] == "   -   "))
				{
					temp = chess[row][column];
					chess[row][column] = chess[row1][column1];
					chess[row1][column1] = temp;

					cout << "The new grid will be:";
					cout << endl << endl;
					grid(chess);
				}

				else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
				{

					if (chess[row1][column1] == "  bK   ")
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						grid(chess);
						cout << endl << endl;
						cout << "The King is Killed. Game Over!";
						cout << endl << endl << endl;
						cout << "----------------  PLAYER 1 WON  ----------------";
						cout << endl << endl << endl;

						score = 1;

					}
					else
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}
				}
			}

			else if (option1 == 7)			// As Option 7 was For the Knight - 1
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aK1  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;

				cout << "Your Next Possible Moves are:  " << "(" << row + 1 << "," << column - 2 << ") , (" << row - 1 << "," << column - 2 << ") , (" << row - 2 << "," << column - 1 << ") , (" << row - 2 << "," << column + 1 << ") , (" << row - 1 << "," << column + 2 << ") , (" << row + 1 << "," << column + 2 << ") , (" << row + 2 << "," << column - 1 << ") , (" << row + 2 << "," << column + 1 << ")";

				//-----------------------------------------------------------------------------------------------


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;


				if ((row1 == row + 1 && column1 == column - 2) || (row1 == row - 1 && column1 == column - 2) || (row1 == row - 2 && column1 == column - 1) || (row1 == row - 2 && column1 == column + 1) || (row1 == row - 1 && column1 == column + 2) || (row1 == row + 1 && column1 == column + 2) || (row1 == row + 2 && column1 == column - 1) || (row1 == row + 2 && column1 == column + 1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
					{

						if (chess[row1][column1] == "  bK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 1 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}
					else
					{
						cout << "The Knight cannot be replaced on an Already Filled Space!";


						cout << "The Old Grid is:";
						cout << endl << endl;
						grid(chess);
					}
				}
				else
				{
					cout << "Wrong options selected!";
				}



				//---------------------------------------------------------------------------------------------------



			}

			else if (option1 == 8)		// As Option 8 was For the Knight - 2
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  aK2  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;

				cout << "Your Next Possible Moves are:  " << "(" << row + 1 << "," << column - 2 << ") , (" << row - 1 << "," << column - 2 << ") , (" << row - 2 << "," << column - 1 << ") , (" << row - 2 << "," << column + 1 << ") , (" << row - 1 << "," << column + 2 << ") , (" << row + 1 << "," << column + 2 << ") , (" << row + 2 << "," << column - 1 << ") , (" << row + 2 << "," << column + 1 << ")";

				//-----------------------------------------------------------------------------------------------


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;


				if ((row1 == row + 1 && column1 == column - 2) || (row1 == row - 1 && column1 == column - 2) || (row1 == row - 2 && column1 == column - 1) || (row1 == row - 2 && column1 == column + 1) || (row1 == row - 1 && column1 == column + 2) || (row1 == row + 1 && column1 == column + 2) || (row1 == row + 2 && column1 == column - 1) || (row1 == row + 2 && column1 == column + 1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
					{

						if (chess[row1][column1] == "  bK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 1 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}
					else
					{
						cout << "The Knight cannot be replaced on an Already Filled Space!";


						cout << "The Old Grid is:";
						cout << endl << endl;
						grid(chess);
					}
				}
				else
				{
					cout << "Wrong options selected!";
				}



				//---------------------------------------------------------------------------------------------------

			}
		}
		else
		{
			cout << "Please select a Valid Input. Program Terminated.";
		}
		//-------------------------------------------------------------------------------------------------------------------------------------------
		cout << endl << endl;


		//Turn for User 2:

		cout << "---------------------------------------------------   PLAYER 02   ---------------------------------------------------";
		cout << endl << endl;

		option1 = option();

		if (option1 == 1 || option1 == 2 || option1 == 3 || option1 == 4 || option1 == 5 || option1 == 6 || option1 == 7 || option1 == 8)
		{
			if (option1 == 1)			// As Option 1 was for the King
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bK   ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your possible Next moves are:  (" << row - 1 << "," << column - 1 << ") , (" << row - 1 << "," << column << ") , (" << row - 1 << "," << column + 1 << ") , (" << row << "," << column - 1 << ") , (" << row << "," << column + 1 << ") , (" << row + 1 << "," << column - 1 << ") , (" << row + 1 << "," << column << ") , (" << row + 1 << "," << column + 1 << ")";
				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;
				if ((row1 == row - 1 && column1 == column - 1) || (row1 == row - 1 && column1 == column) || (row1 == row - 1 && column1 == column + 1) || (row1 == row && column1 == column - 1) || (row1 == row && column1 == column + 1) || (row1 == row + 1 && column1 == column - 1) || (row1 == row + 1 && column1 == column) || (row1 == row + 1 && column1 == column + 1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
					{

						if (chess[row1][column1] == "  aK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 2 WON  ----------------";
							cout << endl << endl << endl;
							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}
					else
					{
						cout << "The King cannot be replaced on an Already Filled Space!";


						cout << "The Old Grid is:";
						cout << endl << endl;
						grid(chess);
					}
				}
				else
				{
					cout << "Wrong options selected!";
				}
			}

			else if (option1 == 2)			// As Option 2 was for the Queen
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bQ   ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your Next Possible positions are: ";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{

						if ((row == i) || (column == j))
						{
							if ((chess[i][j] != "  bR1  ") && (chess[i][j] != "  bK1  ") && (chess[i][j] != "  bB1  ") && (chess[i][j] != "  bQ   ") && (chess[i][j] != "  bK   ") && (chess[i][j] != "  bB2  ") && (chess[i][j] != "  bK2  ") && (chess[i][j] != "  bR2  "))
							{

								cout << "(" << i << "," << j << ")  ";

							}
						}

					}

				}


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
				{

					cout << "The Queen cannot be Placed on an Already Filled Space.";
					cout << endl;

				}

				else if ((chess[row1][column1] == "   *   ") || (chess[row1][column1] == "   -   "))
				{
					temp = chess[row][column];
					chess[row][column] = chess[row1][column1];
					chess[row1][column1] = temp;

					cout << "The new grid will be:";
					cout << endl << endl;
					grid(chess);
				}

				else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
				{

					if (chess[row1][column1] == "  aK   ")
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						grid(chess);
						cout << endl << endl;
						cout << "The King is Killed. Game Over!";
						cout << endl << endl << endl;
						cout << "----------------  PLAYER 1 WON  ----------------";
						cout << endl << endl << endl;

						score = 1;

					}
					else
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}
				}
			}

			else if (option1 == 3)			// As Option 3 was for Bishop - 1
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bB1  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;

				vector<pair<int, int>> moves = get_bishop_moves(row, column);
				cout << "Your possible Next moves are:  ";
				for (auto move : moves)
				{
					cout << "(" << move.first << ", " << move.second << ")" << ",";
				}

				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if (bishopcheck(row, column, row1, column1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
					{

						if (chess[row1][column1] == "  aK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 2 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}

				}
				else
				{
					cout << "Wrong options selected!";
				}



			}

			else if (option1 == 4)					// As Option 4 was for Bishop - 2
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bB2  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;

				vector<pair<int, int>> moves = get_bishop_moves(row, column);
				cout << "Your possible Next moves are:  ";
				for (auto move : moves)
				{
					cout << "(" << move.first << ", " << move.second << ")" << ",";
				}

				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if (bishopcheck(row, column, row1, column1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
					{

						if (chess[row1][column1] == "  aK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 2 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}

				}
				else
				{
					cout << "Wrong options selected!";
				}



			}

			else if (option1 == 5)				// As Option 5 was for Rook - 1
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bR1  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your Next Possible positions are: ";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{

						if ((row == i) || (column == j))
						{
							if ((chess[i][j] != "  bR1  ") && (chess[i][j] != "  bK1  ") && (chess[i][j] != "  bB1  ") && (chess[i][j] != "  bQ   ") && (chess[i][j] != "  bK   ") && (chess[i][j] != "  bB2  ") && (chess[i][j] != "  bK2  ") && (chess[i][j] != "  bR2  "))
							{

								cout << "(" << i << "," << j << ")  ";

							}
						}

					}

				}


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
				{

					cout << "The rook cannot be Placed on an Already Filled Space.";
					cout << endl;

				}

				else if ((chess[row1][column1] == "   *   ") || (chess[row1][column1] == "   -   "))
				{
					temp = chess[row][column];
					chess[row][column] = chess[row1][column1];
					chess[row1][column1] = temp;

					cout << "The new grid will be:";
					cout << endl << endl;
					grid(chess);
				}
				else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
				{

					if (chess[row1][column1] == "  aK   ")
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						grid(chess);
						cout << endl << endl;
						cout << "The King is Killed. Game Over!";
						cout << endl << endl << endl;
						cout << "----------------  PLAYER 2 WON  ----------------";
						cout << endl << endl << endl;

						score = 1;

					}
					else
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}
				}

			}
			else if (option1 == 6)				// As Option 5 was for Rook - 2
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bR2  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl << endl;
				cout << "Your Next Possible positions are: ";
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{

						if ((row == i) || (column == j))
						{
							if ((chess[i][j] != "  bR1  ") && (chess[i][j] != "  bK1  ") && (chess[i][j] != "  bB1  ") && (chess[i][j] != "  bQ   ") && (chess[i][j] != "  bK   ") && (chess[i][j] != "  bB2  ") && (chess[i][j] != "  bK2  ") && (chess[i][j] != "  bR2  "))
							{

								cout << "(" << i << "," << j << ")  ";

							}
						}

					}

				}
				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;

				if ((chess[row1][column1] == "  bR1  ") || (chess[row1][column1] == "  bK1  ") || (chess[row1][column1] == "  bB1  ") || (chess[row1][column1] == "  bQ   ") || (chess[row1][column1] == "  bK   ") || (chess[row1][column1] == "  bB2  ") || (chess[row1][column1] == "  bK2  ") || (chess[row1][column1] == "  bR2  "))
				{

					cout << "The rook cannot be Placed on an Already Filled Space.";
					cout << endl;

				}

				else if ((chess[row1][column1] == "   *   ") || (chess[row1][column1] == "   -   "))
				{
					temp = chess[row][column];
					chess[row][column] = chess[row1][column1];
					chess[row1][column1] = temp;

					cout << "The new grid will be:";
					cout << endl << endl;
					grid(chess);
				}

				else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
				{

					if (chess[row1][column1] == "  aK   ")
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						grid(chess);
						cout << endl << endl;
						cout << "The King is Killed. Game Over!";
						cout << endl << endl << endl;
						cout << "----------------  PLAYER 2 WON  ----------------";
						cout << endl << endl << endl;

						score = 1;

					}
					else
					{
						chess[row1][column1] = chess[row][column];
						chess[row][column] = "   -   ";
						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}
				}
			}

			else if (option1 == 7)				// As Option 7 was for Knight - 1
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bK1  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;


				cout << "Your Next Possible Moves are:  " << "(" << row + 1 << "," << column - 2 << ") , (" << row - 1 << "," << column - 2 << ") , (" << row - 2 << "," << column - 1 << ") , (" << row - 2 << "," << column + 1 << ") , (" << row - 1 << "," << column + 2 << ") , (" << row + 1 << "," << column + 2 << ") , (" << row + 2 << "," << column - 1 << ") , (" << row + 2 << "," << column + 1 << ")";

				//-----------------------------------------------------------------------------------------------


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;


				if ((row1 == row + 1 && column1 == column - 2) || (row1 == row - 1 && column1 == column - 2) || (row1 == row - 2 && column1 == column - 1) || (row1 == row - 2 && column1 == column + 1) || (row1 == row - 1 && column1 == column + 2) || (row1 == row + 1 && column1 == column + 2) || (row1 == row + 2 && column1 == column - 1) || (row1 == row + 2 && column1 == column + 1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
					{

						if (chess[row1][column1] == "  aK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 1 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}
					else
					{
						cout << "The Knight cannot be replaced on an Already Filled Space!";


						cout << "The Old Grid is:";
						cout << endl << endl;
						grid(chess);
					}
				}
				else
				{
					cout << "Wrong options selected!";
				}



				//---------------------------------------------------------------------------------------------------







			}

			else if (option1 == 8)					// As Option 8 was for Knight - 2
			{
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						if (chess[i][j] == "  bK2  ")
						{
							row = i;
							column = j;
							break;
						}
					}
				}
				cout << endl;
				cout << "Your Current Position is:  " << "(" << row << "," << column << ")";
				cout << endl;


				cout << "Your Next Possible Moves are:  " << "(" << row + 1 << "," << column - 2 << ") , (" << row - 1 << "," << column - 2 << ") , (" << row - 2 << "," << column - 1 << ") , (" << row - 2 << "," << column + 1 << ") , (" << row - 1 << "," << column + 2 << ") , (" << row + 1 << "," << column + 2 << ") , (" << row + 2 << "," << column - 1 << ") , (" << row + 2 << "," << column + 1 << ")";

				//-----------------------------------------------------------------------------------------------


				cout << endl << endl;
				cout << "Enter your Row Number:  ";
				cin >> row1;
				cout << "Enter your Column Number:  ";
				cin >> column1;
				cout << endl << endl;


				if ((row1 == row + 1 && column1 == column - 2) || (row1 == row - 1 && column1 == column - 2) || (row1 == row - 2 && column1 == column - 1) || (row1 == row - 2 && column1 == column + 1) || (row1 == row - 1 && column1 == column + 2) || (row1 == row + 1 && column1 == column + 2) || (row1 == row + 2 && column1 == column - 1) || (row1 == row + 2 && column1 == column + 1))
				{
					if ((chess[row1][column1] == "   -   ") || (chess[row1][column1] == "   *   "))
					{

						temp = chess[row][column];
						chess[row][column] = chess[row1][column1];
						chess[row1][column1] = temp;

						cout << "The new grid will be:";
						cout << endl << endl;
						grid(chess);
					}

					else if ((chess[row1][column1] == "  aR1  ") || (chess[row1][column1] == "  aK1  ") || (chess[row1][column1] == "  aB1  ") || (chess[row1][column1] == "  aQ   ") || (chess[row1][column1] == "  aK   ") || (chess[row1][column1] == "  aB2  ") || (chess[row1][column1] == "  aK2  ") || (chess[row1][column1] == "  aR2  "))
					{

						if (chess[row1][column1] == "  aK   ")
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";
							grid(chess);
							cout << endl << endl;
							cout << "The King is Killed. Game Over!";
							cout << endl << endl << endl;
							cout << "----------------  PLAYER 1 WON  ----------------";
							cout << endl << endl << endl;

							score = 1;

						}
						else
						{
							chess[row1][column1] = chess[row][column];
							chess[row][column] = "   -   ";

							cout << "The new grid will be:";
							cout << endl << endl;
							grid(chess);
						}
					}
					else
					{
						cout << "The Knight cannot be replaced on an Already Filled Space!";


						cout << "The Old Grid is:";
						cout << endl << endl;
						grid(chess);
					}
				}
				else
				{
					cout << "Wrong options selected!";
				}



				//---------------------------------------------------------------------------------------------------





			}
			//-------------------------------------------------------------------------------------------------------------------------------------------


			cout << endl << endl << endl;
		}
	}
}