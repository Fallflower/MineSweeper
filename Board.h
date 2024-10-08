#ifndef __BOARD_H__
#define __BOARD_H__
#include "Grid.h"
#include <algorithm>
#include <random>

class Board
{
private:
    unsigned int height, width;
    unsigned int mineNum;
    Grid **gridMatrix;

    inline void check_mine_info(const int& hi, const int& wi) {
        if (gridMatrix[hi][wi].isMine()) return;
        int sum = 0;
        for (int i = -1; i < 2; i++)
        {
            int nhi = hi + i;
            if (nhi < 0 || nhi >= height)
                continue;
            for (int j = -1; j < 2; j++)
            {
                int nwi = wi + j;
                if (nwi < 0 || nwi >= width)
                    continue;
                if (gridMatrix[nhi][nwi].isMine())
                    sum++;
            }
        }
        gridMatrix[hi][wi].setMine(sum);
    }

    inline int f(const int& hi, const int& wi) {
        return (hi + 1) * width + wi;
    }
public:
    Board(int h, int w, int n) : height(h), width(w), mineNum(n) {
        if (h < 1 || w < 1) throw Error(403, "Invalid size of board");
        if (n < 1 || n >= h*w) throw Error(404, "Invalid mineNum");
        gridMatrix = new Grid*[height];
        for (int i = 0; i < height; i++)
            gridMatrix[i] = new Grid[width];
    }

    ~Board() {
        for (int i = 0; i < height; i++)
        {
            delete[] gridMatrix[i];
        }
        delete[] gridMatrix;
    }

    int getMineNum() const { return mineNum; }
    int getNowMineNum() const {
        int sum = 0;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                if (gridMatrix[i][j].isMine()) sum++;
            }
        return sum;
    }

    void init_after_first_click(const int& hi, const int& wi) {
        std::random_device rd;
        std::mt19937 rng(rd());

        int *iarr = new int[height*width];
        for (int i = 0; i < height*width; i++)
            iarr[i] = i;
        
        int iarri = f(hi, wi);
        
        std::shuffle(iarr, iarr + height*width, rng);
        int mN = mineNum;
        for (int i = 0; i < mN; i++) {
            if (i == iarri) {
                mN++;
                continue;
            }
            int mhi = iarr[i] / width;
            int mwi = iarr[i] % width;
            gridMatrix[mhi][mwi].setMine(-1);
        }
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                check_mine_info(i, j);

        delete[] iarr;
    }

    ostream& output(ostream& out) const {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++) {
                if (gridMatrix[i][j].isMine()) {
                    out << "*";
                } else {
                    out << gridMatrix[i][j];
                }
            }
            out << endl;
        }
        return out;
    }
};

ostream& operator<<(ostream& out, const Board& b) {
    b.output(out);
    return out;
}

#endif