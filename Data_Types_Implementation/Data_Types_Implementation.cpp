#include <iostream>
#include <string>
#include <map>
#include "Stack.h"
#include "Linked_Lists.h"
#include "Array.h"
#include "String.h"
#include "Algorithms.h"
#include "Map.h"

using namespace std;

template<typename T>
void Print(Ienumerable<T>& sequence) {


    for (int i = 0; i < sequence.GetSize(); i++)
    {
        cout << sequence[i] << " ";
    }

    cout << endl;
}

template<typename T>
void RandomFIll(Ienumerable<T>& sequence) {


    for (int i = 0; i < sequence.GetSize(); i++)
    {
        sequence[i] = 10 + rand() % 90;
    }

}

void F(Array<int> T) {

}

int main() {

    srand(time(NULL));

    String s = "12344";

    map<int, int> m;
    
    Map<int, String> map;
    map[2] = "123456";

    map[2] += "0987";

    map[2].RemoveLast();

    Print(map[2]);

    return 0;

}