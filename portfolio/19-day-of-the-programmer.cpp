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
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    try {
        // Check for a valid year
        if (year <= 0) {
            throw invalid_argument("Year must be a positive integer.");
        }

        string date;

        if (year == 1918) {
            // Special case for the year of the calendar transition
            date = "26.09.1918";
        } else if ((year < 1918 && year % 4 == 0) ||    // Julian calendar leap year
                   (year > 1918 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))) {
            // Leap year case for both Julian (before 1918) and Gregorian (after 1918)
            date = "12.09." + to_string(year);
        } else {
            // Regular year
            date = "13.09." + to_string(year);
        }

        return date;

    } catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
        return "ERROR: Invalid Year";  // Return an error string for invalid input
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return "ERROR: General Exception";  // Return a general error string for other exceptions
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
