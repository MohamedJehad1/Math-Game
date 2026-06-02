#include <iostream>
#include <cstdlib>    
#include <ctime>      
using namespace std;

short Read_Num_Questions()
{
	short Num_Questions;
	do
	{
		cout << "Please enter the number of questions you want to answer : ";
		cin >> Num_Questions;
	} while (Num_Questions <= 0);
	system("cls");
	return Num_Questions;
}
enum enLevel
{
	Easy = 1,
	Medium = 2,
	Hard = 3
};
enum enOperator
{
	Add = 1, Sub = 2, Mul = 3, Div = 4, Mod = 5, Mix = 6
};
enum enAgain
{
	Yes = 1, No = 2
};
short Read_Level()
{
	short Level;
	do
	{
		cout << "Please choice the level of the game ? \n[1] Easy\n[2]Medium\n[3] Hard" << endl;
		cin >> Level;
	} while (Level < 1 || Level > 3);
	system("cls");
	return Level;
}
short Read_Operator()
{
	short Operator;
	do
	{
		cout << "Please choice the operator of the game ? \n[1] Add\n[2] Sub\n[3] Mul\n[4] Div\n[5] Mod\n[6] Mix" << endl;
		cin >> Operator;
	} while (Operator < 1 || Operator > 6);
	system("cls");
	return Operator;
}
short Random_Num(short Level)
{
	short Num = 0;
	switch (Level)
	{
	case enLevel::Easy:
		Num = rand() % 10 + 1;
		break;
	case enLevel::Medium:
		Num = rand() % 90 + 10;
		break;
	case enLevel::Hard:
		Num = rand() % 900 + 100;
		break;
	default:
		break;
	}
	return Num;
}
struct stQuestion
{
	short Num1 = 0;
	short Num2 = 0;
	enOperator Operator = Add;
	short Result = 0;
	string Status = "";
};

short Ask_Question(stQuestion& Question, short& Correct_Answer, short& Wrong_Answer, short Level, short Operator)
{
	Question.Num1 = Random_Num(Level);
	Question.Num2 = Random_Num(Level);
	Question.Operator = (enOperator)Operator;
	switch (Question.Operator)
	{
	case enOperator::Add:
		cout << Question.Num1 << " + " << Question.Num2 << " = ?" << endl;
		Question.Result = Question.Num1 + Question.Num2;
		break;
	case enOperator::Sub:
		cout << Question.Num1 << " - " << Question.Num2 << " = ?" << endl;
		Question.Result = Question.Num1 - Question.Num2;
		break;
	case enOperator::Mul:
		cout << Question.Num1 << " * " << Question.Num2 << " = ?" << endl;
		Question.Result = Question.Num1 * Question.Num2;
		break;
	case enOperator::Div:
		cout << Question.Num1 << " / " << Question.Num2 << " = ?" << endl;
		Question.Result = Question.Num1 / Question.Num2;
		break;
	case enOperator::Mod:
		cout << Question.Num1 << " % " << Question.Num2 << " = ?" << endl;
		Question.Result = Question.Num1 % Question.Num2;
		break;
	case enOperator::Mix:
		switch (rand() % 5 + 1)
		{
		case enOperator::Add:
			cout << Question.Num1 << " + " << Question.Num2 << " = ?" << endl;
			Question.Result = Question.Num1 + Question.Num2;
			break;
		case enOperator::Sub:
			cout << Question.Num1 << " - " << Question.Num2 << " = ?" << endl;
			Question.Result = Question.Num1 - Question.Num2;
			break;
		case enOperator::Mul:
			cout << Question.Num1 << " * " << Question.Num2 << " = ?" << endl;
			Question.Result = Question.Num1 * Question.Num2;
			break;
		case enOperator::Div:
			cout << Question.Num1 << " / " << Question.Num2 << " = ?" << endl;
			Question.Result = Question.Num1 / Question.Num2;
			break;
		case enOperator::Mod:
			cout << Question.Num1 << " % " << Question.Num2 << " = ?" << endl;
			Question.Result = Question.Num1 % Question.Num2;
			break;
		}
		break;
	default:
		break;
	}
	short Answer;
	cin >> Answer;
	if (Answer == Question.Result)
	{
		system("color 2F");
		Question.Status = "Correct";
		return Correct_Answer++;
	}
	else
	{
		system("color 4F");
		Question.Status = "Wrong";
		cout << "Correct answer = " << Question.Result << endl;
		return Wrong_Answer++;
	}

}
void Print_Score_Status(short& Correct_Answer, short& Wrong_Answer)
{
	if (Correct_Answer > Wrong_Answer)
	{
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "------------ ****   Congratulations, you win the game   **** ----------------" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		system("color 2F");
	}
	else if (Correct_Answer < Wrong_Answer)
	{
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "----------------------    ****   Game Over   **** ---------------------------" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		system("color 4F");
	}
	else
	{
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "----------------------    ****   It's a tie   **** ---------------------------" << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		system("color 6F");
	}
	cout << "                    Total questions is    : " << Correct_Answer + Wrong_Answer << endl;
	cout << "                    Correct answers is    : " << Correct_Answer << endl;
	cout << "                    Wrong answers is      : " << Wrong_Answer << endl;
	cout << "                    Your score is         : " << Correct_Answer << endl;
	cout << "                    Your wrong answers is : " << Wrong_Answer << endl << endl;
	Correct_Answer = 0;
	Wrong_Answer = 0;
}
bool Play_Again()
{
	short Again;
	do
	{
		cout << " Do you want to play again ?\n [1] Yes\n [2] No" << endl;
		cin >> Again;
	} while (Again < 1 || Again > 2);
	system("cls");
	return Again == enAgain::Yes ? true : false;
}

void Print_Total_Questions(stQuestion Questions[], short Num_Questions, short& Correct_Answer, short& Wrong_Answer, short Level, short Operator)
{

	do {
		;
		for (short i = 1; i <= Num_Questions; i++)
		{
			system("color 0F");
			cout << "Question " << i << " : " << endl;
			Ask_Question(Questions[i], Correct_Answer, Wrong_Answer, Level, Operator);
			cout << "Your answer is " << Questions[i].Status << endl;
			cout << "------------------------------" << endl;
			system("pause");
			system("color 0F");
			system("cls");
		}
		Print_Score_Status(Correct_Answer, Wrong_Answer);

	} while (Play_Again());
	system("cls");
	cout << "\n\n\n\n";
	cout << " ------------------------------------------------------------------------------" << endl;
	cout << " ----------------------    ****    End Game   **** ----------------------------" << endl;
	cout << " ------------------------------------------------------------------------------" << endl;
	system("color 0F");
}
int main()
{
	srand((unsigned)time(NULL));
	short Num_Questions = Read_Num_Questions();
	short Level = Read_Level();
	short Operator = Read_Operator();
	stQuestion* Questions = new stQuestion[Num_Questions + 1];
	short Correct_Answer = 0, Wrong_Answer = 0;
	Print_Total_Questions(Questions, Num_Questions, Correct_Answer, Wrong_Answer, Level, Operator);
	int x;

	cin >> x;

	return 0;
}