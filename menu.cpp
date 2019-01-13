#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "type.h"
#include "config.h"
#include "screen.h"
#include "menu.h"

using namespace std;

char Menu::GetChoice ()
{
    char tmp;
    cin >> tmp;
    return tmp;
}

void Menu::MainMenu ()
{
    cout << endl << Screen::center (string (26, '-')) << endl;
    cout << Screen::center (string (5, '-') + string (5, ' ') +" Menu " + string (5, ' ') + string (5, '-')) << endl;
    cout << Screen::center (string (26, '-')) << endl << endl;
    for (const string & text : Screen::square ("1. Jouer"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("2. Paramètres de jeu"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("3. Crédits"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("4. Faire un bronx"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("5. Quitter"))
        cout << Screen::center (text) << endl;
//    cout << Screen::center ("1. Jouer") << endl;
//    cout << Screen::center ("2. Paramètres de jeu") << endl;
//    cout << Screen::center ("3. Crédits") << endl;
//    cout << Screen::center ("4. Faire un bronx") << endl;
//    cout << Screen::center ("5. Quitter") << endl;
}

void Menu::ConfigMenu ()
{

}

void Menu::CreditsMenu ()
{

}

void Menu::ShowConfigMenu ()
{
    while (true) {
        Screen::ClearScreen ();
        ConfigMenu ();
    }
}

void Menu::ShowCreditsMenu ()
{

}

void Menu::ShowPecheMignonDeMarc ()
{

}

void Menu::ShowMainMenu ()
{
    while (true) {
        Screen::ClearScreen();
        MainMenu();
        char choice (GetChoice ());
        switch (choice) {
            case '1':
                Screen::ClearScreen();
                return;
            case '2':
                ShowConfigMenu ();
                break;
            case '3':
                ShowCreditsMenu ();
                break;
            case '4':
                ShowPecheMignonDeMarc ();
                break;
            case '5':
                exit(0);
        }
    }
}
