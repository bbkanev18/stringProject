#pragma once
#include <iostream>
#include<string>
#include <time.h> 

using namespace std;

void HangMenu(bool& loop, string que[], string ansUser, int& random, int lives, int& point, string lock[]);

int game(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void level1(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void level2(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void level3(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void h_main(string lock[])
{

	// second game test
	srand(time(NULL));
	int random;
	int point = 0;
	int lives = 8;
	bool loop = true;
	random = rand() % 9 + 0;
	string que[10] = { "cat","fish","dog","jazz","people","boris","congratulations","pewdiepie","pizza" ,"google" };
	string ansUser;
	int stopProgram = que[random].length();
	
	
	HangMenu(loop, que, ansUser, random, lives, point, lock);
	

}

void HangMenu(bool& loop, string que[], string ansUser, int& random, int lives, int& point, string lock[])
{
	int chooseOpstion;
	int chooseForLock;
	size_t found;
	string lockCheck = "lock";
	string unlock = "unlock";
	while (loop)
	{
		system("CLS");
		titleMsg("Hangman Main Menu");
		newLine();
		cout << "1. 1-level" << " [" << unlock << "]\n";
		cout << "2. 2-level" << " [" << lock[0] << "]\n";
		cout << "3. 3-level" << " [" << lock[1] << "]\n";
		cout << "4. back to main menu\n";

		cout << "Your point: " << point;
		newLine();
		cin >> chooseOpstion;
		if (chooseOpstion == 2)
		{

			if (point >= 500 and lock[0] == lockCheck)
			{
				cout << "Do you want to unlock level?\n";
				cout << "1. yes\n";
				cout << "2. no\n";
				cin >> chooseForLock;
				switch (chooseForLock)
				{
				case 1:
					lock[0] = unlock;
					point = point - 500;
					break;

				case 2:
					cout << "Not saved!\n";
					system("pause");
					break;
				}
				continue;
			}
		}

		if (chooseOpstion == 3)
		{

			if (point >= 1000 and lock[1] == lockCheck)
			{
				cout << "Do you want to unlock level?\n";
				cout << "1. yes\n";
				cout << "2. no\n";
				cin >> chooseForLock;
				switch (chooseForLock)
				{
				case 1:
					lock[1] = unlock;
					point = point - 1000;
					break;

				case 2:
					Msg("Not saved!");
					newLine();
					system("pause");
					break;
				}
				continue;
			}
		}

		switch (chooseOpstion)
		{
		case 0:
			point = point + 1000;
			break;
		case 1:
			level1(loop, que, ansUser, random, lives, point);
			break;
		case 2:
			if (lock[0] == unlock) {
				level2(loop, que, ansUser, random, lives, point);

			}
			else
			{
				cout << "This level is lock!\n";
				cout << "You need 500 point\n";
				system("pause");
			}
			break;
		case 3:
			if (lock[1] == unlock) {
				level3(loop, que, ansUser, random, lives, point);

			}
			else
			{
				cout << "This level is lock!\n";
				cout << "You need 1000 point\n";
				system("pause");
			}
			break;
		case 4:
			loop = false;
			break;
		}

		if (!loop)
			break;
	}
}


int game(bool& loop, string que[], string ansUser, int& random, int lives, int& point)
{
	if (loop)
	{

		int stopProgram = que[random].length();
		string MakeWord[50];
		string MakeMap[20][20];
		char MakeBorder[50];

		//make a word invisible
		for (int i = 0; i < que[random].length(); i++)
		{
			MakeWord[i] = " _ ";

		}

		//make map
		for (int i = 0; i < 22; i++)
		{
			MakeBorder[i] = '*';
		}

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j <= 10; j++)
			{
				MakeMap[i][j] = "  ";

			}
		}

		do
		{
			system("CLS");
			int a;
			size_t found;
			cout << "Lives: " << lives;
			newLine();
			for (int i = 0; i < que[random].length(); i++)
			{
				cout << MakeWord[i];

			}
			newLine(2);

			//make board
			for (int i = 0; i < 22; i++)
			{
				cout << MakeBorder[i];
			}
			cout << endl;
			//make map
			for (int i = 0; i < 10; i++)
			{
				cout << MakeBorder[i];
				for (int j = 0; j < 10; j++)
				{
					cout << MakeMap[i][j];
				}
				cout << MakeBorder[i];
				newLine();
			}

			for (int i = 0; i < 22; i++)
			{
				cout << MakeBorder[i];
			}


			int sum = 0;

			newLine(2);
			cout << "Enter 1 or 2\n";
			cout << "1. Choose to guess a word.\n";
			cout << "2. Choose to guess a letter (only one letter and don't write again the same letter if you write already.)\n";
			cin >> a;
			switch (a)
			{
			case 0:

				cout << "\nYou a fucking bitch! I say first write a number no letter stupped!\n";
				cout << "You dead instant because you are stupped!\n";
				sum = lives - 8;
				cout << "lives-8= " << sum;
				cout << "\nYou lose :(";
				_getch();
				return 0;
				//guess a word
			case 1:
				cin >> ansUser;
				if (ansUser == que[random])
				{
					cout << "Your answear is correct!";
					newLine();
					point = point + (stopProgram * 10);
					_getch();
					return 0;
				}
				else
				{
					cout << "Your answear is wrong!\n";
					lives--;
					system("pause");
				}
				break;


			case 2:
			{
				//guess a letter
				cin >> ansUser;
				char usedLetter = ansUser[0];
				found = que[random].find(ansUser);
				// correct
				if (found != string::npos)
				{
					if (stopProgram > 0)
					{
						for (int i = 0; i <= que[random].length(); i++)
						{
							if (que[random].substr(i, 1) == ansUser)
							{
								MakeWord[i] = ansUser;
								stopProgram--;
								point = point + 10;

							}
						}
						if (stopProgram == 0)
						{
							cout << "Your word: " << que[random];
							newLine();
							cout << "You win!";
							_getch();
							return 0;
						}
					}
				}
				//incorrect
				else
				{
					Msg("Your letter is wrong!");
					newLine();
					lives--;
				}

				break;
			}
			case 2147483647:
				cout << "\nI say enter 1 or 2 no 999999999023820649264204 you a fucking bitch. For that you lose the game, bitch.\n";
				cout << "You dead instant because you are stupped!\n";
				sum = lives - 8;
				cout << "lives-8= " << sum;
				cout << "\nYou lose :(";
				_getch();
				return 0;
				break;
			default:
				Msg();
				break;
			}

			//start bilding a hangman
			//when you have 7 live
			if (lives == 7)
			{
				for (int i = 0; i < 1; i++)
				{

					for (int j = 0; j < 5; j++)
					{

						MakeMap[9][j] = "x ";
					}
					newLine();
				}
			}
			//when you have 6 live
			else if (lives == 6)
			{
				for (int i = 5; i < 9; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][2] = "x ";
					}
					newLine();
				}
			}
			//when you have 5 live
			else if (lives == 5)
			{
				for (int i = 0; i < 5; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][2] = "x ";
					}
					newLine();
				}
			}

			//when you have 4 live
			else if (lives == 4)
			{
				for (int i = 0; i < 1; i++)
				{

					for (int j = 2; j < 8; j++)
					{

						MakeMap[0][j] = "x ";
					}
					newLine();

				}

				for (int i = 0; i < 1; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[1][7] = "x ";
					}
					newLine();
				}
			}

			//when you have 3 lives
			else if (lives == 3)
			{
				for (int i = 0; i < 1; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[2][7] = "0 ";
					}
					newLine();
				}

				for (int i = 3; i < 5; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][7] = "| ";
					}
					newLine();
				}
			}

			//when you have 2 live
			else if (lives == 2)
			{
				for (int i = 3; i < 4; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][7] = "|x";
					}

				}

				for (int i = 3; i < 4; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][6] = " x";
					}

				}

				for (int i = 4; i < 5; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][6] = "x ";
					}

				}

				for (int i = 4; i < 5; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][8] = "x ";
					}

				}


			}
			//when you have 1 live
			else if (lives == 1)
			{
				for (int i = 5; i < 6; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][6] = " x";
					}

				}

				for (int i = 5; i < 6; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][7] = " x";
					}

				}

				for (int i = 6; i < 7; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][6] = "x ";
					}

				}

				for (int i = 6; i < 7; i++)
				{

					for (int j = 0; j < 1; j++)
					{

						MakeMap[i][8] = "x ";
					}

				}
			}
		} while (lives >= 1);

		newLine();
		cout << "You lose!\n";
		cout << "Your word: " << que[random];
		newLine();
	}
}

void level1(bool& loop, string que[], string ansUser, int& random, int lives, int& point)
{
	if (loop)
	{

		random = rand() % 9 + 0;
		if (que[random].length() > 4)
		{
			level1(loop, que, ansUser, random, lives, point);
		}
		else
		{
			game(loop, que, ansUser, random, lives, point);
		}
	}
}

void level2(bool& loop, string que[], string ansUser, int& random, int lives, int& point)
{
	if (loop)
	{
		random = rand() % 9 + 0;
		if (que[random].length() < 5)
		{
			level2(loop, que, ansUser, random, lives, point);
		}
		else if (que[random].length() > 9)
		{
			level2(loop, que, ansUser, random, lives, point);
		}
		else
		{
			game(loop, que, ansUser, random, lives, point);
		}
	}
}

void level3(bool& loop, string que[], string ansUser, int& random, int lives, int& point)
{
	if (loop)
	{

		random = rand() % 9 + 0;
		if (que[random].length() < 10)
		{
			level3(loop, que, ansUser, random, lives, point);
		}
		else
		{
			game(loop, que, ansUser, random, lives, point);
		}
	}
}