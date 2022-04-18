#include <iostream>
#include <iterator> //ostream_iterator
#include <vector>
#include <algorithm>  //copy, sort
#include <functional> //greater
#include <cmath>      //abs

using namespace std;

bool compare(int i, int j)
{
    return (i > j);
}

struct compare_abs
{
    bool operator()(int i, int j)
    {
        return (abs(i) < abs(j));
    }
};

struct copy_condition
{
    int param;
    copy_condition(int arg) { param = arg; }
    bool operator()(int i)
    {
        return (i > param);
    }
};

int main()
{
    vector<int> v = {5, -1, 8, 4, -10};
    ostream_iterator<int> out_it(cout, " ");

    cout << "Spausdiname su copy algoritmu:\n";
    copy(v.begin(), v.end(), out_it); // Tai sioks toks triukas. Taip spausdinti nebutina
    cout << "\n";

    vector<int> v_test = v;
    cout << "Rusiuojame su sort:\n";
    sort(v_test.begin(), v_test.end());
    copy(v_test.begin(), v_test.end(), out_it);
    cout << "\n";

    v_test = v;
    cout << "Rusiuojame mazejimo tvarka su greater<int>:\n";
    sort(v_test.begin(), v_test.end(), greater<int>());
    copy(v_test.begin(), v_test.end(), out_it);
    cout << "\n";

    v_test = v;
    cout << "Rusiuojame mazejimo tvarka su savo funkcija\n";
    sort(v_test.begin(), v_test.end(), compare);
    copy(v_test.begin(), v_test.end(), out_it);
    cout << "\n";

    v_test = v;
    cout << "Rusiuojame pagal moduli su savo funktoriumi\n";
    sort(v_test.begin(), v_test.end(), compare_abs());
    copy(v_test.begin(), v_test.end(), out_it);
    cout << "\n";

    int a = 4;
    cout << "\nFunktoriaus su parametru veikimas \nSpausdiname su copy_if skaicius didesnius uz 4\n";
    copy_if(v_test.begin(), v_test.end(), out_it, copy_condition(a));
    cout << "\n";

    cout << "\nTa pati padarome su lambda funkcija\n";
    copy_if(v_test.begin(), v_test.end(), out_it, [a](int arg)
            { return arg > a; }); // Trumpiau?
    cout << "\n";

    return 0;
}