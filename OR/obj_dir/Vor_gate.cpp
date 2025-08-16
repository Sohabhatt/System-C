// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vor_gate.h for the primary calling header

#include "Vor_gate.h"
#include "Vor_gate__Syms.h"

//==========

VL_SC_CTOR_IMP(Vor_gate) {
    Vor_gate__Syms* __restrict vlSymsp = __VlSymsp = new Vor_gate__Syms(this, name());
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    sensitive << a;
    sensitive << b;
    
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vor_gate::__Vconfigure(Vor_gate__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vor_gate::~Vor_gate() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vor_gate::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vor_gate::eval\n"); );
    Vor_gate__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("or_gate.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vor_gate::_eval_initial_loop(Vor_gate__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("or_gate.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vor_gate::_combo__TOP__1(Vor_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::_combo__TOP__1\n"); );
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__or_gate__b, vlTOPp->b);
    VL_ASSIGN_ISI(1,vlTOPp->__Vcellinp__or_gate__a, vlTOPp->a);
    VL_ASSIGN_SII(1,vlTOPp->y, ((IData)(vlTOPp->__Vcellinp__or_gate__a) 
                                | (IData)(vlTOPp->__Vcellinp__or_gate__b)));
}

void Vor_gate::_eval(Vor_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::_eval\n"); );
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
}

void Vor_gate::_eval_initial(Vor_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::_eval_initial\n"); );
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vor_gate::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::final\n"); );
    // Variables
    Vor_gate__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vor_gate::_eval_settle(Vor_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::_eval_settle\n"); );
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vor_gate::_change_request(Vor_gate__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::_change_request\n"); );
    Vor_gate* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vor_gate::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::_eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

void Vor_gate::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vor_gate::_ctor_var_reset\n"); );
    // Body
    __Vcellinp__or_gate__b = VL_RAND_RESET_I(1);
    __Vcellinp__or_gate__a = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
