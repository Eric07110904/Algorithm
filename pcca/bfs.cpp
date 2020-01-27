#include<iostream>
#include<list>
#include<queue>
class Graph{
	public:
		int vertex_num;
		std::list<int>* adj;
		Graph(int num){//建立圖
			this->vertex_num = num;
			//adj list initial 
			adj = new std::list<int>[num];
		}
		void add_edge(int v1,int v2);
		void BFS(int root_vertex);
};

void Graph::add_edge(int v1,int v2){
	adj[v1].push_back(v2);
}
void Graph::BFS(int root_vertex){
	std::queue<int>q;
	int* visit = new int[vertex_num]{};// if already be visited set 1 
	q.push(root_vertex);
	visit[root_vertex]=1;
	/*           bfs loop size = 0 ->bfs end */ 
	while(q.size()!=0){
		std::cout<<q.front()<<" ";
		std::list<int>::iterator it ;
		//add child to the list 
		for(it = adj[q.front()].begin();it!=adj[q.front()].end();it++){
			if(!visit[*it]){
				q.push(*it);
				visit[*it]=1;
			}
		
		}
		q.pop();
		
	}
}
int main(){

	Graph graph(5);
	graph.add_edge(0,1);
	graph.add_edge(0,3);
	graph.add_edge(0,4);
	graph.add_edge(1,3);
	graph.add_edge(2,0);
	graph.add_edge(3,2);
	graph.add_edge(4,2);
	

	/*
	std::list<int> temp = graph.adj[0];
	for(std::list<int>::iterator it = temp.begin();it!=temp.end();it++){
		std::cout<<" "<<*it;
	
	}
	std::cout<<"asdsdsad\n";
	*/
	std::cout<<"\n start bfs traversal: \n";
	graph.BFS(3);
	std::cout<<"\n";


	return 0;
}
