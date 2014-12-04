#ifndef BOGGLEUTIL_H
#define BOGGLEUTIL_H

#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class BogVertex{
    public:
        /**
         * Constructer that creates a vertex in the boggle board graph.
         * Letters are set to string s, the position is set to pos, and visited
         * is set to false.
         */
        BogVertex(string s, int pos) : letters(s), position(pos), 
                                       visited(false) {}

        // Getters and setters for letters on the dice face
        string getLetters();
        void setLetters(string s);

        // Getters and setters for the position of the dice face in the graph
        int getPosition();
        void setPosition(int pos);

        // Getters and setters for the visited state of the vertex
        bool wasVisited();
        void setVisited(bool visited);
        
        // Getter for the adjcaceny vector
        vector<BogVertex*> getAdj();
        void setAdj(BogVertex* vert);
    private:
        // Adjaceny vector for the vertex
        vector<BogVertex*> adj;
        
        // Letters on the dice face, position of the dice face on the board, and
        // the visted state of the dice face
        string letters;
        int position;
        bool visited;

};

class BogGraph{
    public:
        /**
         * Constructs an empty graph to hold the boggle board values
         */
        BogGraph() {}

        /**
         * Adds a vertex to the graph at the position provided and with the
         * string of letters provided.
         */
        void addVertex(int pos, const string& ltrs);

        /**
         * Adds an edge to the graph between the two positions provided
         */
        void addEdge(int p1, int p2);

        // Getter and setters for number of columns
        int getCols();
        void setCols(int columns);

        // Getter for the boardMap
        map <int, BogVertex*> getMap();
    private:
        // Map containing the dice faces stored as BogVertices
        map <int, BogVertex*> boardMap;

        // Kepps track of the number of columns of the board
        int numCols;
};

class LST{

};
#endif
