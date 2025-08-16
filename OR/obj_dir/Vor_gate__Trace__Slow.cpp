// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_sc.h"
#include "Vor_gate__Syms.h"


//======================

void Vor_gate::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vor_gate::traceInit, &Vor_gate::traceFull, &Vor_gate::traceChg, this);
}
void Vor_gate::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vor_gate* t = (Vor_gate*)userthis;
    Vor_gate__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vor_gate::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vor_gate* t = (Vor_gate*)userthis;
    Vor_gate__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vor_gate::traceInitThis(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vor_gate::traceFullThis(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vor_gate::traceInitThis__1(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (false && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"or_gate a", false,-1);
        vcdp->declBit(c+2,"or_gate b", false,-1);
        vcdp->declBit(c+3,"or_gate y", false,-1);
    }
}

void Vor_gate::traceFullThis__1(Vor_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(oldp+0,(vlTOPp->__Vcellinp__or_gate__a));
        vcdp->fullBit(oldp+1,(vlTOPp->__Vcellinp__or_gate__b));
        vcdp->fullBit(oldp+2,(((IData)(vlTOPp->__Vcellinp__or_gate__a) 
                               | (IData)(vlTOPp->__Vcellinp__or_gate__b))));
    }
}
