//
//  Cell.h
//  mySketch_CA
//
//  Created by SuguruSasaki on 2014/05/28.
//
//

#ifndef __mySketch_CA__Cell__
#define __mySketch_CA__Cell__

#include <iostream>
#include <vector>
#include "ofMain.h"

class Cell
{
public:
    
    // COnstractor
    Cell(float px, float py, float state);
    
    // destractor
    ~Cell();
    
    // 描画
    void draw();
    
    // 次の状態を計算する
    void calcNextState();
    
    // 隣接するCellを設定
    void addNeighbor(Cell *c_ptr);
    
    float state;
    
private:
    float x;
    float y;
    
    
    float nextState;
    float lastState;
    
    std::vector<Cell*> neighbors;
};


#endif /* defined(__mySketch_CA__Cell__) */
