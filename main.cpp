#include <iostream>
#include "IDataList.h"

int main() {
    auto *l1 = new DataList(new LinkedList());
    l1->insert(1,0);
    l1->insert(2,1);
    l1->insert(0,2);
    l1->insert(-1,0);
    l1->removeAt(0);
    l1->removeAt(2);
    l1->print();
    std::cout << std::to_string(l1->get(1));
    return 0;
}
