#include <iostream>
#include <map>
#include "game.h"
#include "params.h"
#include "gridmanager.h"

using namespace std;

template <class T, class U>
void ShowMap(const map<T, U> & AMap) {
	for (const pair <T, U> & Val : AMap)
		cout << "Cle : " << Val.first << "   " << "Valeur : " << Val.second << endl;
	cout << endl;
}

void Menu(CPosition & Pos, char & Direction, const CConfig & Params)
{
	ShowMap(Params.MapParamChar);
	cout << "Saisir un indice de ligne, un indice de column,\n"
		<< " et un sens de Deplacements : \n"
		<< Params.MapParamChar.find("KeyLeft")->second << " a gauche,\n "
		<< Params.MapParamChar.find("KeyDown")->second << " en bas,\n"
		<< Params.MapParamChar.find("KeyRight")->second << " a droite,\n "
		<< Params.MapParamChar.find("KeyUp")->second << " en haut\n"
		<< endl;
	cin >> Pos.first >> Pos.second >> Direction;

} // Menu()

void MakeAMove(CMatrix & Grid, const CPosition & Pos, const char & Direction, const CConfig & Params)
{
	unsigned NewLineNumber(Pos.first), NewColumnNumber(Pos.second);
	if (Direction == Params.MapParamChar.find("KeyLeft")->second)
		--NewColumnNumber;
	else if (Direction == Params.MapParamChar.find("KeyDown")->second)
		++NewLineNumber;
	else if (Direction == Params.MapParamChar.find("KeyRight")->second)
		++NewColumnNumber;
	else if (Direction == Params.MapParamChar.find("KeyUp")->second)
		--NewLineNumber;
	else
		exit(EXIT_FAILURE);
	swap(Grid[Pos.first][Pos.second], Grid[NewLineNumber][NewColumnNumber]);
} // MakeAMove ()

int game()
{
	CConfig Params;
	InitConfig(Params);
	//LoadConfig(Params);

	CMatrix Grid;
	InitGrid(Grid, 10);
	CPosition Pos;
	unsigned Score(0);
	char Dirrection;


	cout << "Your score is : " << Score << endl << "That's not so bad for a dummy ;)" << endl;
	return 0;
}
