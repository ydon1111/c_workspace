#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello","C++","world","from","VS Code","and the C++ extension!","한글 테스트"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
