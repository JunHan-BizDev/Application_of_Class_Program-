//
//  Common.cpp
//  DataStr
//
//  Created by Jun on 2021/01/05.
//

#include "Common.hpp"

void printLectures(const vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits, const int& user) {

    
    cout.fill('-');
    cout.width(50);
    cout << " " << endl;
    cout.fill(' ');

    cout << "과목코드" << cout.width(8) << "강의명" << cout.width(10) << "학점"<< cout.width(5) << "수강가능인원" << endl;

    cout.fill('-');
    cout.width(50);
    cout << " " << endl;
    cout.fill(' ');

    if(user == -100){
        for(int num = 0; num < lectureCodes.size(); num++){
            cout << lectureCodes[num] << "\t" << lectureNames[num] << " \t\t" << lectureCredits[num] << "\t\t" << limits[num] << "\n";
        }
    }
    
    else{
        for(int col = 0; col < appliedLectureCodes[user].size(); col++){
            int position = findLectureByCode(lectureCodes, appliedLectureCodes[user][col]);
            
            cout << appliedLectureCodes[user][col] << "\t" << lectureNames[position] <<
            " \t\t" << lectureCredits[position] << "\t\t" << limits[position] << endl;
        }
    }
    
    cout.fill('-');
    cout.width(50);
    cout << " " << endl;
    cout.fill(' ');

}


int findStudentById(vector<string> studentIds, string id) {
    for (unsigned i = 0; i < studentIds.size(); i++) {
        if (studentIds[i] == id)
            return i;
    }
    return -1;
}

int findLectureByCode(vector<string> lectureCodes, string code) {
    for (unsigned i = 0; i < lectureCodes.size(); i++) {
        if (lectureCodes[i] == code)
            return i;
    }
    return -1;
}

void deleteElement(vector<string>& v, int index) {
    v.erase(v.begin() + index);
}

