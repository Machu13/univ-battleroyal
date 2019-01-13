#include <iostream>
#include <string>
#include "type.h"
#include "config.h"
#include "screen.h"
#include "gridmanager.h"

using namespace std;

void Grid::InitGrid (CMatrix & Mat, unsigned NbLine, unsigned NbColumn, CPosition & PosPlayer1, CPosition & PosPlayer2, Config & Params)
{
    Mat.resize (NbLine);
    const CVLine KLine (NbColumn, Params.readChar("KEmpty"));
    for (CVLine &ALine : Mat)
        ALine = KLine;

    PosPlayer1.first = 0;
    PosPlayer1.second = NbColumn - 1;
    Mat [PosPlayer1.first][PosPlayer1.second]   = Params.readChar("KTokenPlayer1");
    PosPlayer2.first = NbLine - 1;
    PosPlayer2.second =0;
    Mat [PosPlayer2.first][PosPlayer2.second]   = Params.readChar("KTokenPlayer2");

    // + GENERER BOMBE
} // InitGrid ()

void Grid::DisplayGrid (const CMatrix & Mat, Config & Params, const unsigned Border)
{
    const string    KBordurePre    = "103";
    const string    KBordurePost   = "101";
    const char      KGaz           = ' ';
    const char      KE             = Params.readChar("KEmpty");
    const char      KTP1           = Params.readChar("KTokenPlayer1");
    const char      KTP2           = Params.readChar("KTokenPlayer2");

    const unsigned TailleMAT = Mat.size();
    for (unsigned i(0); i < TailleMAT; ++i)
    {
        cout << endl;
        if (i == 0)
        {
            cout << " ┌";
            for (unsigned k(1); k < TailleMAT * 4; ++k)
                cout << ((k == ((TailleMAT * 4) - 1)) ? "─┐" : ((k % 4 == 0) ? "┬" : "─"));
        }
        else
        {
            cout << " ├";
            for (unsigned k(1); k < TailleMAT * 4; ++k)
                cout << ((k == ((TailleMAT * 4) - 1)) ? "─┤" : ((k % 4 == 0) ? "┼" : "─"));
        }
        cout << endl;

        for (unsigned j(0); j < TailleMAT; ++j)
        {
            char c = Mat[i][j];
            cout << " │ ";
            if (i < Border || i > TailleMAT - Border - 1)
            {
                c = KGaz;
                Screen::Color(KBordurePost);
                if(c == KE)
                        cout << c;
                else if(c == KTP1)
                {
                    Screen::Color(KBordurePre);
                    cout << c;
                    Screen::Color(Screen::getColor("Reset"));
                }
                else if(c== KTP2)
                {
                    Screen::Color(KBordurePre);
                    cout << c;
                    Screen::Color(Screen::getColor("Reset"));
                }
                Screen::Color(Screen::getColor("Reset"));
            }
            else
            {
                if (j < Border || j > TailleMAT - Border - 1)
                {
                    Screen::Color(KBordurePost);
                    if(c == KE)
                        cout << c;
                    else if(c == KTP1)
                    {
                        Screen::Color(Screen::getColor("Blue"));
                        cout << c;
                        Screen::Color(Screen::getColor("Reset"));
                    }
                    else if(c== KTP2)
                    {
                        Screen::Color(Screen::getColor("Red"));
                        cout << c;
                        Screen::Color(Screen::getColor("Reset"));
                    }
                    Screen::Color(Screen::getColor("Reset"));
                }
                else
                {
                    if(c == KE)
                        cout << c;
                    else if(c == KTP1)
                    {
                        Screen::Color(Screen::getColor("Blue"));
                        cout << c;
                        Screen::Color(Screen::getColor("Reset"));
                    }
                    else if(c== KTP2)
                    {
                        Screen::Color(Screen::getColor("Red"));
                        cout << c;
                        Screen::Color(Screen::getColor("Reset"));
                    }
                }
            }
        }
        cout << " │";
    }
    cout << endl << " └";
    for (unsigned k(1); k < TailleMAT * 4; ++k)
        cout << ((k == ((TailleMAT * 4) - 1)) ? "─┘" : ((k % 4 == 0) ? "┴" : "─" ));
    cout << endl;
    Screen::Color(Screen::getColor("Reset"));
}
