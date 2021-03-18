#include <systemc.h>
#include <andgate.h>

void andgate::do_andgate(){
    //init
    wait();
    if(reset){
        //reset func
    }
    while(true){
        f.write(a.read() & b.read());
        wait();
    }
}