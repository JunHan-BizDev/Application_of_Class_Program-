
#include "User.hpp"
#include "Common.hpp"

void printStudent(const vector<string>& studentIds, const vector<string>& names, const vector<int>& credits, const int& user) {

    cout.fill('-');
     cout.width(50);
     cout << " " << endl;
     cout.fill(' ');

    cout << "학번: " << studentIds[user] << "\t\t\t이름: " << names[user] << "\t\t수강가능학점: " << credits[user] <<"\n";
    
    cout.fill('-');
    cout.width(50);
    cout << " " << endl;
    cout.fill(' ');
}

void applyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {

    string StuLecCode;
    bool VerifyApply = false;

    while(1){
        printStudent(studentIds, names, credits, user);
        printLectures(appliedLectureCodes,lectureCodes,lectureNames,lectureCredits,limits);

        cout << "신청할 과목 코드(0: 뒤로가기) >>";
        cin >> StuLecCode;

        int position = findLectureByCode(lectureCodes, StuLecCode);
        if( StuLecCode == "0"){
            break;
        }
        if(VerifyApply == false){
            if(limits.at(position) == 0){
                cout << "수강정원이 꽉 찼습니다." << endl;
                system("pause");
                continue;
            }
            else if(credits[user] < lectureCredits[position]){
                cout << "수강가능학점이 부족합니다." << endl;
                system("pause");
                continue;
            }
            else if(appliedLectureCodes[user].size() == 0){
                appliedLectureCodes[user].push_back(StuLecCode);
                limits.at(position)--;
                credits.at(user) -= lectureCredits.at(position);
                
                cout << "[" << StuLecCode << "] " << lectureNames.at(findLectureByCode(lectureCodes, StuLecCode)) << "(을)를 성공적으로 신청하였습니다." << endl;
                VerifyApply = false;
                system("pause");
                continue;

            }
            for(int i = 0;  i < appliedLectureCodes[user].size(); i++){

                 if(StuLecCode == appliedLectureCodes[user][i]){
                    cout << "이미 해당 과목을 신청했습니다." << endl;
                    system("pause");
                    break;
                }
                else if(lectureNames.at(position) == lectureNames.at(findLectureByCode(lectureCodes,appliedLectureCodes[user][i] ))){
                    cout << "이미 동일명의 과목을 신청했습니다." << endl;
                    system("pause");
                    break;
                }
                else if( i == appliedLectureCodes[user].size()-1 ){
                    appliedLectureCodes[user].push_back(StuLecCode);
                    limits.at(position)--;
                    credits.at(user) -= lectureCredits.at(position);
                    
                    cout << "[" << StuLecCode << "] " << lectureNames.at(findLectureByCode(lectureCodes, StuLecCode)) << "(을)를 성공적으로 신청하였습니다." << endl;
                    VerifyApply = false;
                    system("pause");
                    break;
                }
            }
        }
    }
}


void disapplyLecture(const vector<string>& studentIds, const vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, vector<int>& limits, const int& user) {
    
    string disapplycode;
    
    while(1){
        printStudent(studentIds, names, credits, user);
        printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
        
        cout << "철회할 과목 코드(0: 뒤로가기) >>";
        cin >> disapplycode;
        
        if(disapplycode == "0"){
            break;
        }
        
        for(unsigned i = 0; i < appliedLectureCodes[user].size(); i++){
            if(disapplycode == appliedLectureCodes[user][i]){
                
                deleteElement(appliedLectureCodes[user], i);
                credits.at(user) += lectureCredits.at(findLectureByCode(lectureCodes, disapplycode));
                limits.at(findLectureByCode(lectureCodes, disapplycode))++;
                
                cout << "[" << disapplycode << "] " << lectureNames.at(findLectureByCode(lectureCodes, disapplycode)) << " (을)를 철회하였습니다. \n";
                                
                system("pause");
                break;
                
            }
            else if(i == appliedLectureCodes[user].size()-1){
                cout << "과목 코드가 올바르지 않습니다." << endl;
                system("pause");
                break;
            }
        }
    }
}

void changePassword(vector<string>& passwords, const int& user) {
    string tempPW;
    
    cout.fill('-');
    cout.width(42);
    cout << " " << endl;
    cout.fill(' ');

    cout << "\n본인 확인을 위해 비밀번호를 한 번 더 입력해주세요.\n비밀번호: ";
    cin >> tempPW;
    
    cout.fill('-');
    cout.width(42);
    cout << " " << endl;
    cout.fill(' ');

    if(tempPW == passwords[user]){
        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

        cout << "새로 설정할 비밀번호를 입력하세요.\n비밀번호: ";
        cin >> tempPW;
        passwords[user] = tempPW;
        cout << "변경되었습니다.\n";
        
        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

        system("pause");
    }
    else{
        cout << "비밀번호가 일치하지 않습니다.\n";
        system("pause");
    }
}

int runStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, int user) {

    unsigned short num;
    
    while(1){
        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

        cout << "1. 수강 신청\n" << "2. 수강 현황\n" << "3. 수강 철회\n" << "4. 비밀번호 변경\n" << "5. 로그아웃\n" << "0. 종료\n";

        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

        cout << ">>";
        cin >> num;

        switch(num){
            case 1:
                applyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
                break;
            case 2:
                printStudent(studentIds, names, credits, user);
                printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
                system("pause");
                break;

            case 3:
                disapplyLecture(studentIds, names, credits, appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits, user);
                break;

            case 4:
                changePassword(passwords, user);
                break;

            case 5:
                return -1;
                break;

            case 0:
                return 1;
                break;

                }
        
    }
    return -1;

}

