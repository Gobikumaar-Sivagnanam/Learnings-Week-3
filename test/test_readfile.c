#include "read.h"
#include "unity_internals.h"
#include "unity.h"

void setUp(){

}

void tearDown(){

}
FILE *fptr;

void test_csv(void){
    TEST_ASSERT_EQUAL(readfile("data.csv","r",&fptr), SUCCESS);
    TEST_ASSERT_EQUAL(readfile("hello.csv","r",&fptr), FILE_NOT_FOUND);
}

int main(void){
    UNITY_BEGIN();

    RUN_TEST(test_csv);

    return UNITY_END();
}