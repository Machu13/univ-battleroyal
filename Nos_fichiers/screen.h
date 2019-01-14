#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>

using namespace std;

class Screen
{
public:
    static void ClearScreen ();
    static void Color (const string & Col);
    static string getColor (const string & Color);
    static string underline (const string & Color);
    static string center (const string & text);
    static vector<string> square (const string & text);
};

#endif // SCREEN_H
