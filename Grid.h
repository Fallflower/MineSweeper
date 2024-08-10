#ifndef __GRID_H__
#define __GRID_H__

#include "Assistance.h"
enum NoteType{_SIGNED, _UNSIGNED, _SKEPTICAL};

class Grid
{
private:
    NoteType note;
    bool mined;

public:
    Grid():note(_UNSIGNED), mined(0) {}
    Grid(bool mine):note(_UNSIGNED), mined(mine) {}

    bool noting() {
        note = NoteType((int(note) + 1)%3);
    }
};

#endif