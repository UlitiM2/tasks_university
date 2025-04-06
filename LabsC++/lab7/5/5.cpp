#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<string, int, double> Tuple;
typedef tuple<string, double> SecTuple;

void printTupleOfThree(Tuple t) {
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ", "
        << get<2>(t) << ")" << endl;
}


Tuple funtup(string s, int a, double d) {
    s.append("!");
    return make_tuple(s, a, d * 10);
}

Tuple exFunc1(Tuple t) {
    get<0>(t).append("!!!!????@@@@");
    get<1>(t) *= 234;
    get<2>(t) += 12345.6789;
    return t;
}

SecTuple exFunc2(Tuple t) {
    Tuple resT = exFunc1(t);
    string s = get<0>(resT);
    double num = (double)get<1>(resT);
    num *= get<2>(resT);
    return make_tuple(s, num);
}

void printSecTupleOfThree(SecTuple t) {
    cout << "("
        << get<0>(t) << ", "
        << get<1>(t) << ")" << endl;
}

int main()
{
    system("chcp 1251");
    vector<string> v1{ "one", "two", "three", "four", "five", "six" };
    vector<int> v2 = { 1, 2, 3, 4, 5, 6 };
    vector<double> v3 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };

    auto t0 = make_tuple(v1[2], v2[0], v3[0]);
    auto t1 = funtup(v1[1], v2[1], v3[1]);
    printTupleOfThree(t0);
    printTupleOfThree(t1);
    auto t2 = exFunc1(t0);
    printTupleOfThree(t2);
    SecTuple t3 = exFunc2(t2);
    printSecTupleOfThree(t3);
    return 0;
}


