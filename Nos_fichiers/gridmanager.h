#ifndef GRIDMANAGER_H
#define GRIDMANAGER_H

#include "config.h"
#include "type.h"

class Grid
{
private:

    static void BombsGenerator (CMatrix & Mat, Config & Params);

    static void SpeedLootsGenerator (CMatrix & Mat, Config & Params);

public:

    static void InitGrid (CMatrix & Mat, unsigned Size, CPosition & PosPlayer1, CPosition & PosPlayer2, Config & Params);

    static void DisplayGrid (const CMatrix & Mat, Config & Params, const unsigned Border);

};

#endif // GRIDMANAGER_H
