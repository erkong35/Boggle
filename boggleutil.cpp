#include "boggleutil.h"

    // Getters and setters for letters on the dice face
    string BogVertex::getLetters(){
        return letters;
    }
    void BogVertex::setLetters(string s){
        letters = s;
    }

    // Getters and setters for the position of the dice face in the graph
    int BogVertex::getPosition(){
        return position;
    }
    void BogVertex::setPosition(int pos){
        position = pos;
    }

    // Getters and setters for the visited state of the vertex
    bool BogVertex::wasVisited(){
        return visited;
    }
    void BogVertex::setVisited(bool visited){
        this->visited = visited;
    }

    // Getter and setter for the adjacency vector
    vector<BogVertex*> BogVertex::getAdj(){
        return adj;
    }
    void BogVertex::setAdj(BogVertex* vert){
        adj.push_back(vert);
    }
    

    /**
     * Destructs a BogGraph
     */
    BogGraph::~BogGraph(){
        for(auto vert: boardMap){
            delete(vert.second);
            vert.second = nullptr;
        }
    }

    /**
     * Adds a vertex to the graph at the position provided and with the
     * string of letters provided.
     */
    void BogGraph::addVertex(int pos, const string& ltrs){
        BogVertex* node = new BogVertex(ltrs, pos);
        boardMap[pos] = node;
    }

    /**
     * Adds an edge to the graph between the two positions provided by adding
     * the vertices at the given positions to each other's adjaceny vector
     */
    void BogGraph::addEdge(int p1, int p2){
        // Gets the nodes related to the given positions and adds to their
        // adjaceny vector
        BogVertex* node1 = (boardMap.find(p1)->second);
        BogVertex* node2 = (boardMap.find(p2)->second);

        node1->setAdj(node2);
        node2->setAdj(node1);
    }

    // Getter and setters for number of columns
    int BogGraph::getCols(){
        return numCols;
    }
    void BogGraph::setCols(int columns){
        numCols = columns;
    }

    // Getter for the boardMap
    map <int, BogVertex*> BogGraph::getMap(){
        return boardMap;
    }
