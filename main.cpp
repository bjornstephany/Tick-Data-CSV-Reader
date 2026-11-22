#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits>
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

int getTradeCount(vector<Trade> trades)
{
    return trades.size();
}

double getMid(Trade t)
{
    return { (t.ask + t.bid) / 2 };
}

double getMeanMid(vector<Trade> trades)
{
    double midSum {0.0};
    int tradeCount = getTradeCount(trades);
    for ( Trade& t : trades )
    {
        midSum += getMid(t);
    }
    return midSum / tradeCount;
}

double getMinMid(vector<Trade> trades)
{
    double minMid = numeric_limits<double>::max();
    for ( Trade t : trades )
    {
        minMid = min(minMid, getMid(t));
    }
    return minMid;
}

double getMaxMid(vector<Trade> trades)
{
    double maxMid = numeric_limits<double>::min();
    for ( Trade t : trades )
    {
        maxMid = max(maxMid, getMid(t));
    }
    return maxMid;
}

int main()
{
    vector<Trade> trades = getTrades("data/lehman.csv");
    cout << "Number of trades in lehman: " << getTradeCount(trades) << "\n";
    cout << "Mean Mid-price: " << getMeanMid(trades) << "\n";
    cout << "Min Mid-price: " << getMinMid(trades) << "\n";
    cout << "Max Mid-price: " << getMaxMid(trades) << "\n";
}
