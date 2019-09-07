#pragma once
class game
{
public:
	game();
	~game();
	void create_board();
	void drop_piece(int board, int row, int col, int piece);
	int is_valid_location(int board, int col);
	int get_next_open_row(int board, int col);
	void print_board(int board);
	bool winning_move(int board, int piece);
	int evaluate_window(int window, int piece);
	int  score_position(int board, int piece);
	int is_terminal_node(int board);
	int minimax(int board, int depth, int alpha, int beta, int maximizingPlayer);
	int get_valid_locations(int board);
	int pick_best_move(int board, int piece);
	void draw_board(int board);

};

