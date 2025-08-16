// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_sc.h"
#include "Vand_gate__Syms.h"


//======================

void Vand_gate::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vand_gate* t = (Vand_gate*)userthis;
    Vand_gate__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vand_gate::traceChgThis(Vand_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    if (false && vcdp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vand_gate::traceChgThis__2(Vand_gate__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vand_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* oldp = vcdp->oldp(code+1);
    if (false && vcdp && oldp) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(oldp+0,(vlTOPp->__Vcellinp__and_gate__a));
        vcdp->chgBit(oldp+1,(vlTOPp->__Vcellinp__and_gate__b));
        vcdp->chgBit(oldp+2,(((IData)(vlTOPp->__Vcellinp__and_gate__a) 
                              & (IData)(vlTOPp->__Vcellinp__and_gate__b))));
    }
}
