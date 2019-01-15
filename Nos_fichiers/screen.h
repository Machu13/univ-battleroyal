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
     * @brief Color : display color
     * @param Col : current value of the color
     * @fn static void Color (const string & Col)
     */
    static void Color (const string & Col);

    /**
     * @brief getColor : search the color in the config file
     * @param Color : current value of the color
     * @return string : linux color code
     * @fn static string getColor (const string & Color)
     */
    static string getColor (const string & Color);

    /**
     * @brief underline : underline the text
     * @param Color : current value of the color
     * @return string : underlined text
     * @fn static string underline (const string & Color)
     */
    static string underline (const string & Color);

    /**
     * @brief center : center the text
     * @param text : current value of the text
     * @return string : centered text
     * @fn static string center (const string & text)
     */
    static string center (const string & text);

    /**
     * @brief square : surround the text
     * @param text : current value of the text
     * @return vector<string> : surrounded text
     * @fn static vector<string> square (const string & text)
     */
    static vector<string> square (const string & text);

    /**
     * @brief GetChoice : get the player key input
     * @return char : player's key entered
     * @fn static char GetChoice ()
     */
    static char GetChoice ();
};

#endif // SCREEN_H
