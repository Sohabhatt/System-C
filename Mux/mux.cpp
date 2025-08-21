#include<systemc>
using namespace std;
using namespace sc_core;

SC_MODULE (mux) {
  sc_in<bool> I0, I1, sel;
  sc_out<bool> y;
  
  void muxproc() {
     y.write(sel.read() ? I0.read() : I1.read());
     cout << "VALUE OF y is:" << y.read () <<endl; 
     }
  
  SC_CTOR(mux) {
    SC_METHOD(muxproc);
    sensitive << I0 << I1 << sel;
    }

~mux() {
  cout <<"destructor is called. \n" << endl;
  }       
};

int sc_main(int argc, char* argv[]) {

sc_signal<bool> I0, I1, sel, y;

  mux mux1 ("mux1");

  mux1.I0(I0);
  mux1.I1(I1);
  mux1.sel(sel);
  mux1.y(y);
  
  I0 = 0; I1 = 1; sel = 0;
  sc_start(1, SC_NS);

  sel = 1;
  sc_start(1, SC_NS);

  I0 = 1;
  sc_start(1, SC_NS);
   
  cout << "Simulation finished at " << sc_time_stamp() << endl;

  return 0;
}

    
