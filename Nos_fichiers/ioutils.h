#ifndef IOUTILS_H
#define IOUTILS_H

#include <termios.h>

class IO
{
public:

    static void reset_input_mode (void);

    static void set_input_mode (void);

};

#endif // IOUTILS_H
