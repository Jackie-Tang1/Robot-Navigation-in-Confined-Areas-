#include"systemc.h"
#include"pro2_robot2.cpp"

SC_MODULE(robot2){
  sc_in<bool> ctr_pro2;
  sc_in<sc_uint<14> > index_pro2;
  sc_in<bool> ctr_ser2;
  sc_in<sc_uint<4> > status_ser2;
  sc_fifo_in<int> path_r21;
  sc_fifo_in<int> speed_r21;

  sc_out<bool> sig_pro2;
  sc_out<sc_uint<4> > status_pro2;
  sc_out<bool> sig_ser2;
  sc_out<sc_uint<14> > index_ser2;
  sc_fifo_out<int> speed21;
  sc_fifo_out<int> path21;

  sc_signal<bool> ctr_r1t1;
  sc_signal<sc_uint<14> > index_r1t1;
  sc_signal<bool> sig_r2t2;
  sc_signal<sc_uint<4> > status_r2t2;

  rec_pro2* rec_pro12;
  tran_ser2* tran_ser12;
  rec_ser2* rec_ser12;
  tran_pro2* tran_pro12;
  inout2* io21;


  SC_CTOR(robot2){

    rec_pro12 = new rec_pro2("rec_pro1");
    tran_ser12 = new tran_ser2("tran_ser1");
    rec_ser12 = new rec_ser2("rec_ser1");
    tran_pro12 = new tran_pro2("tran_pro1");
    io21 = new inout2("inout2");

    rec_pro12->ctr(ctr_pro2);
    rec_pro12->index_r2(index_pro2);
    rec_pro12->index_out(index_r1t1);
    rec_pro12->flag(ctr_r1t1);

    tran_ser12->flag(ctr_r1t1);
    tran_ser12->index_in(index_r1t1);
    tran_ser12->index_out(index_ser2);
    tran_ser12->control(sig_ser2);

    rec_ser12->sig(ctr_ser2);
    rec_ser12->status_in(status_ser2);
    rec_ser12->status_out(status_r2t2);
    rec_ser12->flag(sig_r2t2);

    tran_pro12->control(sig_r2t2);
    tran_pro12->status_in(status_r2t2);
    tran_pro12->status_r2(status_pro2);
    tran_pro12->sig(sig_pro2);

    io21->path2(path_r21);
    io21->speed2(speed_r21);
    io21->path_r2(path21);
    io21->speed_r2(speed21);
  }

};
