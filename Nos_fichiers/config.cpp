#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "type.h"
#include "config.h"

using namespace std;

Config::Config (CConfig & Param)
{
    this->Param = Param;
}

CConfig Config::getConfig()
{
    return this->Param;
}

int Config::readInt32(const string & Val)
{
    return Param.MapParamUnsigned[Val];
}

char Config::readChar(const string & Val)
{
    return Param.MapParamChar[Val];
}

const string Config::readString(const string & Val)
{
    return Param.MapParamString[Val];
}

void Config::InitConfig()
{
    //Move Keys
    Param.MapParamChar["KeyUp"] = 'z';
    Param.MapParamChar["KeyDown"] = 'x';
    Param.MapParamChar["KeyLeft"] = 'q';
    Param.MapParamChar["KeyRight"] = 'd';
    Param.MapParamChar["KeyUpLeft"] = 'a';
    Param.MapParamChar["KeyUpRight"] = 'e';
    Param.MapParamChar["KeyDownLeft"] = 'w';
    Param.MapParamChar["KeyDownRight"] = 'c';
    Param.MapParamChar["KeyStayHere"] = 's';
    Param.MapParamChar["KTokenPlayer1"] = 'X';
    Param.MapParamChar["KTokenPlayer2"] = 'O';
    Param.MapParamChar["KEmpty"] = ' ';
    Param.MapParamChar["KTokenBomb"] = '#';
    Param.MapParamChar["KTokenSpeed"] = '/';

    //Size of grid -- suppose to be squared
    Param.MapParamUnsigned["GridSize"] = 10;
    Param.MapParamUnsigned["GridMax"] = 10;
    Param.MapParamUnsigned["GridMin"] = 10;

    //Display Colors
    Param.MapParamString["KLineColor"] = KColor.find("KBlack")->second;
    Param.MapParamString["KRowColor"] = KColor.find("KBlack")->second;
    Param.MapParamString["KIndexColor"] = KColor.find("KBlack")->second;
    Param.MapParamString["KColorPlayer1"] = KColor.find("KBlue")->second;
    Param.MapParamString["KColorPlayer2"] = KColor.find("KRed")->second;
    Param.MapParamString["KColorBomb"] = KColor.find("KRed")->second;
    Param.MapParamString["KColorSpeed"] = KColor.find("KCyan")->second;
    Param.MapParamString["KBorderColor"] = KColor.find("KRed")->second;
    Param.MapParamString["KColorVictory"] = KColor.find("KGreen")->second;
    Param.MapParamString["KColorLose"] = KColor.find("KRed")->second;
}

void Config::LoadConfig (const string & FileName)
{
    ifstream ifs(FileName);
    if (!ifs.is_open())
    {
        cerr << "pas le bon fichier de configuration";
        exit(2);
    }
    string Key;
    while (ifs >> Key)
    {
        char tmp;
        ifs >> tmp;
        if (find(KAuthorizedKey.VParamChar.begin(), KAuthorizedKey.VParamChar.end(), Key) != KAuthorizedKey.VParamChar.end())
            ifs >> Param.MapParamChar[Key];
        else if (find(KAuthorizedKey.VParamUnsigned.begin(), KAuthorizedKey.VParamUnsigned.end(), Key) != KAuthorizedKey.VParamUnsigned.end())
            ifs >> Param.MapParamUnsigned[Key];
        else if (find(KAuthorizedKey.VParamString.begin(), KAuthorizedKey.VParamString.end(), Key) != KAuthorizedKey.VParamString.end())
        {
            string Val;
            ifs >> Val;
            Param.MapParamString[Key] = KColor.find(Val)->second;
        }
        else
        {
            // Et merci le partiel du 12/01
            string buffer;
            ifs >> buffer;
        }
    }
}
