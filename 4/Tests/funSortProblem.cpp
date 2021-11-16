#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

// TODO
bool sortkey(Product &a,Product &b){
    if(a.getPrice() == b.getPrice()){
        return a.getWeight()<b.getWeight();
    }
    else{
        return a.getPrice()<b.getPrice();
    }
}
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
        sort(products.begin(),products.end(), sortkey);
        if(products.size()<k){
            return;
        }
        products.erase(products.begin()+k,products.end());
        return;
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if(values.size() < nc){
        return -1;
    }
    if(values.size() == nc){
        return (*std::max_element(values.begin(), values.end()) - *min_element(values.begin(), values.end()));
    }
    vector<unsigned> copy = values;
    sort(copy.begin(),copy.end());
    vector<unsigned> v;
    for(int x = 0; copy.size() > x+nc ;x++){
        v.push_back(copy.at(x+nc-1) - copy.at(x));
    }
    return *min_element(v.begin(),v.end());
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

