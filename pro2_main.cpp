#include"systemc.h"
#include"pro2_pro.h"
#include"pro2_robot1.h"
#include"pro2_robot2.h"
#include"pro2_ser.h"
#include"pro2_mon.cpp"
#include"pro2_robot3.h"
#include"pro2_robot4.h"
int sc_main(int argc, char*argv[]){

   sc_clock clk("clk1",10,SC_MS);
   sc_signal<bool> sig1; //pro to r1
   sc_signal<bool> sig2; //pro to r2
   sc_signal<bool> sig3; //pro to r3
   sc_signal<bool> sig4; //pro to r4
   sc_signal<bool> sig5; //r1 to pro
   sc_signal<bool> sig6; //r2 to pro
   sc_signal<bool> sig7; //r3 to pro
   sc_signal<bool> sig8; //r4 to pro
   sc_signal<bool> sig9; //r1 to ser
   sc_signal<bool> sig10; //r2 to ser
   sc_signal<bool> sig11; //r3 to ser
   sc_signal<bool> sig12; //r4 to ser
   sc_signal<bool> sig13; //ser to r1
   sc_signal<bool> sig14; //ser to r2
   sc_signal<bool> sig15; //ser to r3
   sc_signal<bool> sig16; //ser to r4
   sc_signal<sc_uint<14> > index1; //pro to r1
   sc_signal<sc_uint<14> > index2; //pro to r2
   sc_signal<sc_uint<14> > index3; //pro to r3
   sc_signal<sc_uint<14> > index4; //pro to r4
   sc_signal<sc_uint<14> > index5; //r1 to ser
   sc_signal<sc_uint<14> > index6; //r2 to ser
   sc_signal<sc_uint<14> > index7; //r3 to ser
   sc_signal<sc_uint<14> > index8; //r4 to ser
   sc_signal<sc_uint<4> > status1; //ser to r1
   sc_signal<sc_uint<4> > status2; //ser to r2
   sc_signal<sc_uint<4> > status3; //ser to r3
   sc_signal<sc_uint<4> > status4; //ser to r4
   sc_signal<sc_uint<4> > status5; //r1 to pro
   sc_signal<sc_uint<4> > status6; //r2 to pro
   sc_signal<sc_uint<4> > status7; //r3 to pro
   sc_signal<sc_uint<4> > status8; //r4 to pro
   sc_signal<double> x1_1; // x1 to monitor
   sc_signal<double> x2_1; // x2 to monitor
   sc_signal<double> y1_1; // y1 to monitor
   sc_signal<double> y2_1; // y2 to monitor
   sc_signal<double> x3_1; // x3 to monitor
   sc_signal<double> x4_1; // x4 to monitor
   sc_signal<double> y3_1; // y3 to monitor
   sc_signal<double> y4_1; // y4 to monitor
   sc_signal<double> o1x1_1; //obstacle1 to monitor
   sc_signal<double> o1y1_1; //obstacle1 to monitor
   sc_signal<double> o1x2_1; //obstacle1 to monitor
   sc_signal<double> o1y2_1; //obstacle1 to monitor
   sc_signal<double> o2x1_1; //obstacle2 to monitor
   sc_signal<double> o2y1_1; //obstacle2 to monitor
   sc_signal<double> o2x2_1; //obstacle2 to monitor
   sc_signal<double> o2y2_1; //obstacle2 to monitor
   sc_signal<double> o3x1_1; //obstacle1 to monitor
   sc_signal<double> o3y1_1; //obstacle1 to monitor
   sc_signal<double> o3x2_1; //obstacle1 to monitor
   sc_signal<double> o3y2_1; //obstacle1 to monitor
   sc_signal<double> o4x1_1; //obstacle2 to monitor
   sc_signal<double> o4y1_1; //obstacle2 to monitor
   sc_signal<double> o4x2_1; //obstacle2 to monitor
   sc_signal<double> o4y2_1; //obstacle2 to monitor
   sc_signal<double> o5x1_1; //obstacle1 to monitor
   sc_signal<double> o5y1_1; //obstacle1 to monitor
   sc_signal<double> o5x2_1; //obstacle1 to monitor
   sc_signal<double> o5y2_1; //obstacle1 to monitor
   sc_signal<double> o6x1_1; //obstacle2 to monitor
   sc_signal<double> o6y1_1; //obstacle2 to monitor
   sc_signal<double> o6x2_1; //obstacle2 to monitor
   sc_signal<double> o6y2_1; //obstacle2 to monitor

   sc_fifo<int> fifo1(6);
   sc_fifo<int> fifo2(6);
   sc_fifo<int> fifo3(6);
   sc_fifo<int> fifo4(6);
   sc_fifo<int> fifo11(6);
   sc_fifo<int> fifo21(6);
   sc_fifo<int> fifo31(6);
   sc_fifo<int> fifo41(6);
   sc_fifo<int> fifo5(2);
   sc_fifo<int> fifo6(1);
   sc_fifo<int> fifo7(1);
   sc_fifo<int> fifo8(1);
   sc_fifo<int> fifo51(2);
   sc_fifo<int> fifo61(1);
   sc_fifo<int> fifo71(1);
   sc_fifo<int> fifo81(1);

   processing pro1("processing1");
   robot1 r1("robot1");
   robot2 r2("robot2");
   robot3 r3("robot3");
   robot4 r4("robot4");
   server ser1("server1");
   monitor mon1("monitor1");

   pro1.clock1(clk);
   pro1.re_stat1(status5);
   pro1.re_sig1(sig5);
   pro1.re_stat2(status6);
   pro1.re_sig2(sig6);
   pro1.re_stat3(status7);
   pro1.re_sig3(sig7);
   pro1.re_stat4(status8);
   pro1.re_sig4(sig8);
   pro1.tr_stat1(index1);
   pro1.tr_stat2(index2);
   pro1.tr_sig1(sig1);
   pro1.tr_sig2(sig2);
   pro1.tr_stat3(index3);
   pro1.tr_stat4(index4);
   pro1.tr_sig3(sig3);
   pro1.tr_sig4(sig4);
   pro1.x11(x1_1);
   pro1.x21(x2_1);
   pro1.y11(y1_1);
   pro1.y21(y2_1);
   pro1.x31(x3_1);
   pro1.x41(x4_1);
   pro1.y31(y3_1);
   pro1.y41(y4_1);
   pro1.o1x11(o1x1_1);
   pro1.o1y11(o1y1_1);
   pro1.o1x21(o1x2_1);
   pro1.o1y21(o1y2_1);
   pro1.o2x11(o2x1_1);
   pro1.o2y11(o2y1_1);
   pro1.o2x21(o2x2_1);
   pro1.o2y21(o2y2_1);
   pro1.o3x11(o3x1_1);
   pro1.o3y11(o3y1_1);
   pro1.o3x21(o3x2_1);
   pro1.o3y21(o3y2_1);
   pro1.o4x11(o4x1_1);
   pro1.o4y11(o4y1_1);
   pro1.o4x21(o4x2_1);
   pro1.o4y21(o4y2_1);
   pro1.o5x11(o5x1_1);
   pro1.o5y11(o5y1_1);
   pro1.o5x21(o5x2_1);
   pro1.o5y21(o5y2_1);
   pro1.o6x11(o6x1_1);
   pro1.o6y11(o6y1_1);
   pro1.o6x21(o6x2_1);
   pro1.o6y21(o6y2_1);
   pro1.path11(fifo11);
   pro1.path21(fifo21);
   pro1.path31(fifo31);
   pro1.path41(fifo41);
   pro1.speed11(fifo51);
   pro1.speed21(fifo61);
   pro1.speed31(fifo71);
   pro1.speed41(fifo81);

   r1.ctr_pro1(sig1);
   r1.index_pro1(index1);
   r1.ctr_ser1(sig13);
   r1.status_ser1(status1);
   r1.sig_pro1(sig5);
   r1.status_pro1(status5);
   r1.sig_ser1(sig9);
   r1.index_ser1(index5);
   r1.path_r11(fifo1);
   r1.speed_r11(fifo5);
   r1.path11(fifo11);
   r1.speed11(fifo51);

   r2.ctr_pro2(sig2);
   r2.index_pro2(index2);
   r2.ctr_ser2(sig14);
   r2.status_ser2(status2);
   r2.sig_pro2(sig6);
   r2.status_pro2(status6);
   r2.sig_ser2(sig10);
   r2.index_ser2(index6);
   r2.path_r21(fifo2);
   r2.speed_r21(fifo6);
   r2.path21(fifo21);
   r2.speed21(fifo61);

   r3.ctr_pro3(sig3);
   r3.index_pro3(index3);
   r3.ctr_ser3(sig15);
   r3.status_ser3(status3);
   r3.sig_pro3(sig7);
   r3.status_pro3(status7);
   r3.sig_ser3(sig11);
   r3.index_ser3(index7);
   r3.path_r31(fifo3);
   r3.speed_r31(fifo7);
   r3.path31(fifo31);
   r3.speed31(fifo71);

   r4.ctr_pro4(sig4);
   r4.index_pro4(index4);
   r4.ctr_ser4(sig16);
   r4.status_ser4(status4);
   r4.sig_pro4(sig8);
   r4.status_pro4(status8);
   r4.sig_ser4(sig12);
   r4.index_ser4(index8);
   r4.path_r41(fifo4);
   r4.speed_r41(fifo8);
   r4.path41(fifo41);
   r4.speed41(fifo81);

   ser1.index_rob1(index5);
   ser1.index_rob2(index6);
   ser1.index_rob3(index7);
   ser1.index_rob4(index8);
   ser1.control_r1(sig9);
   ser1.control_r2(sig10);
   ser1.control_r3(sig11);
   ser1.control_r4(sig12);
   ser1.status_rob1(status1);
   ser1.status_rob2(status2);
   ser1.status_rob3(status3);
   ser1.status_rob4(status4);
   ser1.signal_r1(sig13);
   ser1.signal_r2(sig14);
   ser1.signal_r3(sig15);
   ser1.signal_r4(sig16);
   ser1.path_r11(fifo1);
   ser1.path_r21(fifo2);
   ser1.path_r31(fifo3);
   ser1.path_r41(fifo4);
   ser1.speed_r11(fifo5);
   ser1.speed_r21(fifo6);
   ser1.speed_r31(fifo7);
   ser1.speed_r41(fifo8);


   mon1.x1(x1_1);
   mon1.x2(x2_1);
   mon1.y1(y1_1);
   mon1.y2(y2_1);
   mon1.x3(x3_1);
   mon1.x4(x4_1);
   mon1.y3(y3_1);
   mon1.y4(y4_1);
   mon1.o1x1(o1x1_1);
   mon1.o1y1(o1y1_1);
   mon1.o1x2(o1x2_1);
   mon1.o1y2(o1y2_1);
   mon1.o2x1(o2x1_1);
   mon1.o2y1(o2y1_1);
   mon1.o2x2(o2x2_1);
   mon1.o2y2(o2y2_1);
   mon1.o3x1(o3x1_1);
   mon1.o3y1(o3y1_1);
   mon1.o3x2(o3x2_1);
   mon1.o3y2(o3y2_1);
   mon1.o4x1(o4x1_1);
   mon1.o4y1(o4y1_1);
   mon1.o4x2(o4x2_1);
   mon1.o4y2(o4y2_1);
   mon1.o5x1(o5x1_1);
   mon1.o5y1(o5y1_1);
   mon1.o5x2(o5x2_1);
   mon1.o5y2(o5y2_1);
   mon1.o6x1(o6x1_1);
   mon1.o6y1(o6y1_1);
   mon1.o6x2(o6x2_1);
   mon1.o6y2(o6y2_1);
   mon1.index1(index5);
   mon1.index2(index6);
   mon1.index3(index7);
   mon1.index4(index8);
   mon1.status1(status5);
   mon1.status2(status6);
   mon1.status3(status7);
   mon1.status4(status8);
   mon1.s1(status4);
   mon1.clock(clk);

   sc_start(42000,SC_MS);
   return 0;

}
