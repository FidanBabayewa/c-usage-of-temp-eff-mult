#include <iostream>
#include <string>

using namespace std;

// Language traits
class Hun {
public:
    static string name() {
        return "Hungarian";
    }
};

class Eng {
public:
    static string name() {
        return "English";
    }
};

// Operating System traits
class Android {
public:
    static string name() {
        return "Android";
    }
};

class iOS {
public:
    static string name() {
        return "iOS";
    }
};

// Configuration traits
template <class OS, class Language>
class mobile_config {
public:
    typedef OS os_type;
    typedef Language language_type;
};

// Specializations for Samsung and iPhone
template <>
class mobile_config<Android, Hun> {
public:
    static string os() {
        return Android::name();
    }

    static string language() {
        return Hun::name();
    }
};

template <>
class mobile_config<iOS, Eng> {
public:
    static string os() {
        return iOS::name();
    }

    static string language() {
        return Eng::name();
    }
};
// Mobile template class
template <class Brand, class Config = mobile_config<Android, Hun>, unsigned int Version = 10>
class Mobile {
private:
    string name;
public:
    Mobile(const string& n, unsigned int version = Version) : name(n) {
        // Any data member without a default constructor must be initialized in the constructor initialization list
    }

    friend ostream& operator<<(ostream& os, const Mobile& mobile) {
        os << mobile.name << " (" << Brand::name() << ", " << Config::os() << " v" << Version << ", " << Config::language() << ")";
        return os;
    }

    string get_os() const {
        return Config::os();
    }
};

// Samsung and iPhone classes
class Samsung {
public:
    static string name() {
        return "Samsung";
    }
};

class iPhone {
public:
    static string name() {
        return "iPhone";
    }
};

int main() {
    // Example usage
    Mobile<Samsung> samsungPhone("Galaxy S21", 12);
    Mobile<iPhone, mobile_config<iOS, Eng>> iphone("iPhone 13");

    cout << samsungPhone << endl;
    cout << iphone << endl;

    cout << "Operating System of Samsung Phone: " << samsungPhone.get_os() << endl;

    return 0;
}

