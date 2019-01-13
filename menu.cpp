#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include "type.h"
#include "config.h"
#include "screen.h"

using namespace std;

void MainMenu ()
{
    cout << endl << Screen::center (string (15, '-')) << endl;
    cout << Screen::center (string (5, '-') + string (5, ' ') +" Menu " + string (5, ' ') + string (5, '-')) << endl;
    cout << Screen::center (string (15, '-')) << endl << endl;
    cout << Screen::center ("1. Jouer") << endl;
    cout << Screen::center ("2. Paramètres de jeu") << endl;
    cout << Screen::center ("3. Crédits") << endl;
    cout << Screen::center ("4. Faire un bronx") << endl;
    cout << Screen::center ("5. Quitter") << endl;
}

struct termios saved_attributes;

void reset_input_mode (void)
{
  tcsetattr (STDIN_FILENO, TCSANOW, &saved_attributes);
}

void set_input_mode (void)
{
  struct termios tattr;
  char *name;

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

