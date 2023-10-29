#include <iostream>
#include <exception>
#include <algorithm>

template <typename T, unsigned int N>
class Voting {
    struct Candidate {
        T name;
        int votes;

        Candidate() : votes(0) {} // Default constructor
        Candidate(const T& n) : name(n), votes(0) {} // Constructor taking a candidate name

        // Comparison operator (==)
        bool operator==(const T& other) const {
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
    Voting(const T arr[N]) {
        for (unsigned int i = 0; i < N; ++i) {
            candidates[i] = Candidate(arr[i]);
        }
    }

    Voting& operator+=(const T& candidate) {
        auto it = std::find_if(candidates, candidates + N, [&candidate](const Candidate& c) {
            return c == candidate;
        });

        if (it != candidates + N) {
            ++it->votes;
        } else {
            throw std::exception();
        }

        return *this;
    }

    T operator!() const {
        T winner;
        int maxVotes = -1;

        for (unsigned int i = 0; i < N; ++i) {
            if (candidates[i].votes > maxVotes) {
                maxVotes = candidates[i].votes;
                winner = candidates[i].name;
            }
        }

        return winner;
    }

    friend std::ostream& operator<<(std::ostream& os, const Voting& vote) {
        for (unsigned int i = 0; i < N; ++i) {
            os << vote.candidates[i] << std::endl;
        }
        return os;
    }
};

int main() {
    char c[5] = { 'a', 'b', 'c', 'd', 'e' };
    Voting<char, 5> vc(c);
    try {
        ((vc += 'd') += 'd') += 'e';
        std::cout << "Votes:\n" << vc;
        std::cout << "Winner: " << !vc << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
