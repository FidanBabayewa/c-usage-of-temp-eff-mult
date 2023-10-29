#include <iostream>
#include <exception>
#include <algorithm>

template <typename T, unsigned int N>
class voting {
    struct Candidate {
        T candidate;
        int votes;
    };

    Candidate candidates[N];

public:
    voting(T arr[N]) {
        for (unsigned int i = 0; i < N; ++i) {
            candidates[i].candidate = arr[i];
            candidates[i].votes = 0;
        }
    }

    voting& operator+=(const T& candidate) {
        auto it = std::find_if(candidates, candidates + N, [&candidate](const Candidate& c) {
            return c.candidate == candidate;
        });

        if (it != candidates + N) {
            ++it->votes;
        } else {
            throw std::exception();
        }

        return *this;
    }

    T operator!() {
        for (unsigned int i = 0; i < N; ++i) {
            if (candidates[i].votes > 0) {
                return candidates[i].candidate;
            }
        }

        throw std::exception(); // No votes casted, cannot determine winner
    }

    friend std::ostream& operator<<(std::ostream& os, const voting& vote) {
        for (unsigned int i = 0; i < N; ++i) {
            os << vote.candidates[i].candidate << ":" << vote.candidates[i].votes << std::endl;
        }
        return os;
    }
};

int main() {
    char c[5] = { 'a', 'b', 'c', 'd', 'e' };
    voting<char, 5> vc(c);
    try {
        ((vc += 'd') += 'd') += 'e';
        std::cout << vc;
        std::cout << "winner: " << !vc << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
