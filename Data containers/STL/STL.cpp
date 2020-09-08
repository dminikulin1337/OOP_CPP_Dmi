#include <iostream>
#include <list>
using namespace std;

//STL - standard template library. It is a number of template containers - trees, lists, arrays

int main()
{
    setlocale(LC_ALL, "");
    list<int> my_list = { 3,5,8,13,21 };
    for (list<int>::iterator it = my_list.begin(); it != my_list.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
    for (list<int>::reverse_iterator rit = my_list.rbegin(); rit != my_list.rend(); rit++)
    {
        cout << *rit << "\t";
    }
    return 0;
}
