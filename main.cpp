
#include <bits/stdc++.h>

#include "Factory.h"

using namespace std;

int main() {
    try {
        DSInterface<int> *linkedList = (Factory<int>()).getDataStructure("LinkedList");
    } catch (exception const& ex) {
        cout << ex.what();
    }
}