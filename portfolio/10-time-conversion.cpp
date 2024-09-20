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
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>  // For exception handling

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(const string& s) {
    try {
        if (s.size() != 10 || (s.substr(8, 2) != "AM" && s.substr(8, 2) != "PM")) {
            throw std::invalid_argument("Invalid time format.");
        }

        string ans;
        string hour_str = s.substr(0, 2);
        string period = s.substr(8, 2);

        if (period == "AM") {
            if (hour_str == "12") {
                ans = "00";  // Convert "12 AM" to "00"
            } else {
                ans = hour_str;  // Keep the hour as it is
            }
        } else if (period == "PM") {
            if (hour_str == "12") {
                ans = "12";  // Keep "12 PM" as "12"
            } else {
                int hour = stoi(hour_str);  // Convert to int and add 12 for PM
                hour += 12;
                ans = to_string(hour);
            }
        }

        ans += s.substr(2, 6);  // Append the rest of the time (minutes and seconds)

        return ans;

    } catch (const std::invalid_argument& e) {
        cerr << "Invalid argument error: " << e.what() << endl;
        return "";
    } catch (const std::exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
        return "";
    }
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
