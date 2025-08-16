#include <systemc.h>
#include "Vand_gate.h"
#include "verilated_vcd_sc.h"

int sc_main(int argc, char** argv) {
    sc_signal<bool> a, b, y;

    // Instantiate DUT
    Vand_gate dut("dut");
    dut.a(a);
    dut.b(b);
    dut.y(y);

    // Trace setup (optional)
   // Verilated::traceEverOn(true);
   // VerilatedVcdSc* tfp = new VerilatedVcdSc;
   // dut.trace(tfp, 99);
   // tfp->open("wave.vcd");

    // Apply test vectors
    a = 0; b = 0; sc_start(10, SC_NS);
    std::cout << "a=0, b=0 -> y=" << y.read() << std::endl;

    a = 0; b = 1; sc_start(10, SC_NS);
    std::cout << "a=0, b=1 -> y=" << y.read() << std::endl;

    a = 1; b = 0; sc_start(10, SC_NS);
    std::cout << "a=1, b=0 -> y=" << y.read() << std::endl;

    a = 1; b = 1; sc_start(10, SC_NS);
    std::cout << "a=1, b=1 -> y=" << y.read() << std::endl;

    //tfp->close();
    //delete tfp;
    return 0;
}
