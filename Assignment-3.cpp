#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

void readData(string fileName, int size, string passwords[]) {
    ifstream file(fileName);

    // Check if the file opened successfully
    if (!file.is_open()) {
        cout << "Error: Unable to open file '" << fileName << "'" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        string line;
        if (getline(file, line)) { // Read a line
            passwords[i] = line;
        } 
    }
    file.close(); // Close the file
}


// Checks password if it has uppercase, lowercase, digit, and special characters
bool isValidPassword(string password) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (int i = 0; i < password.length(); i++) {
        char ch = password[i];

        if (isupper(ch)) {
            hasUpper = true;
        } else if (islower(ch)) {
            hasLower = true;
        } else if (isdigit(ch)) {
            hasDigit = true;
        } else {
            hasSpecial = true;
        }
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Function to write valid passwords to a new file
void writeData(string fileName, string passwords[], int size) {
    ofstream file(fileName);
    if (file.is_open()) {
        int validCount = 0;
        for (int i = 0; i < size; i++) {
            if (isValidPassword(passwords[i])) { // Check for valid passwords
                file << passwords[i] << endl;
                validCount++;
                if (validCount == 25) {
                    break;
                }
            }
        }
    }
    file.close();
}

int main() {
    int size = 50;
    string passwords[size];

    // Calling readData function
    readData("passwords.txt", size, passwords);

    // Calling writeData function
    writeData("valid_passwords.txt", passwords, size);
    
    cout << "Valid passwords have been stored in valid_passwords.txt" << endl;
}
