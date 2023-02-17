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

void data_A_sorted(data data[]){

}
void data_B_sorted(data data[]){
    
}
void data_C_sorted(data data[]){
    
}

int main(){
    int choice;
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
    while(true){
        cout <<endl << "Enter 1 to Show data" << endl << "Enter 2 to Sort Data Column \"A\" by assending " << endl << "Enter 3 to Sort Data Column \"B\" by assending  " << endl << "Enter 3 to Sort Data Column \"C\" by assending  " << endl<< "Enter -1 to quit : ";
        cin >> choice;
        if(choice == -1){
            break;
        }
        else if (choice == 1){
            display_data_table(data);
        }
    }
    return 0;
}