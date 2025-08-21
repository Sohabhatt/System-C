# System C 

This repository contains basic hardware modeling projects implemented using **SystemC** and **TLM 2.0 (Transaction-Level Modeling)**. 

---

## What is SystemC?

**SystemC** is a C++ class library and simulation kernel used for modeling and simulating hardware systems at various abstraction levels. It is widely used in:

- Electronic System Level (ESL) design
- Functional and behavioral modeling
- Hardware/software co-design


SystemC allows designers to write and simulate hardware designs using standard C++ syntax, making it a powerful tool for pre-silicon verification and architectural modeling.

---

## Key Concepts of SystemC

### Module (sc_module)
Basic building block representing hardware components or systems.

### Processes
Functions that define the behavior of modules. Three types:

**SC_METHOD: Runs instantly, no internal wait; sensitive to signals/events.**

**SC_THREAD: Can include waits and pauses; models sequential behavior.**

**SC_CTHREAD: Clocked thread process, triggered on clock edges.**

### Ports and Interfaces
Used for communication between modules; define inputs and outputs.

### Channels
Communication mechanisms between modules (e.g., signals, FIFOs).

### Events and Sensitivity
Processes can be triggered by changes in signals or explicit events.

### Simulation Kernel
Manages execution, scheduling processes based on events and time.

### Time and Timing
Supports simulation time with classes like sc_time, enabling timed delays and synchronization.

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

### Use EDA Playground.
### Select SystemC (IEEE 1666) as the simulator.
### Copy-paste your code into the editor.
### Run simulations online with waveform support.
### ~ Note: EDA Playground supports small-scale SystemC projects only.

## Feel Free to Collaborate

Contributions are welcome!
Whether you're fixing bugs, adding new modules, or improving documentation. Your input is appreciated.

Fork the repo, make changes, and open a pull request!
Let’s make hardware modeling more accessible for everyone.

## License

This project is intended for educational and academic purposes. Free to use and modify.
