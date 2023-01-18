#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
    int map[10][10],i,j;
    int tree[2] = {rand()%10,rand()%10};
    int birth_week = 5, first_digit = 7, second_digit = 5;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            map[i][j]=0;                                                //เกิดวันศุกร์รหัส 57
            map[abs(tree[1]-9)][tree[0]]=1;                             //Tree 1 (1,7)
            map[abs(first_digit-9)][birth_week]=2;                      //Hero 2 (5,7)
            map[abs(second_digit-9)][abs(10-birth_week)]=3;             //Enemy 3 (5,5)
            cout<<map[i][j]<<" "; 
        }
            cout<<"\n";
    }
    cout<<"\n";

    int taxi_cab = abs(abs(10-5)%10-5)+abs(5-7);
    int euclidean = sqrt(pow(abs(10-23)%10-5,2)+pow(5-7,2));
    int chebyshev = (abs(10-23)%10-5) > (abs(5-7)) ? (abs(10-23)%10-5) : (abs(5-7));
    //มันย่อให่สั้นได้ แต่อ่านยากชิบหาย
    cout<<"Taxi Cab Algorithm : "<<taxi_cab;
    cout<<"\nEuclidean Algorithm : "<<euclidean;
    cout<<"\nChebyshev Algorithm : "<<chebyshev;
    return 0;
}
