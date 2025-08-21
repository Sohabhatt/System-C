#include <systemc>
using namespace std;
using namespace sc_core;

SC_MODULE(consumer) {
    sc_fifo_in<int> in;

    void give() {
        while (true) {
            int val = in.read();  
            cout << "Value received: " << val
                 << " at " << sc_time_stamp() << endl;
            wait(1, SC_NS);
        }
    }

    SC_CTOR(consumer) {
        SC_THREAD(give);
    }
};

SC_MODULE(producer) {
    sc_fifo_out<int> out;

    void produce() {
        for (int i = 1; i <= 5; i++) {
            out.write(i * 100);   
            cout << "Produced: " << i * 100
                 << " at " << sc_time_stamp() << endl;
            wait(1, SC_NS);
        }
    }

    SC_CTOR(producer) {
        SC_THREAD(produce);
    }
};

int sc_main(int argc, char* argv[]) {
    sc_fifo<int> fifo(10);  
    consumer consumer1("consumer1");
    producer producer1("producer1");

    consumer1.in(fifo);
    producer1.out(fifo);

    sc_start(10, SC_NS);
    return 0;
}
