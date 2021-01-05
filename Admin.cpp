//
//  Admin.cpp
//  DataStr
//
//  Created by Jun on 2021/01/05.
//

#include "Admin.hpp"
#include "Common.hpp"

void addStudent(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
    
    string inputId, inputPassword, inputName;
    vector<string> newvec;
    bool VerifyId = true;
   
    while(1){
        
    cout.fill('-');
    cout.width(30);
    cout << " " << endl;
    cout.fill(' ');

    cout << "학번: ";
    cin >> inputId;
    cout << "비밀번호: ";
    cin >> inputPassword;
    cout << "학생 이름: ";
    cin >> inputName;
    
    cout.fill('-');
    cout.width(30);
    cout << " " << endl;
    cout.fill(' ');

    for(unsigned i = 0; i < studentIds.size(); i++){
            if(studentIds[i] == inputId){
                VerifyId = false;
            }
        }
    
    if(VerifyId == false){
        cout << "이미 존재하는 학번입니다.\n";
        system("pause");
        VerifyId = true;
        }
        
    else{
    studentIds.push_back(inputId);
    passwords.push_back(inputPassword);
    names.push_back(inputName);
    credits.push_back(18);
    appliedLectureCodes.push_back(newvec);
    
    cout << "성공적으로 등록되었습니다.\n";
    system("pause");
        break;
    }
    }
}


void addLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {

    string inputCode, inputName;
    int inputCredit, inputLimit;
    bool VerifyLec = true;
    
    while(1){
        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

        cout <<"과목코드: ";
        cin >> inputCode;
        cout <<"과목명: ";
        cin >> inputName;
        cout <<"학점: ";
        cin >> inputCredit;
        cout <<"수강인원: ";
        cin >> inputLimit;
        
        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

    
        for(unsigned i = 0; i < lectureCodes.size(); i++){
            if(lectureCodes[i] == inputCode){
            VerifyLec = false;
            }
        }
        if(VerifyLec == false){
            cout << "이미 존재하는 과목코드 입니다.\n";
            system("pause");
            VerifyLec = true;
        }
        else{
            lectureCodes.push_back(inputCode);
            lectureNames.push_back(inputName);
            lectureCredits.push_back(inputCredit);
            limits.push_back(inputLimit);
    
            cout << "성공적으로 강의가 개설되었습니다.\n";
            system("pause");
            break;
        }

    }
}

void deleteLecture(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {
    
    string code4delete;
    bool VerifyCode = false;
    int position;
    
    while(1){
        printLectures(appliedLectureCodes, lectureCodes, lectureNames, lectureCredits, limits);
        
        cout << "삭제할 강의 코드 (0: 뒤로가기) >> ";
        cin >> code4delete;
        
        if(code4delete == "0"){
            break;
        }
        for(unsigned i = 0; i < lectureCodes.size(); i++){
            if(lectureCodes[i] == code4delete){
                VerifyCode = true;
                position = i;
            }
        }
        
            
        if(VerifyCode == true){
                
              
            deleteElement(lectureCodes, position);
            deleteElement(lectureNames, position);
            lectureCredits.erase(lectureCredits.begin()+ position);
            limits.erase(limits.begin()+ position);
                
                
               
            cout << "성공적으로 강의가 폐쇄되었습니다.\n";
                
               
            for(unsigned row = 0; row < appliedLectureCodes.size(); row++){
              
                for(unsigned col = 0; col < appliedLectureCodes[row].size(); col++){
               
                    if(code4delete == appliedLectureCodes[row][col]){
              
                            deleteElement(appliedLectureCodes[row], col);
             
                    }
                
                }
            
            }

                
              
            VerifyCode = false;
            
             
            system("pause");
               
            continue;
         
        }
           
        else{
           
            cout << "일치하는 코드가 없습니다.\n";
          
            system("pause");
          
            continue;
          
        }
        
    }
}

int runAdmin(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes, vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {

        short input;
        while(1){
        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

        cout << "1. 학생 추가\n" << "2. 강의 개설\n" << "3. 강의 삭제\n" << "4. 로그아웃\n" << "0. 종료\n";
        
        cout.fill('-');
        cout.width(42);
        cout << " " << endl;
        cout.fill(' ');

        cout << ">> ";
        cin >> input;
      
        switch (input) {
            case 1:
                addStudent(studentIds, passwords, names, credits, appliedLectureCodes);
                break;
            case 2:
                addLecture(lectureCodes, lectureNames, lectureCredits, limits);
                break;
            case 3:
                deleteLecture(lectureCodes, lectureNames, lectureCredits, limits, credits, appliedLectureCodes);
                break;
            case 4:
                return -1;
            case 0:
                return 1;
            }
        }
    }

