#ifndef STOCK_H
#define STOCK_H

#include <time.h>
#include <ctime>
#include <vector>

enum TRANSACTION_TYPE { SELL, BUY };

struct Transaction{
    Transaction(int, double);
    string currentTime;
    int type;
    double cost;

    // ToString
    friend ostream& operator<<(ostream& strm, const Transaction& t);
};

struct Company{
    Company(string);
    Company(string, string);
    string companyName;
    string companyType;
    double companyPrice;
    double companyValue;

    // ToString
    friend ostream& operator<<(ostream& strm, const Company& c);
};

class Stock{
public:
    Stock(string);
    Stock(string, double, Company*);

    // Get
    double GetCurrentPrice();
    double GetPrevPrice();
    string GetSymbol();
    Company GetStockIssuer();
    vector<Transaction> GetTransactionHistory();

    // Set
    void SetCurrentPrice(double);
    void SetPrevPrice(double);
    void SetSymbol(string);
    void SetStockIssuer(Company*); // Just passing pointer

    // Methods
    void AddTransactionHistory(int, double);
    int GetRandomNumber(int);
    double GetChangedPercentage();

    // In Progress
    double GetRandomStockPrice(int);
    void UpdateStockPrice(double); // Update both stockCurrentPrice & stockPrevPrice
                                   // Add Transaction History

    // Tests
    void PrintTransactionHistory();

    // Dectructor
    ~Stock();

protected:
    double stockCurrentPrice;
    double stockPrevPrice;
    string stockSymbol;
    Company* stockIssuer; // Stock Issuer
    vector<Transaction> transactionHistory; // Neead fix

    // ToString
    friend ostream& operator<<(ostream& strm, const Stock& s);
};

#endif
