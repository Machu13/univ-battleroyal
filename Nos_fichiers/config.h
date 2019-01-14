#ifndef CONFIG_H
#define CONFIG_H

#include "type.h"

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
