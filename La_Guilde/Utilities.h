#pragma once
#include <ctime>
#include <Windows.h>

using namespace std;

class Utilities
{
public:
	static int generateRandom(int min,int max);
	static int saisirNombre(int min, int max);
	static void flushCin();
	static void clearConsole(char fill = ' ');
	static void waitKey();
};

