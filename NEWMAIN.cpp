#include <iostream>
#include <vector>
 
 
using namespace std;
 
 
//! 1st player's token
const char KTokenPlayer1 = 'X';
//! 2nd player's token
const char KTokenPlayer2 = 'O';
//! empty position token
const char KEmpty        = ' ';
 
//!alias to the reset color display
const string    KReset    = "0";
//!alias to the black color
const string    KBlack    = "30";
//!alias to the red color
const string    KRed      = "31";
//!alias to the green color
const string    KGreen    = "32";
//!alias to the yellow color
const string    KYellow   = "33";
//!alias to the blue color
const string    KBlue     = "34";
//!alias to the mangenta color
const string    KMagenta  = "35";
//!alias to the cyan color
const string    KCyan     = "36";
 
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
 
 
/*!
 * \brief alias to vector of char,
 * represents a line of the matrix
 */
typedef vector <char> CVLine;
 
/*!
 * \brief alias to the Matrix
 */
typedef vector <CVLine> CMatrix;
 
/*!
 * \brief represent a pair (unsigned, unsigned) : a position in the matrix
 * \brief 1st element is coordinate on the x-axis, 2nd element is the coordinate on the y-axis
 */
typedef pair <unsigned, unsigned> CPosition;
 
/*!
 * \brief Initialization of the Matrix from scratch
 * \param[out] Mat the matrix to be initialized
 * \param[in] NbLine number of lines of the matrix Mat
 * \param[in] NbColumn number of columns of the matrix Mat
 * \param[out] PosPlayer1 position of the first player's token in Mat
 * \param[out] PosPlayer2 position of the second player's token in Mat
 */
void InitMat (CMatrix & Mat, unsigned NbLine, unsigned NbColumn, CPosition & PosPlayer1, CPosition & PosPlayer2)
{
    Mat.resize (NbLine);
    const CVLine KLine (NbColumn, KEmpty);
    for (CVLine &ALine : Mat)
        ALine = KLine;
 
    PosPlayer1.first = 0;
    PosPlayer1.second = NbColumn - 1;
    Mat [PosPlayer1.first][PosPlayer1.second] = KTokenPlayer1;
    PosPlayer2.first = NbLine - 1;
    PosPlayer2.second =0;
    Mat [PosPlayer2.first][PosPlayer2.second]   = KTokenPlayer2;
}//InitMat ()
 
 
/*!
 * \brief Display the matrix
 * \param[in] Mat the matrix to be displayed
 */
void ShowMatrix (const CMatrix & Mat)
{
    const unsigned KNbLine = Mat.size ();
    const unsigned KNbCol  = Mat[0].size ();
    cout << string (KNbCol + 2 , '-') << endl;
    for (unsigned i (0); i < KNbLine; ++i)
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
                Color (KBlue);
                cout << c;
                Color (KReset);
                break;
            case KTokenPlayer2:
                Color (KRed);
                cout << c;
                Color (KReset);
                break;
 
            }
        }
        cout << '|' << endl;
    }
    cout << string (KNbCol + 2 , '-') << endl;
}// ShowMatrix ()
 
/*!
 * \brief Move the current token according to the character in the 2nd parameter
 * \param[in, out] Mat the matrix before and after the move
 * \param[in] Move the key pressed by the user
 * \param[in, out] Pos the player's position before and after the move
 */
 
void MoveToken (CMatrix & Mat, char Move, CPosition & Pos)
{
    char car = Mat [Pos.first][Pos.second];
    Mat [Pos.first][Pos.second] = KEmpty;
    switch (Move)
    {
    case 'A':
        -- Pos.first;
        -- Pos.second;
        break;
    case 'Z':
        --Pos.first;
        break;
    case 'E':
        --Pos.first;
        ++Pos.second;
        break;
    case 'Q':
        --Pos.second;
        break;
    case 'D':
        ++Pos.second;
        break;
    case 'W':
        ++Pos.first;
        --Pos.second;
        break;
    case 'X':
        ++Pos.first;
        break;
    case 'C':
        ++Pos.first;
        ++Pos.second;
        break;
    }
    Mat [Pos.first][Pos.second] = car;
} //MoveToken ()
 
 
 
/*!
 * \brief New main programm
 * \return 1 if draw 0 otheriwse
 */
int ppal (void)
{
 
    const unsigned KSize (10);
    unsigned PartyNum (1);
    const unsigned KMaxPartyNum (KSize * KSize);
    CMatrix Mat;
 
    bool Player1Turn (true);
    bool Victory (false);
 
    CPosition PosPlayer1, PosPlayer2;
 
    InitMat (Mat, KSize, KSize, PosPlayer1, PosPlayer2) ;
 
    ShowMatrix (Mat);
 
    while (PartyNum <= KMaxPartyNum && ! Victory)
    {
 
        cout << "tour numero : " << PartyNum << ", Joueur"
             << (Player1Turn ? '1' : '2') << ", entrez un déplacement : ";
 
        char Move;
        cin >> Move;
 
        Move = toupper (Move);
        MoveToken (Mat, Move, (Player1Turn ? PosPlayer1: PosPlayer2));
        ClearScreen();
        ShowMatrix (Mat);
 
        //Victiry test
        if (PosPlayer1 == PosPlayer2) Victory = true;
 
        //Increase party's number
        ++PartyNum;
 
        //Player changing
        Player1Turn = !Player1Turn;
    }//while (no victory)
 
    if (!Victory)
    {
        Color (KMagenta);
        cout << "Aucun vainqueur" << endl;
        return 1;
    }
 
    Color (KGreen);
    cout << "Félicitations Joueur" << (Player1Turn ? '2' : '1')
         << " vous avez gagné :)" << endl;
    Color (KReset);
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
