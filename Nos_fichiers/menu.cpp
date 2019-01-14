#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <iomanip>
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
    for (const string & text : Screen::square ("2. Parametres de jeu"))
        cout << Screen::center (text) << endl;
    for (const string & text : Screen::square ("3. Credits"))
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
    GetChoice();
}

void Menu::CreditsMenu ()
{
    for (const string & text : Screen::square (string (5, ' ') + "Credits" + string (5, ' ')))
        cout << Screen::center (text) << endl;
    cout << endl;
    vector <string> credits;
    credits.push_back("       Maxime Minguella    as Lead Developer");
    credits.push_back("          Arthur Petre    as Game Director");
    credits.push_back("              Hugo Panis    as Leader Designer");
    credits.push_back("Vincent Lavernhe    as himself");
    credits.push_back("               Mathias Meyer    as Redoublant Designer");
    credits.push_back("    Bruce Wayne    as Batman");
    credits.push_back("        Alain Casali    as Beta Tester");
    credits.push_back("         Marc TheDoor    as Bronx Master");
    for (const string & info : credits)
    {
        sleep (1);
        cout << Screen::center (info) << endl;
    }
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
    Screen::ClearScreen();
    CreditsMenu();
    cout << "[RETURN ESC]";
    GetChoice();
}

void Menu::ShowPecheMignonDeMarc ()
{
    Screen::ClearScreen();
    for (const string & text : Screen::square (string (5, ' ') + "BRONXXXXXXXXXX" + string (5, ' ')))
        cout << Screen::center (text) << endl;
    cout << endl;
    ifstream ifs ("../univ-battleroyal/Nos_fichiers/bronx.txt");
    if (ifs.is_open())
    {
        string line;
        for (getline(ifs, line); !ifs.eof(); getline(ifs, line))
            cout << line << endl;
        ifs.close();
    }
    else
    {
        Screen::Color (Screen::getColor ("Red"));
        cout << Screen::center (Screen::underline ("Pas de recette pour ajourd'hui :/ (bronx.txt not found)")) << endl;
        Screen::Color (Screen::getColor ("Reset"));
    }
    cout << endl << "[RETURN ESC]";
    GetChoice();
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
