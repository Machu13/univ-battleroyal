#ifndef GAME_H
#define GAME_H

#include "config.h"
#include "type.h"

class Game
{
public:

    static void MoveToken (CMatrix & Mat, char Move, CPosition & Pos, Config & config);

    static int ppal(const bool & SkipMenu = false);

};

#endif // GAME_H
