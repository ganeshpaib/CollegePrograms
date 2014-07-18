int parent[10];
int find(int edge)
{
	while(parent[edge]!=0)
		edge=parent[edge];
	return edge;
}