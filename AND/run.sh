set -e

# Step 1: Clean previous
rm -rf obj_dir wave.vcd Vand_gate

# Step 2: Run Verilator
verilator --cc --sc and_gate.sv --exe tb.cpp --trace

# Step 3: Compile
make -C obj_dir -f Vand_gate.mk Vand_gate

# Step 4: Run
./obj_dir/Vand_gate

# Step 5: View wave
gtkwave wave.vcd
