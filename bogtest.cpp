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

/*  BogglePlayer * p = new BogglePlayer();
  set<string> lex;
  string wordA("a");
  string wordX("x");
//  lex.insert(wordA);
//  lex.insert("abc");
//  lex.insert("ab");
//  lex.insert("z");
//  string row0[] = {"b","c", "d"};
//  string row1[] = {"g","m", "p"};
//  string row2[] = {"t", "c", "z"};
//  string* board[] = {row0,row1,row2};
//  set<string> words;
//  vector<int> locations;
string row0[] = {"J","N","R","A"};
string row1[] = {"D","S","A","Qu"};
string row2[] = {"L","H","L","X"};
string row3[] = {"E","F","C","V"};
//string row0[] = {"T","H","L","I"};
//string row1[] = {"R","E","A","D"};
//string row2[] = {"I","L","M","O"};
//string row3[] = {"F","P","S","N"};
string* board[] = {row0,row1,row2,row3};
 
// set<string> words;
 vector<int> locations;
 p->setBoard(4,4,board);    //<-------this is important
*/
/* std::vector<int>checkVector;
 checkVector = p->isOnBoard("TRIP");
 if(checkVector.size()==4)
 {
     std::cout << "TRIP found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("mad");
 if(checkVector.size()==3)
 {
     std::cout << "mad found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("Help");
 if(checkVector.size()==4)
 {
     std::cout << "Help found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("lamE");
 if(checkVector.size()==4)
 {
     std::cout << "lamE found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("dOmE");
 if(checkVector.size()==4)
 {
     std::cout << "dOmE found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("FiRe");
 if(checkVector.size()==4)
 {
     std::cout << "FiRe found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("flip");
 if(checkVector.size()==4)
 {
     std::cout << "flip found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("real");
 if(checkVector.size()==4)
 {
     std::cout << "real found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("ream");
 if(checkVector.size()==4)
 {
     std::cout << "ream found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("HEAL");
 if(checkVector.size()==4)
 {
     std::cout << "HEAL at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("had");
 if(checkVector.size()==3)
 {
     std::cout << "had found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("hAm");
 if(checkVector.size()==3)
 {
     std::cout << "hAm found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("son");
 if(checkVector.size()==3)
 {
     std::cout << "son found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("LID");
 if(checkVector.size()==3)
 {
     std::cout << "LID found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("dame");
 if(checkVector.size()==4)
 {
     std::cout << "dame found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
 checkVector = p->isOnBoard("Team");
 if(checkVector.size()==4)
 {
     std::cout << "Team found at: ";
     for(unsigned int i = 0; i < checkVector.size(); i++)
     {
         std::cout<<checkVector.at(i)<<" ";
     }
     std::cout<<"\n";
 };
*/
/*  string word;
  ifstream infile;
  infile.open(argv[1]);
  while(infile.is_open() && infile.good()){
      getline(infile, word);
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      lex.insert(word);
  }
  infile.close();

  p->buildLexicon(lex);
  if(p->isOnBoard("aquas").size() > 0)
      cout << " HI " << endl;

  set<string> list;
  infile.open(argv[1]);
  while(infile.is_open() && infile.good()){
      getline(infile, word);
      if(p->isOnBoard(word).size() > 0 && word.size() >= 5){
          list.insert(word);
      }
  }
  infile.close();

  set<string> validList;
  p->getAllValidWords(5, &validList);
  for(string s : list){
      cout << s << endl;
  }
cout << "WOEIFJOWEIFJOWEJIFWOIEJFOWEJFOWIJEFOWJFOWEIF" << endl;
  for(string p : validList){
      cout << p << endl;
  }
  
  cout << validList.size() << endl;
  cout << list.size() << endl;

  infile.open(argv[1]);
  while(infile.is_open() && infile.good()){
      getline(infile, word);
      if(p->isInLexicon(word)) {
      }
      else {
          cout << " IS NOT IN " << endl;
      }
  }

  for(int i = 0; i < 16; i++){    
     cout << "Key " << p->getBoard().getMap()[i]->getLetters() << ": ";
     for(BogVertex* hi : p->getBoard().getMap()[i]->getAdj()){
         cout << hi->getLetters() << " ";
     }
     cout << endl;
  }

  if(p->isOnBoard("aqua").size() > 0) {
      for(int i : p->isOnBoard("aqua")){
          cout << i << " ";
      }
      cout << endl;
  } else {
      cout << "NO LIST" << endl;
  }

  if(p->isInLexicon(wordX)) {
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

    BogglePlayer p;

    std::set<string> lex;
    std::set<string> results;

    std::ifstream in("lex.txt");

    // Load the lexicon from file
    string word;
    while(std::getline(in, word))
    lex.insert(word);

    in.close();

    std::cout << "wc: " << lex.size() << "\n";


    // Load the board dice from file
    int rows;
    int cols;
    in.open("brd.txt");

    in >> rows;
    in >> cols;

    std::cout << "r: " << rows << " c: " << cols << "\n";

    std::string **brd = new std::string*[rows];
     
    for (int i = 0; i < rows; ++i) {
    std::string *row = new std::string[cols];

    for (int j = 0; j < cols; ++j) {
    in >> row[j];
    }

    brd[i] = row;
    }

    in.close();

    // Prepare the BogglePlayer object
    p.buildLexicon(lex);
    p.setBoard(rows, cols, brd);

    // Get the results
    cout << "HERE " << endl;
    p.getAllValidWords(2, &results);

    std::cout << "wc: " << results.size() << "\n";

    std::set<string>::iterator i = results.begin();
    std::set<string>::iterator e = results.end();

//    delete p;
    return 0;
}
