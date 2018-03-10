//
// Created by Rongjin Qiao on 3/8/18.
//

#include <iostream>
//#include <string>
#include <vector>
#include <bitset>
#include <typeinfo>

using namespace std;

class C {
public:
    int a;
    int b;

    C(int i, int j) : a(i), b(j) {}
};

class PInt {
public:
    int *a;

    explicit PInt(int aa) {
        std::cout << "Call int constructor " << this << endl;
        a = new int(aa);
    }

    PInt(const PInt &that) {
        std::cout << "Call copy constructor " << this << endl;
        a = new int(*that.a);
    }

    PInt(PInt &&that) {
        std::cout << "Call move constructor " << this << endl;
        a = that.a;
        that.a = nullptr;
    }

    PInt &operator=(PInt that) {
        std::cout << "Call assign " << this << endl;
        std::swap(a, that.a);
        return *this;
    }

    ~PInt() {
        std::cout << "destructor " << this << endl;
        if (a == nullptr) {
            std::cout << "null pointer\n";
        }
        delete a;
    }

    friend PInt add(const PInt &one, const PInt &two) {
        PInt res(*one.a + *two.a);
        return res;
    }
};

int logicalShift2(int x, int n) {
    int mask = (1 << (32 + (~n) + 1));
    cout << (32 + (~n) + 1) << " mask: \n" << bitset<32>(mask) << endl;
//    cout<<"x^mask: "<< bitset<32>(x ^ mask)<<endl;
    // x ^= mask;
//    int mask2 =
    return (x >> n) & (~((mask << (n - 1)) >> (n - 1)));
//    return ((((x ^ mask) >> n) | (mask>>n))&(~mask>>(n+(~1)+1)));
}

int logicalShift(int x, int n) {
    int mask = (1 << 31) & x;

    return ((((x ^ mask) >> n) | (mask >> n)) & (~((mask >> n) << 1)));
}

int getByte(int x, int n)
{
    int a = (n<<3);
    int mask = (0xff) << a;
//    cout<<(x&mask)<<endl;

    return (x&mask)>>a;
}

int main() {
//    int a = -8;
//    int b = 9;
//    int c = a & b;
//    int d = ~((~a) | (~b));
//    cout << a << endl;
//    cout << c << " " << d << endl;
//    cout << sizeof(a) << endl;
//
//
//    vector<string> vs = {"first", "second", "third"};
//
//    for (const auto &s : vs) {
//        cout << s << endl;
//    }
//
//    C c2{1, 0}; //C++11 only. Equivalent to: C c(0,0);
//    cout << c2.a << endl;
//
//    int* p = nullptr;
//    delete [] p;
//    cout<<p<<endl;


//    PInt a(1), b(2);
////    a = b;
////    a = b;
//    PInt c = add(a,b);
//    cout << "a " << *(a.a) << endl;
//    cout << "b " << *(b.a) << endl;
//    cout << "c " << *(c.a) << endl;

//    delete a,b;
    int n = 1;
//    cout<<(32+~n+1)<<endl;
//    std::cout << typeid(1).name() << '\n';
//    int mask = 0x03 << (32 + 1 + ~n);
//    cout << hex << mask << endl;
//    cout << "after: \n" << hex << (mask << (-1)) << endl;

    int mask = 0x01 << (32 + 1 + ~n);
    mask = mask + ~0;
    cout<<hex<<mask<<endl;

    cout<<"-------\n";

    int a = 0xc0000100;
    int b = logicalShift(a, 1);
    cout << std::bitset<32>(a) << endl << std::bitset<32>(b) << endl;


    cout<<"-------\n";


    a = 0x12345678;
    cout<<a<<endl;
    cout<<getByte(a,2)<<endl;
}
