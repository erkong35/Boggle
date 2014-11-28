#include "boggleplayer.h"

    /**
     * Destructs the object after game is over
     */
    BogglePlayer::~BogglePlayer(){
    }

    /**
     * Build the lexicon using a given set of words. Sets the boolean for
     * lexicon created to true.
     */
    void BogglePlayer::buildLexicon(const set<string>& word_list){
        return;
    }

    /**
     * Takes in the number of rows and columns for the board and an array
     * of the dice faces.  Creates the board to have the corresponding 
     * number of rows and cols and sets the graph containing the dice
     * faces. Dice face strings are set to lowercase.  Sets the boolean 
     * for board created to true.
     */
    void BogglePlayer::setBoard(unsigned int rows, unsigned int cols, 
                                string** diceArray){

        boardGraph.setCols(cols);
        
        // Adds dice to the BogGraph using the strings from diceArray
        for(unsigned int r = 0; r < rows; r++){
            for(unsigned int c = 0; c < cols; c++){
                boardGraph.addVertex(r * cols + c, diceArray[r][c]);
            }
        }

        // Creates Adj vector for each of the vertices
        for(unsigned int r = 0; r < rows; r++){
            for(unsigned int c = 0; c < cols; c++){
                // Adds vertice one to the right
                if(c < cols - 1){
                    boardGraph.addEdge(r * cols + c, r * cols + (c + 1));
                }
                // Adds vertice one to the left
                if(r < rows - 1){
                    boardGraph.addEdge(r * cols + c, (r + 1) * cols + c);
                }
                // Adds vertice diagonally in the southwest direction
                if(c > 0 && r < rows - 1){
                    boardGraph.addEdge(r * cols + c, (r + 1) * cols + (c - 1));
                }
                // Adds vertice diagonally in the southeast direction
                if(c < cols - 1 && r < rows - 1){
                    boardGraph.addEdge(r * cols + c, (r + 1) * cols + (c + 1));
                }
            }
        }
        boardIsSet = true;
    }

    /**
     * Returns false if setBoard() or buildLexicon() has not been called;
     * else return true.  Fills up the set "words" with all words that
     * are of at least the minimum length, are in the lexicon, and can be
     * found using an acylic path on the board.
     */ 
    bool BogglePlayer::getAllValidWords(unsigned int minimum_word_length, 
                          set<string>* words){
        return false;
    }

    /**
     * Returns true if the given word is in the lexicon, false if it is
     * not or if buildLexicon() was not called yet.
     */
    bool BogglePlayer::isInLexicon(const string& word_to_check){
        return false;
    }

    /**
     * If the string passed in is not on the board or if setBoard() was not
     * called, returns an empty vector.  Otherwise, finds the path to build
     * the word and returns a vector containing integer locations for each
     * dice face.  Location integer: R * COLS + C
     */
    vector<int> BogglePlayer::isOnBoard(const string& word_to_check){
        vector<int> locations;
        if(boardIsSet == false){
            return locations;
        }
        return locations;
    }

    /**
     * Creates a custom board for testing.
     */
    void BogglePlayer::getCustomBoard(string** &new_board, unsigned int *rows, 
                        unsigned int *cols){
        return;
    }

    // Getter for the board graph
    BogGraph BogglePlayer::getBoard(){
        return boardGraph;
    }

