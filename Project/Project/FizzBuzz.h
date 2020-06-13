#pragma once
// Include and Using::::::>
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

// Header Files ::::::>
#include "MainFunctions.h"

// Structures ::::::>
struct RULES {
	int id = -1, pNum = -1;
	string sfix = "";
};

// Functions - Declaration ::::::>
void f_main();

void f_gameLoop(RULES* rule, int rNum);

void f_rulesMenu(RULES* rule, int& rNum); //Work on this you faggot

void f_info();

void f_ruleAdd(RULES& cRule, int num, int pNum = 1, string str = ""); //make it possible to add any numbers(remove pNumcheck) //add a check to see if a number already exists?

void f_ruleCreate(RULES& cRule, int& num); //Work on this you faggot

void f_ruleShow(RULES* rule, int rNum);

void f_ruleRemove(RULES* rule, int& rNum);

void f_rulePrint(RULES cRule, int id);

string f_gameCheckRule(RULES cRule, int i);

// Functions - Definition ::::::>
void f_main()
{
	bool defRulesOn = false;
	bool inFizzMenu = true;
	RULES rule[50];
	int rNum = 0;

	while (inFizzMenu)
	{
		system("CLS");

		titleMsg("FizzBuzz");
		cout << "Welcome to FizzBuzz.\n\nEsc. Quit...\n1. Read About FizzBuzz\n2. Modify Rules\n3. Use Default Rules (3-'Fizz';5-'Buzz')\n4. Start the game\n";

		switch (_getch())
		{
		case 27: // Esc.
			inFizzMenu = false;
			break;
		case '1':
			f_info();
			f_main();
			break;
		case '2':
			f_rulesMenu(rule, rNum);
			break;
		case '3':
			if (!defRulesOn)
			{

				f_ruleAdd(rule[rNum], rNum, 3, "Fizz");
				rNum++;
				f_ruleAdd(rule[rNum], rNum, 5, "Buzz");
				rNum++;
				system("CLS");
				defRulesOn = true;
				cout << "Default Rules applied!\n3 - 'Fizz'\n4 - 'Buzz'";
				Sleep(600);
			}
			else
			{
				cout << "Default Rules already applied!\n3 - 'Fizz'\n4 - 'Buzz'";
				Sleep(600);
			}
			break;
		case '4':
			f_gameLoop(rule, rNum);
			break;
		default:
			Msg();
			break;
		}

	}
}

void f_gameLoop(RULES* rule, int rNum)
{
	system("CLS");

	int max;
	cout << "Set a max: ";
	cin >> max;
	string str = "";
	for (int i = 1; i <= max; i++)
	{
		str = "";

		for (int j = 0; j <= rNum; j++)
			str += f_gameCheckRule(rule[j], i);

		if (str == "")	str = to_string(i);

		cout << str;
		newLine();
	}
	errC = _getch();
}

void f_rulesMenu(RULES* rule, int& rNum)
{
	bool inFizzRulesMenu = true;
	while (inFizzRulesMenu)
	{

		system("CLS");

		titleMsg("Rules");
		cout << "Esc. EscapeTxt\n1. Create a new Rule\n2. View all Rules\n3. Remove a Rule\n";

		switch (_getch())
		{
		case 27: // Esc.
			inFizzRulesMenu = false;
			break;
		case '1':
			f_ruleCreate(rule[rNum], rNum);
			break;
		case '2':
			f_ruleShow(rule, rNum);
			break;
		case '3':
			f_ruleShow(rule, rNum);
			f_ruleRemove(rule, rNum);
			break;
		default:
			Msg();
			break;
		}
	}
}

void f_info() // Prints how the game is played
{
	system("CLS");

	titleMsg("FizzBuzz Info");
	cout << "Fizz buzz is a group word game for children to teach them about division.";
	cout << "\nPlayers take turns to count incrementally, \nreplacing any number divisible by three with the word 'fizz', \nand any number divisible by five with the word 'buzz'.";

	newLine(2);
	cout << "Press any button to continue.";
	errC = _getch();
}

void f_ruleAdd(RULES& cRule, int num, int pNum, string str)
{
	cRule.id = num;//migrate outside!

	cRule.pNum = pNumCheck(pNum);

	cRule.sfix = str;
	cRule.sfix[0] = toupper(cRule.sfix[0]);
}

void f_ruleCreate(RULES& cRule, int& num)
{
	cout << "\nRule Num(must be prime!): ";	cin >> cRule.pNum;
	cRule.pNum = pNumCheck(cRule.pNum);

	cout << "\nRule String: ";	cin >> cRule.sfix;

	f_ruleAdd(cRule, num, cRule.pNum, cRule.sfix);
	num++;
}

void f_ruleShow(RULES* rule, int rNum)
{
	for (int i = 0; i < rNum; i++)
	{
		rule[i].id = i;
		f_rulePrint(rule[i], rule[i].id);
	}
	newLine(2);
	cout << "Press a key to continue";
	errC = _getch();
}

void f_ruleRemove(RULES* rule, int& rNum)
{
	int index;
	newLine(2);
	cout << "Choose id: ";
	cin >> index;

	system("CLS");

	if (index > rNum or index < 0) //checking index in range of client counter 
	{
		Msg();
		newLine();
		f_ruleShow(rule, rNum);
		f_ruleRemove(rule, rNum);
	}
	else
	{
		f_rulePrint(rule[index], index);

		//seperate
		for (int i = index; i < rNum - 1; i++) //delete index register client
		{
			rule[i] = rule[i + 1];
		}
		rNum--;

		Msg("Deleted", 6);
		Sleep(600);
	}
}

void f_rulePrint(RULES cRule, int id)
{
	newLine();
	cout << "Id: " << id;
	cout << "\nSuffix: " << cRule.sfix;
	cout << "\nNumber: " << cRule.pNum;
	newLine();
}

string f_gameCheckRule(RULES cRule, int i)
{
	if (i % cRule.pNum == 0)
		return cRule.sfix;
	else
		return "";
}

//TODO ALLOW USER TO INPUT ANY NUMBERS ?
//TODO MAKE A CHECK IF A NUMBER REPEATS
//TODO ADD SETTINGS TO BE ABLE TO TURN ON OR OFF IDEAS FROM LINE 2 AND 3