#include <iostream>
#include <iomanip>
#include "gridmanager.h"
#include "type.h" //nos types
#include "params.h" //nos parametres
#include "functions.h"

using namespace std;

void ClearScreen()
{
	cout << "\033[H\033[2J";
} // ClearScreen ()

void Color(const string & Col)
{
	cout << "\033[" << Col.c_str() << "m";
} // Color ()

void DisplayGrid(const CMatrix & Mat, const CConfig & Param)
{
	const unsigned KNbLine = Mat.size();
	const unsigned KNbCol = Mat[0].size();

	string Rule(4 * Mat.size() + 1, '=');
	cout << Rule << endl;
	for (const CVLine & Aline : Mat)
	{
		cout << '|';
		for (auto Cel : Aline)
			cout << setw(2) << Cel << setw(2) << '|';
		cout << endl << Rule << endl;
	}
	cout << string(KNbCol + 2, '-') << endl;
	for (unsigned i(0); i < KNbLine; ++i)
	{
		cout << '|';
		for (char c : Mat[i])
		{
			switch (c)
			{
			case KEmpty:
				cout << c;
				break;
			case KTokenPlayer1:
				Color(getColor("Blue"));
				cout << c;
				Color(getColor("Reset"));
				break;
			case KTokenPlayer2:
				Color(getColor("Red"));
				cout << c;
				Color(getColor("Reset"));
				break;
			}
		}
		cout << '|' << endl;
	}

	cout << string(KNbCol + 2, '-') << endl;
} // DisplayGrid ()

void InitGrid(CMatrix & Grid, unsigned & Size)
{
	Grid.resize(Size);
	const CVLine KLine(Size, Size);
	for (auto & ALine : Grid)
		ALine = KLine;

} // InitMat ()
