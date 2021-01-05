#include "IO.hpp"



void readStudentFile(vector<string>& studentIds, vector<string>& passwords, vector<string>& names, vector<int>& credits, vector<vector<string>>& appliedLectureCodes) {

    ifstream fin("students.txt");
    
    string input;
    int inputnum;
    vector<string> inputv;
    
    for(unsigned row = 0; fin; row++){
        if(!fin){break;}
        for(unsigned col = 0; col < 5; col++){
           switch(col){
                case 0:
                    fin >> input;
                    if(!fin){break;}
                    studentIds.push_back(input);
                    break;
                    
                case 1:
                    fin >> input;
                    if(!fin){break;}
                    passwords.push_back(input);
                    break;
                    
                case 2:
                    fin >> input;
                    if(!fin){break;}
                    names.push_back(input);
                    break;
                    
                case 3:
                    fin >> inputnum;
                    if(!fin){break;}
                    credits.push_back(inputnum);
                    break;
                    
                case 4:
                   fin >> inputnum;
                   appliedLectureCodes.push_back(inputv);
                   
                   if(inputnum == 0){
                       continue;
                   }
                   for(int NumofLec = 0; NumofLec < inputnum; NumofLec++){
                       fin >> input;
                       if(!fin){break;}
                       appliedLectureCodes[row].push_back(input);
                   }
           }
        }
    }
    fin.close();
}

void readLectureFile(vector<string>& lectureCodes, vector<string>& lectureNames, vector<int>& lectureCredits, vector<int>& limits) {
    
    ifstream fin("lectures.txt");
    string strinput;
    int intinput;
    
    for(unsigned row = 0; fin ; row++){
        if(!fin){break;}
        for(unsigned col = 0; col < 4; col++){
            if(!fin){break;}

            switch (col) {
                case 0:
                     
                    fin >> strinput;
                    if(!fin){break;}
                    lectureCodes.push_back(strinput);
                    break;
                    
                case 1:
                    
                    fin >> strinput;
                    lectureNames.push_back(strinput);
                    break;
                    
                case 2:
                    
                    fin >> intinput;
                    lectureCredits.push_back(intinput);
                    break;
                    
                case 3:
                    
                    fin >> intinput;
                    limits.push_back(intinput);
                    break;
            }
        if(!fin){break;}
        }
    }
    fin.close();
}

void writeStudentFile(const vector<string>& studentIds, const vector<string>& passwords, const vector<string>& names, const vector<int>& credits, const vector<vector<string>>& appliedLectureCodes) {
    ofstream fout("students.txt");
    
    int CountAppliedcodes = 0;
    
    for(unsigned num = 0; num < studentIds.size(); num++){
        if(!fout){break;}

        CountAppliedcodes += appliedLectureCodes[num].size();
        
        fout << studentIds[num] << "\t";
        fout << passwords[num] << "\t";
        fout << names[num] << "\t";
        fout << credits[num] << "\t";
        fout << CountAppliedcodes << "\t";

        if(CountAppliedcodes != 0){
            for(unsigned rep = 0; rep < CountAppliedcodes; rep++){
                if(!fout){break;}
                fout << appliedLectureCodes[num][rep] <<"\t";
            }
            CountAppliedcodes = 0;
            fout << endl;

        }
        else{
            fout << endl;
        }
    }
    fout.close();
}


void writeLectureFile(const vector<string>& lectureCodes, const vector<string>& lectureNames, const vector<int>& lectureCredits, const vector<int>& limits) {
    ofstream fout("lectures.txt");
              
       for(unsigned num = 0; num < lectureCodes.size(); num++){

           if(!fout){break;}

           fout << lectureCodes[num] << "\t";
           fout << lectureNames[num] << "\t";
           fout << lectureCredits[num] << "\t";
           fout << limits[num];
           fout << endl;

       }
    fout.close();
}
