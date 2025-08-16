# 📘 SystemC and TLM 2.0 Simulation Projects

This repository contains basic hardware modeling projects implemented using **SystemC** and **TLM 2.0 (Transaction-Level Modeling)**. Examples include:

- ✅ Half Adder (HA)
- ✅ Full Adder (FA)
- ✅ Counters
- ✅ Simple Arithmetic Units

---

## 💡 What is SystemC?

**SystemC** is a C++ class library and simulation kernel used for modeling and simulating hardware systems at various abstraction levels. It is widely used in:

- Electronic System Level (ESL) design
- Functional and behavioral modeling
- Hardware/software co-design
- TLM 2.0 modeling for faster simulation of complex designs

SystemC allows designers to write and simulate hardware designs using standard C++ syntax, making it a powerful tool for pre-silicon verification and architectural modeling.

---

## ⚙️ How to Install SystemC (Locally)

Follow the steps below to install **SystemC 2.3.3** on a Linux-based system:

### 1. Install required packages

```bash
sudo apt update
sudo apt install -y build-essential git cmake

2. Download and extract SystemC

mkdir -p $HOME/systemc
cd $HOME/systemc

wget https://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz
tar -xzf systemc-2.3.3.tar.gz
cd systemc-2.3.3

3. Build and install SystemC

mkdir objdir
cd objdir
../configure --prefix=$HOME/systemc/systemc-2.3.3-install
make -j$(nproc)
make install

4. Set environment variables

Add these to your ~/.bashrc or ~/.zshrc:

export SYSTEMC_HOME=$HOME/systemc/systemc-2.3.3-install
export LD_LIBRARY_PATH=$SYSTEMC_HOME/lib-linux64:$LD_LIBRARY_PATH
export CPLUS_INCLUDE_PATH=$SYSTEMC_HOME/include:$CPLUS_INCLUDE_PATH

Then apply the changes:

source ~/.bashrc

🖥️ How to Run the Code
Option 1: Run Locally

You can compile and run any module using g++:

g++ -I$SYSTEMC_HOME/include -L$SYSTEMC_HOME/lib-linux64 \
    -o run_module folder/initiator.cpp folder/target.cpp folder/main.cpp \
    -lsystemc -lm
./run_module

Replace folder/ with the name of the subdirectory (e.g., ha, fa, counter).
Option 2: Run on EDA Playground

If you don't want to install SystemC locally, you can:

    Use EDA Playground

    Select SystemC (IEEE 1666) as the simulator

    Copy-paste your code into the editor

    Run simulations online with waveform support

    Note: EDA Playground supports small-scale SystemC projects only.
