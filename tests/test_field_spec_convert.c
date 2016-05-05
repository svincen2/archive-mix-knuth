#include "../field_spec_convert.h"
#include <assert.h>
#include <stdio.h>


void assert_field_spec(mix_byte exp,
                       mix_byte left,
                       mix_byte right)
{
    mix_byte fs = field_spec(left, right);
    assert(exp == fs);
    printf("Left = %d, Right = %d, Expected = %d PASSED\n", left, right, exp);
}

void assert_field_left(mix_byte exp, mix_byte fs)
{
    mix_byte l = field_l(fs);
    assert(exp == l);
    printf("Field spec = %d, Left = %d, Expected = %d PASSED\n", fs, l, exp);
}

void assert_field_right(mix_byte exp, mix_byte fs)
{
    mix_byte r = field_r(fs);
    assert(exp == r);
    printf("Field spec = %d, Right = %d, Expected = %d PASSED\n", fs, r, exp);
}

void test_field_spec()
{
    assert_field_spec(13, 1, 5);
    assert_field_spec(0, 0, 0);
    assert_field_spec(5, 0, 5);
    assert_field_spec(37, 4, 5);
    assert_field_spec(28, 3, 4);
}

void test_field_l()
{
    assert_field_left(0, 5);
    assert_field_left(1, 13);
    assert_field_left(4, 37);
    assert_field_left(3, 28);
}

void test_field_r()
{
    assert_field_right(0, 0);
    assert_field_right(5, 5);
    assert_field_right(5, 13);
    assert_field_right(5, 37);
    assert_field_right(4, 28);
}

int main()
{
    test_field_spec();
    test_field_l();
    test_field_r();
    return 0;
}
