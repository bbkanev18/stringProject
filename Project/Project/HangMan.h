#pragma once
#include <iostream>
#include<string>
#include <time.h> 
#include <set>

using namespace std;


int h_main()
{
	//first game test
	/*
	srand(time(NULL));
	int random;
	string ansUser;
	string que[3] = { "hello","hello1","hello2" };
	string ans[3] = { "ans for hello", "ans for hello1", "ans for hello2" };
	random = rand() % 2 + 0;
	cout << que[random] << endl;
	getline(cin, ansUser);
	if (ansUser == ans[random]) {
		cout << "It is correct!";
	}
	else {
		cout << "It is wrong!"<<endl;
		cout << ans[random];
	}
	*/


	// second game test

	set<char> usedLetters;
	srand(time(NULL));
	int random;
	random = rand() % 9 + 0;
	int lives = 8;
	string que[10] = { "cat","fish","dog","jazz","people","boris","congratulations","pewdiepie","pizza" ,"google" };
	string ansUser;
	string MakeWord[50];
	string MakeMap[20][20];
	char MakeBorder[50];
	int stopProgram = que[random].length();

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
		cout << "Lives: " << lives << "\n";
		for (int i = 0; i < que[random].length(); i++)
		{
			cout << MakeWord[i];

		}
		cout << endl;
		cout << endl;

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
			cout << endl;
		}

		for (int i = 0; i < 22; i++)
		{
			cout << MakeBorder[i];
		}


		int sum = 0;

		cout << "\n";
		cout << "\n";
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
			return 0;
			break;
			//guess a word
		case 1:
			cin >> ansUser;
			if (ansUser == que[random])
			{
				cout << "Your answear is correct!\n";
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
			if (usedLetters.count(usedLetter) == 0) {
				usedLetters.insert(usedLetter);
			}
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
							if (usedLetters.count(ansUser.at(0)) == 0) {
								stopProgram--;
							}
						}
					}
					if (stopProgram == 0)
					{
						cout << "Your word: " << que[random] << "\n";
						cout << "You win!";
						return 0;
					}
				}
			}
			//incorrect
			else
			{
				cout << "Your letter is wrong!\n";
				lives--;
				system("pause");
			}

			break;
		}
		case 2147483647:
			cout << "\nI say enter 1 or 2 no 999999999023820649264204 you a fucking bitch. For that you lose the game, bithc.\n";
			cout << "You dead instant because you are stupped!\n";
			sum = lives - 8;
			cout << "lives-8= " << sum;
			cout << "\nYou lose :(";
			return 0;
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
				cout << endl;
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
				cout << endl;
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
				cout << endl;
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
				cout << endl;

			}

			for (int i = 0; i < 1; i++)
			{

				for (int j = 0; j < 1; j++)
				{

					MakeMap[1][7] = "x ";
				}
				cout << endl;
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
				cout << endl;
			}

			for (int i = 3; i < 5; i++)
			{

				for (int j = 0; j < 1; j++)
				{

					MakeMap[i][7] = "| ";
				}
				cout << endl;
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

	cout << "\nYou lose!\n";
	cout << "Your word: " << que[random] << "\n";



	//test manu
	/*
	bool stopWhile = true;
	int chooseOpstion;
	int chooseForLock;
	int point = 0;
	size_t found;
	string lock[2]{ "lock","lock" };
	string lockCheck = "lock";
	string unlock="unlock";
	while (stopWhile)
	{
		system("CLS");
		cout << ".::Menu::.\n";
		cout << "1. 1-level" << " [" << unlock << "]\n";
		cout << "2. 2-level" << " [" << lock[0] << "]\n";
		cout << "3. 3-level" << " [" << lock[1] << "]\n";
		cout << "4. back to main menu\n";

		cout << "Your point: " << point << "\n";
		cin >> chooseOpstion;
		if (chooseOpstion == 2)
		{

			if (point >= 100 and lock[0]==lockCheck)
			{
				cout << "Do you want to unlock level?\n";
				cout << "1. yes\n";
				cout << "2. no\n";
				cin >> chooseForLock;
				switch (chooseForLock)
				{
				case 1:
					lock[0] = unlock;
					point = point - 100;
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
					cout << "Not saved!\n";
					system("pause");
					break;
				}
				continue;
			}
		}

		switch (chooseOpstion)
		{
		case 1:
			point = point + 1000;
			break;
		case 2:
			if (lock[0] == unlock) {
				cout << "main functio\n";
				system("pause");
			}
			else
			{
				cout << "This level is lock!\n";
				cout << "You need 100 point\n";
				system("pause");
			}
			break;
		case 3:
			if (lock[1] == unlock) {
				cout << "main functio\n";
				system("pause");
			}
			else
			{
				cout << "This level is lock!\n";
				cout << "You need 1000 point\n";
				system("pause");
			}
			break;
		case 4:
			stopWhile = false;
			break;
		}
	}
	*/


}
