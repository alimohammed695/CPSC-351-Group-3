#include <iostream>
using namespace std;

void print_hex(string a) {
    const double pi = 3.14569 * 2;
    cout << "TEST" << endl;
    cout << a << endl;
}

class Testa {
   public:
    int a;

   private:
    int b;
};

struct AnotherOne {
    int te;
};

int main() {
    bool val = true;

    if (val) {
        cout << "test" << endl;
    }

    cout << "test" << endl;
    print_hex("s");
    return 0;
}