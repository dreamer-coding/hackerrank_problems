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
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <string>
#include <stdexcept>
#include <cstdint>

using namespace std;

enum {
    ERROR_CODE_VALUE = -2,
    ERROR_INVALID_ARG = -1
};

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int32_t diagonalDifference(const std::vector<std::vector<int32_t>>& arr) {
    try {
        size_t n = arr.size();
        if (n == 0 || arr[0].size() != n) {
            throw std::invalid_argument("Input matrix must be non-empty and square.");
        }

        int32_t sum1 = 0, sum2 = 0;

        // Calculate the first diagonal sum
        for (size_t row = 0; row < n; ++row) {
            sum1 += arr[row][row];
        }

        // Calculate the second diagonal sum
        for (size_t row = 0, col = n - 1; row < n; ++row, --col) {
            sum2 += arr[row][col];
        }

        return std::abs(sum1 - sum2);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
        return ERROR_INVALID_ARG;  // Return an error code
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // General error code
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = diagonalDifference(arr);

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
