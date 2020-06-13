#pragma once
#include <iostream>
#include<string>
#include <time.h> 

//int &point = 0; //ask martin for help!!!



void HangMenu(bool& loop, string que[], string ansUser, int& random, int lives, int& point, string lock[]);

int game(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void level1(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void level2(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void level3(bool& loop, string que[], string ansUser, int& random, int lives, int& point);

void saveAns(int& point,int cost, string lock[], int num);

void infoGame();



void h_main(string lock[], int &point)
{


	srand(time(NULL));
	int random;
	int lives = 8;
	bool loop = true;
	random = rand() % 22 + 0;
	string que[] = { "cat","fish","dog","jazz","people",
	"congratulation","pewdiepie","pizza" ,"google","door",
	"bot","youtube","tank","keyboard","notebook",
	"bus","martin","boris","planetarium","observatory",
	"pixel","blizzard","bagpipe"}; //todo add more words someday
	string ansUser;
	int stopProgram = que[random].length();
	
	
	HangMenu(loop, que, ansUser, random, lives, point, lock);
	

}

void HangMenu(bool& loop, string que[], string ansUser, int& random, int lives, int& point, string lock[])
{
	int chooseOpstion;
	int chooseForLock;
	size_t found;
	string lockCheck = "locked";
	string unlocked = "unlocked";
	while (loop)
	{
		system("CLS");
		titleMsg("Hangman Main Menu");
		cout << "Welcome to Hangman";
		newLine(2);

		cout << "1. 1-level" << " [" << unlocked << "]\n";
		cout << "2. 2-level" << " [" << lock[0] << "]\n";
		cout << "3. 3-level" << " [" << lock[1] << "]\n";
		cout << "4. Hangman Info\n";
		cout << "5. Quit...\n";

		cout << "Your points: " << point;
		newLine();
		cin >> chooseOpstion;
		if (chooseOpstion == 2)
		{

			if (point >= 500 and lock[0] == lockCheck)
			{
				saveAns(point, 500, lock, 0);
				continue;
			}
		}

		if (chooseOpstion == 3)
		{

			if (point >= 1000 and lock[1] == lockCheck)
			{
				saveAns(point, 1000, lock, 1);
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
			if (lock[0] == unlocked) {
				level2(loop, que, ansUser, random, lives, point);

			}
			else
			{
				cout << "This level is locked!\n";
				cout << "You need: " << 500 - point<<" points to unlock\n";
				system("pause");
			}
			break;

		case 3:
			if (lock[1] == unlocked) {
				level3(loop, que, ansUser, random, lives, point);

			}
			else
			{
				cout << "This level is locked!\n";
				cout << "You need: " << 1000 - point << " points to unlock\n";
				system("pause");
			}
			break;

		case 4:
			infoGame();
			break;

		case 5:
			loop = false;
			break;
		}

		if (!loop)
			break;
	}
}

void infoGame() 
{
	system("CLS");

	titleMsg("Hangman Info");
	cout << "Hangman is a word game where the player guesses a word.\n";
	cout << "The player guesses a word or a letter and if it is correct you will get points.\nFor each correct letter you get 10 points.\n";
	cout << "\nYou have 3 levels:\n";
	cout << "\n-First level gives you a word with between 3 and 4 letters.\n";
	cout << "\n-Second level gives you a word with between 5 and 7 letters. (need 500 points)\n";
	cout << "\n-Third level gives you a word with more than 8 letters. (need 1000 points)\n";

	newLine(2);
	Msg("Press any button to continue");
	errC = _getch();
}

void level1(bool& loop, string que[], string ansUser, int& random, int lives, int& point)
{
	if (loop)
	{

		random = rand() % 22 + 0;
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
		random = rand() % 22 + 0;
		if (que[random].length() < 5)
		{
			level2(loop, que, ansUser, random, lives, point);
		}
		else if (que[random].length() > 7)
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

		random = rand() % 22 + 0;
		if (que[random].length() < 8)
		{
			level3(loop, que, ansUser, random, lives, point);
		}
		else
		{
			game(loop, que, ansUser, random, lives, point);
		}
	}
}

void saveAns(int& point, int cost, string lock[], int num)
{
	int chooseForLock;
	Msg("Do you want to unlock this level", 3, 3);
	newLine();
	cout << "1. yes\n";
	cout << "2. no\n";
	cin >> chooseForLock;
	switch (chooseForLock)
	{
	case 1:
		point = point - cost;
		lock[num] = "unlocked";
		break;

	case 2:
		Msg("Not saved");
		newLine();
		system("pause");
		break;
	}
}

int game(bool& loop, string que[], string ansUser, int& random, int lives, int& point)
{
	if (loop)
	{
		string checkLetter[31];
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
			newLine();
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
			cout << "Guess?\n";
			cin >> ansUser;
			
			if (ansUser.length() == 1)
				a = 2;
			else
				a = 1;

			switch (a)
			{
			//guess a word
			case 1:
				if (ansUser == que[random])
				{
					Msg("Your answer is correct");
					newLine();
					point = point + (stopProgram * 10);
					errC = _getch();
					return 0;
				}
				else
				{
					Msg("Your guess is wrong");
					newLine();
					lives--;
					errC = _getch();
				}
				break;


			case 2:
			{
				//guess a letter
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

								if (ansUser == checkLetter[i])
								{
									Msg("You have used this letter");
									errC = _getch();
									break;
								}
								else
								{
									MakeWord[i] = ansUser;
									stopProgram--;
									checkLetter[i] = ansUser;
									point = point + 10;
								}


							}

						}

						if (stopProgram == 0)
						{
							cout << "Your word: " << que[random];
							newLine();
							cout << "You win!";
							errC = _getch();
							return 0;
						}
					}
				}
				//incorrect
				else
				{
					Msg("Your letter is wrong");
					newLine();
					lives--;
					errC = _getch();
				}

				break;
			}
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
		errC = _getch();

	}
}