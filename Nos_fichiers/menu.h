#ifndef MENU_H
#define MENU_H

class Menu
{
private:
    static char GetChoice ();
    static void MovePointer (char & choice, unsigned & nbr, const unsigned & max);
    static void ConfigMenu (unsigned nbr);
    static void ShowConfig ();
    static void CreditsMenu ();
    static void MainMenu (unsigned nbr);
public:
    static void ShowConfigMenu ();
    static void ShowCreditsMenu ();
    static void ShowPecheMignonDeMarc ();
    static void ShowMainMenu ();
};

#endif // MENU_H
