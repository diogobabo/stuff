// AED 2021/2022 - Aula Pratica 08
// Pedro Ribeiro (DCC/FCUP) [12/12/2021]

#include "funWithHashTables.h"
#include "hashTable.h"

#include <vector>
#include <iostream>
#include <cctype>

// Exemplo de função de hash para ints
unsigned FunWithHashTables::hashInt(const int& i) {
  return i;
}

// Exemplo de função de hash para strings
unsigned FunWithHashTables::hashString(const string& s) {
  hash<string> h;
  return h(s);
}

// ----------------------------------------------------------
// Exercicio 1: Tabelas de Dispersão
// ----------------------------------------------------------

// ..............................
// d) Contando diferentes somas de pares
// TODO
int FunWithHashTables::sum(int a, int b) {
    return a+b;
}
int FunWithHashTables::sumPairs(const vector<int>& numbers) {
    HashTable<int> hashTable(numbers.size()*numbers.size()+2,hashInt);
    for(int x=0;x<numbers.size();x++){
        for(int y = x+1;y<numbers.size();y++)
            if(x != y)
                hashTable.insert(sum(numbers[x],numbers[y]));
    }
    return hashTable.getNumActive();
}

// ----------------------------------------------------------
// Exercicio 2: Um padrão no DNA
// ----------------------------------------------------------
// TODO
int FunWithHashTables::dnaMotifs(string dna, int k, unordered_set<string>& motifs) {
  return 0;
}

// ----------------------------------------------------------
// Exercicio 3: Torre de Babel
// ----------------------------------------------------------
// TODO
void FunWithHashTables::findLanguage(string text, const unordered_map<string, vector<string>>& dict, unordered_map<string, int>& answer) {
}

// ----------------------------------------------------------
// Exercicio 4: Palavras Alienígenas
// ----------------------------------------------------------
// TODO
void FunWithHashTables::wordIndex(const vector<string> &words, vector<int>& answer) {
}
