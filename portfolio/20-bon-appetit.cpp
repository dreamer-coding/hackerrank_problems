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
#include <string>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <stdexcept>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bonAppetit' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY bill
 *  2. INTEGER k
 *  3. INTEGER b
 */

void bonAppetit(vector<int32_t> bill, int32_t k, int32_t b) {
    try {
        // Check if the bill array is empty
        if (bill.empty()) {
            throw invalid_argument("Input array must not be empty.");
        }
        
        // Check if 'k' is within valid bounds
        if (k < 0 || k >= bill.size()) {
            throw out_of_range("Invalid item index.");
        }

        // Erase the item Anna didn't eat
        bill.erase(bill.begin() + k);
        
        // Calculate the fair share
        int32_t totalCost = 0;
        for (const auto& item : bill) {
            totalCost += item;
        }
        int32_t annaShare = totalCost / 2;

        // Check if Brian overcharged Anna
        if (annaShare == b) {
            cout << "Bon Appetit" << endl;
        } else {
            cout << (b - annaShare) << endl;  // Amount that Brian overcharged
        }

    } catch (const invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Out of range error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
}

int main() {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string bill_temp_temp;
    getline(cin, bill_temp_temp);

    vector<string> bill_temp = split(rtrim(bill_temp_temp));

    vector<int> bill(n);

    for (int i = 0; i < n; i++) {
        int bill_item = stoi(bill_temp[i]);

        bill[i] = bill_item;
    }

    string b_temp;
    getline(cin, b_temp);

    int b = stoi(ltrim(rtrim(b_temp)));

    bonAppetit(bill, k, b);

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
