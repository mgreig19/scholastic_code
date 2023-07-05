#include "BookStore.h"

int main()
{
	BookStore BritsCorner("bookdata");
	BritsCorner.BookStorePrint();
	BritsCorner.processOrders("orders.txt");
	BritsCorner.BookStorePrint();
}
