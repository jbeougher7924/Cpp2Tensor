#include <iostream>
#include "game.h"


using namespace std;



int main()
{
	game ML_game = game();

	ML_game.create_board();
	ML_game.print_board();
	return 0;

}

