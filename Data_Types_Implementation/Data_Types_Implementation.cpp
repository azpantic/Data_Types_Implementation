#include <iostream>
#include "Stack.h"
#include "Linked_Lists.h"
#include "Array.h"
#include "String.h"
#include "Algorithms.h"

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

int main() {

    srand(time(NULL));

    Array<string> array({"1234" , "143", "1111"});

    Sort(array);

    Print(array);

    cout << BinarySearch(array, (string)"1111");

    return 0;

}