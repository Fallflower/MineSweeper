#ifndef __GRID_H__
#define __GRID_H__

#include "Assistance.h"
enum NoteType{_UNSIGNED, _SIGNED, _SKEPTICAL};

class Grid
{
private:
    NoteType note;
    bool mined;

public:
    Grid() {}
    Grid(bool mine):note(_UNSIGNED), mined(mine) {}

    void noting() {
        note = NoteType((int(note) + 1)%3);
    }
};

#endif