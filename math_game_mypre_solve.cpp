#include<iostream>
#include<string>


using namespace std;
enum enop_level { EASY = 1, MEDIUM = 2, HARD = 3, RANDOM = 4 };
enum enop_operation { ADDITION = 1, SUBTRACTION = 2, MULTIPLICATION = 3, DIVISION = 4, RANDOM_OPRATION = 5 };
enum enop_symbol { ADD = 1, SUBTRACT = 2, MULTIPLY = 3, DVIDE = 4 };

struct stgame {
	int num_1 = 0;
	int num_2 = 0;
	enop_symbol symbol;
	short level = 1;
	short operation = 1;
	int result = 0;
	int user_answer = 0;
	short right_answers = 0;
	short wrong_answers = 0;
	short currnt_opration = 0;
};

void play_math_game();
int main()
{

	srand((unsigned)time(NULL));
	play_math_game();
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

int add(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
}
int mutiplay(int a, int b) {
	return a * b;
}
int divde(int a, int b) {
	if (b == 0)
		b = 1;
	return a / b;
}

enop_level opration_level(short level) {
	switch (level) {
	case 1:
		return EASY;
	case 2:
		return MEDIUM;
	case 3:
		return HARD;
	case 4:
		return RANDOM;
	}
	return EASY;
}
enop_operation opration_type(short type) {
	switch (type) {
	case 1:
		return ADDITION;
	case 2:
		return SUBTRACTION;
	case 3:
		return MULTIPLICATION;
	case 4:
		return DIVISION;
	case 5:
		return RANDOM_OPRATION;
	}
	return ADDITION;
}
string opration_symbol(enop_symbol symbol) {
	switch (symbol) {
	case ADD:
		return "+";
	case SUBTRACT:
		return "-";
	case MULTIPLY:
		return "X";
	case DVIDE:
		return "/";
	}
	return "";
}

void select_opration_type(short type, stgame& game) {
	switch (opration_type(type)) {
	case ADDITION:
		game.symbol = ADD;
		game.currnt_opration = type;
		game.result = add(game.num_1, game.num_2);
		break;
	case SUBTRACTION:
		game.symbol = SUBTRACT;
		game.currnt_opration = type;
		if (game.num_1 < game.num_2)
			swap(game.num_1, game.num_2);
		game.result = subtract(game.num_1, game.num_2);
		break;
	case MULTIPLICATION:
		game.symbol = MULTIPLY;
		game.currnt_opration = type;
		game.result = mutiplay(game.num_1, game.num_2);
		break;
	case DIVISION:
		game.symbol = DVIDE;
		game.currnt_opration = type;
		game.result = divde(game.num_1, game.num_2);
		break;
	case RANDOM_OPRATION:
		select_opration_type(random_number(1, 4), game);
		break;
	default:
		game.result = add(game.num_1, game.num_2);
		break;
	}
}
void select_level(short level, stgame& game) {
	switch (opration_level(level)) {
	case EASY:
		game.num_1 = random_number(1, 10);
		game.num_2 = random_number(1, 10);
		break;
	case MEDIUM:
		game.num_1 = random_number(11, 50);
		game.num_2 = random_number(11, 50);
		break;
	case HARD:
		game.num_1 = random_number(50, 500);
		game.num_2 = random_number(50, 500);
		break;
	case RANDOM:
		select_level(random_number(1, 3), game);
		break;

	default:
		game.num_1 = random_number(1, 10);
		game.num_2 = random_number(1, 10);
		break;
	}
}

void show_level_menu() {
	cout << "Select level: " << endl;
	cout << "1- Easy" << endl;
	cout << "2- Medium" << endl;
	cout << "3- Hard" << endl;
	cout << "4- Random" << endl;
}
void show_operation_menu() {
	cout << "Select operation type: " << endl;
	cout << "1- Add" << endl;
	cout << "2- Subtract" << endl;
	cout << "3- Multiply" << endl;
	cout << "4- Divide" << endl;
	cout << "5- Random" << endl;
}
void clear_screen() {
	system("cls"); // For Windows
	// system("clear"); // For Linux/Unix
	//cout << string(100, '\n'); // Simple way to simulate clearing the screen
}
void pause_screen() {
	cout << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
	cin.get(); // Wait for user to press Enter
}

void ask_qustion(stgame& game) {
	cout << "what : " << endl;
	cout << "      " << game.num_1 << endl;
	cout << "          " << opration_symbol(game.symbol) << endl;
	cout << "      " << game.num_2 << endl;
	cout << "   -----------" << endl;
	cin >> game.user_answer;
}
bool compeare_result(int result1, int result2) {
	return result1 == result2;
}

void game_summary(const stgame& game) {
	clear_screen();
	if (compeare_result(game.user_answer, game.result))
	{
		system("color 2F");
		cout << "congratulations you win the game" << endl;
	}
	else
	{
		system("color 40");
		cout << "sorry you lose the game" << endl;
	}
	cout << "\n==========================" << endl;
	cout << "Game Summary:" << endl;
	cout << "Level: " << game.level << endl;
	cout << "number of questions: " << game.right_answers + game.wrong_answers << endl;
	cout << "Right Answers: " << game.right_answers << endl;
	cout << "Wrong Answers: " << game.wrong_answers << endl;
	cout << "==========================" << endl;
}


void play_math_game()
{
	stgame game;
	show_level_menu();
	game.level = user_input(1, 4);
	show_operation_menu();
	game.operation = user_input(1, 5);
	clear_screen();
	short questions_count = 0;
	cout << "How many questions you want to answer?" << endl;
	cin >> questions_count;

	for (short i = 0; i < questions_count; i++)
	{
		system("color 0F");
		select_level(game.level, game);
		select_opration_type(game.operation, game);
		ask_qustion(game);
		if (compeare_result(game.user_answer, game.result))
		{
			system("color 2F");
			cout << "Right answer" << endl;
			game.right_answers++;
		}
		else
		{
			system("color 40");
			cout << "Wrong answer" << endl;
			cout << "The write answer is : " << game.result << endl;
			game.wrong_answers++;
		}
		pause_screen();
	}
	game_summary(game);
}
