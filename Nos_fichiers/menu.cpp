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

void Menu::MovePointer (char & choice, unsigned & nbr, const unsigned & max)
{
    if (tolower(choice) == 'z')
        if (nbr > 0)
            --nbr;
    if (tolower(choice) == 's')
        if (nbr < max - 1)
            ++nbr;
    if (tolower(choice) == '0')
        choice = '1' + nbr;
}

void Menu::MainMenu (unsigned nbr)
{
    cout << Screen::center (" ______        ______           ______   _____  _     _      _       ")      << endl;
    cout << Screen::center ("(_____ \\ /\\   / _____)         (_____ \\ / ___ \\| |   | |/\\  | |      ") << endl;
    cout << Screen::center (" _____) )  \\ | /         ___    _____) ) |   | | |___| /  \\ | |      ")    << endl;
    cout << Screen::center ("|  ____/ /\\ \\| |        (___)  (_____ (| |   | |\\_____/ /\\ \\| |      ") << endl;
    cout << Screen::center ("| |   | |__| | \\_____                | | |___| |  ___| |__| | |_____ ")     << endl;
    cout << Screen::center ("|_|   |______|\\______)               |_|\\_____/  (___)______|_______)")    << endl;
    for (const string & text : Screen::square (string (5, ' ') + "Menu Principal" + string (5, ' ')))
        cout << Screen::center (text) << endl;
    cout << endl;
    if (nbr == 0)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("1. Jouer"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
    if (nbr == 1)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("2. Parametres de jeu"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
    if (nbr == 2)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("3. Credits"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
    if (nbr == 3)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("4. Faire un bronx"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
    if (nbr == 4)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("5. Quitter"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
}

void Menu::ConfigMenu (unsigned nbr)
{
    for (const string & text : Screen::square (string (5, ' ') + "Menu Config" + string (5, ' ')))
        cout << Screen::center (text) << endl;
    cout << endl;
    if (nbr == 0)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("1. Config actuelle"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
    if (nbr == 1)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("2. Editer la config"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
    if (nbr == 2)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("3. Recharger la config"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
    if (nbr == 3)
        Screen::Color (Screen::getColor ("Yellow"));
    for (const string & text : Screen::square ("4. Retour au menu principal"))
        cout << Screen::center (text) << endl;
    Screen::Color (Screen::getColor ("Reset"));
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
    unsigned nbr (0);
    while (true) {
        Screen::ClearScreen ();
        ConfigMenu (nbr);
        char choice = GetChoice();
        MovePointer (choice, nbr, 4);
        switch (choice) {
        case '1':
            ShowConfig();
            break;
        case '2':
            system ("(gedit ../univ-battleroyal/Nos_fichiers/config.yml > /dev/null)");
            break;
        case '3':
            cout << "> Tkt ca va se reload tout seul quand la partie aura demarre :)" << endl;
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
        cout << Screen::center (Screen::underline ("Pas de recette pour aujourd'hui :/ (bronx.txt not found)")) << endl;
        Screen::Color (Screen::getColor ("Reset"));
    }
    cout << endl << "[RETURN ESC]";
    GetChoice();
}

void Menu::ShowMainMenu ()
{
    unsigned nbr (0);
    while (true) {
        Screen::ClearScreen();
        MainMenu(nbr);
        char choice = GetChoice();
        MovePointer (choice, nbr, 5);
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
            Screen::ClearScreen ();
            cout << Screen::center ("  ______          ______   _______     _____   _    _  _______  ______  ")       << endl;
            cout << Screen::center (" / _____)   /\\   |  ___ \\ (_______)   / ___ \\ | |  | |(_______)(_____ \\ ")   << endl;
            cout << Screen::center ("| /  ___   /  \\  | | _ | | _____     | |   | || |  | | _____    _____) )")      << endl;
            cout << Screen::center ("| | (___) / /\\ \\ | || || ||  ___)    | |   | | \\ \\/ / |  ___)  (_____ ( ")   << endl;
            cout << Screen::center ("  | \\____/|| |__| || || || || |_____   | |___| |  \\  /  | |_____       | | ")  << endl;
            cout << Screen::center ("   \\_____/ |______||_||_||_||_______)   \\_____/    \\/   |_______)      |_| ") << endl;
            cout << endl;
            exit(0);
        }
    }
}
