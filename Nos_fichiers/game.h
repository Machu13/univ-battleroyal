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
     * @brief MoveToken
     * @param Mat
     * @param Move
     * @param Pos
     * @param config
     */
    static void MoveToken (CMatrix & Mat, char Move, CPosition & Pos, Config & config);

    /**
     * @brief new main
     * @param SkipMenu
     * @return
     * @fn int ppal ();
     */
    static int ppal(const bool & SkipMenu = false);

};

#endif // GAME_H
