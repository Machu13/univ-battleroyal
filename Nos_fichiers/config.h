#ifndef CONFIG_H
#define CONFIG_H

/*!
* @file config.h
* @brief Definition of configuration of the game
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

#include "type.h"

/**
* @class Config config.h
* @brief class containing all the game's parameters
*/
class Config {
private:
    /**
     * @brief configuration file
     * @fn CConfig Param
     */
    CConfig Param;
public:
    /**
     * @brief Constructor : Class manage configuration
     * @param [in] Param : settings
     * @fn Config (CConfig & Param)
     */
    Config (CConfig & Param);

    /**
     * @brief InitConfig : initialize default configuration
     * @fn void InitConfig()
     */
    void InitConfig ();

    /**
     * @brief Loading of configuration
     * @param [in] FileName : config stream file
     * @fn void LoadConfig (const std::string & FileName)
     */
    void LoadConfig (const std::string & FileName);

    /**
     * @brief void looking for value
     * @param [in] Val : key of configuration
     * @return value of int
     * @fn int readInt32 (const::string & Val)
     */
    int readInt32(const std::string & Val);

    /**
     * @brief readChar : recover config characters
     * @param [in] Val : Char
     * @return char
     * @fn char readChar (const std::string & val)
     */
    char readChar(const std::string & Val);

    /**
     * @brief readString : recover config string
     * @param [in] Val : string
     * @return value of function in parameters
     * @fn const std::string readString(const std::string & Val)
     */
    const std::string readString(const std::string & Val);

    /**
     * @brief getConfig : return configuration file
     * @return class of the config parameters
     * @fn CConfig getConfig()
     */
    CConfig getConfig();

};

#endif // CONFIG_H
