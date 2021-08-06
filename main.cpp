#include <vector>
#include "List.h"

using namespace std;

int main(){
   
   List<int> l;
   l.insert(1);
   l.insert(2);
   l.insert(3);
   l.insert(3);
   l.insertAfter(5, 2);
   l.insertAt(5, 0);
   //l.priorityInsert(7,1);
   l.remove(2);
   l.removeAll(3);
   cout << l.getFirst() << endl;
   l.contains(3);
   
   l.print("s");
   
   
   return 0;
}

