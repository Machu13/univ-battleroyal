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
     * @brief opening score file stream
     * @fn std::ofstream scoreStream
     */
    std::ofstream scoreStream;

    /**
     * @brief path to the file
     * @fn std::string FileName
     */
    std::string FileName;

public:
    /**
     * @brief Constructor : display game score
     * @param [in] FileName : file name
     * @fn Score (const std::string & FileName)
     */
    Score (const std::string & FileName);

    /**
     * @brief open the score file stream
     * @return  int Score file
     * @fn int ReadScoreFile ()
     */
    int ReadScoreFile ();

    /**
     * @brief display player's score
     * @param [in] PlayerNb : value of player's number
     * @param [in] NbV : value of game number
     * @fn void WriteScoreFile (const unsigned & PlayerNb, const unsigned & NbV)
     */
    void WriteScoreFile (const unsigned & PlayerNb, const unsigned & NbV);

    /**
     * @brief close the file stream
     * @fn void CloseScoreFile ()
     */
    void CloseScoreFile ();

};

#endif // SCORE_H
