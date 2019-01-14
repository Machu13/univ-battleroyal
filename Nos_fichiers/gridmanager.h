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
     * @brief BombsGenerator
     * @param Mat
     * @param Params
     * @return
     */
    static CPosition BombsGenerator (CMatrix & Mat, Config & Params);

    /**
     * @brief SpeedLootsGenerator
     * @param Mat
     * @param Params
     * @return
     */
    static CPosition SpeedLootsGenerator (CMatrix & Mat, Config & Params);

public:
    /**
     * @brief InitGrid
     * @param Mat
     * @param Size
     * @param PosPlayer1
     * @param PosPlayer2
     * @param Params
     */
    static void InitGrid (CMatrix & Mat, unsigned Size, CPosition & PosPlayer1, CPosition & PosPlayer2, Config & Params);

    /**
     * @brief DisplayGrid
     * @param Mat
     * @param Params
     * @param Border
     * @param PreBorder
     */
    static void DisplayGrid (const CMatrix & Mat, Config & Params, const unsigned Border,  const bool & PreBorder = false);

};

#endif // GRIDMANAGER_H
