#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Student{
    string name;
    int score;
};

double MaxStudent(Student student[],int size){
    int max_score = student[0].score;
    for(int i=0; i<size; i++){
        if(max_score<student[i].score){
            max_score = student[i].score;
        }
    }
    return max_score;
}
double MinStudent(Student student[],int size){
    int min_score = student[0].score;
    for(int i=0; i<size; i++){
        if(min_score>student[i].score){
            min_score = student[i].score;
        }
    }
    return min_score;
}
double AvrScore(Student student[],int size){
    double avr_score = 0;
    for(int i=0; i<size; i++){
        avr_score+=student[i].score;
    }
    return avr_score/size;
}

double ModeScore(Student student[],int size){
    double score_list[10];
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

int main(){
    Student student[10];
    student[0] = {"John",60};
    student[1] = {"Ono",63};
    student[2] = {"Non",77};
    student[3] = {"Bryan",63};
    student[4] = {"Earth",77};
    student[5] = {"Mon",63};
    student[6] = {"Toto",73};
    student[7] = {"Boom",77};
    student[8] = {"Dikolo",90};
    student[9] = {"Boss",77};
    int size = (sizeof(Student)/(sizeof(student[0].score)));

    cout<<"Max score : "<<MaxStudent(student,size)<<endl;
    cout<<"Min score : "<<MinStudent(student,size)<<endl;
    cout<<"Average score : "<<AvrScore(student,size)<<endl;
    cout<<"Mode score : "<<ModeScore(student,size)<<endl;
}