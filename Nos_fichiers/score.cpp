#include <iostream>
#include <string>
#include <fstream>
#include "score.h"

using namespace std;

Score::Score (const string & FileName)
{
    this->FileName = FileName;
} // Score::Score ()

int Score::ReadScoreFile ()
{
    scoreStream.open(this->FileName, ios_base::app);
    return scoreStream.is_open();
} // Score::ReadScoreFile ()

void Score::WriteScoreFile (const unsigned & PlayerNb, const unsigned & NbV)
{
    if (0 == PlayerNb)
        this->scoreStream
                << string (40, '=') << endl
                << " Aucun joueur n'a gagné la partie n° " << NbV << "!" << endl
                << string (40, '=') << endl;
    else
        this->scoreStream
                << string (40, '=') << endl
                << " Le joueur n°" << PlayerNb
                << " a gagné la partie n° " << NbV << "!" << endl
                << string (40, '=') << endl;
} // Score::WriteScoreFile ()

void Score::CloseScoreFile ()
{
    this->scoreStream.close();
} // Score::CloseScoreFile ()
