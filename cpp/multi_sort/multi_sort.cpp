#include<iostream>
#include<iomanip>
using namespace std;

const int data_count = 14;

struct Data{
    int number, data_a, data_b, data_c;
};

void display_data_table(Data data[]){
    for(int i=-1; i<data_count; i++){
        if(i == -1) {
            cout << setw(5) << left << "No" << setw(5) << left << "A" << setw(5) << left << "B" << setw(5) << left << "C";
        }
        else{
            cout << setw(5) << left << data[i].number << setw(5) << left << data[i].data_a << setw(5) << left << data[i].data_b << setw(5) << left << data[i].data_c;
        }
        cout << endl;
    }
}

void multi_column_sort_ABC(Data data[]){
    Data temp;
    for(int i=0; i<data_count-1; i++){
        for(int j=0; j<data_count-i-1; j++){
            if(data[j].data_a > data[j+1].data_a){
                temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
            }
            else if(data[j].data_a == data[j+1].data_a){
                if(data[j].data_b > data[j+1].data_b){
                    temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                    data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                    data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                }
                else if(data[j].data_b == data[j+1].data_b){
                    if(data[j].data_c > data[j+1].data_c){
                        temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                        data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                        data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                    }
                }
            }
        }
    }
}
void multi_column_sort_ACB(Data data[]){
    Data temp;
    for(int i=0; i<data_count-1; i++){
        for(int j=0; j<data_count-i-1; j++){
            if(data[j].data_a > data[j+1].data_a){
                temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
            }
            else if(data[j].data_a == data[j+1].data_a){
                if(data[j].data_c > data[j+1].data_c){
                    temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                    data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                    data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                }
                else if(data[j].data_c == data[j+1].data_c){
                    if(data[j].data_b > data[j+1].data_b){
                        temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                        data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                        data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                    }
                }
            }
        }
    }
}
void multi_column_sort_BAC(Data data[]){
    Data temp;
    for(int i=0; i<data_count-1; i++){
        for(int j=0; j<data_count-i-1; j++){
            if(data[j].data_b > data[j+1].data_b){
                temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
            }
            else if(data[j].data_b == data[j+1].data_b){
                if(data[j].data_a > data[j+1].data_a){
                    temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                    data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                    data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                }
                else if(data[j].data_a == data[j+1].data_a){
                    if(data[j].data_c > data[j+1].data_c){
                        temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                        data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                        data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                    }
                }
            }
        }
    }
}
void multi_column_sort_BCA(Data data[]){
    Data temp;
    for(int i=0; i<data_count-1; i++){
        for(int j=0; j<data_count-i-1; j++){
            if(data[j].data_b > data[j+1].data_b){
                temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
            }
            else if(data[j].data_b == data[j+1].data_b){
                if(data[j].data_c > data[j+1].data_c){
                    temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                    data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                    data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                }
                else if(data[j].data_c == data[j+1].data_c){
                    if(data[j].data_a > data[j+1].data_a){
                        temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                        data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                        data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                    }
                }
            }
        }
    }
}
void multi_column_sort_CAB(Data data[]){
    Data temp;
    for(int i=0; i<data_count-1; i++){
        for(int j=0; j<data_count-i-1; j++){
            if(data[j].data_c > data[j+1].data_c){
                temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
            }
            else if(data[j].data_c == data[j+1].data_c){
                if(data[j].data_a > data[j+1].data_a){
                    temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                    data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                    data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                }
                else if(data[j].data_a == data[j+1].data_a){
                    if(data[j].data_b > data[j+1].data_b){
                        temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                        data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                        data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                    }
                }
            }
        }
    }
}
void multi_column_sort_CBA(Data data[]){
    Data temp;
    for(int i=0; i<data_count-1; i++){
        for(int j=0; j<data_count-i-1; j++){
            if(data[j].data_c > data[j+1].data_c){
                temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
            }
            else if(data[j].data_c == data[j+1].data_c){
                if(data[j].data_b > data[j+1].data_b){
                    temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                    data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                    data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                }
                else if(data[j].data_b == data[j+1].data_b){
                    if(data[j].data_a > data[j+1].data_a){
                        temp = {data[j].number, data[j].data_a ,data[j].data_b ,data[j].data_c};
                        data[j] = {data[j+1].number, data[j+1].data_a ,data[j+1].data_b ,data[j+1].data_c};
                        data[j+1] = {temp.number, temp.data_a ,temp.data_b ,temp.data_c};
                    }
                }
            }
        }
    }
}


int main(){
    Data data[data_count];
    data[0] = {1,1,1,4};
    data[1] = {2,3,1,1};
    data[2] = {3,4,4,4};
    data[3] = {4,2,5,4};
    data[4] = {5,3,5,3};
    data[5] = {6,4,3,3};
    data[6] = {7,1,3,3};
    data[7] = {8,2,4,3};
    data[8] = {9,3,3,5};
    data[9] = {10,1,5,3};
    data[10] = {11,1,1,4};
    data[11] = {12,4,1,1};
    data[12] = {13,5,2,3};
    data[13] = {14,3,5,2};
    multi_column_sort_BCA(data);
    display_data_table(data);
    return 0;
}