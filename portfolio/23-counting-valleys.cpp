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
#include <cstdint>
#include <algorithm>
#include <string>
#include <stdexcept>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

enum {
    ERROR_CODE_VALUE = -1
};

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int32_t countingValleys(int32_t steps, string path) {
    try {
        if (steps < 0) {
            throw invalid_argument("Number of steps cannot be negative.");
        }

        if (path.empty()) {
            throw invalid_argument("Path cannot be empty.");
        }

        if (path.length() != steps) {
            throw invalid_argument("The length of the path string must match the number of steps.");
        }

        // Initialize variables
        int32_t seaLevel = 0;
        int32_t valleys = 0;
        bool inValley = false;

        for (char step : path) {
            if (step == 'U') {
                seaLevel++;
            } else if (step == 'D') {
                seaLevel--;
            } else {
                throw invalid_argument("Path must only contain 'U' (uphill) and 'D' (downhill) steps.");
            }

            // If the hiker goes below sea level and enters a valley
            if (seaLevel < 0 && !inValley) {
                valleys++;
                inValley = true;
            }

            // If the hiker comes back to sea level, they leave the valley
            if (seaLevel >= 0 && inValley) {
                inValley = false;
            }
        }

        return valleys;

    } catch (const invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << endl;
        return ERROR_CODE_VALUE;  // Error code for invalid input
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return ERROR_CODE_VALUE;  // General error code
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
