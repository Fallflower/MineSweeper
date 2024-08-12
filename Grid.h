#ifndef __GRID_H__
#define __GRID_H__

#include "Assistance.h"
enum NoteType {_UNSIGNED, _SIGNED, _SKEPTICAL};

class Board;

class Grid
{
private:
    NoteType note;
    bool sweeped;
    int mine;

public:
    Grid():note(_UNSIGNED), sweeped(0), mine(0) {}

    bool isMine() const { return mine == -1; }

    void setMine(const int& mInfo) { mine = mInfo; } 

    void BLC() {    // be left clicked
        if (!sweeped) sweeped = 1;
    }

    void BRC() {    // be right clicked
        if (!sweeped)
            note = NoteType((int(note) + 1)%3);
    }

    ostream& output(ostream& out) const {
        if (sweeped) {
            out << mine;
        }
        else
            switch (note)
            {
            case _UNSIGNED:
                out << " ";
                break;
            case _SIGNED:
                out << "~";
                break;
            case _SKEPTICAL:
                out << "?";
                break;
            }
        return out;
    }

    // friend class Board;
};

ostream& operator<<(ostream& out, const Grid& g) {
    g.output(out);
    return out;
}

#endif