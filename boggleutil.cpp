#include "boggleutil.h"

    // Getters and setters for letters on the dice face
    string BogVertex::getLetters(){
        return "";
    }
    void BogVertex::setLetters(string s){
        return;
    }

    // Getters and setters for the position of the dice face in the graph
    int BogVertex::getPosition(){
        return 0;
    }
    void BogVertex::setPosition(int pos){
        return;
    }

    // Getters and setters for the visited state of the vertex
    bool BogVertex::wasVisited(){
        return false;
    }
    void BogVertex::setVisited(bool visited){
        return;
    }

    /**
     * Destructs a BogGraph
     */
    BogGraph::~BogGraph(){
    }

    /**
     * Adds a vertex to the graph at the position provided and with the
     * string of letters provided.
     */
    void BogGraph::addVertex(int pos, const string& ltrs){
        return;
    }

    /**
     * Adds an edge to the graph between the two positions provided
     */
    void BogGraph::addEdge(int p1, int p2){
        return;
    }
