#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello","C++","world","from","VS Code","and the C++ extension!","�ѱ� �׽�Ʈ"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
