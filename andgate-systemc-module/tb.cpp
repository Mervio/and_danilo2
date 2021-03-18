#include "tb.h"
#include "terminal_color.h"

void tb::source(){
    // Reset

    //wait();

    // Functionality
    bool a_stim, b_stim = false;
    for (int i = 0; i<=1; i++){
        for (int j = 0; j<=1; j++){
            a.write(a_stim);
            b.write(b_stim);
            wait();
            b_stim = ~b_stim;
        }
        a_stim = ~a_stim;
    }
    wait();
    sc_stop();

}

void tb::sink(){
    bool f_in;
    bool passed = 1;
    for (int i =0; i<4; i++){
        wait();
        f_in = f;
        cout << i << " :\t" << f_in << endl;
        if ((i < 3 && f_in == 1 ) || (i == 3 && f_in == 0)){
            passed = 0;
        }
    }
    if (passed){
        cout << BOLDGREEN << "PASS!!!" << RESET << endl;
    }
    else{
        cout << BOLDRED << "FAIL!!!" << RESET << endl;
    }
    sc_stop();
}