#ifndef MENU_H
#define MENU_H

class Menu
{
private:
    static char GetChoice ();
    static void ConfigMenu ();
    static void CreditsMenu ();
    static void MainMenu ();
public:
    static void ShowConfigMenu ();
    static void ShowCreditsMenu ();
    static void ShowPecheMignonDeMarc ();
    static void ShowMainMenu ();
};

#endif // MENU_H
