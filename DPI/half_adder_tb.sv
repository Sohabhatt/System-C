module half_adder_tb;

  bit a, b;
  byte sum_out, carry_out;

  import "DPI-C" function void half_adder (
    input byte a,
    input byte b,
    output byte sum,
    output byte carry
  );

  initial begin
    $dumpfile("dump.vcd");
    $dumpvars;  
  end

  initial begin
    a = 0; b = 0;
    half_adder(a, b, sum_out, carry_out);
    $display("a = %0d, b = %0d, sum_out = %0d, carry_out = %0d", a, b, sum_out, carry_out);
    #5;

    a = 0; b = 1;
    half_adder(a, b, sum_out, carry_out);
    $display("a = %0d, b = %0d, sum_out = %0d, carry_out = %0d", a, b, sum_out, carry_out);
    #5;

    a = 1; b = 0;
    half_adder(a, b, sum_out, carry_out);
    $display("a = %0d, b = %0d, sum_out = %0d, carry_out = %0d", a, b, sum_out, carry_out);
    #5;

    a = 1; b = 1;
    half_adder(a, b, sum_out, carry_out);
    $display("a = %0d, b = %0d, sum_out = %0d, carry_out = %0d", a, b, sum_out, carry_out);
    #5;
  end

  initial begin
    #50;
    $finish;
  end

endmodule
