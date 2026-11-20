#include <iostream>
#include <fstream>
using namespace std;

void readFrom(string fileName)
{
    int lineCount;

    ifstream file;
    file.open(fileName);
    string line;
    while ( getline (file, line) )
    {
        cout << line << "\n";
        lineCount++;
    }
    file.close();

    cout << "\n" << "Line count: " << lineCount << "\n";
}

int main()
{
    cout << "Test\n";
    readFrom("data/covid.csv");
}
