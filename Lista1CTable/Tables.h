#ifndef TABLES_H
#define TABLES_H


#include <string>

const int FILL_TABLE_WITH = 34;
const std::string WRONG_TABLE_SIZE_MSG = "Table length cannot be less than 0!\n";
const std::string NULLPTR_PASSED_MSG = "Cannot pass nullptr!\n";

void v_alloc_table_fill_34(int iSize);
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int*** piTable, int iSizeX);

#endif