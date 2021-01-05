#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "IO.hpp"
#include "Login.hpp"
#include "Common.hpp"
#include "Admin.hpp"
#include "User.hpp"
using namespace std;

int main() {
    int user = -1; //user index
    int status = -1;

    // Student Info
    vector<string> studentIds;
    vector<string> passwords;
    vector<string> names;
    vector<int> credits;
    vector<vector<string>> appliedLectureCodes;

    // Lecture Info
    vector<string> lectureCodes;
    vector<string> lectureNames;
    vector<int> lectureCredits;
    vector<int> limits;
    // Read from files
    
    readStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
    readLectureFile(lectureCodes, lectureNames, lectureCredits, limits);
    // Login phase
    while (status == -1) {
        user = login(studentIds, passwords);

        if (user == -999) { // Login fail
            break;
        }
        else if (user == -1) { // Exit command
            break;
        }
        else if (user == -100) { // Admin login success
            status = runAdmin(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
        }
        else { // Student login success
            status = runStudent(studentIds, passwords, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
        }
    }

    // Write to files
    writeStudentFile(studentIds, passwords, names, credits, appliedLectureCodes);
    writeLectureFile(lectureCodes, lectureNames, lectureCredits, limits);

    return 0;
}
