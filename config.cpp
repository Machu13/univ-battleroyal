#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "type.h"
#include "config.h"

using namespace std;

void InitConfig(CConfig & Param)
{
    //Move Keys
    Param.MapParamChar["KeyUp"] = 'z';
    Param.MapParamChar["KeyDown"] = 's';
    Param.MapParamChar["KeyLeft"] = 'q';
    Param.MapParamChar["KeyRight"] = 'd';
    Param.MapParamChar["KeyUpLeft"] = 'a';
    Param.MapParamChar["KeyUpRight"] = 'e';
    Param.MapParamChar["KeyDownLeft"] = 'w';
    Param.MapParamChar["KeyDownRight"] = 'c';
    Param.MapParamChar["Icon1"] = 'X';
    Param.MapParamChar["Icon2"] = 'O';
    Param.MapParamChar["Icon3"] = '¤';
    Param.MapParamChar["Icon4"] = '‡';

    //Size of grid -- suppose to be squared
    Param.MapParamUnsigned["GridSize"] = 10;
    Param.MapParamUnsigned["GridMax"] = 10;
    Param.MapParamUnsigned["GridMin"] = 10;

    //Display Colors
    Param.MapParamString["LineColor"] = KColor.find("KBlack")->second;
    Param.MapParamString["RowColor"] = KColor.find("KBlack")->second;
    Param.MapParamString["IndexColor"] = KColor.find("KBlack")->second;
    Param.MapParamString["Color1"] = KColor.find("KBlue")->second;
    Param.MapParamString["Color2"] = KColor.find("KGreen")->second;
    Param.MapParamString["Color3"] = KColor.find("KRed")->second;
    Param.MapParamString["Color4"] = KColor.find("KCyan")->second;
    Param.MapParamString["BorderColor"] = KColor.find("KRed")->second;
}

void LoadConfig(CConfig & Param)
{
    ifstream ifs("config.yml");
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
    }
}

int readInt32(CConfig & Param, const string & Val)
{
    return Param.MapParamUnsigned[Val];
}

char readChar(CConfig & Param, const string & Val)
{
    return Param.MapParamChar[Val];
}

string readString(CConfig & Param, const string & Val)
{
    return Param.MapParamString[Val];
}

