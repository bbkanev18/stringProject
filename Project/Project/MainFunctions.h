#pragma once
// Include and Using::::::>
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

// Header Files ::::::>


// Structures ::::::>


// Functions - Declaration ::::::>
inline void Msg(string str = "Error", int n = 3);

inline int pNumCheck(int in);

inline int rng(int min, int  max);

inline void titleMsg(string str = "Menu");

// Functions - Definition ::::::>
inline void Msg(string str, int n)
{
	cout << "\n" << str << "!";
	for (int i = 0; i < n; i++)
	{
		Sleep(100);
		cout << ".";
	}
	Sleep(600);
}

inline int pNumCheck(int in)
{
	bool isPrime = true;
	for (int i = 2; i <= in / 2; ++i) {
		if (in % i == 0) {
			isPrime = false;
			break;
		}
	}
	if (isPrime)
		return in;
	else
	{
		Msg();

		cout << "\nInput the num again.  ";
		cin >> in;

		pNumCheck(in);
	}
}

inline int rng(int min, int  max)
{
	srand(time(NULL));
	int tmp = rand();
	return (tmp % (max - min) + min);
}

inline void titleMsg(string str)
{
	string out = "";
	int rnd;

	for (int i = 0; i < 15; i++)
		rnd = rng(0, 5);

	switch (rnd)
	{
	case 0:
		out += "(#=#=>-<: " + str + " :>-<=#=#)\n\n";
		break;
	case 1:
		out += "=-=}>~~<| " + str + " |>~~<{=-=\n\n";
		break;
	case 2:
		out += ";=;[]>---<| " + str + "|>---<[];=;\n\n";
		break;
	case 3:
		out += ":....:| " + str + "|:....:\n\n";
		break;
	case 4:
		out += "[]-----| " + str + "|-----[]\n\n";
		break;
	default:
		break;
	}

	cout << out;
}