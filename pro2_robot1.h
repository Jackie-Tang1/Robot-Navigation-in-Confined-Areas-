#include"systemc.h"
#include"pro2_robot1.cpp"

SC_MODULE(robot1){
//  sc_in<bool> clock;
  sc_in<bool> ctr_pro1;
  sc_in<sc_uint<14> > index_pro1;
  sc_in<bool> ctr_ser1;
  sc_in<sc_uint<4> > status_ser1;
  sc_fifo_in<int> path_r11;
  sc_fifo_in<int> speed_r11;

  sc_out<bool> sig_pro1;
  sc_out<sc_uint<4> > status_pro1;
  sc_out<bool> sig_ser1;
  sc_out<sc_uint<14> > index_ser1;
  sc_fifo_out<int> speed11;
  sc_fifo_out<int> path11;

  sc_signal<bool> ctr_r1t1;
  sc_signal<sc_uint<14> > index_r1t1;
  sc_signal<bool> sig_r2t2;
  sc_signal<sc_uint<4> > status_r2t2;

  rec_pro1* rec_pro11;
  tran_ser1* tran_ser11;
  rec_ser1* rec_ser11;
  tran_pro1* tran_pro11;
  inout1* io11;

  SC_CTOR(robot1){

    rec_pro11 = new rec_pro1("rec_pro1");
    tran_ser11 = new tran_ser1("tran_ser1");
    rec_ser11 = new rec_ser1("rec_ser1");
    tran_pro11 = new tran_pro1("tran_pro1");
    io11 = new inout1("inout1");

    rec_pro11->ctr(ctr_pro1);
    rec_pro11->index_r1(index_pro1);
    rec_pro11->index_out(index_r1t1);
    rec_pro11->flag(ctr_r1t1);
  //  rec_pro11->clock1(clock);

    tran_ser11->flag(ctr_r1t1);
    tran_ser11->index_in(index_r1t1);
    tran_ser11->index_out(index_ser1);
    tran_ser11->control(sig_ser1);
   // tran_ser11->clock2(clock);

    rec_ser11->sig(ctr_ser1);
    rec_ser11->status_in(status_ser1);
    rec_ser11->status_out(status_r2t2);
    rec_ser11->flag(sig_r2t2);

    tran_pro11->control(sig_r2t2);
    tran_pro11->status_in(status_r2t2);
    tran_pro11->status_r1(status_pro1);
    tran_pro11->sig(sig_pro1);

    io11->path1(path_r11);
    io11->speed1(speed_r11);
    io11->path_r1(path11);
    io11->speed_r1(speed11);
  }

};
