#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>

class Screen
{
public:
    static void ClearScreen ();
    static void Color (const std::string & Col);
    static std::string getColor (const std::string & Color);
    static std::string center (const std::string & text);
    static std::vector<std::string> square (const std::string & text);
};

#endif // SCREEN_H
