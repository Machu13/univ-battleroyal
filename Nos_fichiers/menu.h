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
     * @brief MovePointer : moving through options on the menu
     * @param choice : user movement key
     * @param nbr : value of current choice
     * @param max : max opts in menu
     * @fn static void MovePointer(char & choice, unsigned & nbr, const unsigned & max)
     */
    static void MovePointer (char & choice, unsigned & nbr, const unsigned & max);

    /**
     * @brief ConfigMenu : contents design of the menu's choices
     * @param nbr : value of current choice
     * @fn static void ConfigMenu (const unsigned & nbr)
     */
    static void ConfigMenu (const unsigned & nbr);

    /**
     * @brief ShowConfig : display all values of the config
     * @fn static void ShowConfig ()
     */
    static void ShowConfig ();

    /**
     * @brief CreditsMenu : contents credits
     * @fn static void CreditsMenu ()
     */
    static void CreditsMenu ();

    /**
     * @brief MainMenu : contents all values of the main menu
     * @param nbr : value of current choice
     * @fn static void MainMenu (const unsigned & nbr)
     */
    static void MainMenu (const unsigned & nbr);

public:
    /**
     * @brief ShowConfigMenu : display all choices for the config menu
     * @fn static void ShowConfigMenu ()
     */
    static void ShowConfigMenu ();

    /**
     * @brief ShowCreditsMenu : display credits
     * @fn static void ShowCreditsMenu ()
     */
    static void ShowCreditsMenu ();

    /**
     * @brief ShowPecheMignonDeMarc : display the bronx's recipe
     * @fn static void ShowPecheMignonDeMarc ()
     */
    static void ShowPecheMignonDeMarc ();

    /**
     * @brief ShowMainMenu : display the menu of the game
     * @fn static void ShowMainMenu ()
     */
    static void ShowMainMenu ();
};

#endif // MENU_H
