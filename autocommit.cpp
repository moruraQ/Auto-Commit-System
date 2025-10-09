/*
* Github Auto Commit System
* 2025-10-09
*Change commit log -> write commit log
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

// return KST time
string get_current_timestamp_kst() {
    // system time
    auto now = chrono::system_clock::now();
    // change UTC -> KST
    auto kst_time = now + chrono::hours(9);
    // type transform
    auto in_time_t = chrono::system_clock::to_time_t(kst_time);

    stringstream ss;
    ss << put_time(gmtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

int main() {
    const string target_file = "AUTO_COMMIT_LOG.md";

    // file check
    bool file_exists = false;
    {
        ifstream infile(target_file);
        if (infile.good()) {
            file_exists = true;
        }
    }

    // open file
    ofstream outfile(target_file, ios::app);

    // file open fails
    if (!outfile.is_open()) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1; // error
    }

    // new file
    if (!file_exists) {
        outfile << "# Auto Commit Log\n\n";
    }

    // add log
    string timestamp = get_current_timestamp_kst();
    string new_log_entry = "- It is automated commit. Not changed. Timestamp: " + timestamp + " KST\n";
    outfile << new_log_entry;

    // close file
    outfile.close();

    cout << "Successfully appended log to " << target_file << endl;

    return 0;
}


