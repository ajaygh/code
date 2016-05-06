
#include <iostream>
#include "linkedlist.h"

using namespace std;

int main() {
	linkelists *lls1 = new linkelists();	
	lls1->append(1);
	lls1->append(2);
	lls1->append(3);
	lls1->append(4);
	lls1->append(5);

	lls1->display();
	lls1->reverse(lls1->head);
	lls1->display();
	return 0;
} 
