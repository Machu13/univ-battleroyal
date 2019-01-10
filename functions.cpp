#include <string>
#include "type.h"

std::string getColor(const std::string & Color)
{
	try
	{
		return KColor.find("K" + Color)->second;
	}
	catch (...)
	{
		return "0";
	}
}