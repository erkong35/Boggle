#include "boggleplayer.h"

    /**
     * Destructs the object after game is over
     */
    BogglePlayer::~BogglePlayer(){
        for(auto vert: boardGraph.getMap()){
            delete(vert.second);
            vert.second = nullptr;
        }
    }

    /**
     * Build the lexicon using a given set of words. Sets the boolean for
     * lexicon created to true.
     */
    void BogglePlayer::buildLexicon(const set<string>& word_list){
        LSTNode* parent;
        for(string s : word_list){
            parent = lexTree.getRoot();
            for(char c : s){
                if(parent->getChildren()[c] == nullptr){
                    lexTree.addChild(parent, c);
                }
                parent = parent->getChildren()[c];
            }
            parent->setEndWord();
        }
        lexIsSet = true;
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
        // string being added to the board
        string toAdd;
        // Adds dice to the BogGraph using the strings from diceArray
        for(unsigned int r = 0; r < rows; r++){
            for(unsigned int c = 0; c < cols; c++){
                // Sets everything to lowercase before adding
                toAdd = diceArray[r][c];
                transform(toAdd.begin(), toAdd.end(), toAdd.begin(), ::tolower);
                boardGraph.addVertex(r * cols + c, toAdd);
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
            if(!lexIsSet || !boardIsSet){
                return false;
            }
            
            return true;
        }

        /**
         * Returns true if the given word is in the lexicon, false if it is
         * not or if buildLexicon() was not called yet.
         */
        bool BogglePlayer::isInLexicon(const string& word_to_check){
            if(!lexIsSet){
                return false;
            }

            LSTNode* curr  = lexTree.getRoot();
            for(char c : word_to_check){
                if(curr->getChildren()[c] == nullptr){
                    return false;
                }
                else {
                    curr = curr->getChildren()[c];
                }
            } 
            return true;
        }

        /**
         * If the string passed in is not on the board or if setBoard() was not
         * called, returns an empty vector.  Otherwise, finds the path to build
         * the word and returns a vector containing integer locations for each
         * dice face.  Location integer: R * COLS + C
         */
        vector<int> BogglePlayer::isOnBoard(const string& word_to_check){

            // Empty vector
            vector<int> empty;
            // Vector to store locations
            vector<int> locations;
            if(!boardIsSet){
                return locations;
            }

            // String that holds the word_to_check
            string tmpWord = word_to_check; 
            transform(tmpWord.begin(), tmpWord.end(), tmpWord.begin(), ::tolower);

            // boolean keeping track of valid word being built
            bool valid = false;

            // string taken from dice face to compare to the word given
            string compareStr;

            // position to keep track of the current vertice on the board
    //        int vertPosition = 0;

            // Checks if any of the dice can be the first letter/letters of the
            // word and pushes that dice to locations
            for(auto let : boardGraph.getMap()){
                compareStr = let.second->getLetters();
            if(tmpWord.substr(0, compareStr.size()) == compareStr){
                valid = true;
                locations.push_back(let.first);
        //        vertPosition = let.first; 
                let.second->setVisited(true);
                break;
            }
        }

        // If the prefix for the word is not valid or if the word size is equal
        // to one of the dice face word sizes, return locations
        if(!valid || tmpWord.size() == compareStr.size()){
            return locations;
        }

        // Cuts off the first part that was already found
        tmpWord = tmpWord.substr(compareStr.size());

        // Vertex to keep track of the board traversal
//        BogVertex* vert = boardGraph.getMap()[vertPosition];

        // int to keep track of position in the string
        unsigned int pos = 0;

        // Stack to do search through
        stack<BogVertex*> vertStack;

        for(auto vert : boardGraph.getMap()){
            vertStack.push(vert.second);
        }

        // Vertex that keeps track of current vertice
        BogVertex* vert;

        while(!vertStack.empty()){
            vert = vertStack.top();
            vertStack.pop();
            compareStr = vert->getLetters();
            if(vert->wasRevisited()){
                locations.pop_back();
                vert->setRevisited(false);
                vert->setVisited(false);
                pos = pos - 1;
            }
            else if(!vert->wasVisited() && 
                    vert->getLetters() == 
                    tmpWord.substr(pos, compareStr.size())){
                vert->setVisited(true);
                pos = pos + 1;
                valid = true;
                locations.push_back(vert->getPosition());
                // If the sizes are the same, this means the word
                // is found and completed
                if(pos == tmpWord.size()){
                    break;
                }
                vert->setRevisited(true);
                vertStack.push(vert);
                for(BogVertex* adjVert : vert->getAdj()){
                    if(!adjVert->wasVisited()){
                        vertStack.push(adjVert);
                    }
                }
            }
            else {
                valid = false;
            }
        }

            

        // Loops through adjacent vertices until word is built or word is 
        // found to not exist on the board
/*        while(valid && !done){
            for(BogVertex* adjVert : vert->getAdj()){
                if(adjVert->wasRevisited()){
                    cout << " CHANGE" << endl;
                    adjVert->setRevisited(false);
                    adjVert->setVisited(false);
                    pos = pos - 1;
                }
                if(adjVert->wasVisited()){
                    continue;
                }
                compareStr = adjVert->getLetters();
                if(tmpWord.substr(pos, compareStr.size() + pos) == compareStr){
                    pos = pos + 1;
                    locations.push_back(adjVert->getPosition());
                    valid = true;
                    // If the sizes are the same, this means the word
                    // is found and completed
                    if(pos == tmpWord.size()){
                        done = true;
                        break;
                    }
                    adjVert->setVisited(true);
                    adjVert->setRevisited(true);
                    vert = adjVert;
                    break;
                }
                else
                {
                    valid = false;
                }
            }
        }*/

        // Reset vertices to not visited for next call to isOnBoard
        for(auto vert : boardGraph.getMap()){
            vert.second->setVisited(false);
            vert.second->setRevisited(false);
        }

        if(!valid) return empty;
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

