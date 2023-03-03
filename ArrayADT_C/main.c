#include <stdlib.h>
#include <stdio.h>
#include "ArrayADT.h"
#include "CUnit/Basic.h"
void appendTest()
{
    struct ArrayADT *x = Init(1);
    for (int i = 0; i < 5; i++)
    {
        Append(x, i);
    }
    CU_ASSERT_EQUAL(x->length, 5);
    CU_ASSERT_EQUAL(x->size, 8);
    for (int i = 0; i < x->length; i++)
    {
        CU_ASSERT_EQUAL(x->A[i], i);
    }
    free(x);
}
void DeleteTest()
{
    struct ArrayADT *x = Init(1);
    for (int i = 0; i < 5; i++)
    {
        Append(x, i);
    }
    for (int i = 0; i < 5; i++)
    {
        int rem = Delete(x, 0);
        CU_ASSERT_EQUAL(rem, i);
    }
    CU_ASSERT_EQUAL(x->length, 0);
    CU_ASSERT_EQUAL(x->size, 1);
}
void InsertTest()
{

    // 9 0 1 7 2 3 20 30 4

    struct ArrayADT *x = Init(1);
    for (int i = 0; i < 5; i++)
    {
        Append(x, i);
    }
    Insert(x, 9, 0);
    CU_ASSERT_EQUAL(x->length, 6);
    CU_ASSERT_EQUAL(x->A[0], 9);

    Insert(x, 7, 3);
    CU_ASSERT_EQUAL(x->length, 7);
    CU_ASSERT_EQUAL(x->A[3], 7);

    Insert(x, 20, 6);
    CU_ASSERT_EQUAL(x->length, 8);
    CU_ASSERT_EQUAL(x->A[6], 20);

    CU_ASSERT_EQUAL(x->size, 8);

    Insert(x, 30, 7);
    CU_ASSERT_EQUAL(x->length, 9);
    CU_ASSERT_EQUAL(x->A[7], 30);

    CU_ASSERT_EQUAL(x->size, 16);
}
void LinearSearchTest()
{
    struct ArrayADT *x = Init(5);
    for (int i = 0; i < 5; i++)
    {
        Append(x, i);
    }

    int res = LinearSearch(x, 4);
    CU_ASSERT_EQUAL(res, 4);

    res = LinearSearch(x, 1);
    CU_ASSERT_EQUAL(res, 1);

    res = LinearSearch(x, 3);
    CU_ASSERT_EQUAL(res, 3);

    res = LinearSearch(x, 7);
    CU_ASSERT_EQUAL(res, -1);
}
void BinarySearchTest()
{
    struct ArrayADT *x = Init(5);
    for (int i = 0; i < 5; i++)
    {
        Append(x, i);
    }

    int res = BinarySearch(x, 4);
    CU_ASSERT_EQUAL(res, 4);

    res = BinarySearch(x, 1);
    CU_ASSERT_EQUAL(res, 1);

    res = BinarySearch(x, 3);
    CU_ASSERT_EQUAL(res, 3);

    res = BinarySearch(x, 7);
    CU_ASSERT_EQUAL(res, -1);
}
int main()
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    CU_pSuite pSuite = NULL;                        // Add a suite to the registry
    pSuite = CU_add_suite("core_test_suite", 0, 0); // Always check if add was successful
    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    } // Add the test to the suite
    if (NULL == CU_add_test(pSuite, "append_test", appendTest))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "delete_test", DeleteTest))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "insert_test", InsertTest))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "Linear_search_test", LinearSearchTest))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "binary_search_test", BinarySearchTest))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
    // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
    CU_basic_set_mode(CU_BRM_VERBOSE); // Run the tests and show the run summary
    CU_basic_run_tests();
    return CU_get_error();
}