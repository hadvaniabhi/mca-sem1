//Design a manipulator to provide the following output specifications for
//printing float values
//
//(i) 5 column width
//(ii) Right justified
//(iii) 2 digits precision
//(iv) Filling unused spaces with +

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float n = 12.345;

    cout << setfill('+')
         << setw(5)
         << right
         << fixed
         << setprecision(2)
         << n << endl;

    return 0;
}

