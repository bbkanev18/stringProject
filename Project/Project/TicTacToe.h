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


// Functions - Declaration ::::::>
void t_main();

void t_gameLoop(int points[], int botOn);

void t_printMap(string map[], int maxX);

void t_tileCheck(string map[], string mark, int num, int player);

int t_checkwin(string map[]);

void t_printHUD(int points[], string pMark, string eMark, int botOn);

int t_playerMove(string map[], string mark, int player);

// Functions - Definition ::::::>
void t_main()
{
	int points[]{ 0,0 };
	int botOn = 0; //0 - P2; 1 - bot

	system("CLS");

	cout << "1. Player vs Player\n2. Player vs Bot";
	switch (_getch())
	{
	case '1':
		botOn = 0;
		break;
	case '2':
		botOn = 1;
		break;
	default:
		break;
	}

	t_gameLoop(points, botOn);
}

void t_gameLoop(int points[], int botOn)
{
	string map[9]; //maxX = 3 - 00 10 20 /\ 01 11 21 /\ 02 12 22 |\/\/| 0 1 2 3 4 5 6 7 8 9
	const int maxX = 3;

	for (int i = 0; i < maxX; i++) //y
	{
		for (int j = 0; j < maxX; j++) //x
		{
			map[j + (i * maxX)] = to_string(j + (i * maxX));
		}
	}

	int inTmain = -1;
	int winner = 3; //0 - p1; 1 - bot
	string pMark = "";
	string eMark = "";

	system("CLS");

	cout << "Player Mark?\n";
	getline(cin, pMark);
	pMark = toupper(pMark[0]);

	cout << "Enemy Mark?\n";
	getline(cin, eMark);
	eMark = toupper(eMark[0]);

	cout << "So you have chosen " << pMark << " and " << eMark; 
	errC = _getch();

	int num;
	char ch;

	while (inTmain == -1) 
	{
		system("CLS");
		titleMsg("Tic Tac Toe");
		newLine(2);

		t_printHUD(points, pMark, eMark, botOn);

		t_printMap(map, maxX);

		newLine(2);
		cout << "Player 1's Turn";
		
		inTmain = t_playerMove(map, pMark, 0);
		if (inTmain == 1)
		{
			winner = 0;
			break;
		}
		else if (inTmain == 2)
		{
			winner = 4;
			break;
		}

		system("CLS");
		titleMsg("Tic Tac Toe");
		newLine(2);

		t_printHUD(points, pMark, eMark, botOn);

		t_printMap(map, maxX);
		Sleep(200);

		if (botOn == 1)
		{
			
			num = rng(0, 9);
			t_tileCheck(map, eMark, num, 1);
			inTmain = t_checkwin(map);
		}
		else
		{
			newLine(2);
			cout << "Player 2's Turn";
			
			inTmain = t_playerMove(map, eMark, 2);
		}
		if (inTmain == 1)
		{
			winner = 1;
			break;
		}
		else if (inTmain == 0)
		{
			winner = 3;
			break;
		}
		else if (inTmain == 2)
		{
			winner = 4;
			break;
		}


	}

	system("CLS");

	string msg = "";
	switch (winner)
	{
	case 0:
		msg += "Winner is Player 1";
		points[0]++;
		Msg(msg, 5);
		break;
	case 1:
		msg += "Winner is ";
		if (botOn == 1)
			msg += "Bot";
		else
			msg += "Player 2";
		points[1]++;
		Msg(msg, 5);
		break;
	case 3:
		msg += "Draw";
		Msg(msg, 5, 4);
		break;
	case 4:
		msg += "Forfeit";
		Msg(msg, 5, 1);
		break;
	default:
		break;
	}
	newLine(2);

	t_printHUD(points, pMark, eMark, botOn);

	t_printMap(map, maxX);

	newLine(2);

	cout << "Want to play again? y/n 1/0 Enter/Escape";
	newLine(2);

	switch (_getch())
	{
	case 'y':
	case '1':
	case 13:
		t_gameLoop(points, botOn);
		break;
	case 'n':
	case '0':
	case 27:
		Msg("Thanks for playing");
		Sleep(500);
		break;
	default:
		Msg();
		break;
	}
}

void t_printMap(string map[], int maxX)
{
	for (int i = 0; i < maxX; i++) //y
	{
		for (int j = 0; j < maxX; j++) //x
		{
			cout << map[j + (i * maxX)] << "\t";
		}
		newLine(3);
	}
	
}

void t_tileCheck(string map[], string mark, int num, int player) //player: 0 = p1, 1 = bot, 2 = p2;
{

	if (map[num] == to_string(num))
	{
		map[num] = mark;
	}
	else
	{
		if (player == 1)
		{
			num = rng(0, 9);
			t_tileCheck(map, mark, num, 1);
		}
		else
		{
			Msg("Tile Taken", 5);
			_getch();
			t_playerMove(map, mark, player);
		}
	}
}


//1 FOR GAME IS OVER WITH RESULT
//O GAME IS OVER AND NO RESULT
//-1 FOR GAME IS IN PROGRESS
//2 FOR EXIT

int t_checkwin(string map[])
{
	if (map[0] == map[1] and map[1] == map[2])
		return 1;
	else if (map[3] == map[4] and map[4] == map[5])
		return 1;
	else if (map[6] == map[7] and map[7] == map[8])
		return 1;
	else if (map[0] == map[3] and map[3] == map[6])
		return 1;
	else if (map[1] == map[4] and map[4] == map[7])
		return 1;
	else if (map[2] == map[5] and map[5] == map[8])
		return 1;
	else if (map[0] == map[4] and map[4] == map[8])
		return 1;
	else if (map[2] == map[4] and map[4] == map[6])
		return 1;
	else if (map[0] != "0" and map[1] != "1" and map[2] != "2" and map[3] != "3" and map[4] != "4" and map[5] != "5" and map[6] != "6" and map[7] != "7" and map[8] != "8")
		return 0;
	else
		return -1;
}

void t_printHUD(int points[], string pMark, string eMark, int botOn)
{
	cout << "Player 1: " << pMark << " " << points[0];
	newLine(2);

	if (botOn == 1)
		cout << "Bot: ";
	else
		cout << "Player 2: ";
	cout << eMark << " " << points[1];
	newLine(2);
}

int t_playerMove(string map[], string mark, int player)
{
	char ch = _getch();
	int num = int(ch) - 48;

	if (num >= 0 and num <= 8) //Nums
	{
		t_tileCheck(map, mark, num, player);
		return t_checkwin(map);
	}
	else if (ch == 27) //Esc
		return 2;
	else
	{
		Msg();
		t_playerMove(map, mark, player);
	}
}

//[x][y] to [z]: z = x + (y * maxX)