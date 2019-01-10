#pragma once

#ifndef GAME_H
#define GAME_H

/*!
* \file game.h
* \brief Set of functions usefull for the gam
*/

#include "type.h"

/**
* @brief Display the menu according to the set of parameters.
* @param[out] Pos : Position of the token to move
* @param[out] Direction : Direction of wanted movement
* @param[in] Params : List of usefull parameters
* \fn void Menu (CPosition & Pos, char & Direction, const CConfig & Params);
*/
void Menu(CPosition & Pos, char & Direction, const CConfig & Params);

/**
* @brief Swap the token from its inital place to its final destination
* @param[in|out] Grid : Game grid
* @param[in] Pos : Position of the token to move
* @param[in] Direction : : Direction of wanted movement
* @param[in] Params : List of usefull parameters
* \fn void MakeAMove (CMatrix & Grid, const CPosition & Pos, const char & Direction, const CConfig & Params);
* \bug No control is provided as to the validity of the move
*/
void MakeAMove(CMatrix & Grid, const CPosition & Pos, const char & Direction, const CConfig & Params);

/**
* @brief new main
* @return 0 if everything is OK
* @fn int ppal ();
*/
int game();
#endif // GAME_H
