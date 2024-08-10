#ifndef __BOARD_H__
#define __BOARD_H__
#include "Grid.h"

class Board
{
private:
    unsigned int height, width;
    unsigned int mineNum;
    Grid **gridMatrix;
    int **mineInfo;    
public:
    Board(int h, int w, int n) : height(h), width(w), mineNum(n) {
        if (h < 1 || w < 1) throw Error(403, "Invalid size of board");
        if (n < 1 || n >= h*w) throw Error(404, "Invalid mineNum");
        gridMatrix = new Grid*[height];
        mineInfo = new int*[height];
        for (int i = 0; i < height; i++)
        {
            gridMatrix[i] = new Grid[width];
            mineInfo[i] = new int[width]{0};
        }
    }

    ~Board() {
        for (int i = 0; i < height; i++)
        {
            delete[] gridMatrix[i];
            delete[] mineInfo[i];
        }
        delete[] gridMatrix;
        delete[] mineInfo;
    }
};

#endif