#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int countEqualSubstrings(string S) {
    unordered_map<int, int> prefixCount;
    int balance = 0;
    int count = 0;
    prefixCount[0] = 1;
    for (char c : S) {
        if (c == '1') {
            balance += 1;
        } else {
            balance -= 1;
        }
        if (prefixCount.find(balance) != prefixCount.end()) {
            count += prefixCount[balance];
        }
        prefixCount[balance]++;
    }
    return count;
}

int main() {
    string S;
    cin >> S;
    cout << countEqualSubstrings(S) << endl;
    return 0;
}
