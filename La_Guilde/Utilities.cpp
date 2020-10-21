#pragma once;
#include "Utilities.h"
#include <iostream>

using namespace std;

int Utilities::generateRandom(int min,int max)
{
    return(rand() % (max - min + 1)) + min;
}

int Utilities::saisirNombre(int min,int max) {
    cout << "\n";
    int nombre = 0;
    cin >> nombre;
    Utilities::flushCin();

    //Validation
    nombre > max ? nombre = max : nombre = nombre;
    nombre < min ? nombre = min : nombre = nombre;

    return nombre;
}

void Utilities::flushCin() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

void Utilities::clearConsole(char fill) {
    COORD tl = { 0,0 };
    CONSOLE_SCREEN_BUFFER_INFO s;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(console, &s);
    DWORD written, cells = s.dwSize.X * s.dwSize.Y;
    FillConsoleOutputCharacter(console, fill, cells, tl, &written);
    FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
    SetConsoleCursorPosition(console, tl);
}

void Utilities::waitKey()
{
    cout << "Appuyez sur une touche puis enter pour continuer!" << endl;
    saisirNombre(0, 0);
}

