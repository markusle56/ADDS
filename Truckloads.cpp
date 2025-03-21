#include "Truckloads.h"

int Truckloads::numTrucks(int numCrates, int loadSize){
    if (loadSize >= numCrates) {
        return 1;
    } else {
        int n1 = numCrates / 2;
        int n2 = n1 + (numCrates % 2);
        return numTrucks(n1, loadSize) + numTrucks(n2, loadSize);
    }
}