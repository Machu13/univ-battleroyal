#ifndef IOUTILS_H
#define IOUTILS_H
/*!
* @file ioutils.h
* @brief DEFINITION A FAIRE
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

/**
* @class IO ioutils.h
* @brief class CLASS AUSSI A FAIRE
*/
class IO
{
private:
    /**
     * @brief sig_handler
     * @param signal
     */
    static void sig_handler (int signal);

public:
    /**
     * @brief reset_input_mode
     */
    static void reset_input_mode (void);

    /**
     * @brief set_input_mode
     */
    static void set_input_mode (void);

    /**
     * @brief bloc_sig
     */
    static void bloc_sig (void);

};

#endif // IOUTILS_H
