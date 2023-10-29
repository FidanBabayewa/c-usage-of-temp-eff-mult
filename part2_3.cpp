#include <iostream>
#include <iomanip>

class AnonymManipulator {
public:
    AnonymManipulator() : anonymize(false) {}

    friend std::ostream& operator<<(std::ostream& os, const AnonymManipulator& manipulator) {
        std::string input;
        getline(os, input); // Read the input from the stream

        if (manipulator.anonymize) {
            size_t start = 0;
            size_t end = input.find_first_of(" \t\n"); // Find the first word in the input

            while (end != std::string::npos) {
                // Anonymize words starting with a capital letter
                if (isupper(input[start])) {
                    for (size_t i = start; i < end; ++i) {
                        input[i] = '*';
                    }
                }

                start = end + 1; // Move to the next word
                end = input.find_first_of(" \t\n", start); // Find the next word
            }

            // Handle the last word in the input
            if (isupper(input[start])) {
                for (size_t i = start; i < input.length(); ++i) {
                    input[i] = '*';
                }
            }
        }

        os << input; // Output the modified input back to the stream
        return os;
    }

    friend AnonymManipulator& operator<<(std::ostream& os, const AnonymManipulator& manipulator) {
        return const_cast<AnonymManipulator&>(manipulator);
    }

    AnonymManipulator& toggle() {
        anonymize = !anonymize;
        return *this;
    }

private:
    bool anonymize;
};

AnonymManipulator anonym;

int main() {
    std::cout << anonym << " Simon Doyle is the murderer. " << anonym << "It was investigated by Hercule Poirot." << std::endl;
    std::cout << anonym << " his last known location: the Nile " << anonym << std::endl;

    return 0;
}

