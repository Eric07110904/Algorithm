#include<iostream>
#include<list>
#include<stack>
class Graph{
	public:
		int vertex_num;
		std::list<int>*adj;

		Graph(int number){
			vertex_num = number;
			adj = new std::list<int>[number];
		}
		void add_edge(int v1,int v2);
		void dfs(int v);

		void test();


};

void Graph::add_edge(int v1,int v2){
	adj[v1].push_back(v2);

}
void Graph::test(){
	std::list<int>::iterator it;
	for(it = adj[0].begin();it!=adj[0].end();it++){
			std::cout<<"mother\n";
		}
}
void Graph::dfs(int v){
	int *visit = new int[vertex_num]{};
	std::stack<int>s;
	s.push(v);
	visit[v]=1;

	while(s.size()!=0){
		
		std::list<int>::iterator it;
		std::cout<<s.top()<<" ";
		int temp=s.top();
		s.pop();
		for(it = adj[temp].begin();it!=adj[temp].end();it++){
			
			if(!visit[*it]){
				visit[*it]=1;
				s.push(*it);
			}
		}
		
	}
	std::cout<<"\n";
}
int main(){
	Graph g(6);

	g.add_edge(0,1);
	g.add_edge(0,2);
	g.add_edge(2,3);
	g.add_edge(2,4);
	g.add_edge(4,5);

	g.dfs(0);
	std::cout<<"\n";

	
	return 0;
}
