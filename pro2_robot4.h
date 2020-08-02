#include"systemc.h"
#include"pro2_robot4.cpp"

SC_MODULE(robot4){
//  sc_in<bool> clock;
  sc_in<bool> ctr_pro4;
  sc_in<sc_uint<14> > index_pro4;
  sc_in<bool> ctr_ser4;
  sc_in<sc_uint<4> > status_ser4;
  sc_fifo_in<int> path_r41;
  sc_fifo_in<int> speed_r41;

  sc_out<bool> sig_pro4;
  sc_out<sc_uint<4> > status_pro4;
  sc_out<bool> sig_ser4;
  sc_out<sc_uint<14> > index_ser4;
  sc_fifo_out<int> speed41;
  sc_fifo_out<int> path41;

  sc_signal<bool> ctr_r1t4;
  sc_signal<sc_uint<14> > index_r1t4;
  sc_signal<bool> sig_r2t4;
  sc_signal<sc_uint<4> > status_r2t4;

  rec_pro4* rec_pro41;
  tran_ser4* tran_ser41;
  rec_ser4* rec_ser41;
  tran_pro4* tran_pro41;
  inout4* io41;

  SC_CTOR(robot4){

    rec_pro41 = new rec_pro4("rec_pro4");
    tran_ser41 = new tran_ser4("tran_ser4");
    rec_ser41 = new rec_ser4("rec_ser4");
    tran_pro41 = new tran_pro4("tran_pro4");
    io41 = new inout4("inout4");

    rec_pro41->ctr(ctr_pro4);
    rec_pro41->index_r4(index_pro4);
    rec_pro41->index_out(index_r1t4);
    rec_pro41->flag(ctr_r1t4);
  //  rec_pro11->clock1(clock);

    tran_ser41->flag(ctr_r1t4);
    tran_ser41->index_in(index_r1t4);
    tran_ser41->index_out(index_ser4);
    tran_ser41->control(sig_ser4);
   // tran_ser11->clock2(clock);

    rec_ser41->sig(ctr_ser4);
    rec_ser41->status_in(status_ser4);
    rec_ser41->status_out(status_r2t4);
    rec_ser41->flag(sig_r2t4);

    tran_pro41->control(sig_r2t4);
    tran_pro41->status_in(status_r2t4);
    tran_pro41->status_r4(status_pro4);
    tran_pro41->sig(sig_pro4);

    io41->path4(path_r41);
    io41->speed4(speed_r41);
    io41->path_r4(path41);
    io41->speed_r4(speed41);
  }

};
