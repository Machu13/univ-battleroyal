#ifndef IOUTILS_H
#define IOUTILS_H
/*!
* @file ioutils.h
* @brief input/output utilities
* @author {Maxime Minguella, Arthur Petre, Mathias Meyer, Hugo Panis, Vincent Lavernhe}
* @version 1.0
* @date 14 janvier 2019
*/

/**
* @class IO ioutils.h
* @brief class input/output utilities
*/
class IO
{
private:
    /**
     * @brief sig_handler : display random sentences for MR CASALI
     * @param signal : linux sig signal
     * @fn static void sig_handler (int signal)
     */
    static void sig_handler (int signal);

public:
    /**
     * @brief reset_input_mode : reset canonic mode
     * @fn static void reset_input_mode (void)
     */
    static void reset_input_mode (void);

    /**
     * @brief set_input_mode : set canonic mode
     * @fn static void set_input_mode (void)
     */
    static void set_input_mode (void);

    /**
     * @brief bloc_sig : block killing signal
     * @fn static void bloc_sig (void)
     */
    static void bloc_sig (void);

};

#endif // IOUTILS_H
