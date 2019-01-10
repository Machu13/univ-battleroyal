/**
 * @file main.cpp
 * @brief Main programm
 * @author Maxime Minguella
 * @author Arthur Petre
 * @author Vincent Lavernhe
 * @author Hugo Panis
 * @author Mathias Meyer
 * @version 1.0
 * @date 10 janvier 2019
 */

#include <iostream>
#include "game.h"

using namespace std;
/**
 * @brief main function
 * @return return 0 if everything is OK, 1 if we have an exception
 */
int main()
{
    try
    {
        return ppal();
    }
    catch (...)
    {
        cerr << "Erreur au lancement" << endl;
        return 1;
    }
} // main ()
