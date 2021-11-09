#include "funSearchProblem.h"
#include <algorithm>
FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

// TODO
int FunSearchProblem::facingSun(const vector<int> & values) {
    if(values.size() == 0){
        return 0;
    }
    int temp = values.at(0);
    unsigned int couter = 1;
    for(auto it = values.begin()+1;it != values.end(); it++){
        if(temp >= *it){
            continue;

        }else{
            temp = *it;
            couter++;
        }
    }
    return couter;
}

// TODO
int FunSearchProblem::squareR(int num) {
    int mid = num/2;
    int max,temp;
    max = num;
    if(num == 0 or num == 1){
        return num;
    }
    while((max - mid )> 1){
        temp = mid*mid;
        if(temp > num){
            max = mid;
            mid = max/2;
        }else if(temp < num){
            mid = (mid+max)/2;
        }else{
            return mid;
        }

    }
    if(mid * mid >num){
        return mid-1;
    }
    return mid;
}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    vector<int> copy = values;
    sort(copy.begin(),copy.end());
    copy.erase(unique(copy.begin(),copy.end()),copy.end());
    int counter = 0;
    for(auto x : copy){
        if(x<0){
            continue;
        }else{
            if(x > counter){
                return counter;
            }else{
                counter++;
            }
        }
    }
    return counter;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    return 0;
}

