#pragma once
#ifndef PARAMS_H
#define PARAMS_H

/**
* @file params.h
* @brief Paramters' definition and associated functions
* @ author Maxime Minguella
* @version 1.0
* @date 10 janvier 2019
*/

#include "type.h"

// Lister toutes les cionstantes
//! 1st player's token
const char KTokenPlayer1 = 'X';
//! 2nd player's token
const char KTokenPlayer2 = 'O';
//! empty position token
const char KEmpty = ' ';

/**
* @brief Initialize the set of parameters from scratch
* @param[out] Param : List of usefull parameters
* @fn void InitConfig (CConfig & Param);
*/
void InitConfig(CConfig & Param);

/**
* @brief Load the set of parameters from a YAML file
* @param[out] Param : List of usefull parameters
* @fn void LoadParams (CConfig & Param);
*/
void LoadConfig(CConfig & Param);
#endif // PARAMS_H
