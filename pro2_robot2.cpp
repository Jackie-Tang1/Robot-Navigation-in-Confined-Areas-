#include"systemc.h"

SC_MODULE(rec_pro2){
  sc_in<bool> ctr;
  sc_in<sc_uint<14> > index_r2;
  sc_out<sc_uint<14> > index_out;
  sc_out<bool> flag;

  bool ctr1;
  sc_uint<14> index;


  void prc_recpro(){
    ctr1 = ctr.read();
    index = index_r2.read();

    if(ctr1 == true){
      flag.write(true);
      index_out.write(index);
    }
    else{
      flag.write(false);
    }

  }

  SC_CTOR(rec_pro2){
    SC_METHOD(prc_recpro);
    sensitive << ctr<<index_r2;
  }

};

SC_MODULE(tran_ser2){
  sc_in<bool> flag;
  sc_in<sc_uint<14> > index_in;
  sc_out<sc_uint<14> > index_out;
  sc_out<bool> control;

  bool ctr;
  sc_uint<14> index;


  void prc_transer(){
    ctr = flag.read();
    index = index_in.read();

    if(ctr == true){
      control.write(true);
      index_out.write(index);
    }
    else{
      control.write(false);
      index_out.write(0);
    }

  }

  SC_CTOR(tran_ser2){
    SC_METHOD(prc_transer);
    sensitive << flag<<index_in;
  }

};

SC_MODULE(rec_ser2){
  sc_in<bool> sig;
  sc_in<sc_uint<4> > status_in;
  sc_out<sc_uint<4> > status_out;
  sc_out<bool> flag;

  bool ctr;
  sc_uint<4> status;

  void prc_recser(){
    ctr = sig.read();
    status = status_in.read();

    if(ctr == true){
      flag.write(true);
      status_out.write(status);
    }
    else{
      flag.write(false);
    }
  }

  SC_CTOR(rec_ser2){
    SC_METHOD(prc_recser);
    sensitive << sig<<status_in;
  }

};

SC_MODULE(tran_pro2){
  sc_in<bool> control;
  sc_in<sc_uint<4> > status_in;
  sc_out<sc_uint<4> > status_r2;
  sc_out<bool> sig;

  bool ctr;
  sc_uint<4> status;

  void prc_tranpro(){
    ctr = control.read();
    status = status_in.read();

    if(ctr == true){
      sig.write(true);
      status_r2.write(status);
    }
    else{
      sig.write(false);
       status_r2.write(0);
    }
//   cout<<"2222222   "<<status_r2<<endl;
  }

  SC_CTOR(tran_pro2){
    SC_METHOD(prc_tranpro);
    sensitive << control<<status_in;
  }

};

SC_MODULE(inout2){
  sc_fifo_in<int> path2;
  sc_fifo_in<int> speed2;
  sc_fifo_out<int> path_r2;
  sc_fifo_out<int> speed_r2;

  int a;
  int val1,val2;

  void prc_inout21(){
    for (a = 0; a <= 5; a++)
    {
    path2.read(val1);
    path_r2.write(val1);
    }
  }
  void prc_inout22(){
    speed2.read(val2);
    speed_r2.write(val2);
 }

 SC_CTOR(inout2){
   SC_THREAD(prc_inout21);
   SC_THREAD(prc_inout22);
 }

};
