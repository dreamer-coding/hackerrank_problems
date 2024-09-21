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
#include <string>
#include <cstdint>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <limits>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

enum {
    ERROR_CODE_VALUE = -1
};

/*
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */
int32_t simpleArraySum(std::vector<int32_t> ar) {
    try {
        int32_t sum = 0;

        for (auto iter : ar) {
            // Check for integer overflow before adding
            if (sum > (std::numeric_limits<int32_t>::max() - iter)) {
                throw std::overflow_error("Integer overflow detected during summation.");
            }
            sum += iter;
        }

        return sum;
    } catch (const std::overflow_error& e) {
        std::cerr << "Overflow error: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Return an error code for overflow
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return ERROR_CODE_VALUE;  // Return a general error code
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);

    int32_t ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int32_t> ar(ar_count);

    for (int32_t i = 0; i < ar_count; i++) {
        int32_t ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int32_t result = simpleArraySum(ar);

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
