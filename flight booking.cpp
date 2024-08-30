#include <iostream>
#include <vector>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> seats(n + 1, 0);
    for (auto& booking : bookings) {
        seats[booking[0] - 1] += booking[2];
        seats[booking[1]] -= booking[2];
    }

    for (int i = 1; i < n; ++i) {
        seats[i] += seats[i - 1];
    }

    seats.pop_back();
    return seats;
}

int main() {
    vector<vector<int>> bookings1 = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    vector<int> result1 = corpFlightBookings(bookings1, 5);
    for (int seats : result1) {
        cout << seats << " "; // Output: 10 55 45 25 25
    }
    cout << endl;

    vector<vector<int>> bookings2 = {{1, 2, 10}, {2, 2, 15}};
    vector<int> result2 = corpFlightBookings(bookings2, 2);
    for (int seats : result2) {
        cout << seats << " "; // Output: 10 25
    }
    cout << endl;

    return 0;
}
