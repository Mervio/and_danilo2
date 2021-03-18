#include <systemc.h>

SC_MODULE(tb)
{
    sc_out<bool > a, b;
    sc_in<bool > f;
    sc_in_clk clk;

    void source();
    void sink();

    SC_CTOR(tb){
        SC_CTHREAD(source, clk.pos() );
        SC_CTHREAD(sink,   clk.pos() );
    }


};