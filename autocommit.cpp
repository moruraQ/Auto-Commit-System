/*
* Github Auto Commit System
* 2025-10-04
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

// return time
string get_current_timestamp_kst() {
    // time
    auto now = chrono::system_clock::now();
    // UTC -> KST
    auto kst_time = now + chrono::hours(9);
    //type transform
    auto in_time_t = chrono::system_clock::to_time_t(kst_time);

    stringstream ss;
    ss << put_time(gmtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

int main() {
    const string target_file = "AUTO_COMMIT_LOG.md";

    string timestamp = get_current_timestamp_kst();

    // content
    string content = "it is auto commit system. not changed\n";
    content += "Timestamp: " + timestamp + " KST\n";

    // open file and write content
    try {
        ofstream outfile(target_file);
        outfile << "# Auto Commit Log\n\n";
        outfile << content;
        outfile.close();

        cout << "Successfully wrote log to " << target_file << endl;
    }
    catch (const exception& e) {
        cerr << "Error writing to file: " << e.what() << endl;
        return 1; // error
    }

    return 0;
}