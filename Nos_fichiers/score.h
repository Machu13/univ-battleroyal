#ifndef SCORE_H
#define SCORE_H
/*!
* @file score.h
* @brief Definition of the score of the game
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

#include <iostream>
#include <string>
#include <fstream>

/**
* @class Score score.h
* @brief class containing score display parameters
*/
class Score
{
private:
    /**
     * @brief scoreStream
     */
    std::ofstream scoreStream;

    /**
     * @brief FileName
     */
    std::string FileName;

public:
    /**
     * @brief Score
     * @param FileName
     */
    Score (const std::string & FileName);

    /**
     * @brief ReadScoreFile
     * @return
     */
    int ReadScoreFile ();

    /**
     * @brief WriteScoreFile
     * @param PlayerNb
     * @param NbV
     */
    void WriteScoreFile (const unsigned & PlayerNb, const unsigned & NbV);

    /**
     * @brief CloseScoreFile
     */
    void CloseScoreFile ();

};

#endif // SCORE_H
