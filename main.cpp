#include "dataset.h"
#include <iostream>

int main()
{
    Dataset data(10);
    data.print();
    data.sortDataset();
    data.print();
}
