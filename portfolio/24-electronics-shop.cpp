/**
 * ==============================================================================
 * Author: Michael Gene Brockus (Dreamer)
 * Email: michaelbrockus@gmail.com
 * Organization: Fossil Logic
 * Description: 
 *     This file is part of the Fossil Logic project, where innovation meets
 *     excellence in software development. Michael Gene Brockus, also known as
 *     "Dreamer," is a dedicated contributor to this project. For any inquiries,
 *     feel free to contact Michael at michaelbrockus@gmail.com.
 * ==============================================================================
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stdexcept>

using namespace std;

vector<string> split_string(string);

enum {
    ERROR_CODE_VALUE = -1
};

/*
 * Complete the getMoneySpent function below.
 */
int32_t getMoneySpent(vector<int32_t> keyboards, vector<int32_t> drives, int32_t b) {
    try {
        // Validate inputs
        if (b < 0) {
            throw invalid_argument("Budget cannot be negative.");
        }
        if (keyboards.empty() || drives.empty()) {
            throw invalid_argument("Input arrays must not be empty.");
        }

        int32_t maxSpent = -1;  // Initialize to -1 to indicate no valid purchase

        // Try every combination of keyboard and drive
        for (int32_t k : keyboards) {
            for (int32_t d : drives) {
                int32_t totalCost = k + d;
                // If the total cost is within the budget and greater than the current maxSpent, update maxSpent
                if (totalCost <= b && totalCost > maxSpent) {
                    maxSpent = totalCost;
                }
            }
        }

        return maxSpent;  // If no combination was found within budget, return -1

    } catch (const invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << endl;
        return ERROR_CODE_VALUE;  // Return error code for invalid argument
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return ERROR_CODE_VALUE;  // General error code
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string bnm_temp;
    getline(cin, bnm_temp);

    vector<string> bnm = split_string(bnm_temp);

    int b = stoi(bnm[0]);

    int n = stoi(bnm[1]);

    int m = stoi(bnm[2]);

    string keyboards_temp_temp;
    getline(cin, keyboards_temp_temp);

    vector<string> keyboards_temp = split_string(keyboards_temp_temp);

    vector<int> keyboards(n);

    for (int keyboards_itr = 0; keyboards_itr < n; keyboards_itr++) {
        int keyboards_item = stoi(keyboards_temp[keyboards_itr]);

        keyboards[keyboards_itr] = keyboards_item;
    }

    string drives_temp_temp;
    getline(cin, drives_temp_temp);

    vector<string> drives_temp = split_string(drives_temp_temp);

    vector<int> drives(m);

    for (int drives_itr = 0; drives_itr < m; drives_itr++) {
        int drives_item = stoi(drives_temp[drives_itr]);

        drives[drives_itr] = drives_item;
    }

    /*
     * The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
     */

    int moneySpent = getMoneySpent(keyboards, drives, b);

    fout << moneySpent << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
