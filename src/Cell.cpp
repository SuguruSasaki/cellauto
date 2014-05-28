//
//  Cell.cpp
//  mySketch_CA
//
//  Created by SuguruSasaki on 2014/05/28.
//
//

#include "Cell.h"


// Constractor
//
//
Cell::Cell(float px, float py, float state)
{
    x = px;
    y = py;
    
    nextState = state;
    this->state = nextState;
}

// destractor
//
//
Cell::~Cell()
{
    
}

// addNeighbor : 隣接するセルを登録
//
//
void Cell::addNeighbor(Cell *c_ptr)
{
    neighbors.push_back(c_ptr);
    
   
}

// calcNextState : 次の状態を計算する
//
//
void Cell::calcNextState()
{
    float total = 0;
    
    for( int i = 0; i < neighbors.size(); ++i)
    {
        total += neighbors[i]->state;
    }
    
    float average = total / 8;
    
    if( average == 255 )
    {
        nextState = 0;
    }
    else if( average == 0)
    {
        nextState = 255;
    }
    else
    {
        nextState = state + average;
        if( lastState > 0 ) nextState -= lastState;
        if( nextState > 255) nextState = 255;
        else if (nextState < 0) nextState = 0;
    }
    
    lastState = state;
}

// draw : 画面に描画
//
//
void Cell::draw()
{
    state = nextState;
    
    ofSetColor(state);
    ofRect(x, y, 10, 10);
}










