#ifndef GAME_H
#define GAME_H
/*!
* @file game.h
* @brief Definition of moves and position of the token
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

#include "config.h"
#include "type.h"

/**
* @class Game game.h
* @brief class containing all Token parameters
*/
class Game
{
public:
    /**
     * @brief Update position tokens players
     * @param Mat : Game grid
     * @param Move : Touch move token
     * @param Pos : Position token
     * @param config : Init box with KEmpty
     * @fn static void MoveToken (CMatrix & Mat, char & Move, CPosition & Pos, Config & config);
     */
    static void MoveToken (CMatrix & Mat, char Move, CPosition & Pos, Config & config);

    /**
     * @brief Main fonction which load config, init grid, run menu , run game and check victory condition
     * @param SkipMenu : Play Game with or without menu
     * @return 0 if everything is OK, return 1 if it can't load the score.txt file
     * @fn static int ppal(const bool & SkipMenu = false);
     */
    static int ppal(const bool & SkipMenu = false);

};

#endif // GAME_H
