#include<iostream>
#include<string>



using namespace std;
enum enoption { stone = 1, paper = 2, scissor = 3 };
struct sgame {
	string player_name = "player";
	short round_number = 0;
	short total_round_number = 0;
	short player_score = 0;
	short total_player_score = 0;
	short computer_score = 0;
	short total_computer_score = 0;
	short total_draw_rounds = 0;
};
void start_game(sgame& game);
void game_stone_paper_scissor();

int main()
{

	srand((unsigned)time(NULL));

	game_stone_paper_scissor();

}


int random_number(short from, short to)
{
	return rand() % (to - from + 1) + from;
}

short user_input(short from, short to)
{
	short select = 0;
	while (true)
	{
		cout << "Enter your selection ";
		cin >> select;

		// Check if input is valid and within range
		if (cin.fail() || select < from || select > to)
		{
			cout << "Wrong selection. Try again: ";
			cin.clear(); // Clear error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
		}
		else
		{
			break;
		}
	}
	return select;
}
string show_selection(enoption option)
{
	if (option == stone)
		return "stone";
	else if (option == paper)
		return "paper";
	else
		return "scissor";
}

void show_user_option()
{
	cout << "please select \n";
	cout << "[1] stone \n";
	cout << "[2] paper \n";
	cout << "[3] scissor \n";
}

enoption user_selection(short input)
{
	switch (input)
	{
	case 1:
		return stone;
	case 2:
		return paper;
	case 3:
		return scissor;
	}
	return scissor;
}
enoption computer_selection()
{
	short input = random_number(1, 3);
	return user_selection(input);
}


void user_win(sgame& game)
{
	system("color 2F");
	cout << "\n------------------\n";
	cout << "|--" << game.player_name << " WIN-- | ";
	cout << "\n------------------\n";
	game.player_score++;
	cout << game.player_name << " score :" << game.player_score << "\n";
	cout << "computer score : " << game.computer_score << "\n";
	game.total_player_score++;
}
void computer_win(sgame& game)
{
	system("color 40");
	cout << "\n------------------\n";
	cout << "|--COMPUTER WIN--|";
	cout << "\n------------------\n";
	cout << "\a";
	game.computer_score++;
	cout << game.player_name << " score :" << game.player_score << "\n";
	cout << "computer score : " << game.computer_score << "\n";
	game.total_computer_score++;
}
void game_draw(sgame& game)
{
	system("color 60");
	cout << "\n------------------\n";
	cout << "|----DRAW GAME----|";
	cout << "\n------------------\n";
	game.total_draw_rounds++;
	cout << game.player_name << " score :" << game.player_score << "\n";
	cout << "computer score : " << game.computer_score << "\n";
}

void show_round_result(enoption user1, enoption user2, sgame& game)
{
	cout << game.player_name << " : " << show_selection(user1);
	cout << "     computer : " << " " << show_selection(user2);
}
void game_logic(sgame& game)
{
	enoption user = user_selection(user_input(1, 3));
	enoption computer = computer_selection();

	if (user == computer)
	{
		show_round_result(user, computer, game);
		game_draw(game);
	}
	else if ((user == stone && computer == scissor) ||
		(user == paper && computer == stone) ||
		(user == scissor && computer == paper))
	{
		show_round_result(user, computer, game);
		user_win(game);
	}
	else
	{
		show_round_result(user, computer, game);
		computer_win(game);
	}
}
short rounds(short num_of_round, sgame& game)
{
	short round = 0;
	while (round < num_of_round)
	{
		game.round_number++;
		cout << "\n------Round [" << game.round_number << "]------\n";
		game_logic(game);
		round++;
		game.total_round_number++;
		cout << "\n---------------------------------\n";
	}
	return round;
}
void start_game(sgame& game)
{
	cout << "\n**************************\n";
	cout << "******WELCOME TO GAME******";
	cout << "\n**************************\n";
	string name;
	cout << "please Enter your Name : ";
	cin >> name;
	game.player_name = name;
}
void game_over(sgame game)
{
	system("cls");
	if (game.total_player_score > game.total_computer_score)
	{
		system("color 2F");
		cout << "\n\t----CONGRATULATION YOU WIN----" << endl;
	}
	else if (game.total_player_score < game.total_computer_score)
	{
		system("color 40");
		cout << "\n\t----HARDLUCK COMPUTER WIN----" << endl;
	}
	else
	{
		system("color 60");
		cout << "\n\t----GAME DROW----" << endl;
	}

	cout << "\n\t--------------- \n";
	cout << "\t|--GAME OVER--|";
	cout << "\n\t---------------\n";
	cout << "\ttotal round : " << game.total_round_number << endl;
	cout << "\ttotal draw round : " << game.total_draw_rounds << endl;
	cout << "\ttotal " << game.player_name << " score: " << game.total_player_score << endl;
	cout << "\ttotal computer score :" << game.total_computer_score << endl;
	cout << "\n**********************************\n";
}
void game_default(sgame& game)
{
	game.player_score = 0;
	game.computer_score = 0;
	game.total_player_score = 0;
	game.total_computer_score = 0;
	game.total_round_number = 0;
	game.round_number = 0;
	game.total_draw_rounds = 0;
	system("color 07");
}

void game_stone_paper_scissor()
{

	short answer = 2;
	short num_of_round = 0;
	sgame game;
	start_game(game);
	do {
		system("cls");
		cout << "How many rounds do you want to play :";
		cin >> num_of_round;
		show_user_option();
		rounds(num_of_round, game);
		system("pause");
		game_over(game);
		cout << "\ndo you want to play again ? Enter[1] = Yes OR [2] =No \n";
		answer = user_input(1, 2);
		game_default(game);
	} while (answer != 2);
}