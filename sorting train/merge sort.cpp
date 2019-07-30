#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&array,int front,int mid,int end){
    vector<int>left(array.begin()+front,array.begin()+mid+1);
    vector<int>right(array.begin()+mid+1,array.begin()+end+1);
    /*
    cout<<"left: ";
    for(int i=0;i<left.size();i++)
        cout<<left[i]<<" ";
    cout<<endl<<"right: ";
    for(int i=0;i<right.size();i++)
        cout<<right[i]<<" ";
    cout<<endl;
    */
    left.insert(left.end(),INT_MAX);
    right.insert(right.end(),INT_MAX);//加入無限大就不用判斷左邊還右邊先排完!
    int index_left=0,index_right=0;
    for(int i=front;i<=end;i++){

        if(left[index_left]<=right[index_right]){
            array[i]=left[index_left];
            index_left+=1;
        }
        else{
            array[i]=right[index_right];
            index_right+=1;
        }

    }

}
void mergesort(vector<int>&array,int front,int end){
    if(front<end){
        int mid=(front+end)/2;
        mergesort(array,front,mid);
        mergesort(array,mid+1,end);
        merge(array,front,mid,end);
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
    int n,temp;fin>>n;

    for(int i=0;i<n;i++){
        fin>>temp;
        array.push_back(temp);
    }
    clock_t t;
    t=clock();
    mergesort(array,0,n-1);
    t=clock()-t;
    show(array);
    cout<<"\nconsume time: "<<((double)t/CLOCKS_PER_SEC)<<endl;




    return 0;
}
