#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <utility>
#include <algorithm>
#include "assignment9.h"

using namespace std;

//#define DEBUG //Uncomment to show debugging cout statements

/*****GOLBALS USED IN traverse() and depth_first() *****/
vector<int> numTraversal;             //Store the traversal order
vector<pair<int, int> > visitOrder;   //Stores the two ints that were visited
int orderIncrementer = 0;             //Keeps track of 
vector<int>::iterator it;             //Iterator can be used for and vector<int>
list<int>::iterator adjIt;            //Iterator can be used for any list<int>
list<int> tempList;                   //Stores the edge numbers from input
/********************************************************/

/***************************************************************
Function: graph()

Use: This is the constructor. It reads from the input
file of the graph with the adjacency matrix
representation and builds the graph with the 
adjacency list representation. This method sets the
value of 'size', builds the vectors 'labels' and
'adj_list'. The following line of input:

D
0 1
0 0
1 0
0

Adds edges to 'adj_list[3]' (edges starting at
vertex 'D') by adding values '1' and '4' which are
index 'B' and 'E'.

Arguments: const char* inputFile

Returns: Nothing
***************************************************************/
graph::graph(const char* input)
{
#ifdef DEBUG
cout << "\n\t\t*** DEBUGGING MESSAGES ENABLED ***\n\n";
#endif //DEBUG

int temp = 0;

//Read in the first character (which is the number of vertices in the graph)
ifstream infile(input, ios::in);
char line;
infile >> line;

//Read in the first number and convert it to an int
int verticiesInGraph = line - '0';

//Assign the size of the graph (total num of vertices)
size = verticiesInGraph;

//Get the first line of vertex labels
for (int i = 0; i < verticiesInGraph; i++) {
infile >> line;
labels.push_back(line);  //Push the v
#ifdef DEBUG
cout << "Pushed back: " << "\'" << line << "\'" << " to labels[" << i << ']' << endl;
#endif //DEBUG
}

#ifdef DEBUG
cout << endl;
#endif //DEBUG

for (int k = 0; k < verticiesInGraph; k++) {

//Ignores vertex label (they are already stored in the 'labels' vector)
infile >> line;

#ifdef DEBUG
cout << "Ignorning character '" << line << "\'" << endl;
#endif

for (int j = 0; j < verticiesInGraph; j++) {

//Store the next char in to 'temp' (this can be a '0' or a '1')
infile >> temp;
tempList.push_back(temp); //Push read in value into tempList

#ifdef DEBUG
cout << "tempList[" << k << "]: pushed back " << temp << endl;
#endif //DEBUG
}

#ifdef DEBUG
cout << endl;
#endif //DEBUG

//Push the integers in tempList ot adj_list
adj_list.push_back(tempList);

//Clear out the tempList so it can be used again with the next line of input
tempList.erase(tempList.begin(), tempList.end());
}

//Debugging message to show the complete contents of adjList[]
#ifdef DEBUG
int listNum = 0;
for (std::vector<std::list<int> >::iterator it = adj_list.begin(); it != adj_list.end(); it++) {

cout << "Contents of adjList[" << listNum << "]: ";
std::list<int> li = *it;
for (std::list<int>::iterator iter = li.begin(); iter != li.end(); iter++) {
cout << *iter << " ";
}

cout << endl;
listNum++;
}
cout << "\n\n\t\t*** END OF DEBUGGING MESSAGES ***\n\n\n";
#endif

infile.close();
}

/***************************************************************
Function: depth_first()

Use: This private function is used to traverse a graph
in the depth-first traversal/search algorithm
starting at the vertex with the index value of 'v'.
It uses the global iterators, vector, and list.

Arguments: int v - The vertex with the index value 'v'

Returns: Nothing
***************************************************************/
void graph::depth_first(int v) const
{
int dist = 0;

orderIncrementer++;
numTraversal[v] = orderIncrementer;

//Assign adj_list[v] values to tempList
tempList = adj_list[v];

for (adjIt = tempList.begin(); adjIt != tempList.end(); adjIt++) {

tempList = adj_list[v];

//Find the distance from the beginning of tempList to the adjIt
dist = distance(tempList.begin(), adjIt);

if (*adjIt == 1 && numTraversal[dist] == 0) {

//Make the pair where the visit happened
visitOrder.push_back(make_pair(v, dist));

depth_first(dist);
}
}
}

/***************************************************************
Function: traverse()

Use: This public function is used to traverse a graph and
invokes the 'depth_first()' method. Within the
traverse() function, the traverse results are also
printed. This result shows the list of vertices in
the order of their visit and the list of edges
showing the path(s) of the traversal.

Arguments: None

Returns: Nothing
***************************************************************/
void graph::traverse() const
{
//Resize the numTraversal vector to the amount of vertices
//Starts of filles with all 0's
numTraversal.resize(size);
//Find the first 0 in numTraversal
it = find(numTraversal.begin(), numTraversal.end(), 0);

while(it != numTraversal.end()) {

//Calls depth_first at the index the 0 was found
depth_first(it - numTraversal.begin());

//Finds the next 0 in numTraversal
it = find(numTraversal.begin(), numTraversal.end(), 0);
}

cout << "------- traverse of graph ------" << endl;

for (int i = 1; i <= size; i++) {

//Print out the labels of the traversal path
it = find(numTraversal.begin(), numTraversal.end(), i);
cout << labels[it - numTraversal.begin()] << " ";
}

cout << endl;

for (unsigned int j = 0; j < visitOrder.size(); j++) {

//eg (A, B)
cout << "(" << labels[visitOrder[j].first] << ", " << labels[visitOrder[j].second] << ") ";
}

cout << endl;
cout << "--------- end of traverse -------" << endl << endl; 

}

/***************************************************************
Function: print()

Use: This function prints the adjacency list for the
graph. Example output: "D: B, E,"

Arguments: None

Returns: Nothing
***************************************************************/
void graph::print() const
{
//Keeps track of the labels being printed - eg "A:"
int vertexLabelCounter = 0;


int edgeCounter = 0;

cout << endl << "Number of vertices in the graph: " << size << endl << endl;

cout << "-------- graph -------" << endl;
//While there are integers in the adj_list
for (std::vector<std::list<int> >::const_iterator it = adj_list.begin(); it != adj_list.end(); it++) {

//eg "A: " or "B: "
cout << labels[vertexLabelCounter] << ": ";

//Assign value held at the iterator to a temporary list
std::list<int> li = *it;
for (std::list<int>::iterator iter = li.begin(); iter != li.end(); iter++) {

//If a '1' was found, an edge exists. Record it.
if (*iter == 1) {
cout << labels[edgeCounter] << ", ";   //Prints out the edges
}

edgeCounter++; //Increase the edgeCounter. If a '1' is found above, the newly incremented
  //value will be printed using labels[edgeCounter].
}

cout << endl;
vertexLabelCounter++; //Increment the vertexLabelCounter since we need to print the next vertex
edgeCounter = 0;  //Reset the edgeCounter since we are going to print out  a new line
}

cout << "------- end of graph ------" << endl << endl;
}

#define ASSIGNMENT9_TEST
#ifdef ASSIGNMENT9_TEST

int main(int argc, char** argv) {
if (argc < 2) {
cerr << "args: input-file-name\n";
return 1;
}

graph g(argv[1]);

g.print();

g.traverse();

return 0;
}

#endif