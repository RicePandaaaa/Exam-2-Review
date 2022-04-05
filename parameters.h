#include <iostream>

// Pass by value
void passByValue(int n);

// Pass by variable reference
void passByVarReference(int& n);

// Pass by pointer
void passByPointer(int* map);

// Pass by constant
void passByConstant1(const int** map);
void passByConstant2(int*const* map);
void passByConstant3(const int*const* map);