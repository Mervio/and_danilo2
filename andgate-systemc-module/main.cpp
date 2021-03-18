#include <systemc.h>
#include "andgate.h"
#include "tb.h"

int sc_main(int argc, char** argv){

    // Signals
    sc_signal<bool > a_sig, b_sig;
    sc_signal<bool > f_sig;

    // Clock
    //period, timestep, duty, first edge, value of first edge
    sc_clock clk_sig("clk", 10, SC_NS, 0.5, 0.0, SC_NS);

    // Connections
    // andgate a1
    andgate a1("AND1");
    a1.clk(clk_sig);
    a1.a  (a_sig);
    a1.b  (b_sig);
    a1.f  (f_sig);

    // testbench
    tb tb1("TESTBENCH");
    tb1.clk(clk_sig);
    tb1.a(a_sig);
    tb1.b(b_sig);
    tb1.f(f_sig);
    

    // start the simulation
    sc_start();
    return 0;
}