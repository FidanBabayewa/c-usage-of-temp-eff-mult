#include <iostream>
#include <stdexcept>
#include <iomanip>

// Define TEMPLATE_VECTOR_INTERVAL to enable testing for this task
// #define TEMPLATE_VECTOR_INTERVAL

template <unsigned int MIN, unsigned int MAX>
class IntervalVector {
private:
    unsigned int elements[MAX - MIN + 1] = {0};

public:
    IntervalVector() {
        static_assert(MIN <= MAX, "MIN must be less than or equal to MAX");
    }

    IntervalVector& operator+=(unsigned int num) {
        if (num >= MIN && num <= MAX) {
           elements[num - MIN] = elements[num - MIN] + 1;
        } else {
            throw std::out_of_range("Invalid input: " + std::to_string(num));
        }
        return *this;
    }

    IntervalVector operator+(const IntervalVector& other) const {
        IntervalVector result;
        for (unsigned int i = MIN; i <= MAX; ++i) {
            result.elements[i - MIN] = elements[i - MIN] + other.elements[i - MIN];
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const IntervalVector& iv) {
        os << "IntervalVector <" << MIN << " ," << MAX << " > v;" << std::endl;
        for (unsigned int i = MIN; i <= MAX; ++i) {
            os << i << ": " << iv.elements[i - MIN] << std::endl;
        }
        return os;
    }
};



int main() {
    try {
        IntervalVector<1, 5> v;
        v += 5;

        std::cout << v;



        IntervalVector<1, 5> v1;
        v1 += 5;

        IntervalVector<1, 5> v2;
        v2 += 5;

        IntervalVector<1, 5> v3 = v1 + v2;
        std::cout << v3;

        // Uncomment the lines below to test invalid input
         //nt of 6: " << v[6] << std::endl; // Throws exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

