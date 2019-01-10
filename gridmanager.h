#pragma once
#ifndef GRIDMANAGEMENT_H
#define GRIDMANAGEMENT_H

/*!
* @file gridmanagement.h
* @brief Set of usefull functions for the grid management
*/

#include <string>

#include "type.h" //nos types

/**
* @brief Clear the current terminal
* @fn void ClearScreen ();
*/
void ClearScreen();

/**
* @brief Set the color of the future input in the terminal
* @param[in] Col : Next color to be used
* @fn void Color (const std::string & Col);
*/
void Color(const std::string & Col);

/**
* @brief Display the grid according to the parameters
* @param[in] Mat : Game grid
* @param[in] Params : : List of usefull parameters
* @fn void DisplayGrid (const CMatrix & Mat, const CConfig & Params);
*/
void DisplayGrid(const CMatrix & Mat, const CConfig & Params);


/**
* @brief Initialize the grid according to the size
* @param[out] Grid: Game grid to be initalized
* @param[in] Size : Number of rows / columns of the grid (supposed to be squared)
* @fn void InitGrid (CMatrix & Grid, const unsigned & Size);
*/
void InitGrid(CMatrix & Grid, const unsigned & Size);

#endif // GRIDMANAGEMENT_H
