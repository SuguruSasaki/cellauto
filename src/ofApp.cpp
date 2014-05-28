#include "ofApp.h"


ofApp::~ofApp()
{
    std::cout << "destractor" << std::endl;
    
    for(int x = 0; x < numX; ++x)
    {
        for( int y = 0; y < numY; ++y)
        {
            delete cellArray[x][y];
        }
    }
}


//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundAuto(180);
    ofSetFrameRate(60);
    
    numX = (int)ofGetWidth() / CELL_SIZE;
    numY = (int)ofGetHeight() / CELL_SIZE;
   
    // set vector size
    cellArray.resize(numX);
    
    // create instance of Cell
    for( int x = 0; x < numX; ++x)
    {
        for( int y = 0; y < numY; ++y)
        {
            float px = x * CELL_SIZE;
            float py = y * CELL_SIZE;
            float state = ( (px/500.0f) + (py/300.0f) * 14.0f );
            Cell* c_ptr = new Cell(px, py, state);
            cellArray[x].push_back(c_ptr);
        }
    }
    
    restart();
}

//--------------------------------------------------------------
void ofApp::restart()
{
    // リセット処理
    for( int x = 0; x < numX; ++x)
    {
        for( int y = 0; y < numY; ++y)
        {
            float px = x * CELL_SIZE;
            float py = y * CELL_SIZE;
            float state = ( (px/500.0f) + (py/300.0f) * 14.0f );
            cellArray[x][y]->state = state;
        }
    }
    
    
    for( int x = 0; x < numX; ++x)
    {
        for( int y = 0; y < numY; ++y)
        {
            int above = y - 1;
            int below = y + 1;
            int left  = x - 1;
            int right = x + 1;
            
            if( above < 0 ) above = numY - 1;
            if( below == numY) below = 0;
            if( left < 0 ) left = numX - 1;
            if( right == numX ) right = 0;
            
            cellArray[x][y]->addNeighbor( cellArray[left][above] );
            cellArray[x][y]->addNeighbor( cellArray[left][y] );
            cellArray[x][y]->addNeighbor( cellArray[left][below] );
            cellArray[x][y]->addNeighbor( cellArray[x][below] );
            cellArray[x][y]->addNeighbor( cellArray[right][below] );
            cellArray[x][y]->addNeighbor( cellArray[right][y] );
            cellArray[x][y]->addNeighbor( cellArray[right][above] );
            cellArray[x][y]->addNeighbor( cellArray[x][above] );
        }
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for( int x = 0; x < numX; ++x )
    {
        for( int y = 0; y < numY; ++y )
        {
            cellArray[x][y]->calcNextState();
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw()
{
    for( int x = 0; x < numX; ++x)
    {
        for( int y = 0; y < numY; ++y)
        {
            cellArray[x][y]->draw();
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    restart();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
