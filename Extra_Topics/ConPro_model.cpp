#include<systemc>
using namespace std;
using namespace sc_core;

SC_MODULE (consumer) {
  sc_in<int> in;
  
  void give() {
    cout << "Value received: " << in.read() << endl;
    }
 
 SC_CTOR(consumer) {
   SC_METHOD (give) ;
   sensitive << in;
   }
 };
 
 SC_MODULE (producer) {
   sc_out <int> out;
   
   void produce() {
     out.write(100);
     cout << "Produced: "<< out.read() << endl;
     }
   
   SC_CTOR (producer) {
     SC_METHOD (produce);
     }
 };
 
 int sc_main (int argc, char* argv[]) {
   sc_signal<int> signal;
   
   consumer consumer1 ("consumer1");
   producer producer1 ("producer1");
   
   consumer1.in(signal);
   producer1.out(signal);
   
   sc_start();
   return 0;
  } 
