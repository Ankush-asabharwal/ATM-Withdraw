#include<iostream>

using namespace std;

int notes[] = {5, 5, 5, 5, 5};
int totalBalance = 50000;

void note(int amountRequired) {
    int d[] = {500, 200, 100, 20, 10};
    int r = amountRequired;
    for (int i = 0; i < 5; i++) {
        int notesRemoved = min(r / d[i], notes[i]);
        notes[i] = notes[i] - notesRemoved;
        r -= notesRemoved * d[i];
        cout << d[i] << " x " << notes[i] << endl;
    }
    if (r == 0) {
        totalBalance -= amountRequired;
        cout << "Withdrawal Successfully" << endl;
    } else {
        cout << "Insufficient Notes" << endl;
    }
}

void withdrawl(int &totalBalance, int aR) {
    if (aR % 100 != 0) {
        cout << "Enter the amount which is multiple of 100" << endl;
    } else {
        if (aR > totalBalance) {
            cout << "Insufficient Balance" << endl;
        } else {
            note(aR);
        }
    }
}

bool notesAvailable() {
    for (int i = 0; i < 5; i++) {
        if (notes[i] > 0) return true;
    }
    return false;
}

int main() {
    int amountRequired;
    while (notesAvailable()) {
        cout << "How much you want to withdraw?" << endl;
        cin >> amountRequired;

        if (amountRequired == 0) {
            cout << "Exiting..." << endl;
            break;
        }

        withdrawl(totalBalance, amountRequired);
        cout << "Balance remaining: " << totalBalance << endl;
    }
    cout << "No notes available for further withdrawal or user exited." << endl;
    return 0;
}
