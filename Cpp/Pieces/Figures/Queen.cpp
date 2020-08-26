//
// Created by jakub on 09.08.2020.
//

#include "../../../Headers/Pieces/Figures/Queen.h"
#include "../../../Headers/Board/Board.h"
#include <iostream>

void Queen::isMoveValid(std::vector<std::vector<Piece *>> array, int x, int y) {
    std::cout << "1";
}


void Queen::print() {
    std::cout << "q ";
}

MoveUtil Queen::move(std::vector<std::vector<Square>> boardFields, int newX, int newY) {

    if (boardFields[newX][newY].hasPiece() || (newX + newY) % 2 == 0) {
        return {NONE};
    }

    int x0 = this->getX();
    int y0 = this->getY();
    bool isPieceOnWay = false;

    if (abs(newX - x0) == abs(newY - y0)) {
        Piece *piece = checkDiagonal(boardFields, x0, y0, newX, newY);

        if (piece != nullptr && piece->getColor() != boardFields[x0][y0].getPiece()->getColor()) isPieceOnWay = true; //&&
        std::cout << "ffffffffff " << isPieceOnWay << std::endl;
        if (isPieceOnWay) {
            return MoveUtil(KILL, piece);
        } else return {NORMAL};
    }


//    if (((newX - x0) * (int) (this->getColor())) > 0 && isPieceOnWay) {
//    }
//    else if (((newX - x0) * (int) (this->getColor())) > 0) {
//        return {NORMAL};
//    }
    else return {NONE};

}

Piece *Queen::checkDiagonal(std::vector<std::vector<Square>> boardFields, int oldX, int oldY, int newX, int newY) {
    if (newX - oldX > 0 && newY - oldY > 0) {
        for (int i = newX, j = newY; i > oldX && j < oldY; i--, j--) {
            if (boardFields[i][j].hasPiece()) {
                return boardFields[i][j].getPiece();
            }
        }



    } else {
        for (int i = newX, j = newY; i < oldX && j < oldY; i++, j++) {
            if (boardFields[i][j].hasPiece()) {
                return boardFields[i][j].getPiece();
            }
        }
    }
    return nullptr;
}
