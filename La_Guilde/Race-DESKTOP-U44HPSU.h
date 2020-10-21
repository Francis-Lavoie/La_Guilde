#pragma once
#include <string>;

using namespace std;

class Race
{
public:
	Race();
	Race(int attaque, int defense, int vie, int chance);
	string getNom();

protected:
	int attaque;
	int defense;s
};

