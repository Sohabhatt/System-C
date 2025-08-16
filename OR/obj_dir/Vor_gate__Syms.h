// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VOR_GATE__SYMS_H_
#define _VOR_GATE__SYMS_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vor_gate.h"

// SYMS CLASS
class Vor_gate__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vor_gate*                      TOPp;
    
    // CREATORS
    Vor_gate__Syms(Vor_gate* topp, const char* namep);
    ~Vor_gate__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
