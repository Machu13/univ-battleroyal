#include <iostream>
#include <string>
#include <fstream>
#include "score.h"

using namespace std;

Score::Score (const string & FileName)
{
    this->FileName = FileName;
}

int Score::ReadScoreFile ()
{
    scoreStream.open(this->FileName, ios_base::app);
    return scoreStream.is_open();
}

void Score::WriteScoreFile (const unsigned & PlayerNb, const unsigned & NbV)
{
    this->scoreStream
            << "=====================================================" << endl
            <<" Le Joueur n°" << PlayerNb
            << " a gagné la partie n° "<< NbV << "!" << endl
            << "=====================================================" << endl;
}

void Score::CloseScoreFile ()
{
    this->scoreStream.close();
}