#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
    int n = 10;
    int map[n][n];
    int tree[2] = {rand()%10,rand()%10};
    int birth_week = 5, first_digit = 7, second_digit = 5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=0;                                                 
        };
    }
    map[tree[0]][tree[1]] = 1;
    map[birth_week][first_digit] = 2;
    map[10 - birth_week][second_digit] = 3;
    for(int i=0;i<n/2;i++){
      for(int j=i;j<n-i-1;j++){
          int temp=map[i][j];
          map[i][j]=map[j][n-i-1];
          map[j][n-i-1]=map[n-i-1][n-j-1];
          map[n-i-1][n-j-1]=map[n-j-1][i];
          map[n-j-1][i]=temp;
      }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    float taxi_cab = abs(birth_week - (10 - birth_week)) + abs(first_digit - second_digit);
    float euclidean = sqrt(pow(birth_week - (10 - birth_week),2) + pow(first_digit - second_digit,2));
    float chebyshev = max(abs(birth_week - (10 - birth_week)),abs(first_digit - second_digit));
    cout<<"Taxi Cab Algorithm : "<<taxi_cab<<endl;
    cout<<"Euclidean Algorithm : "<<euclidean<<endl;
    cout<<"Chebyshev Algorithm : "<<chebyshev;
    return 0;
}