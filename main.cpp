#include <iostream>
#include <vector>
#include "type.h"
#include "config.h"

using namespace std;

/*!
 * \brief Clear the terminal
 */
void ClearScreen ()
{
    cout << "\033[H\033[2J";
} //ClearScreen ()

/*!
 * \brief Display color in the terminal
 * \param[in] Col the color in which the next text will be displayed in
 */
void Color (const string & Col)
{
    cout << "\033[" << Col <<"m";
} // Color()

string getColor (const string & Color)
{
    return KColor.find('K' + Color)->second;
}

/*!
 * \brief Initialization of the Matrix from scratch
 * \param[out] Mat the matrix to be initialized
 * \param[in] NbLine number of lines of the matrix Mat
 * \param[in] NbColumn number of columns of the matrix Mat
 * \param[out] PosPlayer1 position of the first player's token in Mat
 * \param[out] PosPlayer2 position of the second player's token in Mat
 */
void InitMat (CMatrix & Mat, unsigned NbLine, unsigned NbColumn, CPosition & PosPlayer1, CPosition & PosPlayer2, CConfig conf)
{
    Mat.resize (NbLine);
    const CVLine KLine (NbColumn, readChar(conf , "KEmpty"));
    for (CVLine &ALine : Mat)
        ALine = KLine;

    PosPlayer1.first = 0;
    PosPlayer1.second = NbColumn - 1;
    Mat [PosPlayer1.first][PosPlayer1.second] = readChar(conf, "KTokenPlayer1");
    PosPlayer2.first = NbLine - 1;
    PosPlayer2.second =0;
    Mat [PosPlayer2.first][PosPlayer2.second]   = readChar(conf, "KTokenPlayer2");

    // + GENERER BOMBE
}//InitMat ()

/*!
 * \brief Display the matrix
 * \param[in] Mat the matrix to be displayed
 */
void ShowMatrix (const CMatrix & Mat, CConfig & config, const unsigned BR)
{
    const string    KBordurePre    = "103";
    const string    KBordurePost   = "101";
    const char KGaz          = ' ';
    const char KE = readChar(config, "KEmpty");
    const char KTP1 = readChar(config, "KTokenPlayer1");
    const char KTP2 = readChar(config, "KTokenPlayer2");

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
            if (i < BR || i > TailleMAT - BR - 1)
            {
                c = KGaz;
                Color(KBordurePost);
                if(c == KE)
                        cout << c;
                else if(c == KTP1)
                {
                    Color(KBordurePre);
                    cout << c;
                    Color(getColor("Reset"));
                }
                else if(c== KTP2)
                {
                    Color(KBordurePre);
                    cout << c;
                    Color(getColor("Reset"));
                }
                Color(getColor("Reset"));
            }
            else
            {
                if (j < BR || j > TailleMAT - BR - 1)
                {
                    Color(KBordurePost);
                    if(c == KE)
                        cout << c;
                    else if(c == KTP1)
                    {
                        Color(getColor("Blue"));
                        cout << c;
                        Color(getColor("Reset"));
                    }
                    else if(c== KTP2)
                    {
                        Color(getColor("Red"));
                        cout << c;
                        Color(getColor("Reset"));
                    }
                    Color(getColor("Reset"));
                }
                else
                {
                    if(c == KE)
                        cout << c;
                    else if(c == KTP1)
                    {
                        Color(getColor("Blue"));
                        cout << c;
                        Color(getColor("Reset"));
                    }
                    else if(c== KTP2)
                    {
                        Color(getColor("Red"));
                        cout << c;
                        Color(getColor("Reset"));
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
    Color(getColor("Reset"));
}// ShowMatrix ()

/*!
 * \brief Move the current token according to the character in the 2nd parameter
 * \param[in, out] Mat the matrix before and after the move
 * \param[in] Move the key pressed by the user
 * \param[in, out] Pos the player's position before and after the move
 */
void MoveToken (CMatrix & Mat, char Move, CPosition & Pos, CConfig & config)
{
    char car = Mat[Pos.first][Pos.second];
    Mat[Pos.first][Pos.second] = readChar(config, "KEmpty");
    unsigned Size = Mat.size() - 1;
    Move = tolower(Move);
    if ('z' == Move && 0 != Pos.first)
    {
        --Pos.first;
    }
    else if ('s' == Move && Size != Pos.first)
    {
        ++Pos.first;
    }
    else if ('q' == Move && 0 != Pos.second)
    {
        --Pos.second;
    }
    else if ('d' == Move && Size != Pos.second)
    {
        ++Pos.second;
    }
    else if ('a' == Move && 0 != Pos.second && 0 != Pos.first)
    {
        --Pos.first;
        --Pos.second;
    }
    else if ('e' == Move && Size != Pos.second && 0 != Pos.first)
    {
        --Pos.first;
        ++Pos.second;
    }
    else if ('w' == Move && 0 != Pos.second && Size != Pos.first)
    {
        ++Pos.first;
        --Pos.second;
    }
    else if ('c' == Move && Size != Pos.second && Size != Pos.first)
    {
        ++Pos.first;
        ++Pos.second;
    }
    Mat[Pos.first][Pos.second] = car;
} //MoveToken ()

/*!
 * \brief New main programm
 * \return 1 if draw 0 otheriwse
 */
int ppal (void)
{
    CConfig config;
    InitConfig (config);
    LoadConfig (config);

    const unsigned KSize (10);
    unsigned PartyNum (1);
    const unsigned KMaxPartyNum (KSize * KSize);
    unsigned BR = 0;
    CMatrix Mat;

    bool Player1Turn (true);
    bool Victory (false);

    CPosition PosPlayer1, PosPlayer2;

    InitMat (Mat, KSize, KSize, PosPlayer1, PosPlayer2, config) ;

    ShowMatrix (Mat, config, BR);

    while (PartyNum <= KMaxPartyNum && ! Victory)
    {

        cout << "tour numero : " << PartyNum << ", Joueur"
             << (Player1Turn ? '1' : '2') << ", entrez un déplacement : ";

        char Move;
        cin >> Move;

        Move = toupper (Move);
        MoveToken (Mat, Move, (Player1Turn ? PosPlayer1: PosPlayer2), config);
        ClearScreen();
        ShowMatrix (Mat, config, BR);

        //Victiry test
        if (PosPlayer1 == PosPlayer2) Victory = true;

        //Increase party's number
        ++PartyNum;
        //TODO//++BR;

        //Player changing
        Player1Turn = !Player1Turn;
    }//while (no victory)

    if (!Victory)
    {
        Color (getColor("Magenta"));
        cout << "Aucun vainqueur" << endl;
        return 1;
    }

    Color (getColor("KGreen"));
    cout << "Félicitations Joueur" << (Player1Turn ? '2' : '1')
         << " vous avez gagné :)" << endl;
    Color (getColor("Reset"));
    return 0;
} //ppal ()

/*!
 * \brief main
 * \return ppal () value
 */
int main ()
{
    return ppal ();

}// main ()
