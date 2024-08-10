#include "Board.h"
using namespace std;


int main() {
    Board board(5, 12, 17);
    board.init_after_first_click(3, 6);

    cout << board << endl;
    cout << board.getNowMineNum() << endl;

    return 0;
}