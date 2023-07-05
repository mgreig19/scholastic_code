/*
May-Myo Khine
Zid : z1785954
Course and section number: CSCI340-2
I certify that this is my own work and where appropriate an extension
of the starter code provided for the assignment.
*/
/*************************
Assign : 07
Heaps and Heapsort (15 points) [Due April 6, 2017]
**************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::left;
using std::right;
using std::swap;
using std::setw;


const int HEAP_SIZE = 50;
const int NO_ITEM = 8;
const int ITEM_W = 5;

void heapify(vector <int>&v, int HEAP_SIZE, int r, bool(*compar)(int, int));
void build_heap(vector <int>& v, int HEAP_SIZE, bool (*compar)(int, int));
bool less_than(int e1, int e2);
bool greater_than(int e1, int e2);
void heap_sort(vector <int>& v, int HEAP_SIZE, bool (*compar)(int, int));
int extract_heap(vector <int>& v, int& HEAP_SIZE, bool (*compar)(int,int));
void print_vector (vector <int>& v, int pos, int size);

void build_heap(vector <int>& v, int HEAP_SIZE, bool (*compar)(int, int))
{

    for(int i = (int)v.size()/2; i > 0; --i)
   {
        heapify(v, HEAP_SIZE, i, compar);
   }

}

void heapify(vector <int>&v, int HEAP_SIZE, int r, bool(*compar)(int, int))
{
    int left = 2*r;
    int right = 2*r +1;
    int val ;

  

    if ( left <= HEAP_SIZE && compar(v[left], v[r]))
        val = left;
    else
        val = r;

    if ( right <= HEAP_SIZE && compar (v[right],v[val]))
        val = right; 

    if ( val != r )
    {
        swap( v[r], v[val]);

        return heapify(v, HEAP_SIZE, val, compar);
    }


}


bool less_than(int e1, int e2)
{
    if( e1 < e2)
        return true; 
    else
        return false;
}

bool greater_than(int e1, int e2)
{
    if ( e1 > e2)
        return true;
    else
        return false;
}

void heap_sort(vector <int>& v, int HEAP_SIZE, bool (*compar)(int, int))
{
//    build_heap(v, HEAP_SIZE, compar);

    for( int i= HEAP_SIZE ; i >1; --i)
    {
  v[i] =  extract_heap ( v, HEAP_SIZE, compar);
   }
	reverse(v.begin()+1, v.end());
}

int extract_heap(vector <int>& v, int& HEAP_SIZE, bool (*compar)(int,int))
{
	int max = v[1];
	v[1] = v[HEAP_SIZE];
	HEAP_SIZE = HEAP_SIZE-1;
	heapify(v, HEAP_SIZE, 1, compar);

	return max;
}

/*
    if(HEAP_SIZE < 1)
        cout << "Heap Underflow";
    else
    {
    v[1] = v[HEAP_SIZE];
    HEAP_SIZE = HEAP_SIZE-1;
    heapify(v, HEAP_SIZE, 1, compar);
    }
	return 1;
*/



void print_vector (vector <int>& v, int pos, int size)
{
        for ( ; pos <= HEAP_SIZE; pos++)
        {
		cout<< setw(ITEM_W) << v[pos];
                if( pos % NO_ITEM == 0 and pos != 0)
               	cout<< endl;
//		cout<< setw(ITEM_W) << v[pos];
        }
        cout << endl;
}


int main(int argc, char** argv) {
    // ------- creating input vector --------------
    vector<int> v;
    v.push_back(-1000000);    // first element is fake
    for (int i=1; i<=HEAP_SIZE; i++)
        v.push_back( i );
    random_shuffle( v.begin()+1, v.begin()+HEAP_SIZE+1 );

    cout << "\nCurrent input numbers: " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing min heap ------------------
    cout << "\nBuilding a min heap..." << endl;
    build_heap(v, HEAP_SIZE, less_than);
    cout << "Min heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, less_than);
    cout << "Heap sort result (in ascending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    // ------- testing max heap ------------------
    cout << "\nBuilding a max heap..." << endl;
    build_heap(v, HEAP_SIZE, greater_than);
    cout << "Max heap: " << endl;
    print_vector( v, 1, HEAP_SIZE );
    heap_sort( v, HEAP_SIZE, greater_than);
    cout << "Heap sort result (in descending order): " << endl;
    print_vector( v, 1, HEAP_SIZE );

    return 0;
}

