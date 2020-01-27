#include<iostream>
#define vertex_num 6

void initial(int* parent){
	for(int i=0;i<vertex_num;i++){
		parent[i]=-1;
	}
}
int find_root(int v,int* parent){

	while(parent[v]!=-1){
		v = parent[v];
	}
	return v;
}
bool uni(int v1,int v2,int* parent){
	int root_v1,root_v2;
	root_v1 = find_root(v1,parent);
	root_v2 = find_root(v2,parent);
	if(root_v1!=root_v2){
		parent[root_v2] = root_v1;
		return true;
	}
	else{
		return false;
	}
	
}
int main(){
	int* parent = new int[vertex_num];
	initial(parent);
	int graph_edge[5][2]={{0,1},{1,2},{1,3},{2,5},{2,4}};
	int flag=0;
	for(int i=0;i<5;i++){
		int v1=graph_edge[i][0];
		int v2=graph_edge[i][1];

		if(uni(v1,v2,parent)){
			flag=0;
		}
		else{
			std::cout<<"cycle detected!\n";
			flag=1;
			break;
		}
	}
	if(flag!=1){
		std::cout<<"No cycle detected!\n";
	}










	return 0;
}
