#ifndef __GRID_H__
#define __GRID_H__

#include "Assistance.h"
enum NoteType{_UNSIGNED, _SIGNED, _SKEPTICAL};

class Grid
{
private:
    NoteType note;

public:
    Grid():note(_UNSIGNED) {}

    void noting() {
        note = NoteType((int(note) + 1)%3);
    }
};

#endif