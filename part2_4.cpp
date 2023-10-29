#include <iostream>
#include <stdexcept>

using namespace std;

class Exchange {
public:
    string operator()(unsigned int value, const string& currency) const {
        if (currency == "EUR") {
            // Convert euro to forint
            unsigned int forint = value * 425;
            return to_string(forint) + " HUF";
        } else if (currency == "HUF") {
            // Convert forint to euro (integer division)
            unsigned int euro = value / 425;
            return to_string(euro) + " EUR";
        } else {
            // Handle invalid currency with exception
            throw invalid_argument("Invalid currency: " + currency);
        }
    }
};

int main() {
    Exchange exchange;

    try {
        cout << "Convert 100 EUR to HUF: " << exchange(100, "EUR") << endl;
        cout << "Convert 800 HUF to EUR: " << exchange(800, "HUF") << endl;

        // Attempting to convert with invalid currency
        cout << "Convert 500 USD to EUR: " << exchange(500, "USD") << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
