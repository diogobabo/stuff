#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------

// TODO
void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const {
    return (list<Kid>(kids));
}

// TODO
void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

// TODO
Kid Game::loseGame(string phrase) {
    int indexLast=0;
    while(kids.size()>1) {
        int size = numberOfWords(phrase);
        int index = (size-1) % kids.size();
        index = indexLast + index;
        index = index % kids.size();
        list<Kid>::iterator it1 = kids.begin();
        advance(it1,index);
        kids.erase(it1);
        indexLast = index;
    }
    auto it = kids.begin();
    return *it;

}

// TODO
list<Kid> Game::removeOlder(unsigned id) {
    return (list<Kid>());
}

// TODO
queue<Kid> Game::rearrange() {
    int gajas = 0;
    int gajos = 0;

    queue<Kid> machaos,touras,festa;

    for(auto &it : kids){
        if(it.getSex() == 'm'){
            gajos = gajos + 1;
            machaos.push(it);
        }else{
            gajas = gajas + 1;
            touras.push(it);
        }
    }
    if(gajos>gajas){
        int combo = gajos/gajas;
        int tamanho = touras.size();
        for(int x = 0; x<tamanho;x++){
            festa.push(touras.front());
            touras.pop();
            for(int y =0; y<combo;y++ ){
                festa.push(machaos.front());
                machaos.pop();
            }
        }
    }else{
        int combo = gajas/gajos;
        for(int y =0; 0<touras.size();y++ ){
            for(int x = 0; x<combo;x++){
                festa.push(touras.front());
                touras.pop();
            }
            festa.push(machaos.front());
            machaos.pop();
        }
    }
    kids.clear();
    for(int x = 0; x<festa.size();x++){
        kids.push_back(festa.front());
        festa.pop();
    }


    return(machaos);
}

// TODO
bool Game::operator==(Game& g2) {
	return true;
}

// TODO
list<Kid> Game::shuffle() const {
	return (list<Kid>());
}
