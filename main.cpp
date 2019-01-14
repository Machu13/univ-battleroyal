#include <iostream>
#include "Nos_fichiers/game.h"

using namespace std;

int main ()
{
    try {
        return Game::ppal ();
    } catch (...) {
        cerr << "C'est dommage ca ne marche pas :/" << endl;
        return 1;
    }
} // main ()
