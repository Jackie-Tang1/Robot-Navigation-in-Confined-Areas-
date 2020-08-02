#include"systemc.h"
#include"pro2_robot3.cpp"

SC_MODULE(robot3){
//  sc_in<bool> clock;
  sc_in<bool> ctr_pro3;
  sc_in<sc_uint<14> > index_pro3;
  sc_in<bool> ctr_ser3;
  sc_in<sc_uint<4> > status_ser3;
  sc_fifo_in<int> path_r31;
  sc_fifo_in<int> speed_r31;


  sc_out<bool> sig_pro3;
  sc_out<sc_uint<4> > status_pro3;
  sc_out<bool> sig_ser3;
  sc_out<sc_uint<14> > index_ser3;
  sc_fifo_out<int> speed31;
  sc_fifo_out<int> path31;

  sc_signal<bool> ctr_r1t3;
  sc_signal<sc_uint<14> > index_r1t3;
  sc_signal<bool> sig_r2t3;
  sc_signal<sc_uint<4> > status_r2t3;

  rec_pro3* rec_pro31;
  tran_ser3* tran_ser31;
  rec_ser3* rec_ser31;
  tran_pro3* tran_pro31;
  inout3* io31;

  SC_CTOR(robot3){

    rec_pro31 = new rec_pro3("rec_pro3");
    tran_ser31 = new tran_ser3("tran_ser3");
    rec_ser31 = new rec_ser3("rec_ser3");
    tran_pro31 = new tran_pro3("tran_pro3");
    io31 = new inout3("inout3");

    rec_pro31->ctr(ctr_pro3);
    rec_pro31->index_r3(index_pro3);
    rec_pro31->index_out(index_r1t3);
    rec_pro31->flag(ctr_r1t3);
  //  rec_pro11->clock1(clock);

    tran_ser31->flag(ctr_r1t3);
    tran_ser31->index_in(index_r1t3);
    tran_ser31->index_out(index_ser3);
    tran_ser31->control(sig_ser3);
   // tran_ser11->clock2(clock);

    rec_ser31->sig(ctr_ser3);
    rec_ser31->status_in(status_ser3);
    rec_ser31->status_out(status_r2t3);
    rec_ser31->flag(sig_r2t3);

    tran_pro31->control(sig_r2t3);
    tran_pro31->status_in(status_r2t3);
    tran_pro31->status_r3(status_pro3);
    tran_pro31->sig(sig_pro3);

    io31->path3(path_r31);
    io31->speed3(speed_r31);
    io31->path_r3(path31);
    io31->speed_r3(speed31);
  }

};
