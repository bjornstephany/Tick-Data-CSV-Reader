#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Trade
{
    int64_t time;
    double ask;
    double bid; 
};

vector<Trade> getTrades(string fileName)
{
    vector<Trade> trades;

    ifstream file (fileName);
    if (!file)
    { 
        cerr << "Could not open file\n";
        return trades;
    }
    
    string line;
    getline(file, line);
    while ( getline (file, line) )
    {
        stringstream ss(line);
        string time, ask, bid;

        getline(ss, time, ',');
        getline(ss, ask, ',');
        getline(ss, bid, ',');

        Trade t;
        t.time = stoll(time);
        t.ask = stod(ask);
        t.bid = stod(bid);
        trades.push_back(t);
    }
    return trades;
}

int main()
{
    vector<Trade> trades = getTrades("data/lehman.csv");
    int64_t test = trades[0].time;
    cout << test << "\n";
}
