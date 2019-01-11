#ifndef CONFIG_H
#define CONFIG_H

#include "type.h"

void InitConfig (CConfig & Param);

void LoadConfig (CConfig & Param);

int readInt32(const std::string & Val);

char readChar(const std::string & Val);

std::string readString(const std::string & Val);

#endif // CONFIG_H
