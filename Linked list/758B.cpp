#include<bits/stdc++.h>
#define  ll long long
#define kaj_ses return 0;
#define IO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int main(){
    IO
    string str;
    cin>>str;
    int k;
    int l = str.size();
    /*pair<char,int>cntR={'R',0};
    pair<char,int>cntB={'B',0};
    pair<char,int>cntY={'Y',0};
    pair<char,int>cntG={'G',0}; */
    int arr1[4]={0,0,0,0};
    int arr[4];
    for( int i=0;i<l;i++){
        if(str[i]=='R'){
            arr[0] = (i+1)%4;
        }
        else if(str[i]=='B'){
            arr[1] = (i+1)%4;
        }
        else if(str[i]=='Y'){
            arr[2] = (i+1)%4;
        }
        else if(str[i]=='G'){
            arr[3] = (i+1)%4;
        }
        else
            continue;


    }
    for(int i =0;i<l;i++){
        if(str[i]=='!'){
            k = (i+1)%4;
            if(arr[0]==k){
                arr1[0]++;
            }
            else if(arr[1]==k){
                arr1[1]++;
            }
            else if(arr[2]==k){
                arr1[2]++;
            }
            else if(arr[3]==k){
                arr1[3]++;
            }

        }
    }
    for(int i=0;i<4;i++){
        cout<<arr1[i]<<" ";
    }




}
