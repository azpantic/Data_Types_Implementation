#include <iostream>
#include "Stack.h"
#include "Linked_Lists.h"

using namespace std;

int main()
{
   
    Linked_List<int> List;

    List.Push_Back(1);
    List.Push_Back(2);
    List.Push_Back(3);
    List.Push_Back(4);
    List.Push_Front(0);

    for (int i = 0; i < List.Get_Size(); i++)
    {
        cout << List[i] << " ";
    }

    return 0;
}
