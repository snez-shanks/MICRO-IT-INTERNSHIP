#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

class CurrencyConverter {
private:
    map<string, double> exchangeRates;

public:
    CurrencyConverter() {
        // Exchange rates based on 1 USD
        exchangeRates["USD"] = 1.0;        // Base
        exchangeRates["EUR"] = 0.92;       // Euro
        exchangeRates["INR"] = 83.26;      // Indian Rupee
        exchangeRates["GBP"] = 0.78;       // British Pound
        exchangeRates["JPY"] = 154.33;     // Japanese Yen
    }

    bool isSupported(const string& currency) {
        return exchangeRates.find(currency) != exchangeRates.end();
    }

    void convert(double amount, const string& from, const string& to) {
        if (!isSupported(from) || !isSupported(to)) {
            cout << "Error: Unsupported currency." << endl;
            return;
        }

        double usdAmount = amount / exchangeRates[from];     // Convert to USD
        double convertedAmount = usdAmount * exchangeRates[to]; // Convert to target

        cout << fixed << setprecision(2);
        cout << amount << " " << from << " = " << convertedAmount << " " << to << endl;
    }

    void showSupportedCurrencies() {
        cout << "Supported currencies:\n";
        for (const auto& pair : exchangeRates) {
            cout << "- " << pair.first << endl;
        }
    }
};

int main() {
    CurrencyConverter converter;
    string fromCurrency, toCurrency;
    double amount;
    char choice;

    do {
        cout << "\n--- Currency Converter ---\n";
        converter.showSupportedCurrencies();

        cout << "\nEnter amount: ";
        cin >> amount;

        cout << "Convert from (currency code): ";
        cin >> fromCurrency;

        cout << "Convert to (currency code): ";
        cin >> toCurrency;

        converter.convert(amount, fromCurrency, toCurrency);

        cout << "\nDo you want to convert another amount? (y/n): ";
        cin >> choice;
        cout << "-----------------------------\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the Currency Converter!\n";
    return 0;
}
