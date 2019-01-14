#include <iostream>
#include <string>
#include <regex>
#include "game.h"
#include "config.h"
#include "screen.h"
#include "gridmanager.h"
#include "ioutils.h"
#include "menu.h"
#include "score.h"

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

int Game::ppal (const bool & SkipMenu)
{
    // Firewall again Alain
    IO::bloc_sig ();
    // Noncanon stream
    IO::set_input_mode ();
    // Show Main Menu
    if (! SkipMenu)
        Menu::ShowMainMenu ();
    // Init config
    CConfig configFile;
    Config config = Config (configFile);
    config.InitConfig ();
    config.LoadConfig ("../univ-battleroyal/Nos_fichiers/config.yml");
    // Vars
    const unsigned KSize (config.readInt32("GridSize"));
    unsigned RoundNum (0);
    const unsigned KMaxRoundNum (4 * KSize - 4);
    const unsigned KNbTourAvantGaz ( KMaxRoundNum / ( ( KSize / 2 ) + 1 ) );
    unsigned Border (0), Gagnant (0), NbV (0);
    bool PreBorder (false), Player1Turn (true);

    Score score = Score ("../univ-battleroyal/Nos_fichiers/score.txt");
    if (! score.ReadScoreFile())
    {
        cerr << "Le fichier score.txt n'existe pas !" << endl;
        return 1;
    }

    CMatrix Mat;
    CPosition PosPlayer1, PosPlayer2;

    Grid::InitGrid (Mat, KSize, PosPlayer1, PosPlayer2, config) ;

    Grid::DisplayGrid (Mat, config, Border);

    while (RoundNum <= KMaxRoundNum)
    {
        cout << "Tour numero : " << RoundNum << endl;
        Screen::Color (config.readString("KColorPlayer" + string (1, (Player1Turn ? '1' : '2'))));
        cout << "Joueur" << (Player1Turn ? '1' : '2') << endl << "Entrez un deplacement : ";
        Screen::Color (Screen::getColor ("Reset"));

        bool CorrectMove (false);
        char Move;
        cin >> Move;
        Move = toupper (Move);
        regex pattern ("^Key");
        // Beaucoup de complexitude pour pas grand chose.
        // Mais au moins c'est plus opti que un grand if avec plein de OU
        for (const auto & Val : config.getConfig().MapParamChar)
            for (sregex_iterator regIt (sregex_iterator(Val.first.begin(), Val.first.end(), pattern));
                 regIt != sregex_iterator (); ++ regIt)
                if (Move == toupper(Val.second))
                    CorrectMove = true;
        if (CorrectMove)
        {
            MoveToken (Mat, Move, (Player1Turn ? PosPlayer1: PosPlayer2), config);
            Screen::ClearScreen();
            Grid::DisplayGrid (Mat, config, Border, PreBorder);
            Screen::Color (config.readString("KColorPlayer" + string (1, (Player1Turn ? '1' : '2'))));
            if (Move == toupper(config.readChar("KeyStayHere")))
                cout << "Joueur n° " << (Player1Turn ? '1' : '2') << " dit : \"JE RESTE PLANTE LA\"" << endl;
            else
                cout << "Joueur n° " << (Player1Turn ? '1' : '2') << ", au tour precedent, a fait : " << Move << endl;
            Screen::Color (Screen::getColor ("Reset"));

            // Victory test
            if (PosPlayer1 == PosPlayer2)
            {
                Gagnant = (Player1Turn ? 1 : 2);
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

            // Increase Round's number
            ++ RoundNum;

            // Gaz size increasing
            if ((RoundNum + 2) % (KNbTourAvantGaz) == 0)
            {
                ++ Border;
                PreBorder = ! PreBorder;
            }
            else if ((RoundNum) % (KNbTourAvantGaz) == 0)
                PreBorder = ! PreBorder;

            // Player changing
            Player1Turn = !Player1Turn;
        }
        else
        {
            Screen::ClearScreen ();
            Grid::DisplayGrid(Mat, config, Border);
            cout << "!! Veuillez entrer un deplacement correct !!" << endl << endl;
        }
    }

    while (! false)  // <3
    {
        Screen::ClearScreen ();
        Screen::Color (config.readString("KColorVictory"));
        cout << Screen::center (" _    _ _____ ______ _______ _____  ______  _     _ ")    << endl;
        cout << Screen::center ("| |  | (_____) _____|_______) ___ \\(_____ \\| |   | |")  << endl;
        cout << Screen::center ("| |  | |  _ | /      _     | |   | |_____) ) |___| |")    << endl;
        cout << Screen::center (" \\ \\/ /  | || |     | |    | |   | (_____ ( \\_____/ ") << endl;
        cout << Screen::center ("  \\  /  _| || \\_____| |____| |___| |     | |  ___   ")  << endl;
        cout << Screen::center ("   \\/  (_____)______)\\______)_____/      |_| (___)  ")  << endl;
        cout << endl << endl;
        switch (Gagnant) {
        case 0:
            Screen::Color (config.readString("KColorLose"));
            cout << Screen::center ("Aucun vainqueur") << endl;
            break;
        case 1:
            cout << Screen::center ("Le Joueur n° 1 a gagné la partie n° ") << ++NbV << " !" << endl << endl;
            score.WriteScoreFile(1, NbV);
            break;
        case 2:
            cout << Screen::center ("Le Joueur n° 2 a gagné la partie n° ") << ++NbV << " !" << endl << endl;
            score.WriteScoreFile(2, NbV);
            break;
        }
        score.CloseScoreFile();
        for (const string & text : Screen::square (string (5, ' ') + "Voulez-faire la revanche ?" + string (5, ' ')))
            cout << Screen::center (text) << endl;
        for (const string & text : Screen::square ("1. Prendre sa revanche !"))
            cout << Screen::center (text) << endl;
        for (const string & text : Screen::square ("2. Fuir et abdiquer..."))
            cout << Screen::center (text) << endl;
        char choiceRe;
        cin >> choiceRe;
        switch (choiceRe) {
            case '1':
                Screen::Color (Screen::getColor("Reset"));
                Game::ppal (true);
                break;
            case '2':
                Screen::Color (Screen::getColor("Reset"));
                return 0;
            default:
                cout << "Ayer la sincérité de fuir avec classe en appuyant sur 2 ..." << endl;
                return 0;
        }
    }
} // ppal ()
