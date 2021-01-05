//
//  Login.cpp
//  DataStr
//
//  Created by Jun on 2021/01/05.
//

#include "Login.hpp"


string getInputId() {

    string UserId;
    
    cout << "아이디 :";
    cin >> UserId;
    
    return UserId;
}

string getInputPassword() {
    string UserPw;
  
    cout << "비밀번호 : ";
    cin >> UserPw;
    
    return UserPw;
    
}

int studentLogin(const vector<string>& studentIds, const vector<string>& passwords) {

    string UserId = getInputId();
    string UserPw = getInputPassword();

    for(unsigned rowIds = 0; rowIds < studentIds.size(); rowIds++){
        if(studentIds[rowIds] == UserId){
            if(passwords[rowIds] == UserPw){
                return rowIds;
            }
        }
    }
    
    return -1;
}

bool adminLogin() {
    string UserId = getInputId();
    string UserPw = getInputPassword();
    string AdminId = "admin";
    string AdminPw = "admin";
    
    if(AdminId == UserId){
        if(AdminPw == UserPw)
            return true;
        else
            return false;
    }
    else
        return false;
    
}

int login(const vector<string>& studentIds, const vector<string>& passwords) {

    unsigned menu;
    int loginResult = 0;

    cout.fill('-');
    cout.width(30);
    cout << " " << endl;
    cout.fill(' ');

    cout << "1. 학생 로그인\n" << "2. 관리자 로그인\n" << "0. 종료\n";
    
    cout.fill('-');
    cout.width(30);
    cout << " " << endl;
    cout.fill(' ');

    cout << ">> ";
    cin >> menu;
    
    if(menu == 1){
        for(unsigned _try = 1; _try < 4; _try++){
                loginResult = studentLogin(studentIds, passwords);
                
                if(loginResult == -1){
                    cout << "로그인 " << _try << "회 실패 (3회 실패시 종료)\n";
                    if(_try == 3){
                        cout << "3회 실패하여 종료합니다." << endl;
                        loginResult = -999;
                        break;
                    }
                }
                else{
                    return loginResult;
                }
        }
    }
    
    else if(menu == 2){
        for(unsigned _try = 1; _try < 4; _try++){
                if(adminLogin() == false){
                    cout << "로그인 " << _try << "회 실패 (3회 실패시 종료)\n";
                    if(_try == 3){
                        cout << "3회 실패하여 종료합니다." << endl;
                        loginResult = -999;
                        break;
                    }
                }
                else{
                    return -100;
                }
        }
    }
    
    else if(menu == 0){
        loginResult = -1;
    }
    
    return loginResult;
}

