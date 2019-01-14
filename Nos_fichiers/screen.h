#ifndef SCREEN_H
#define SCREEN_H
/*!
* @file screen.h
* @brief Definition of the display
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

#include <iostream>
#include <vector>

/**
* @namespace std
*/
using namespace std;

/**
* @class Screen screen.h
* @brief class containing all display parameters
*/
class Screen
{
public:
    /**
     * @brief Clear the current terminal
     * @fn void ClearScreen ();
     */
    static void ClearScreen ();

    /**
     * @brief Color
     * @param Col
     */
    static void Color (const string & Col);

    /**
     * @brief getColor
     * @param Color
     * @return
     */
    static string getColor (const string & Color);

    /**
     * @brief underline
     * @param Color
     * @return
     */
    static string underline (const string & Color);

    /**
     * @brief center
     * @param text
     * @return
     */
    static string center (const string & text);

    /**
     * @brief square
     * @param text
     * @return
     */
    static vector<string> square (const string & text);
};

#endif // SCREEN_H
