// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VOR_GATE_H_
#define _VOR_GATE_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

//==========

class Vor_gate__Syms;
class Vor_gate_VerilatedVcd;


//----------

SC_MODULE(Vor_gate) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    sc_in<bool> a;
    sc_in<bool> b;
    sc_out<bool> y;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vcellinp__or_gate__b;
    CData/*0:0*/ __Vcellinp__or_gate__a;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vor_gate__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vor_gate);  ///< Copying not allowed
  public:
    SC_CTOR(Vor_gate);
    virtual ~Vor_gate();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// SC tracing; avoid overloaded virtual function lint warning
    virtual void trace(sc_trace_file* tfp) const { ::sc_core::sc_module::trace(tfp); }
    
    // API METHODS
  private:
    void eval() { eval_step(); }
    void eval_step();
  public:
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vor_gate__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vor_gate__Syms* symsp, bool first);
  private:
    static QData _change_request(Vor_gate__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vor_gate__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vor_gate__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vor_gate__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vor_gate__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
