#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

/*  Testes how many reallocations are done when doing resize(). As expected
    it doubles the vector space to avoid excessive copies. */

int main(){
    vector<char> v;
    uint64_t limit = 1ULL <<30;
    uint64_t i = 0;
    uint64_t last_capacity = v.capacity();
    while(v.capacity()<limit){
        v.resize(i);
        if(last_capacity != v.capacity()){
            cout << "Capacity changed " << v.capacity() << endl;
            last_capacity = v.capacity();
        }
        i++;
    }
    return 0;
}
