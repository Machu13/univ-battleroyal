#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "type.h"
#include "screen.h"

using namespace std;

void Screen::ClearScreen ()
{
    cout << "\033[H\033[2J";
} //ClearScreen ()

void Screen::Color (const string & Col)
{
    cout << "\033[" << Col <<"m";
} // Color()

string Screen::getColor (const string & Color)
{
    return KColor.find('K' + Color)->second;
}

string Screen::underline (const string & text)
{
    return "\033[4m" + text;
}

string Screen::center (const string & text)
{
    struct winsize w;
    ioctl (STDOUT_FILENO, TIOCGWINSZ, & w);
    return string ((w.ws_col - text.length()) / 2, ' ') + text;
}

vector<string> Screen::square (const string & text)
{
    vector<string> squaredTxt;
    squaredTxt.push_back (string (text.size() + 4, '-'));
    squaredTxt.push_back ("| " + text + " |");
    squaredTxt.push_back (string (text.size() + 4, '-'));
    return squaredTxt;
}

char Screen::GetChoice ()
{
    string line;
    getline (cin, line);
    cin.clear ();
    return line[0];
}
