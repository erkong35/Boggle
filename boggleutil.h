#ifndef BOGGLEUTIL_H
#define BOGGLEUTIL_H

#include <map>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>

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
        
        // Getter and setter for the adjcaceny vector
        vector<BogVertex*> getAdj();
        void setAdj(BogVertex* vert);

        // Getter and setter for the revisit boolean
        bool wasRevisited();
        void setRevisited(bool revisited);
    private:
        // Adjaceny vector for the vertex
        vector<BogVertex*> adj;
        
        // Letters on the dice face, position of the dice face on the board, and
        // the visted state of the dice face
        string letters;
        int position;
        bool visited;
        bool revisit;

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

class LSTNode{
    public:
        LSTNode(){
            for(char c = 'a'; c <='z'; c++){
                children[c] = nullptr;
            }
        }
        unordered_map<char, LSTNode*> getChildren();
        void setChildren(char c, LSTNode* child);
        bool isEndWord();
        void setEndWord(); 
    private:
        unordered_map<char, LSTNode*> children;
        bool isEnd;
};

class LST{
    public:
        LST(){
            root = new LSTNode();
            allNodes[pos] = root;
            pos = pos + 1;
        }
        void addChild(LSTNode* parent, char c);
        LSTNode* getRoot();
        unordered_map<int, LSTNode*> getAllNodes();
    private:
        unordered_map<int, LSTNode*> allNodes;
        LSTNode* root;
        unsigned int pos = 0;
};
#endif
