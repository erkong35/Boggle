#include "boggleplayer.h"

    /**
     * Destructs the object after game is over
     */
    BogglePlayer::~BogglePlayer(){
        for(auto node : lexTree->getAllNodes()){
            delete(node.second);
            node.second = nullptr;
        }
        delete(lexTree);
        for(auto vert : boardGraph->getMap()){
            delete(vert.second);
            vert.second = nullptr;
        }
        delete(boardGraph);
    }

    /**
     * Build the lexicon using a given set of words. Sets the boolean for
     * lexicon created to true.
     */
    void BogglePlayer::buildLexicon(const set<string>& word_list){
        if(lexIsSet){
            for(auto node : lexTree->getAllNodes()){
                delete(node.second);
                node.second = nullptr;
            }
            lexTree = new LST();
        }

        LSTNode* parent;
        char last;
        // Creates new children for each character in string 
        for(string s : word_list){
            parent = lexTree->getRoot();
            for(string::size_type i = 0; i < s.size(); i++){
                // Adds child at character if child not already there
                last = s[i];
                if(parent->getChildren()[s[i]] == nullptr){
                    lexTree->addChild(parent, s[i]);
                }
                if(i < s.size() - 1){
                    parent = parent->getChildren()[s[i]];
                }
            }
            parent->setEndWord(last);
            // End of the string is a word, so set the last node's boolean to 
            // mark end of word
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
        if(boardIsSet){
            for(auto vert : boardGraph->getMap()){
                delete(vert.second);
                vert.second = nullptr;
            }
            boardGraph = new BogGraph();
        }

        boardGraph->setCols(cols);
        // string being added to the board
        string toAdd;
        // Adds dice to the BogGraph using the strings from diceArray
        for(unsigned int r = 0; r < rows; r++){
            for(unsigned int c = 0; c < cols; c++){
                // Sets everything to lowercase before adding
                toAdd = diceArray[r][c];
                transform(toAdd.begin(), toAdd.end(), toAdd.begin(), ::tolower);
                boardGraph->addVertex(r * cols + c, toAdd);
            }
        }

        // Creates Adj vector for each of the vertices
        for(unsigned int r = 0; r < rows; r++){
            for(unsigned int c = 0; c < cols; c++){
                // Adds vertice one to the right
                if(c < cols - 1){
                    boardGraph->addEdge(r * cols + c, r * cols + (c + 1));
                }
                // Adds vertice one to the left
                if(r < rows - 1){
                    boardGraph->addEdge(r * cols + c, (r + 1) * cols + c);
                }
                // Adds vertice diagonally in the southwest direction
                if(c > 0 && r < rows - 1){
                    boardGraph->addEdge(r * cols + c, (r + 1) * cols + (c - 1));
                }
                // Adds vertice diagonally in the southeast direction
                if(c < cols - 1 && r < rows - 1){
                    boardGraph->addEdge(r * cols + c, (r + 1) * cols + (c + 1));
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

        for(auto vert : boardGraph->getMap()){
            vert.second->setVisited(false);
        }

        time_t start = time(0);
        // Keep track of current node
        LSTNode* curr;
        char last;
        for(auto vert : boardGraph->getMap()){
            curr = lexTree->getRoot();

            // If the word on the dice face is not a prefix, go to next die
            if(!lexTree->isPrefix(vert.second->getLetters())){
                continue;
            } 

            // Go down the tree to the correct node
            for(string::size_type i = 0; 
                i < vert.second->getLetters().size(); i++){
                if(i < vert.second->getLetters().size() - 1){
                    curr = curr->getChildren()[vert.second->getLetters()[i]];
                }
                last = vert.second->getLetters()[i];
            }

            // No more possible words can be formed from this 
            if(curr->noMoreWords() && curr->isEndWord(last)){
                if(vert.second->getLetters().size() >= minimum_word_length){
                    words->insert(vert.second->getLetters());
                }
                continue;
            }
            else {
                vert.second->setVisited(true);
                if(curr != 0 && curr->isEndWord(last) &&
                   vert.second->getLetters().size() >= minimum_word_length){
                    words->insert(vert.second->getLetters());
                }
                getWords(vert.second, vert.second->getLetters(), curr->getPos(),
                         minimum_word_length, words);
                vert.second->setVisited(false);
            }
        }
        cout << "TIME: " << difftime(time(0), start) << endl;
        
        return true;
    }

    void BogglePlayer::getWords(BogVertex* currVert, string prefix, 
                                unsigned int position,
                                unsigned int minimum_word_length,
                                set<string>* words){ 

        // Holds original prefix
        string origPref = prefix;

        // Vertex to keep track as adjaceny stack is searched through
        BogVertex* curr;

        // Node to keep track of curr node
        LSTNode* currNode;
        char last;

        // Stack containing adjacent vertices to be checked
        stack<BogVertex*> adjVerts;

        for(BogVertex* adjV : currVert->getAdj()){
            if(!adjV->wasVisited()){
                adjVerts.push(adjV);
            }
        }
        while(!adjVerts.empty()){
            currNode = lexTree->getRoot();
            curr = adjVerts.top();
            adjVerts.pop();
            prefix += curr->getLetters();

            if(!lexTree->isPrefix(prefix)){
                prefix = origPref;
                continue;
            }

            // Go down the tree to the correct node
            for(string::size_type i = 0;
                i < prefix.size(); i++){
                if(i < prefix.size() - 1){
                    currNode = currNode->getChildren()[prefix[i]];
                }
                last = prefix[i];
            }

            // No more possible words can be formed from this 
            if(currNode != 0 && currNode->noMoreWords() 
               && currNode->isEndWord(last)){
                if(prefix.size() >= minimum_word_length){
                    words->insert(prefix);
                }
                prefix = origPref;
                continue;
            }
            else {
                curr->setVisited(true);

                if(currNode != 0 && currNode->isEndWord(last) && 
                   prefix.size() >= minimum_word_length){
                    words->insert(prefix);
                }
                getWords(curr, prefix, currNode->getPos(),
                         minimum_word_length, words);
                prefix = origPref;
                curr->setVisited(false);
            }
        }
        return;
    }

    /**
     * Returns true if the given word is in the lexicon, false if it is
     * not or if buildLexicon() was not called yet.
     */
    bool BogglePlayer::isInLexicon(const string& word_to_check){
        if(!lexIsSet){
            return false;
        }

        string tmp = word_to_check;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        char last; 

        // Traverse the lexicon, comparing characters as it goes
        // If character is not found, return false, else keep traversing
        LSTNode* curr  = lexTree->getRoot();
        for(string::size_type i = 0; i < tmp.size(); i++){
            if(curr->getChildren()[tmp[i]] == nullptr){
                return false;
            }
            else {
                if(i < tmp.size() - 1){
                   curr = curr->getChildren()[tmp[i]];
                }
            }
            last = tmp[i];
        }

        // Return true if ends on a word
        return curr->isEndWord(last);
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

        // int to keep track of position in the string
        unsigned int pos = 0;

        // Stack to do search through
        stack<BogVertex*> vertStack;

        // Reset vertices to not visited for next call to isOnBoard
        for(auto vert : boardGraph->getMap()){
            vert.second->setVisited(false);
            vert.second->setRevisited(false);
        }

        for(int i = boardGraph->getMap().size() - 1; i >= 0; i--){
            vertStack.push(boardGraph->getMap()[i]);
        }

        // Vertex that keeps track of current vertice
        BogVertex* vert;

        // Traverse the stack to find the locations to make a word
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
            else if(!vert->wasVisited() && pos <= tmpWord.size() &&
                    vert->getLetters() == 
                    tmpWord.substr(pos, compareStr.size()) ){
                // Check if the letter found is not adjacent to the most
                // recently added location.  If it is not adj, then the loop
                // ends and word is not found on board.
                if(locations.size() > 0){
                    vector<BogVertex*> adj = boardGraph->getMap()
                                             [locations.back()]->getAdj();
                    if(find(adj.begin(), adj.end(), vert) == adj.end()){
                        valid = false;
                        break;
                    }
                }

                vert->setVisited(true);
                pos = pos + compareStr.size();
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
        
        // If invalid return the empty vector
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
    BogGraph* BogglePlayer::getBoard(){
        return boardGraph;
    }

    // Getter for the Lexicon trie
    LST* BogglePlayer::getLex(){
        return lexTree;
    }


