#include<systemc>
using namespace sc_core;
using namespace std;

SC_MODULE (Module1) {
   SC_CTOR (Module1) {
     SC_METHOD(process1);
     }
     
  void process1() {
     cout << "Process is : 1 " << endl;
     }
  
 ~Module1(){
   cout <<" Destructor 2 is called .\n" <<endl;
   }
 };
  
 SC_MODULE (Module2) {
  sc_in <bool> clk;
  
   SC_CTOR (Module2) {
     SC_THREAD (process2);
     sensitive <<clk.pos();
     }
     
    void process2() {
     wait(10, SC_NS);
     cout << "Process is : 2 " << endl;
     }

 ~Module2(){
   cout <<" Destructor 2 is called .\n" <<endl;
   }
};   
 
 int sc_main(int argc, char* argv[]) {
   sc_clock clk("clk", 10, SC_NS); 
   Module1 module1 ("module1");
   Module2 module2 ("module2");
   module2.clk(clk);
   sc_start();
   return 0;
 }       
        
