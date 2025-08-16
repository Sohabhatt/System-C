// Code your testbench here.
// Uncomment the next line for SystemC modules.
 #include <systemc>
#include "inverter.h"
#include <cstdlib>
#include <cstring>

using namespace std;

int sc_main(int argc, char* argv[])
{
  sc_signal<bool>inv_in,inv_out;
  //Trace pointer - for VCD waves
  sc_trace_file *fp;
  
  inverter inv_mod("inv_mod");
  fp=sc_create_vcd_trace_file("vcd_inv_mod");
  fp->set_time_unit(1.0,SC_NS);
                              
  inv_mod.in(inv_in);
  inv_mod.out(inv_out);
  
  inv_mod.LIB=true;
                              
  inv_in.write(true);
  sc_start(2,SC_NS);
  
  cout<<"@ "<<sc_time_stamp()<<" When the input is "<<inv_in.read()<<" the output is "<<inv_out.read();
  
     return 0;                         
  
}
