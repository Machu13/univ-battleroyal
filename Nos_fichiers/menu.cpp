#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "type.h"
#include "config.h"
#include "screen.h"
#include "ioutils.h"
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
    for (const string & text : Screen::square (string (5, ' ') + "Menu Principal" + string (5, ' ')))
        cout << Screen::center (text) << endl;
    cout << endl;
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
}

void Menu::ConfigMenu ()
{
    for (const string & text : Screen::square (string (5, ' ') + "Menu Config" + string (5, ' ')))
        cout << Screen::center (text) << endl;
    cout << endl;
    for (const string & text : Screen::square ("1. Config actuelle"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("2. Editer la config"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("3. Recharger la config"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("4. Retour au menu principal"))
        cout << Screen::center (text) << endl;
}

void Menu::ShowConfig ()
{
    CConfig configFile;
    Config config = Config (configFile);
    config.InitConfig ();
    config.LoadConfig ("../univ-battleroyal/Nos_fichiers/config.yml");
    for (const string & text : Screen::square (string (5, ' ') + "Menu Config" + string (5, ' ')))
        cout << Screen::center (text) << endl;
    cout << Screen::center (Screen::underline ("Configuration actuelle")) << endl << endl;
    Screen::Color (Screen:: getColor("Reset"));
    for (auto & val : config.getConfig().MapParamString)
       cout << val.first << " = " << val.second << endl;
    for (auto & val : config.getConfig().MapParamChar)
       cout << val.first << " = " << val.second << endl;
    for (auto & val : config.getConfig().MapParamUnsigned)
       cout << val.first << " = " << val.second << endl;
    cout << "[RETURN ESC]";
    char tmp;
    cin >> tmp;
}

void Menu::CreditsMenu ()
{

}

void Menu::ShowConfigMenu ()
{
    while (true) {
        Screen::ClearScreen ();
        ConfigMenu ();
        char choice = GetChoice();
        switch (choice) {
            case '1':
                ShowConfig();
                break;
            case '2':
                system ("(gedit ../univ-battleroyal/Nos_fichiers/config.yml > /dev/null)");
                break;
            case '3':
                cout << "> Tkt ca va se reload tout seul quand la partie aura demare :)" << endl;
                sleep(3);
                break;
            case '4':
                return;
        }
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
    IO::set_input_mode ();
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
