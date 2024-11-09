
// include external libraries @top of files
#include <complex>
#include <iostream>
#include <stdexcept>
#include <string>
#include <variant>
#include <vector>
//declare namespaces to be used throughout here
using namespace std;
// define / declar functions or global variables before main
double square(double x) {
    return x * x;
}


void printSquare(double x) {
    cout << "the square of" << x << "is" << square(x) << "\n";
}
struct Node {
    Node *next; // or `left` and `right` if in a binary tree
};
enum Type { ptr, num };

//class after enum enforses strongly typed scope
enum class Color { red, blue, green };


struct EntryBasic {
    string name;
    Type t;
    Node *p;
    int i;
};

void efb(EntryBasic *pe) {
    if (pe->t == num) {
        cout << pe->i;
    }
}
//p and i arent used at the same time
union Value {
    Node *p;
    int i;
};
struct EntryUnion {
    string name;
    Type t;
    Value v;
};
void efu(EntryUnion *pe) {
    if (pe->t == num) {
        cout << pe->v.i;
    }
}
//draw back no correspondecnt between type field

//varient
struct EntryVarient {
    string name;
    variant<Node *, int> v;
};


void efv(EntryVarient *pe) {
    if (holds_alternative<int>(pe->v)) {
        cout << get<int>(pe->v);
    }
}

void errorHandler(double x) {
    try {
        //something
    } catch (out_of_range &err) {
        cerr << err.what() << "\n";
    }
}
// define program instructions here
int main() {
    cout << "Hello, World!\n";
    printSquare(1.2334);
    int x = -5;
    int y = 6;

    cout << "x + y\n";
    cout << x + y << endl;
    cout << "++x\n";
    cout << +x << endl;
    cout << "x - y\n";
    cout << x - y << endl;
    cout << "-y\n";
    cout << -y << endl;
    cout << "x * y\n";
    cout << x * y << endl;
    cout << "x / y\n";
    cout << x / y << endl;
    cout << "x % y\n";
    cout << x % y << endl;
    cout << "x == y\n";
    cout << (x == y) << endl;
    cout << "x != y\n";
    cout << (x != y) << endl;
    cout << "x < y\n";
    cout << (x < y) << endl;
    cout << "x > y\n";
    cout << (x > y) << endl;
    cout << "x <= y\n";
    cout << (x <= y) << endl;
    cout << "x >= y\n";
    cout << (x >= y) << endl;
    cout << "x & y\n";
    cout << (x & y) << endl;
    cout << "x | y\n";
    cout << (x | y) << endl;
    cout << "x ^ y\n";
    cout << (x ^ y) << endl;
    cout << "~x\n";
    cout << (~x) << endl;
    cout << "x && y\n";
    cout << (x && y) << endl;
    cout << "x || y\n";
    cout << (x || y) << endl;
    cout << "!x\n";
    cout << (!x) << endl;

    x += y;
    ++x;
    x -= y;
    --x;
    x *= y;
    x /= y;
    x %= y;

    double d1 = 2.3;
    double d2{2.3};
    double d3{2.3};

    complex<double> z = 1; //complex with double percision floating point scalars
    complex<double> z2{d1, d2};
    complex<double> z3{d1, d3};

    //int i2{7.8} will throw floating point errorc
    int i1 = 7.8; // will assing to 7;cbbb

    const int c = 7;       // mainly used to pass in unmodifiable params;calculated at run time
    constexpr int cxr = 7; //mainly used to allow data to be placed in read-only-memory calculated by compliler


    char v[6]; // defines cahr arra of 6 character
    char *p;   // points to a char location

    char x = *p; //asinged what p pointed location value is

    double *ull = nullptr;
}
