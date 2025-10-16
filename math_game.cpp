#include<iostream>
#include<string>


using namespace std;
enum enop_level { EASY = 1, MEDIUM = 2, HARD = 3, RANDOM = 4 };
enum enop_operation { ADDITION = 1, SUBTRACTION = 2, MULTIPLICATION = 3, DIVISION = 4, RANDOM_OPRATION = 5 };

struct stquestion {
	int num_1 = 0;
	int num_2 = 0;
	short level = 1;
	short operation = 1;
	int result = 0;
	int user_answer = 0;
	bool is_answered = false;
};
struct stgame {
	stquestion question;
	stquestion questions_groop[100];
	short level = 1;
	short operation = 1;
	short right_answers = 0;
	short wrong_answers = 0;
	short question_count = 0;
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
void pause_screen() {
	cout << "Press Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
	cin.get(); // Wait for user to press Enter
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

void make_question(stquestion& question) {
	switch (question.operation)
	{
	case ADDITION:
		question.result = add(question.num_1, question.num_2);
		break;
	case SUBTRACTION:
		if (question.num_1 < question.num_2)
		{
			swap(question.num_1, question.num_2);
		}
		question.result = subtract(question.num_1, question.num_2);
		break;
	case MULTIPLICATION:
		question.result = mutiplay(question.num_1, question.num_2);
		break;
	case DIVISION:
		if (question.num_2 == 0)
			question.num_2 = 1;
		question.result = divde(question.num_1, question.num_2);
		break;
	case RANDOM_OPRATION:
		question.operation = static_cast<short>(random_number(ADDITION, DIVISION));
		make_question(question);
		break;
	default:
		break;
	}
}
void generate_question(stquestion& question) {
	switch (question.level)
	{
	case EASY:
		question.num_1 = random_number(1, 10);
		question.num_2 = random_number(1, 10);
		break;
	case MEDIUM:
		question.num_1 = random_number(10, 50);
		question.num_2 = random_number(10, 50);
		break;
	case HARD:
		question.num_1 = random_number(50, 100);
		question.num_2 = random_number(50, 100);
		break;
	case RANDOM:
		question.level = static_cast<short>(random_number(EASY, HARD));
		generate_question(question);
		break;
	default:
		break;
	}
	//make_question(question);
}
void save_question_to_game(stgame& game, const stquestion& question) {
	game.questions_groop[game.question_count] = question;
	game.question_count++;
}
string opration_symbol(short operation) {
	switch (operation)
	{
	case ADDITION:
		return "+";
	case SUBTRACTION:
		return "-";
	case MULTIPLICATION:
		return "*";
	case DIVISION:
		return "/";
	default:
		return "?";
	}
}
void queston_header(const stquestion& question) {
	cout << "what is : " << endl;
	cout << "      " << question.num_1 << endl;
	cout << "   " << opration_symbol(question.operation) << "  " << question.num_2 << endl;
	cout << "   -----------" << endl;
}
void ask_question(stquestion& question) {
	queston_header(question);
	cin >> question.user_answer;
	question.is_answered = true;
}
bool compeare_result(int result1, int result2) {
	return result1 == result2;
}
void compare_answer(stgame& game, stquestion& question) {
	if (compeare_result(question.user_answer, question.result))
	{
		system("color 2F");
		cout << "correct answer :)" << endl;
		pause_screen();
		game.right_answers++;
	}
	else
	{
		system("color 40");
		cout << "wrong answer :( the correct answer is : " << question.result << endl;
		pause_screen();
		game.wrong_answers++;
	}
}

void welcome_message() {
	cout << "==========================" << endl;
	cout << "      Welcome to" << endl;
	cout << "      Math Game" << endl;
	cout << "==========================" << endl;
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
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}


void game_summary(const stgame& game) {
	//clear_screen();
	if (game.right_answers > game.wrong_answers)
	{
		system("color 2F");
		cout << "\tcongratulations you win the game" << endl;
	}
	else
	{
		system("color 40");
		//system("\a");
		cout << "\tsorry you lose the game" << endl;
	}
	cout << "\n\t==========================" << endl;
	cout << "\tGame Summary:" << endl;
	cout << "\tLevel: " << game.level << endl;
	cout << "\tnumber of questions: " << game.right_answers + game.wrong_answers << endl;
	cout << "\tRight Answers: " << game.right_answers << endl;
	cout << "\tWrong Answers: " << game.wrong_answers << endl;
	cout << "\t==========================" << endl;
}

void read_questions_from_array(stgame& game) {
	for (short i = 0; i < game.question_count; i++)
	{
		stquestion& question = game.questions_groop[i];
		queston_header(question);
		cout << "Your answer: " << question.user_answer << endl;
		cout << "Correct answer: " << question.result << endl;
		if (compeare_result(question.user_answer, question.result))
			cout << "Result: Correct :)" << endl;
		else
			cout << "Result: Wrong :(" << endl;
		cout << "--------------------------" << endl;
	}
}

void play_math_game()
{
	stgame game;
	welcome_message();
	show_level_menu();
	game.level = user_input(EASY, RANDOM);
	show_operation_menu();
	game.operation = user_input(ADDITION, RANDOM_OPRATION);
	clear_screen();
	cout << "How many questions do you want to answer ? ";
	short question_count = user_input(1, 100);
	for (short i = 0; i < question_count; i++)
	{
		game.question.level = game.level;
		game.question.operation = game.operation;
		generate_question(game.question);
		make_question(game.question);
		ask_question(game.question);
		compare_answer(game, game.question);
		save_question_to_game(game, game.question);
		clear_screen();
	}
	read_questions_from_array(game);
	game_summary(game);

}
