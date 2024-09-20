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
#include <algorithm>
#include <stdexcept>
#include <iomanip>  // For setting precision
#include <cstdint>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(std::vector<int>& arr) {
    try {
        uint64_t n;
        std::cin >> n;

        if (n != arr.size()) {
            throw std::invalid_argument("Input size does not match the array size.");
        }

        for (auto iter = 0U; iter < arr.size(); ++iter) {
            std::cin >> arr[iter];
        }

        double fr1 = 0.0, fr2 = 0.0, fr3 = 0.0;

        for (auto iter = 0U; iter < arr.size(); ++iter) {
            if (arr[iter] > 0) {
                fr1++;
            } else if (arr[iter] < 0) {
                fr2++;
            } else {
                fr3++;
            }
        }

        std::cout << std::fixed << std::setprecision(6);
        std::cout << (fr1 / arr.size()) << std::endl;
        std::cout << (fr2 / arr.size()) << std::endl;
        std::cout << (fr3 / arr.size()) << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

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
