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

void getTrades(string fileName)
{
    ifstream file (fileName);
    if (!file) { cerr << "Could not open file\n";}

    vector<Trade> trades;
    string line;

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
}

int main()
{
    getTrades("data/covid.csv");
}
