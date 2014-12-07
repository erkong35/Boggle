/******************************************************
 * Tester file to test basic functionality of your code
 * ****************************************************/

#include "baseboggleplayer.h"
#include "boggleplayer.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <algorithm>

using namespace std;

int main (int argc, char* argv[]) {

  BogglePlayer * p = new BogglePlayer();
  set<string> lex;
  string wordA("a");
  string wordX("x");
//  lex.insert(wordA);
//  lex.insert("abc");
//  lex.insert("ab");
//  lex.insert("z");
  string row0[] = {"b","c", "d"};
  string row1[] = {"g","m", "p"};
  string row2[] = {"t", "c", "z"};
  string* board[] = {row0,row1,row2};
  set<string> words;
  vector<int> locations;

  string word;
  ifstream infile;
  infile.open(argv[1]);
  while(infile.is_open() && infile.good()){
      getline(infile, word);
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      lex.insert(word);
  }
  infile.close();

  p->buildLexicon(lex);

  infile.open(argv[1]);

  while(infile.is_open() && infile.good()){
      getline(infile, word);
      if(p->isInLexicon(word)) {
      }
      else {
          cout << " IS NOT IN " << endl;
      }
  }
  p->setBoard(3,3,board);
  for(int i = 0; i < 9; i++){    
     cout << "Key " << p->getBoard().getMap()[i]->getLetters() << ": ";
     for(BogVertex* hi : p->getBoard().getMap()[i]->getAdj()){
         cout << hi->getLetters() << " ";
     }
     cout << endl;
  }

  if(p->isOnBoard("dt").size() > 0) {
      for(int i : p->isOnBoard("dt")){
          cout << i << " ";
      }
      cout << endl;
  } else {
      cout << "NO LIST" << endl;
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
  }*/ 

  delete p;
  return 0;

}
