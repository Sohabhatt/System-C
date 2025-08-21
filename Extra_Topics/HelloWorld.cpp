#include<systemc>
using namespace sc_core;
using namespace std;

SC_MODULE (HelloWorld) {
    SC_CTOR(HelloWorld) {
       SC_THREAD(hello);
       }
       
  void hello () {
     cout << " Hello World! " << endl;
     }     
  };   
int sc_main(int argc, char* argv[] ) {
  HelloWorld hello ("hello");
  sc_start();
  return 0;
}       
