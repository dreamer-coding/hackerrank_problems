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
#include <map>
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
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    try {
        if (arr.empty()) {
            throw std::invalid_argument("Input array must be non-empty.");
        }
        // Map of bird types along with migratory score (bird type range is 1-5)
        std::map<int32_t, int32_t> results = {
            {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}
        };

        // First, count each bird type
        for (int bird : arr) {
            results[bird]++;
        }

        // We look at the results and select the bird type with the highest frequency
        int32_t mostFrequentBird = 1;
        int32_t maxCount = results[1];

        for (const auto& entry : results) {
            int32_t birdType = entry.first;
            int32_t count = entry.second;

            if (count > maxCount) {
                maxCount = count;
                mostFrequentBird = birdType;
            } else if (count == maxCount && birdType < mostFrequentBird) {
                mostFrequentBird = birdType;  // Return the smallest bird type in case of a tie
            }
        }

        return mostFrequentBird;
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

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

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
