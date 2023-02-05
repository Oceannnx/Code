#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int score;
    char grade;
};

double MaxStudent(Student student[],int size){
    int max_score = student[0].score;
    for(int i=0; i<size; i++){
        if(max_score < student[i].score or i==0){
            max_score = student[i].score;
        }
    }
    return max_score;
}
string MaxStudentName(Student student[],int size){
    int max_score = student[0].score;
    string name;
    for(int i=0; i<size; i++){
        if(max_score < student[i].score or i==0){
            max_score = student[i].score;
            name = student[i].name;
        }
    }
    return name;
}
double MinStudent(Student student[],int size){
    int min_score = MaxStudent(student,size);
    for(int i=0; i<size; i++){
        if(student[i].score < min_score or i == 0){
            min_score = student[i].score;
        }

    }
    return min_score;
}
string MinStudentName(Student student[],int size){
    int min_score = MaxStudent(student,size);
    string student_name;
    for(int i=0; i<size; i++){
        if(student[i].score < min_score or i == 0){
            min_score = student[i].score;
            student_name = student[i].name;
        }

    }
    return student_name;
}
double AvrScore(Student student[],int size){
    double avr_score = 0;
    for(int i=0; i<size; i++){
        avr_score+=student[i].score;
    }
    return avr_score/size;
}

double ModeScore(Student student[],int size){
    double score_list[size];
    int size_list = sizeof(score_list)/sizeof(score_list[0]);
    for(int i=0; i<size;i++){
        score_list[i] = student[i].score;
    }
    sort(score_list,score_list+size_list);
    int max_mode = 1, most_num = score_list[0], count = 1;
    for(int i=1; i<size ; i++){
        if(score_list[i]==score_list[i-1]){
            count++;
        }
        else{
            if(count>max_mode){
                max_mode = count;
                most_num = score_list[i-1];
            }
            count = 1;
        }
    }
    if(count>max_mode){
        most_num = score_list[size-1];
    }
    return most_num;
}
double MedianScore(Student student[],int size){
    double score_list[size];
    int size_list = sizeof(score_list)/sizeof(score_list[0]);
    for(int i=0; i<size; i++){
        score_list[i] = student[i].score;
    }
    sort(score_list,score_list+size_list);
    return (size_list%2==0)? (score_list[(size_list/2)-1]+score_list[size_list/2])/2 : score_list[size_list/2];
    
}
double SDScore(Student student[],int size){
    double x_bar = AvrScore(student,size), sum = 0;
    for(int i=0; i<size; i++){
        sum += pow((student[i].score - x_bar),2);
    }
    return sqrt(sum/(size-1));
}
void GradeStudent(Student student[], int size){
    for(int i=0; i<size; i++){
        if(student[i].score > AvrScore(student,size)+(SDScore(student,size)*2)){
            student[i].grade ='A';
        }
        else if(student[i].score > AvrScore(student,size)+(SDScore(student,size))){
            student[i].grade = 'B';
        }
        else if(student[i].score > AvrScore(student,size)){
            student[i].grade = 'C';
        }
        else if(student[i].score > AvrScore(student,size)-(SDScore(student,size))){
            student[i].grade = 'D';
        }
        else{
            student[i].grade = 'F';
        }
        cout<<student[i].name<<" : "<<student[i].grade<<endl;
    }
}

int main(){
    Student student[10];
    student[0] = {"John",60};
    student[1] = {"Ono",60};
    student[2] = {"Non",66};
    student[3] = {"Bryan",63};
    student[4] = {"Earth",77};
    student[5] = {"Mon",63};
    student[6] = {"Toto",63};
    student[7] = {"Boom",85};
    student[8] = {"Dikolo",100};
    student[9] = {"Boss",77};
    int size = (sizeof(student)/(sizeof(student[0])));
    
    // cout<<"size : "<<size<<endl;
    cout<<"Max score : "<<MaxStudentName(student,size)<<" = "<<MaxStudent(student,size)<<endl;
    cout<<"Min score : "<<MinStudentName(student,size)<<" = "<<MinStudent(student,size)<<endl;
    cout<<"Average score : "<<AvrScore(student,size)<<endl;
    cout<<"Mode score : "<<ModeScore(student,size)<<endl;
    cout<<"Median score : "<<MedianScore(student,size)<<endl;
    cout<<"SD score : "<<SDScore(student,size)<<endl;
    GradeStudent(student,size);
}