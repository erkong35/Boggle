/******************************************************
 * Tester file to test basic functionality of your code
 * ****************************************************/

#include "baseboggleplayer.h"
#include "boggleplayer.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main (int argc, char* argv[]) {

  BogglePlayer * p = new BogglePlayer();
  set<string> lex;
  string wordA("a");
  string wordX("x");
  lex.insert(wordA);
  lex.insert("z");
  string row0[] = {"D ","C ", "R ", "BOB"};
  string row1[] = {"b ","A ", "Z ", "DUDE"};
  string row2[] = {"DC ", "BB ", "CC ", "REKT "};
  string row3[] = {"Lo ", "To ", "Bo ", "Pwnt "};
  string* board[] = {row0,row1,row2,row3};
  set<string> words;
  vector<int> locations;

//  p->buildLexicon(lex);
  p->setBoard(4,4,board);
  for(int i = 0; i < 16; i++){    
     cout << "Key " << p->getBoard().getMap()[i]->getLetters() << ": ";
     for(BogVertex* hi : p->getBoard().getMap()[i]->getAdj()){
         cout << hi->getLetters() << " ";
     }
     cout << endl;
  }
/*  if(p->isInLexicon(wordX)) {
    std::cerr << "Apparent problem with isInLexicon #1." << std::endl;
    return -1;
  }
  if(!p->isInLexicon(wordA)) {
    std::cerr << "Apparent problem with isInLexicon #2." << std::endl;
    return -1;
  }

  if(p->isOnBoard(wordX).size() > 0) {
    std::cerr << "Apparent problem with isOnBoard #1." << std::endl;
    return -1;
  }

  locations.clear();
  locations = p->isOnBoard(wordA);
  if(locations.size() != 1 || locations[0] != 3) {
    std::cerr << "Apparent problem with isOnBoard #2." << std::endl;
    return -1;
  }
  
  
  if(!p->getAllValidWords(0,&words)) {
    std::cerr << "Apparent problem with getAllValidWords #1." << std::endl;
    return -1;
  };
  if(words.size() != 1 || words.count(wordA) != 1) {
    std::cerr << "Apparent problem with getAllValidWords #2." << std::endl;
    return -1;
  } */

  delete p;
  return 0;

}
