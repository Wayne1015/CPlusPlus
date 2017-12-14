// TicTacToe2Thackston.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';


void instructions();
char askQuestion(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>* const pBoard);
char winner(const vector<char>* const pBoard);
bool isLegal(const vector<char>* const pBoard, int move);
int humanMove(const vector<char>* const pBoard, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);


int main()
{
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	instructions();
	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;
	displayBoard(&board);

	while (winner(&board) == NO_ONE)
	{
		if (turn == human)
		{
			move = humanMove(&board, human);
			board[move] = human;
		}
		else
		{
			move = computerMove(board, computer);
			board[move] = computer;
		}
		displayBoard(&board);
		turn = opponent(turn);
	}

	announceWinner(winner(&board), computer, human);

	return 0;
}


void instructions()
{
	cout << "Welcome to Tic Tac Toe.\n";

	cout << "To make a move enter a number between 0 and 8" << endl;

	cout << "       0 | 1 | 2\n";
	cout << "       ---------\n";
	cout << "       3 | 4 | 5\n";
	cout << "       ---------\n";
	cout << "       6 | 7 | 8\n";
}

char askQuestion(string question)
{
	char response;
	do
	{
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	return response;
}

int askNumber(string question, int high, int low)
{
	int number;
	do
	{
		cout << question << " (" << low << " - " << high << "): ";
		cin >> number;
	} while (number > high || number < low);

	return number;
}

char humanPiece()
{
	char go_first = askQuestion("Would you like the first move?");
	if (go_first == 'y')
	{
		cout << "\nGood Luck!\n";
		return X;
	}
	else
	{
		cout << "\nVery well I'll go first";
		return O;
	}
}

char opponent(char piece)
{
	if (piece == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

void displayBoard(const vector<char>* const pBoard)
{
	cout << "\n\t" << (*pBoard)[0] << " | " << (*pBoard)[1] << " | " << (*pBoard)[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << (*pBoard)[3] << " | " << (*pBoard)[4] << " | " << (*pBoard)[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << (*pBoard)[6] << " | " << (*pBoard)[7] << " | " << (*pBoard)[8];
	cout << "\n\n";
}

char winner(const vector<char>* const pBoard)
{

	const int WINNING_ROWS[8][3] = { { 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 0, 4, 8 },
	{ 2, 4, 6 } };
	const int TOTAL_ROWS = 8;


	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
		if (((*pBoard)[WINNING_ROWS[row][0]] != EMPTY) &&
			((*pBoard)[WINNING_ROWS[row][0]] == (*pBoard)[WINNING_ROWS[row][1]]) &&
			((*pBoard)[WINNING_ROWS[row][1]] == (*pBoard)[WINNING_ROWS[row][2]]))
		{
			return (*pBoard)[WINNING_ROWS[row][0]];
		}
	}

	if (count(pBoard->begin(), pBoard->end(), EMPTY) == 0)
		return TIE;

	return NO_ONE;
}

inline bool isLegal(int move, const vector<char>* pBoard)
{
	return ((*pBoard)[move] == EMPTY);
}

int humanMove(const vector<char>* const pBoard, char human)
{
	int move = askNumber("Where will you move?", (pBoard->size() - 1));
	while (!isLegal(move, pBoard))
	{
		cout << "\nThat square is taken already\n";
		move = askNumber("Where will you move?", (pBoard->size() - 1));
	}
	return move;
}

int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;

	while (!found && move < board.size())
	{
		if (isLegal(move, &board))
		{
			board[move] = computer;

			found = winner(&board) == computer;

			board[move] = EMPTY;
		}

		if (!found)
		{
			++move;
		}
	}


	if (!found)
	{
		move = 0;
		char human = opponent(computer);

		while (!found && move < board.size())
		{
			if (isLegal(move, &board))
			{
				board[move] = human;

				found = winner(&board) == human;

				board[move] = EMPTY;
			}

			if (!found)
			{
				++move;
			}
		}
	}


	if (!found)
	{
		move = 0;
		unsigned int i = 0;

		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };

		while (!found && i <  board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(move, &board))
			{
				found = true;
			}

			++i;
		}
	}

	cout << "I'll move to square " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << "'s won!\n";
		cout << "Better luck next time!";
	}

	else if (winner == human)
	{
		cout << winner << "'s won!\n";
		cout << "Good job!";
	}

	else
	{
		cout << "It's a tie.\n";

	}
}




