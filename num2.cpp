#include <iostream>
#include <exception>
#include <algorithm>

template <unsigned int N>
class Voting {
    struct Candidate {
        unsigned int name;
        unsigned int votes;
        Candidate() : name(0), votes(0) {}  // Default constructor
        Candidate(unsigned int n) : name(n), votes(0) {} // Constructor taking a candidate name

        // Comparison operator (==)
        bool operator==(unsigned int other) const {
            return name == other;
        }

        // Output stream operator
        friend std::ostream& operator<<(std::ostream& os, const Candidate& candidate) {
            os << candidate.name << ":" << candidate.votes;
            return os;
        }
    };

    Candidate candidates[N];

public:
    Voting(const unsigned int arr[N]) {
        for (unsigned int i = 0; i < N; ++i) {
            candidates[i] = Candidate(arr[i]);
        }
    }

    Voting& operator+=(unsigned int candidate) {
        auto it = std::find_if(candidates, candidates + N, [&candidate](const Candidate& c) {
            return c == candidate;
        });

        if (it != candidates + N) {
            it->votes += candidate;
        } else {
            throw std::exception();
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Voting& vote) {
        for (unsigned int i = 0; i < N; ++i) {
            os << vote.candidates[i] << std::endl;
        }
        return os;
    }
};

int main() {
    unsigned int uns[] = {1, 2, 3, 4};
    Voting<4> uv(uns);

    try {
        uv += 3u; // Vote for candidate with value 3
        std::cout << uv << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
