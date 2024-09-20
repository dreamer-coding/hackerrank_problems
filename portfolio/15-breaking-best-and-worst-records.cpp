/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>  // For exception handling
#include <cstdint>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */

vector<int32_t> breakingRecords(const vector<int32_t>& scores) {
    try {
        if (scores.empty()) {
            throw invalid_argument("The scores array must not be empty.");
        }

        int32_t maxScore = scores[0];
        int32_t minScore = scores[0];
        int32_t maxCounter = 0;
        int32_t minCounter = 0;
        vector<int32_t> results;

        // Iterate over the scores to count max and
        // min record breaks
        for (const auto& iter : scores) {
            if (iter > maxScore) {
                maxScore = iter;
                ++maxCounter;
            } else if (iter < minScore) {
                minScore = iter;
                ++minCounter;
            }
        }

        // Store results in the results vector
        results.push_back(maxCounter);
        results.push_back(minCounter);

        return results;

    } catch (const invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << endl;
        return {}; // Return an empty vector in case of an exception
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return {}; // Return an empty vector in case of an exception
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split(rtrim(scores_temp_temp));

    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    vector<int> result = breakingRecords(scores);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
