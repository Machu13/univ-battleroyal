#ifndef IOUTILS_H
#define IOUTILS_H

#include <termios.h>

class IO
{
private:

    static void sig_handler (int signal);

public:

    static void reset_input_mode (void);

    static void set_input_mode (void);

    static void bloc_sig (void);

};

#endif // IOUTILS_H
