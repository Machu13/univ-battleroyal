#include <iostream>
#include <string>
#include "game.h"
#include "config.h"
#include "screen.h"
#include "gridmanager.h"
#include "ioutils.h"
#include "menu.cpp"

using namespace std;

void Game::MoveToken (CMatrix & Mat, char Move, CPosition & Pos, Config & config)
{
    char car = Mat[Pos.first][Pos.second];
    Mat[Pos.first][Pos.second] = config.readChar("KEmpty");
    unsigned Size = Mat.size() - 1;
    Move = tolower(Move);
    if (config.readChar("KeyUp") == Move && 0 != Pos.first)
    {
        --Pos.first;
    }
    else if (config.readChar("KeyDown") == Move && Size != Pos.first)
    {
        ++Pos.first;
    }
    else if (config.readChar("KeyLeft") == Move && 0 != Pos.second)
    {
        --Pos.second;
    }
    else if (config.readChar("KeyRight") == Move && Size != Pos.second)
    {
        ++Pos.second;
    }
    else if (config.readChar("KeyUpLeft") == Move && 0 != Pos.second && 0 != Pos.first)
    {
        --Pos.first;
        --Pos.second;
    }
    else if (config.readChar("KeyUpRight") == Move && Size != Pos.second && 0 != Pos.first)
    {
        --Pos.first;
        ++Pos.second;
    }
    else if (config.readChar("KeyDownLeft") == Move && 0 != Pos.second && Size != Pos.first)
    {
        ++Pos.first;
        --Pos.second;
    }
    else if (config.readChar("KeyDownRight") == Move && Size != Pos.second && Size != Pos.first)
    {
        ++Pos.first;
        ++Pos.second;
    }
    Mat[Pos.first][Pos.second] = car;
} // MoveToken ()

int Game::ppal ()
{
    // Noncanon stream
    IO::set_input_mode();
    // Show Main Menu
    Menu::ShowMainMenu();
    // Init config
    CConfig configFile;
    Config config = Config (configFile);
    config.InitConfig ();
    config.LoadConfig ("../univ-battleroyal/Nos_fichiers/config.yml");
    // Vars
    const unsigned KSize (config.readInt32("GridSize"));
    unsigned PartyNum (0);
    const unsigned KMaxPartyNum (4 * KSize - 4);
    const unsigned KNbTourAvantGaz ( KMaxPartyNum / ( ( KSize / 2 ) + 1 ) );
    unsigned Border (0);
    bool PreBorder (false);
    unsigned Gagnant (0);
    bool Player1Turn (true);

    CMatrix Mat;
    CPosition PosPlayer1, PosPlayer2;

    Grid::InitGrid (Mat, KSize, PosPlayer1, PosPlayer2, config) ;

    Grid::DisplayGrid (Mat, config, Border);

    while (! false) // <3
    {
        (Player1Turn ? Screen::Color(config.readString("KColorPlayer1")) : Screen::Color(config.readString("KColorPlayer2")));
        cout << "Joueur" << (Player1Turn ? '1' : '2') << ", entrez un déplacement : " << PartyNum;
        Screen::Color (Screen::getColor ("Reset"));

        char Move;
        cin >> Move;

        Move = toupper (Move);
        MoveToken (Mat, Move, (Player1Turn ? PosPlayer1: PosPlayer2), config);

        Screen::ClearScreen();
        Grid::DisplayGrid (Mat, config, Border, PreBorder);

        //Victiry test
        if (PosPlayer1 == PosPlayer2)
        {
            Gagnant=(Player1Turn ? 1 : 2);
            break;
        }
        if ((! PreBorder
             && (   (PosPlayer1.first  + 1) <= Border || PosPlayer1.first  >= (KSize - Border)
                 || (PosPlayer1.second + 1) <= Border || PosPlayer1.second >= (KSize - Border))
             && (   (PosPlayer2.first  + 1) <= Border || PosPlayer2.first  >= (KSize - Border)
                 || (PosPlayer2.second + 1) <= Border || PosPlayer2.second >= (KSize - Border))))
            break;
        else if (! PreBorder
             && (   (PosPlayer1.first  + 1) <= Border || PosPlayer1.first  >= (KSize - Border)
                 || (PosPlayer1.second + 1) <= Border || PosPlayer1.second >= (KSize - Border)))
        {
            Gagnant = 2;
            break;
        }
        else if (! PreBorder
             && (   (PosPlayer2.first  + 1) <= Border || PosPlayer2.first  >= (KSize - Border)
                 || (PosPlayer2.second + 1) <= Border || PosPlayer2.second >= (KSize - Border)))
        {
            Gagnant = 1;
            break;
        }

        // Increase party's number
        ++PartyNum;

        // Gaz size increasing
        if ((PartyNum + 2) % (KNbTourAvantGaz) == 0)
        {
            ++Border;
            PreBorder = ! PreBorder;
        }
        else if ((PartyNum) % (KNbTourAvantGaz) == 0)
        {
            PreBorder = ! PreBorder;
        }

        // Player changing
        Player1Turn = !Player1Turn;
    }

    switch (Gagnant) {
    case 0:
        cout << "Aucun winner" << endl;
        break;
    case 1 :
        cout << "Joueur 1 gagnant !" << endl;
        break;
    case 2 :
        cout << "Joueur 2 gagnant " << endl;
        break;
    default:
        break;
    }
    return 0;
} // ppal ()
