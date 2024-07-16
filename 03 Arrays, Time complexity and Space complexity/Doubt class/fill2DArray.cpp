#include<iostream>
using namespace std;
//fill: 2d array
int main(){
    int arr[4][3]={{10,20,30},
                    {11,12,13},
                    {15,16,17},
                    {20,21,22}};
    fill(&arr[0][0],&arr[0][0]+ (4*3),-1);
    for( int i=0; i<4; i++){
        for(int j=0; j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
