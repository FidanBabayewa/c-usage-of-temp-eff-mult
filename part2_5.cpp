#include <iostream>
#include <string>

using namespace std;

class Sugar {
public:
    double energy() const { return 1.0; }
};

class BrownSugar {
public:
    double energy() const { return 1.2; }
};

class FullPortion {
public:
    double size() const { return 1.0; }
};

class HalfPortion {
public:
    double size() const { return 0.5; }
};

class Normal {
public:
    string get_name() const { return "Normal Person"; }
};

class Dietary {
public:
    string get_name() const { return "Dietary Person"; }
};

template<class PersonType>
class PersonTraits;

template<>
class PersonTraits<Normal> {
public:
    using sugar_type = Sugar;
    using portion_size = FullPortion;
};

template<>
class PersonTraits<Dietary> {
public:
    using sugar_type = BrownSugar;
    using portion_size = HalfPortion;
};

template<class Person, class Traits = PersonTraits<Person>>
class PersonalizedCake {
public:
    PersonalizedCake(const Person& person) : person(person) {}

    double calorie_intake() const {
        return typename Traits::sugar_type().energy() * typename Traits::portion_size().size();
    }

    friend ostream& operator<<(ostream& os, const PersonalizedCake& cake) {
        os << cake.person.get_name();
        return os;
    }

    // Overload the > operator for different Traits types
    template<class OtherPerson, class OtherTraits>
    bool operator>(const PersonalizedCake<OtherPerson, OtherTraits>& other) const {
        return calorie_intake() > other.calorie_intake();
    }

private:
    Person person;
};

int main() {
    Normal normalPerson;
    PersonalizedCake<Normal> normalCake(normalPerson);
    cout << "Calorie Intake for Normal Person: " << normalCake.calorie_intake() << endl;

    Dietary dietaryPerson;
    PersonalizedCake<Dietary> dietaryCake(dietaryPerson);
    cout << "Calorie Intake for Dietary Person: " << dietaryCake.calorie_intake() << endl;

    if (normalCake > dietaryCake) {
        cout << "Normal Person's cake has a higher calorie intake." << endl;
    } else {
        cout << "Dietary Person's cake has a higher calorie intake." << endl;
    }

    return 0;
}
