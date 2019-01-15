#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H
/*!
* @file gridmanager.h
* @brief Definition of the map and gameplay elements
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

#include "config.h"
#include "type.h"

/**
* @class Grid grid.h
* @brief class containing all map parameters and definition of gameplay elements
*/
class Grid
{
private:

    /**
     * @brief Generation Bombs
     * @param Mat : Game grid
     * @param Params : Init position with Params
     * @return Bombs  Position
     * @fn static CPosition BombsGenerator (CMatrix & Mat, Config & Params);
     */
    static CPosition BombsGenerator (CMatrix & Mat, Config & Params);

    /**
     * @brief Generation SpeedBonus
     * @param Mat : Game grid
     * @param Params : Init position with Params
     * @return SpeedBonus  Position
     * @fn static CPosition SpeedLootsGenerator (CMatrix & Mat, Config & Params);
     */
    static CPosition SpeedLootsGenerator (CMatrix & Mat, Config & Params);

public:
    /**
     * @brief Initialization Grid and KTokensPlayers
     * @param Mat : Game grid
     * @param Size : Size grid
     * @param PosPlayer1 : Position Player 1
     * @param PosPlayer2 : Position Player 2
     * @param Params : Init positions players
     * @fn static void InitGrid (CMatrix & Mat, unsigned & Size, CPosition & PosPlayer1, CPosition & PosPlayer2, Config & Params);
     */
    static void InitGrid (CMatrix & Mat, unsigned & Size, CPosition & PosPlayer1, CPosition & PosPlayer2, Config & Params);

   /**
    * @brief Display Grid and KTokensPlayers
    * @param Mat : Game grid
    * @param Params : Init all variables
    * @param Border : Size gaz border
    * @param PreBorder : Deadly effect gaz
    * @fn static void DisplayGrid (const CMatrix & Mat, Config & Params, const unsigned & Border,  const bool & PreBorder = false);
    */
    static void DisplayGrid (const CMatrix & Mat, Config & Params, const unsigned & Border,  const bool & PreBorder = false);

};

#endif // GRIDMANAGER_H
