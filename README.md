# Tick Data CSV Reader With Statistics

The Goal: 
- Read historical EUR/USD tick-level quote data, compute market statistics, and compare market behaviour across three major financial crises

The data sets:
- 15 September 2008 — financial crisis
- 6 May 2010 — flash crash
- 16 March 2020 — COVID market crash

Data meaning:
- timestamp	= Time of the quote update, in Unix milliseconds
- askPrice	= Lowest price at which someone is willing to sell
- bidPrice	= Highest price at which someone is willing to buy

The Statistics;
- Mid-price
- Mid-price OHLC
- Rolling mid-price mean
- Rolling return volatility	
- Largest mid-price movement
- Bid-ask spread
- Tick arrival frequency
- Bid/ask quote analysis

Data set source: dukascopy
