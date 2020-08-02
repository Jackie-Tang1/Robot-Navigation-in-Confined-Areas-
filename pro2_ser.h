#include"systemc.h"
#include"pro2_ser.cpp"

SC_MODULE(server){
  sc_in<sc_uint<14> > index_rob1;
  sc_in<sc_uint<14> > index_rob2;
  sc_in<sc_uint<14> > index_rob3;
  sc_in<sc_uint<14> > index_rob4;

  sc_in<bool> control_r1;
  sc_in<bool> control_r2;
  sc_in<bool> control_r3;
  sc_in<bool> control_r4;

  sc_out<sc_uint<4> > status_rob1;
  sc_out<sc_uint<4> > status_rob2;
  sc_out<sc_uint<4> > status_rob3;
  sc_out<sc_uint<4> > status_rob4;

  sc_out<bool> signal_r1;
  sc_out<bool> signal_r2;
  sc_out<bool> signal_r3;
  sc_out<bool> signal_r4;

  sc_fifo_out<int> path_r11;
  sc_fifo_out<int> path_r21;
  sc_fifo_out<int> path_r31;
  sc_fifo_out<int> path_r41;
  sc_fifo_out<int> speed_r11;
  sc_fifo_out<int> speed_r21;
  sc_fifo_out<int> speed_r31;
  sc_fifo_out<int> speed_r41;

  sc_signal<sc_uint<14> > index11;
  sc_signal<sc_uint<14> > index21;
  sc_signal<sc_uint<14> > index31;
  sc_signal<sc_uint<14> > index41;
  sc_signal<sc_uint<4> > status11;
  sc_signal<sc_uint<4> > status21;
  sc_signal<sc_uint<4> > status31;
  sc_signal<sc_uint<4> > status41;

  sc_signal<bool> rec2up1;
  sc_signal<bool> rec2up2;
  sc_signal<bool> rec2up3;
  sc_signal<bool> rec2up4;

  rec2* rec12;
  tran2* tran12;
  update2* up12;

  SC_CTOR(server){

    rec12 = new rec2("rec1");
    tran12 = new tran2("tran1");
    up12 = new update2("up1");

    rec12->index_r1(index_rob1);
    rec12->index_r2(index_rob2);
    rec12->index_r3(index_rob3);
    rec12->index_r4(index_rob4);
    rec12->ctr_r1(control_r1);
    rec12->ctr_r2(control_r2);
    rec12->ctr_r3(control_r3);
    rec12->ctr_r4(control_r4);
    rec12->index_1(index11);
    rec12->index_2(index21);
    rec12->index_3(index31);
    rec12->index_4(index41);
    rec12->flag1(rec2up1);
    rec12->flag2(rec2up2);
    rec12->flag3(rec2up3);
    rec12->flag4(rec2up4);

    up12->r1_index(index11);
    up12->r2_index(index21);
    up12->r3_index(index31);
    up12->r4_index(index41);
    up12->r1_status(status11);
    up12->r2_status(status21);
    up12->r3_status(status31);
    up12->r4_status(status41);
    up12->ctr1(rec2up1);
    up12->ctr2(rec2up2);
    up12->ctr3(rec2up3);
    up12->ctr4(rec2up4);

    tran12->status_r1(status11);
    tran12->status_r2(status21);
    tran12->status_r3(status31);
    tran12->status_r4(status41);
    tran12->status1_out(status_rob1);
    tran12->status2_out(status_rob2);
    tran12->status3_out(status_rob3);
    tran12->status4_out(status_rob4);
    tran12->sig_r1(signal_r1);
    tran12->sig_r2(signal_r2);
    tran12->sig_r3(signal_r3);
    tran12->sig_r4(signal_r4);
    tran12->path_r1(path_r11);
    tran12->path_r2(path_r21);
    tran12->path_r3(path_r31);
    tran12->path_r4(path_r41);
    tran12->speed_r1(speed_r11);
    tran12->speed_r2(speed_r21);
    tran12->speed_r3(speed_r31);
    tran12->speed_r4(speed_r41);


  }

};
