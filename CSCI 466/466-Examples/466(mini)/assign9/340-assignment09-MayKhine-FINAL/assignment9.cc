#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include "assignment9.h"
#include <algorithm>
using namespace std;

//global variables
list<int>xList;
int order = 0;
vector<int>traversal_num;
vector<pair<int,int>> order_visit;
vector<int>::iterator it;
list<int>::iterator liit;


/***************************
the constructor
graph::graph(const char* filename)
Use:		the constructor. It reads from the input file of the graph with adjacency matrix representation
		and builds the graph with adjacency list representation.
		This method sets the value of size, builds the vectors labels and adj_list.
		For example, for the following line of input: D 0 1 0 0 1 0 0 Add edges to adj_list[3],
		which records edges starting from vertex D, by adding values 1 and 4,
		which are indexes for vertices B and E.
Parameter:	const chat* filename
Return:		nothing
*****************************/
graph::graph(const char* filename)
{
	int x = 0;

	//read the first char, number of vertices in graph, from filename
	ifstream infile(filename, ios::in);
	char line;
	infile>>line;

	//read the char and change it to a number
	int verticies_num = line-0;
	//assign that the number of vertices to the size of graph
	size = verticies_num;

	//get the first line of vertex
	for ( int i = 0; i < verticies_num; i++)
	{
	infile >> line;
	//push the vertex and read
	labels.push_back(line);
	}

	for ( int z = 0; z < verticies_num; z++)
	{
	infile >> line;
		for ( int y; y < verticies_num; y++)
		{
		//store next char in x ( after the vertex, theres's 0 or 1)
		infile >> x;
		//push and read values in xList
		xList.push_back(x);
		}
	//push the integers to adj list from xList
	adj_list.push_back(xList);
	//after pushing integers to adj list, delete xList
	xList.erase(xList.begin(), xList.end());
	}

	//close the infile
	infile.close();
}

graph::~graph()
{

}


/***************************
depth-first traversal/search algorithm
void graph::depth_first(int v)

Use:            This private function is used to traverse a graph in the depth-first traversal/search algorithm
		starting at the vertex with the index value of v.
		To implement this method (and together with the traverse method below),
		you may need several global variable and objects.
		For example, container objects to record the visiting order of all vertices,
		the container object to record the paths of traversing edges,
		and an integer indicating the current order in traversing.
Parameter:      int v
Return:         nothing
*****************************/
void graph::depth_first(int v)
{
	//initialize distance to 0, and incre order to order++
	int distance_graph = 0;
	order++;
	//set order to num of traversal
	traversal_num[v] = order;
	//assign adj list to xList
	xList = adj_list[v];

	//vist all the vertices and store them in xList
	for(liit = xList.begin(); liit != xList.end(); liit++)
	{
	//set adj_list to xList
	xList = adj_list[v];
	//call distance function from the xList being to the end and set the distance to distance_graph
	//distance function calculates the number of elements between first and last.
	distance_graph = distance(xList.begin(), liit);

	//if its the end node or there's no edge between two vertices
	if(*liit ==1 && traversal_num[distance_graph] == 0)
	{
	//create the pair where the order vist has happened
	order_visit.push_back(make_pair(v,distance_graph));
	//recursive call the depth_first function
	depth_first(distance_graph);
	}//end of if loop

	}//endo fo for loop

}

/***************************
traverse a graph function
void graph::traverse()

Use:            This public function is used to traverse a graph and invokes the above depth_first method.
		You will also need to display traverse result: the list of vertices in the order of their visit
		and the list of edges showing the path(s) of the traversal.
		At beginning of this method,
		you need to initialize the global variable(s) and object(s) used in depth_first.
Parameter:      -
Return:         nothing
*****************************/
void graph::traverse()
{
	//set the size of vector traversal_num to "size"
	traversal_num.resize(size);

	it = find(traversal_num.begin(), traversal_num.end(), 0);

	while( it != traversal_num.end())
	{
	depth_first( it - traversal_num.begin());

	it = find (traversal_num.begin(), traversal_num.end(), 0);
	}//end of while loop

	cout << "------- travere of graph ------" <<endl;

	for ( int i = 1; i <= size; i++)
	{
	it = find ( traversal_num.begin(), traversal_num.end(), i);
	cout << labels [ it - traversal_num.begin()] << " ";
	}//end of for loop

	cout << endl;

	for ( unsigned int x = 0; x < order_visit.size(); x++)
	{
	cout << "(" << labels[order_visit[x].first] << ","
		<< labels[ order_visit[x].second]<< ") ";

	}//end of for loop

	cout << endl;
	cout << "--------- end of traverse -------"<< endl << endl;
}

void graph::print() const
{


}










#define ASSIGNMENT9_TEST
#ifdef 	ASSIGNMENT9_TEST

int main(int argc, char** argv) {
    if ( argc < 2 ) {
        cerr << "args: input-file-name\n";
        return 1;
    }

    graph g(argv[1]);

    g.print();

    g.traverse();

    return 0;
}

#endif
