#ifndef MENU_H
#define MENU_H
/*!
* @file menu.h
* @brief Definition the menu of the game
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

/**
* @class Menu menu.h
* @brief class containing all menu and sub-menu propositions
*/
class Menu
{
private:
    /**
     * @brief GetChoice
     * @return
     */
    static char GetChoice ();

    /**
     * @brief MovePointer
     * @param choice
     * @param nbr
     * @param max
     */
    static void MovePointer (char & choice, unsigned & nbr, const unsigned & max);

    /**
     * @brief ConfigMenu
     * @param nbr
     */
    static void ConfigMenu (unsigned nbr);

    /**
     * @brief ShowConfig
     */
    static void ShowConfig ();

    /**
     * @brief CreditsMenu
     */
    static void CreditsMenu ();

    /**
     * @brief MainMenu
     * @param nbr
     */
    static void MainMenu (unsigned nbr);

public:
    /**
     * @brief ShowConfigMenu
     */
    static void ShowConfigMenu ();

    /**
     * @brief ShowCreditsMenu
     */
    static void ShowCreditsMenu ();

    /**
     * @brief ShowPecheMignonDeMarc
     */
    static void ShowPecheMignonDeMarc ();

    /**
     * @brief ShowMainMenu
     */
    static void ShowMainMenu ();
};

#endif // MENU_H
