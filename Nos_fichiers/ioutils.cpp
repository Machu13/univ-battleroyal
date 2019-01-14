#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <signal.h>
#include <time.h>
#include "ioutils.h"

static struct termios saved_attributes;

void IO::reset_input_mode (void)
{
    tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
}

void IO::set_input_mode (void)
{
    struct termios tattr;

    /* Make sure stdin is a terminal. */
    if (!isatty (STDIN_FILENO))
    {
        fprintf (stderr, "Not a terminal.\n");
        exit (EXIT_FAILURE);
    }

    /* Save the terminal attributes so we can restore them later. */
    tcgetattr (STDIN_FILENO, &saved_attributes);
    atexit (reset_input_mode);

    /* Set the funny terminal modes. */
    tcgetattr (STDIN_FILENO, &tattr);
    tattr.c_lflag &= ~(ICANON|ECHO); /* Clear ICANON and ECHO. */
    tattr.c_cc[VMIN] = 1;
    tattr.c_cc[VTIME] = 0;
    tcsetattr (STDIN_FILENO, TCSAFLUSH, &tattr);
}

void IO::sig_handler (int signal)
{
    std::vector <std::string> errorMsg;
    errorMsg.push_back("Nan c'est rate ! Essaie encore :) Il en faudra plus pour nous faire planter");
    errorMsg.push_back("Opla on try des trucs bizarres BAH NON !");
    errorMsg.push_back("lol nope");
    errorMsg.push_back("Tia vu ? On est plus resistant qu'Allegro ! <3");
    srand (time (NULL));
    std::cout << errorMsg[rand() % errorMsg.size() - 1] << std::endl;
    exit (2);
}

void IO::bloc_sig ()
{
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = sig_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);
}
