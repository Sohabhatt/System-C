#include <systemc.h>
using namespace std;
using namespace sc_core;

SC_MODULE(producer) {
  sc_fifo_out<int> out;

  void process() {
    for (int i = 10; i <= 20; i++) {
      wait(1, SC_NS);

      if(out.nb_write(i)){
        cout << "Producer " << sc_time_stamp() << " : Writing " << i << endl;
      }
      else
      {
        cout << "FIFO full" << endl;
      }
    }
  }

  SC_CTOR(producer) {
    SC_THREAD(process);
  }
};

SC_MODULE(consumer) {
  sc_fifo_in<int> in;
  int val;
  
  void process() {
    while (true) {
      if(in.nb_read(val)){
        cout << "Consumer @ " << sc_time_stamp() << " : Read " << val << endl;
      }
      else {
        cout << "FIFO empty" << endl;
        wait(1, SC_NS);
      }
      wait(1, SC_NS);
    }
  }

  SC_CTOR(consumer) {
    SC_THREAD(process);
  }
};

int sc_main(int argc, char* argv[]) {
  sc_fifo<int> fifo(3); 

  producer prod ("prod");
  consumer cons ("cons");

  prod.out(fifo);
  cons.in(fifo);

  sc_start(100, SC_NS); 
  return 0;
}
