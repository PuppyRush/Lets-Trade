/* Every header files working in progress here */
#include "../include/public_header.hpp"
#include "stock.cpp"
#include "transaction.cpp"
#include "csvExtractor.cpp"
//#include "banking.cpp"
//#include "player.cpp"
//#include "share.cpp"
//#include "portfolio.cpp"

#include <memory>

template<class T>
void GetUserInput(T const &arg, std::string const msg);
vector< std::unique_ptr<Stock> > CreateStocks(int howMany);  // Should return vecotr<Stock*> later
int main(){

    /* Initializing Data */

    srand(time(NULL));
    bool isPlaying, isDay, isTrade = true;
    auto official_date = std::make_unique<Date>();
    string name;
    int age;
    //vector<Share*> fake_shares;
    //Portfolio* portfolio = new Portfolio(fake_shares);


    /* Create Stocks */
    auto stocks = CreateStocks(15);

    /* for (auto& s: stocks)
        cout << *s << endl; */

    /* Generate Player */
    GetUserInput<std::string&>(name, "Insert player name");
    GetUserInput<int&>(age, "Insert player age");

    cout << name << endl;
    cout << age << endl;

    // Player::Player* player = new Player::Player(name, age, portfolio);

    /* Genertate BankAccount */
    // Account::Account* account  = new Account::Account(player, "#s346xcc", 100000.00);

    /*
    Main Loop
    while(isPlaying){

        while(isDay){

            while(isTrade){
                // Print Current Time()
                // Print Positions
                // Print Balance
                // Print All Stocks

                swtich(first_decision){
                    case:
                        break;
                    case:
                        break;
                    case:
                        break;
                    case:
                        break;
                }
                // If trade ends
                Date::AddGameTime(official_date);
                if(official_date->GetHour() = 9)
                    isTrade = false;
            }
            isDay = false;
        }
        isPlaying = false;
    }
    */
    system("pause");
    return 0;
}

vector<std::unique_ptr<Stock>> CreateStocks(int howMany){
    int count;
    vector<std::unique_ptr<Stock>> stocks;
    auto e = std::make_unique<CSVExtractor>("./companies.csv");
    auto r = std::make_unique<RandomNumberGenerator>(1, 400, howMany);
    auto data = e->GetResult();
    auto manyIndex = r->GetNumbers();

    for(int i = 0; i < manyIndex.size(); i++){
        count = manyIndex.at(i);

        Company* c = new Company(data.at(count).at(1), data.at(count).at(2)); // This will be handled by ~Stock()
        auto s = std::make_unique<Stock>(data.at(count).at(0), c);
        stocks.push_back(std::move(s)); // emplace_back() does not work
    }
    return stocks;
}

template <class T>
void GetUserInput(T const& arg, std::string const msg){
    cout << msg << ": \n";
    cin >> arg;
}
