#include <systemc.h>

SC_MODULE(andgate)
{
    sc_in<bool> clk;
    sc_in<bool > a, b;
    sc_out<bool > f;

    void do_andgate();

    SC_CTOR(andgate){
        SC_CTHREAD(do_andgate, clk.pos());
    }

};

// class andgate{
//     // private:

//     public:
//         sc_in<bool> clk;
//         sc_in<bool > a, b;
//         sc_out<bool > f;

//         sc_in<bool> rst_n;

//         void do_andgate();
//         andgate(sc_module_name nm){
//             SC_CTHREAD(do_andgate, clk.pos());
//             async_reset_signal_is(rst_n, false);

//         }
//         SC_HAS_PROCESS(andgate);
// };