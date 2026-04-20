#include <iostream>
using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;
	
    long long count = (R + 1) / 2 - L / 2;
    cout << (count % 2 == 0 ? "even" : "odd");
    return 0;
}
