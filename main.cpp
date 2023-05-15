#include <iostream>
#include "BSTree.h"
#include "Node.h"

int main(){
	BSTree *t1 = new BSTree();
	t1->setup();
	std::cout << t1->get_debug_string() << std::endl;
	int n;
  	n = t1->searchr(10);
  	std::cout << "found " << n << "\n";
  	n = t1->searchr(8);
  	std::cout << "found " << n << "\n";
  	n = t1->searchr(15);
  	std::cout << "found " << n << "\n";
  	try {
  	n = t1->search(17);
  	std::cout << "found " << n << "\n";
  	} catch (int e){
    std::cout << 17 << " not found\n";
  	}
  	t1->deleten(10);
  	try {
  	n = t1->search(10);
  	std::cout << "found " << n << "\n";
  	} catch (int e){
    std::cout << 10 << " not found\n";
  	}
}
