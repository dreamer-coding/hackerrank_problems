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
#include <algorithm>
#include <stdexcept>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

enum {
    ERROR_CODE_VALUE = -1
};

/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */

int32_t divisibleSumPairs(int32_t n, int32_t k, vector<int32_t> ar) {
    try {
        if (ar.empty()) {
            throw std::invalid_argument("Input array must be non-empty.");
        }
        int32_t ways = 0;

        // Check all unique pairs
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((ar[i] + ar[j]) % k == 0) {
                    ++ways;
                }
            }
        }

        return ways;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Return an error code for invalid argument
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Return a general error code
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = divisibleSumPairs(n, k, ar);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
