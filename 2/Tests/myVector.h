#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
T MyVector<T>::max() const {
    vector<T> cena = getValues();
    if(values.size() == 0){
        throw EmptyVector();
    }
    T vmax = cena[0];
    for(auto x : cena){
        if(!(vmax > x)){
            vmax = x;
        }
    }
	return vmax;
}

// TODO
template<class T>
bool MyVector<T>::hasDuplicates() const {
    if(values.size() == 0){
        return false;
    }
    vector<T> testVec = getValues();
    sort(testVec.begin(),testVec.end());
    for(auto it = testVec.begin();it < (testVec.end()-1);it++){
        if(*it == *(it+1)){
            return true;
        }
    }
	return false;
}

// TODO
template<class T>
void MyVector<T>::removeDuplicates() {
    if(values.size() == 0){
        return;
    }
    vector<T> testVec = getValues();
    sort(testVec.begin(),testVec.end());
    std::set<T> dic;
    for(auto it = testVec.begin();it < (testVec.end()-1);it++){
        if(*it == *(it+1)){
            dic.insert(*it);
        }
    }
    for(auto it : dic){
        auto it1 = std::find(values.begin(),values.end(),it);
        do{
            it1 = std::find(it1+1,values.end(),it);
            if(it1 == values.end()){
                break;
            }
            values.erase(it1);
            it1--;
        }while(it1 != values.end());
    }
}

