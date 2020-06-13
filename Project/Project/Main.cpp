// Include and Using::::::>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

char errC; //To get rid of _getch errors :)

// Header Files ::::::>
#include "FizzBuzz.h"
#include "HangMan.h"
#include "TicTacToe.h"
#include "MainFunctions.h"

// Structures ::::::>


// Functions - Declaration ::::::>
void gameMenu(string lock[], int &point);

void mainMenu(string lock[], int &point);

void aboutUs();

void programInfo();

// Main ::::::>
int main()
{
	//for hangman game
	int point = 0;
	string lock[2] = { "locked","locked" };

	mainMenu(lock, point);
}

// Functions - Definition ::::::>
void gameMenu(string lock[], int &point)
{
	
	bool inLoop = true;
	while (inLoop)
	{
		system("CLS");

		titleMsg("Choose a game");
		cout << "Esc. Quit...\n1. FizzBuzz...\n2. Hangman...\n3. Tic Tac Toe...";

		switch (_getch())
		{
		case 27: // Esc.
			inLoop = false;
			break;
		case '1':
			f_main();
			break;
		case '2':
			h_main(lock, point);
			break;
		case '3':
			t_main();
			break;
		default:
			Msg();
			break;
		}


	}
}

void mainMenu(string lock[], int &point)
{
	bool inLoop = true;
	while (inLoop)
	{
		system("CLS");

		titleMsg("Main Menu");
		cout << "Esc. Quit...\n1. Games...\n2. About us...\n3. Program Info...\n";
		//TODO add an about us option
		//TODO add program info option


		switch (_getch())
		{
		case 27: // Esc.
			inLoop = false;
			break;
		case '1':
			gameMenu(lock, point);
			break;
		case '2':
			aboutUs();
			break;
		case '3':
			programInfo();
			break;
		default:
			Msg();
			break;
		}


	}
}

void aboutUs()
{
	system("CLS");

	titleMsg("About us");
	newLine(2);

	cout << "We are: \n\tMartin Sevov - Developer;\n\tBoris Kanev - Developer + Team Manager";
	newLine(2);

	cout << "If you wish to contact us you can send an email to: \n\t->Martin - mssevov18@codingburgas.bg\n\t->Boris - bbkanev18@codingburgas.bg";
	newLine(2);

	cout << "Or you can fill in the Bug/Error Report Form by following this link: \n\t https://forms.office.com/Pages/ResponsePage.aspx?id=S_1sXtMSpEuOqRnbGVq9pAP1BRj8i3VFmY5bGCYTZDNUQlRGNDY1STIxTjZZMjZaUFhYUkFPMjdYNC4u";
	newLine(2);

	cout << "If you want to check out the Git repo: \n\t https://github.com/bbkanev18/stringProject";
	newLine(2);

	Msg("Press 3 keys to continue");
	errC = _getch();
	errC = _getch();
	errC = _getch();
}

void programInfo()
{
	system("CLS");

	titleMsg("Program Info");
	newLine(2);

	cout << "->Martin Sevov - Worked on Main.cpp, FizzBuzz.h, TicTacToe.h, Main Function.h;\n->Boris Kanev - Worked on Main.cpp, HangMan.h, MainFunction.h;";
	newLine(2);

	cout << "The Program was made in Visual Studio with C++. We used Git to collaborate and work on the Program.";
	newLine(2);


	cout << "+-----------+   +----------+   +-------------+\n";
	cout << "| Fizz Buzz |   | Hang Man |   | Tic Tac Toe |\n";
	cout << "+-----^-----+   +----^-----+   +-------^-----+\n";
	cout << "      |              |                 |\n";
	cout << "      +--------------+-----------------+\n";
	cout << "                     |\n";
	cout << "               +-----^-----+\n";
	cout << "               | Game Menu |\n";
	cout << "               +-----^-----+\n";
	cout << "                     |\n";
	cout << "               +-----^-----+\n";
	cout << "               | Main Menu |\n";
	cout << "               +-----^-----+\n";
	cout << "                     |\n";
	cout << "                 +---^--+\n";
	cout << "                 | Main |\n";
	cout << "                 +------+\n";

	newLine(2);
	Msg("Press 3 keys to continue");
	errC = _getch();
	errC = _getch();
	errC = _getch();
}