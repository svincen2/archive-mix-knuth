#include "field_spec_convert.h"


// Divisor to separate field specification L and R values.
const mix_byte FIELD_SPEC_DIVISOR = 8;


/*
* Return the L (left) part of the field specification value.
* param field_spec - Field specification.
* return unsigned char - Left part of field specification.
*/
mix_byte field_l(mix_byte field_spec)
{
    return field_spec / FIELD_SPEC_DIVISOR;
}


/*
* Return the R (right) part of the field specification value.
* param field_spec - Field specification.
* return unsigned char - Right part of field specification.
*/
mix_byte field_r(mix_byte field_spec)
{
    return field_spec % FIELD_SPEC_DIVISOR;
}


/*
* Return a field specification value for the given left and right values.
* param left - Left part of field specification.
* param right - Right part of field specification.
* return unsigned char - Resulting field specification.
*/
mix_byte field_spec(mix_byte left, mix_byte right)
{
    return left * 8 + right;
}

