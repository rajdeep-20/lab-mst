#include <iostream>
#include <cmath>
using namespace std;

void tower(int n, char source, char temp, char destination) {
    if (n == 0)
        return;

    tower(n - 1, source, destination, temp);
    cout << "\nMove disc " << n << " from " << source << " to " << destination;
    tower(n - 1, temp, source, destination);
}

int main() {
    int n;
    cout << "\nEnter the number of discs: \n";
    cin >> n;

    tower(n, 'A', 'B', 'C');

    cout << "\n\nTotal Number of moves are: " << static_cast<int>(std::pow(2, n) - 1) << endl;

    return 0;
}
