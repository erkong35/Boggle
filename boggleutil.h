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
        /**
         * Constructs an LSTNo  de that holds the characters a-z.  Initially
         * sets all values of children to null pointers.
         */
        LSTNode(){
            for(char c = 'a'; c <='z'; c++){
                children[c] = nullptr;
            }
            for(char c = 'a'; c <='z'; c++){
                fullWords[c] = false;
            }
        }

        // Getter and setter for children of a LSTNode
        unordered_map<char, LSTNode*> getChildren();
        void setChildren(char c, LSTNode* child);

        // Getter and setter for the boolean that checks for end of a word
        bool isEndWord(char c);
        void setEndWord(char c); 

        // Returns true if the word is not a prefix for anymore words
        bool noMoreWords();

        // Getters and Setters for the position of the word
        int getPos();
        void setPos(unsigned int i);

    private:
        // Unordered map of the children of this node
        unordered_map<char, LSTNode*> children;

        // True if this node is the end of a word
        unordered_map<char, bool> fullWords;

        unsigned int position;
};

class LST{
    public:
        /**
         * Constructs a LST with one root node.  This node is added to the
         * map that holds all the nodes.
         */
        LST(){
            root = new LSTNode();
            allNodes[pos] = root;
            pos = pos + 1;
        }

        /**
         * Adds a child to the specified parent node at the specified 
         * character c.  Also adds to the map of all nodes in the tree.
         */
        void addChild(LSTNode* parent, char c);

        // Getter for the root of the tree
        LSTNode* getRoot();

        // Getter for all the nodes in the tree
        unordered_map<int, LSTNode*> getAllNodes();

        // Checks if string is prefix
        bool isPrefix(string pref);
    private:
        // Map containing all the nodes in the tree
        unordered_map<int, LSTNode*> allNodes;

        // Root of the tree
        LSTNode* root;

        // Holds current position for the map
        unsigned int pos = 0;
};
#endif
