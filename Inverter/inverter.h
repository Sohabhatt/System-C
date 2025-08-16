#include <systemc.h>
using namespace std;

SC_MODULE(inverter)
{
  sc_in<bool>in;
  sc_out<bool>out;
  
  bool LIB;
  
  void inv_func()
  {
    while(1)
    {
      wait();
      if(LIB==1)
      {
        out.write(!(in.read()));
      }
    }
  }
  SC_CTOR(inverter) // Constructor
                  {
                    SC_THREAD(inv_func);
                    sensitive<<in;
                    
                  }
                  //Destructor
  ~inverter(){};
};
