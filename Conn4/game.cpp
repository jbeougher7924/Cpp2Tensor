#include "game.h"



game::game()
{
}


game::~game()
{
}

void game::create_board()
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			board[row][column] = 0;
		}
	}
}

void game::drop_piece(int board, int row, int col, int piece)
{
}

int game::is_valid_location(int board, int col)
{
	return 0;
}

int game::get_next_open_row(int board, int col)
{
	return 0;
}

void game::print_board()
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			cout <<  board[row][column] << " ";
		}
		cout << endl;
	}
}

bool game::winning_move(int board, int piece)
{
	return false;
}

int game::evaluate_window(int window, int piece)
{
	return 0;
}

int game::score_position(int board, int piece)
{
	return 0;
}

int game::is_terminal_node(int board)
{
	return 0;
}

int game::minimax(int board, int depth, int alpha, int beta, int maximizingPlayer)
{
	return 0;
}

int game::get_valid_locations(int board)
{
	return 0;
}

int game::pick_best_move(int board, int piece)
{
	return 0;
}

void game::draw_board(int board)
{
}
