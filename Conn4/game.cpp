#include "game.h"



game::game()
{
	srand(time(NULL));
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

void game::drop_piece(int board[ROW_COUNT][COLUMN_COUNT], int row, int col, int piece)
{
	board[row][col] = piece;
}

int game::is_valid_location(int board[ROW_COUNT][COLUMN_COUNT], int col)
{
	return board[ROW_COUNT][col] == 0;
}

int game::get_next_open_row(int board[ROW_COUNT][COLUMN_COUNT], int col)
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		if (board[row][col] == 0)
			return row;
	}
}

void game::print_board()
{
	for (int row = 0; row < ROW_COUNT; row++)
	{
		for (int column = 0; column < COLUMN_COUNT; column++)
		{
			cout << board[row][column] << " ";
		}
		cout << endl;
	}
}

bool game::winning_move(int board[ROW_COUNT][COLUMN_COUNT], int piece)
{
	// Check horizontal locations for win
	for (int c = 0; c < COLUMN_COUNT - 3; c++)
	{
		for (int r = 0; r < ROW_COUNT; r++)
		{
			if ((board[r][c] == piece) && (board[r][c + 1] == piece) && (board[r][c + 2] == piece) && (board[r][
				c + 3] == piece))
				return true;
		}
	}

	//# Check vertical locations for win
	for (int c = 0; c < COLUMN_COUNT; c++)
	{
		for (int r = 0; r < ROW_COUNT - 3; r++)
		{
			if ((board[r][c] == piece) && (board[r + 1][c] == piece) && (board[r + 2][c] == piece) && (board[r + 3][
				c] == piece))
				return true;
		}
	}


	//# Check positively sloped diaganols
	for (int c = 0; c < COLUMN_COUNT - 3; c++)
	{
		for (int r = 0; r < ROW_COUNT - 3; r++)
		{
			if ((board[r][c] == piece) && (board[r + 1][c + 1] == piece) && (board[r + 2][c + 2] == piece) && (board[r + 3][
				c + 3] == piece))
				return true;
		}
	}

	//# Check negatively sloped diaganols
	for (int c = 0; c < COLUMN_COUNT - 3; c++)
	{
		for (int r = 0; r < ROW_COUNT; r++)
		{
			if ((board[r][c] == piece) && (board[r - 1][c + 1] == piece) && (board[r - 2][c + 2] == piece) && (board[r - 3][
				c + 3] == piece))
				return true;
		}
	}
	return false;
}

int game::evaluate_window(int window, int piece)
{
	int score = 0;
	int opp_piece = PLAYER;
	if (piece == PLAYER)
	{
		opp_piece = AI;
	}
	return 0;
}

int game::score_position(int board, int piece)
{
	int score = 0;

    //## Score center column
	//int center_array = [int(i) for i in list(board[:, COLUMN_COUNT // 2])];
	int center;
	int center_count = 0; //center_array.count(piece);
	score += center_count * 3;

 //   //## Score Horizontal
 //   for r in range(ROW_COUNT):
 //       row_array = [int(i) for i in list(board[r, :])]
 //       for c in range(COLUMN_COUNT - 3):
 //           window = row_array[c:c + WINDOW_LENGTH]
 //           score += evaluate_window(window, piece)

 //   //## Score Vertical
 //   for c in range(COLUMN_COUNT):
 //       col_array = [int(i) for i in list(board[:, c])]
 //       for r in range(ROW_COUNT - 3):
 //           window = col_array[r:r + WINDOW_LENGTH]
 //           score += evaluate_window(window, piece)

 //   //## Score posiive sloped diagonal
 //   for r in range(ROW_COUNT - 3):
 //       for c in range(COLUMN_COUNT - 3):
 //           window = [board[r + i][c + i] for i in range(WINDOW_LENGTH)]
 //           score += evaluate_window(window, piece)

 //   for r in range(ROW_COUNT - 3):
 //       for c in range(COLUMN_COUNT - 3):
 //           window = [board[r + 3 - i][c + i] for i in range(WINDOW_LENGTH)]
 //           score += evaluate_window(window, piece)

	return score;
}

int game::is_terminal_node(int board[ROW_COUNT][COLUMN_COUNT])
{

	//todo sizeof(valid_locations) == 0 will always be true since the array is always init to rows * columns
	//todo continue need to create a function that returns true or false if their are no other locations
	return (winning_move(board, PLAYER) || winning_move(board, AI) || get_valid_locations(board) == -1);

}

int game::minimax(int board, int depth, int alpha, int beta, int maximizingPlayer)
{
	return 0;
}

int game::get_valid_locations(int board[ROW_COUNT][COLUMN_COUNT])
{
	//todo this function will always have 42 items in it. and it uses 0 also know as a column and false
	int count = -1;
	for (int col = 0; col < COLUMN_COUNT; col++)
		if (is_valid_location(board, col))
		{
			count++;
			valid_locations[count] = col;
		}
	return count;
}

int game::pick_best_move(int board[ROW_COUNT][COLUMN_COUNT], int piece)
{
	get_valid_locations(board);
	int best_score = -10000;
	int valid_locations_count = get_valid_locations(board);
	int best_col = valid_locations[rand() % valid_locations_count];
	//todo finish this function after fixing the valid locaiton problem

	return 0;
}

void game::draw_board(int board)
{
}
