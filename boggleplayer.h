#ifndef BOGGLEPLAYER_H
#define BOGGLEPLAYER_H

#include "boggleutil.h"
#include "baseboggleplayer.h"

#include <stack>

using namespace std;

class BogglePlayer : public BaseBogglePlayer{
    public:
        /**
         * Creates player for the game.  Board and lexicon are not yet built,
         * so their corresponding booleans are set to false.
         */
        BogglePlayer():boardIsSet(false), lexIsSet(false){}

        /**
         * Destructs the object after game is over
         */
        ~BogglePlayer();

        /**
         * Build the lexicon using a given set of words. Sets the boolean for
         * lexicon created to true.
         */
        void buildLexicon(const set<string>& word_list);

        /**
         * Takes in the number of rows and columns for the board and an array
         * of the dice faces.  Creates the board to have the corresponding 
         * number of rows and cols and sets the graph containing the dice
         * faces. Dice face strings are set to lowercase.  Sets the boolean 
         * for board created to true.
         */
        void setBoard(unsigned int rows, unsigned int cols, string** diceArray);

        /**
         * Returns false if setBoard() or buildLexicon() has not been called;
         * else return true.  Fills up the set "words" with all words that
         * are of at least the minimum length, are in the lexicon, and can be
         * found using an acylic path on the board.
         */ 
        bool getAllValidWords(unsigned int minimum_word_length, 
                              set<string>* words);

        /**
         * Recursively gets all the words on the board that start with the 
         * string prefix passed in.  Adds words that are greter than or 
         * equal to the minimum_word_length to the set words.
         */
        void getWords(BogVertex* currVert, string prefix, 
                      unsigned int minimum_word_length, set<string>* words);

        /**
         * Returns true if the given word is in the lexicon, false if it is
         * not or if buildLexicon() was not called yet.
         */
        bool isInLexicon(const string& word_to_check);

        /**
         * If the string passed in is not on the board or if setBoard() was not
         * called, returns an empty vector.  Otherwise, finds the path to build
         * the word and returns a vector containing integer locations for each
         * dice face.  Location integer: R * Width + C
         */
        vector<int> isOnBoard(const string& word_to_check);

        /**
         * Creates a custom board for testing.
         */
        void getCustomBoard(string** &new_board, unsigned int *rows, 
                            unsigned int *cols);

        // Getter for the board graph
        BogGraph* getBoard();

        // Getter for the Lexicon trie
        LST* getLex();

    private:
        // Booleans to check if setBoard() and buildLexicon() were called
        bool boardIsSet;
        bool lexIsSet;

        // Graph for the board
        BogGraph* boardGraph = new BogGraph();

        // Lexicon search tree for the lexicon
        LST* lexTree = new LST();
};

#endif 
