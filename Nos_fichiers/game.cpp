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
    Menu::ShowMainMenu();
    IO::set_input_mode();
    CConfig configFile;
    Config config = Config (configFile);
    config.InitConfig ();
    config.LoadConfig ("../univ-battleroyal/Nos_fichiers/config.yml");

    const unsigned KSize (config.readInt32("GridSize"));
    unsigned PartyNum (1);
    const unsigned KMaxPartyNum (KSize * KSize);
    unsigned BR = 0;
    CMatrix Mat;

    bool Player1Turn (true);
    bool Victory (false);

    CPosition PosPlayer1, PosPlayer2;

    Grid::InitGrid (Mat, KSize, PosPlayer1, PosPlayer2, config) ;

    Grid::DisplayGrid (Mat, config, BR);

    while (PartyNum <= KMaxPartyNum && ! Victory)
    {

        cout << "Tour numero : " << PartyNum << ", ";
        (Player1Turn ? Screen::Color(config.readString("KColorPlayer1")) : Screen::Color(config.readString("KColorPlayer2")));
        cout << "Joueur" << (Player1Turn ? '1' : '2') << ", entrez un déplacement : ";
        Screen::Color (Screen::getColor ("Reset"));

        char Move;
        cin >> Move;

        Move = toupper (Move);
        MoveToken (Mat, Move, (Player1Turn ? PosPlayer1: PosPlayer2), config);
        Screen::ClearScreen();
        Grid::DisplayGrid (Mat, config, BR);

        //Victiry test
        if (PosPlayer1 == PosPlayer2)
            Victory = true;
        //Increase party's number
        ++PartyNum;
       //++BR;

        //Player changing
        Player1Turn = !Player1Turn;
    }//while (no victory)

    if (!Victory)
    {
        Screen::Color (Screen::getColor("Magenta"));
        cout << "Aucun vainqueur" << endl;
        return 1;
    }

    Screen::Color (Screen::getColor("KGreen"));
    cout << "Félicitations Joueur" << (Player1Turn ? '2' : '1')
         << " vous avez gagné :)" << endl;
    Screen::Color (Screen::getColor("Reset"));
    return 0;
} // ppal ()
