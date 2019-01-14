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
    CConfig Param;
public:

    Config (CConfig & Param);

    void InitConfig ();

    void LoadConfig (const std::string & FileName);

    static void UpdateConfig();

    int readInt32(const std::string & Val);

    char readChar(const std::string & Val);

    const std::string readString(const std::string & Val);

    CConfig getConfig();

};

#endif // CONFIG_H
