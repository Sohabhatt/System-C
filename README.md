# System C 

This repository contains basic hardware modeling projects implemented using **SystemC**. 

---

## What is SystemC?

**SystemC** is a C++ class library and simulation kernel used for modeling and simulating hardware systems at various abstraction levels. It is widely used in:

- Electronic System Level (ESL) design
- Functional and behavioral modeling
- Hardware/software co-design
- Supports concurrent process modeling like Verilog/VHDL.
- Can simulate timing and concurrency.
- Allows modular and hierarchical design.

SystemC allows designers to write and simulate hardware designs using standard C++ syntax, making it a powerful tool for pre-silicon verification and architectural modeling.

---

## Key Concepts of SystemC

### Module (sc_module)
Basic building block representing hardware components or systems.

```
SC_MODULE (Modname) {
  SC_CTOR (Modname) {
     //Declare Process
  }
};
```
### Constructor (SC_CTOR) 
  - Initializes the module
  - Registers the process (SC_METHOD, SC_THREAD, SC_CTHREAD)
  - Build ports to signals
  - Called once at the beginning of the simulation.

### Destructor (~ModuleName())
  - Optional
  - Cleans up resources (like file handles or dynamic memory)
  - Called after the simulation ends or the object is detected.

```
SC_MODULE(Modname) {  
 SC_CTOR(Modname) {  //Constructor
  SC_METHOD(process);
  sensitive << clk.pos();
  cout << " Constructor is called. \n" << endl;
}

~Modname() { // Destructor
  cout << "Destructor is called. \n" << endl;
}

void process () {
  //Process logic
 }
};
```

### Processes
Functions that define the behavior of modules. Three types:

**SC_METHOD:**  
  - Runs instantly.
  - No internal wait or zero delay
  - Sensitive to signals/events.

**SC_THREAD:**
  - Can include wait() statement
  - Models sequential behavior.
  - Supports delays.

**SC_CTHREAD:**
  - Clocked thread process
  - Triggered on clock edges.

### Ports and Interfaces
Used for communication between modules; defines inputs and outputs.
**sc_in<T> -> Input port**
**sc_out<T> -> Output port**
**sc_signal<T> -> Signal for communication**
**sc_clock -> Clock signal**

### Channels
 - Communication mechanisms between modules (e.g., signals, FIFOs).

### Events and Sensitivity
  - Processes can be triggered by changes in signals or explicit events.
  - SystemC uses simulation time to model hardware behavior.

**sc_start() -> Starts the simulation.**
**wait() -> Used in threads to suspend or resume.**
**sc_time() -> Defines specific time units ( eg," sc_time (10, SC_NS) ).**
**SC_ZERO_TIME -> Zero time constant.**

### Simulation Kernel
Manages execution, scheduling processes based on events and time.

### Hierarchy
  - Modules can be instantiated under different modules to create a hierarchical system design.

### Tracing and Debugging
  - Use " sc_trace () " to record signal values during simulation.
```
sc_trace_file* tf = sc_create_vcd_trace_file ("wave");
sc_trace (tf, signal_name. "signal_label");
sc_close_vcd_trace_file(tf);
```

### DataTypes

| Type        |                            Description         |
|**sc_int<N>**|  Signed Integer with "n" bits.                 |
|**sc_uint<N>**  |  Unsigned Integer with "n" bits.               |
|**sc_bigint<N>** |  Larger Signed Integer with "n" bits.          |
|**sc_logic**     |  Supports 4-valued logic: 0, 1, X, Z .         |
|**sc_fixed**     |  Fixed point numbers.                          |








## ⚙️ How to Install SystemC (Locally)

Follow the steps below to install **SystemC 2.3.3** on a Linux-based system:

### 1. Install required packages

```bash
sudo apt update
sudo apt install -y build-essential git cmake
```
### 2. Download and extract SystemC
```
mkdir -p $HOME/systemc
cd $HOME/systemc

wget https://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
tar -xzf systemc-2.3.3.tar.gz
cd systemc-2.3.3
```
### 3. Build and install SystemC
```
mkdir objdir
cd objdir
../configure --prefix=$HOME/systemc/systemc-2.3.3-install
make -j$(nproc)
make install
```
### 4. Set environment variables

Add these to your ~/.bashrc or ~/.zshrc:
```
export SYSTEMC_HOME=$HOME/systemc/systemc-2.3.3-install
export LD_LIBRARY_PATH=$SYSTEMC_HOME/lib-linux64:$LD_LIBRARY_PATH
export CPLUS_INCLUDE_PATH=$SYSTEMC_HOME/include:$CPLUS_INCLUDE_PATH
```
Then apply the changes:
```
source ~/.bashrc
```
## How to Run the Code
### Option 1: Run Locally

You can compile and run any module using g++:
```
g++ -I$SYSTEMC_HOME/include -L$SYSTEMC_HOME/lib-linux64 \
    -o run_module folder/initiator.cpp folder/target.cpp folder/main.cpp \
    -lsystemc -lm
./run_module
```
Replace folder/ with the name of the subdirectory (e.g., ha, fa, counter).
### Option 2: Run on EDA Playground

If you don't want to install SystemC locally, you can:

#### Use EDA Playground :
   Select SystemC (IEEE 1666) as the simulator.
   Copy-paste your code into the editor.
   Run simulations online with waveform support.
#### ~ Note: EDA Playground supports small-scale SystemC projects only.

## Feel Free to Collaborate

Contributions are welcome!
Whether you're fixing bugs, adding new modules, or improving documentation. Your input is appreciated.

Fork the repo, make changes, and open a pull request!
Let’s make hardware modeling more accessible for everyone.

## License

This project is intended for educational and academic purposes. Free to use and modify.
