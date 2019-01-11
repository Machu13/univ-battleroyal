#ifndef CONFIG_H
#define CONFIG_H

#include "type.h"

/**
 * @brief InitConfig
 * @param Param
 */
void InitConfig (CConfig & Param);

/**
 * @brief LoadConfig
 * @param Param
 */
void LoadConfig (CConfig & Param);

/**
 * @brief readInt32
 * @param Param
 * @param Val
 * @return
 */
const int readInt32(CConfig & Param, const std::string & Val);

/**
 * @brief readChar
 * @param Param
 * @param Val
 * @return
 */
const char readChar(CConfig & Param, const std::string & Val);

/**
 * @brief readString
 * @param Param
 * @param Val
 * @return
 */
const std::string readString(CConfig & Param, const std::string & Val);

#endif // CONFIG_H
