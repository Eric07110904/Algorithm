#include<bits/stdc++.h>
using namespace std;
void swap(int&a, int&b){
    int temp=a;
    a=b;
    b=temp;
}
void selection_sort(vector<int>&array){
    int len=array.size();
    int min=INT_MAX;int min_flag=0;
    for(int i=0;i<len;i++){
        min=INT_MAX;
        for(int j=i;j<len;j++){
            if(array[j]<min){
                min_flag=j;
                min=array[j];
            }

        }
        swap(array[i],array[min_flag]);
    }
}
void show(vector<int>& array){
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
}
int main(){

    vector<int>array;
    ifstream fin("test.txt");
    int n,temp;
    fin>>n;
    //input data
    for(int i=0;i<n;i++){
        fin>>temp;
        array.push_back(temp);
    }
    clock_t t;
    t=clock();
    selection_sort(array);


    show(array);
    t=clock()-t;
    cout<<"\n consume time: "<<((double)t/CLOCKS_PER_SEC)<<endl;




    return 0;
}
