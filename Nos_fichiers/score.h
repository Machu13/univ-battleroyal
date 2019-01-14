#ifndef SCORE_H
#define SCORE_H

#include <iostream>
#include <string>
#include <fstream>

class Score
{
private:
    std::ofstream scoreStream;
    std::string FileName;
public:

    Score (const std::string & FileName);

    int ReadScoreFile ();

    void WriteScoreFile (const unsigned & PlayerNb, const unsigned & NbV);

    void CloseScoreFile ();

};

#endif // SCORE_H
