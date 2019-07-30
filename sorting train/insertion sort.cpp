#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int>&array){

    for(int i=1;i<array.size();i++){
        int temp=i;int ans=array[i];
        while((ans<array[temp-1])&&temp-1>=0){
            array[temp]=array[temp-1];
            temp--;
        }
        array[temp]=ans;

    }


}
void show(vector<int>&array){
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
}
int main(){

    vector<int>array;
    ifstream fin("test.txt");
    int n,temp; fin>>n;

    for(int i=0;i<n;i++){
        fin>>temp;
        array.push_back(temp);
    }

    clock_t t;
    t=clock();

    insertion_sort(array);
    show(array);

    t=clock()-t;
    cout<<"\nconsume time: "<<((double)t/CLOCKS_PER_SEC)<<endl;









    return 0;
}
