#include<systemc>
#include<iostream>

using namespace sc_dt;
using namespace sc_core;
using namespace std;

extern "C" void half_adder (unsigned char a, unsigned char b, unsigned char *sum, unsigned char *carry)
{
   *sum = a ^ b;
   *carry = a & b;

}

