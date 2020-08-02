#include"systemc.h"

SC_MODULE(rec_pro3){
  sc_in<bool> ctr;
  sc_in<sc_uint<14> > index_r3;
  sc_out<sc_uint<14> > index_out;
  sc_out<bool> flag;
  //sc_in<bool> clock1;

  bool ctr3;
  //sc_uint<14> index;


  void prc_recpro(){
    ctr3 = ctr.read();
//    index = index_r1.read();

    if(ctr3 == true){
      flag.write(true);
      index_out.write(index_r3.read());
    }
    else{
      flag.write(false);
    }
//cout <<"!!!" <<index_r1<<"   "<<index_out <<endl;
  //cout<<"**" <<flag;
  }

  SC_CTOR(rec_pro3){
    SC_METHOD(prc_recpro);
sensitive <<ctr << index_r3;
  }

};

SC_MODULE(tran_ser3){
  sc_in<bool> flag;
  sc_in<sc_uint<14> > index_in;
  sc_out<sc_uint<14> > index_out;
  sc_out<bool> control;
  //sc_in<bool> clock2;

  bool ctr;
  sc_uint<14> index;


  void prc_transer(){
    ctr = flag.read();
    index = index_in.read();
//cout<<"##" <<ctr;
    if(ctr == true){
      control.write(true);
      index_out.write(index);
    }
    else{
      control.write(false);
      index_out.write(0);
    }
  // cout<<"????" <<index_out<<endl;
  }

  SC_CTOR(tran_ser3){
    SC_METHOD(prc_transer);
    sensitive <<flag<<index_in;
  }

};

SC_MODULE(rec_ser3){
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

  SC_CTOR(rec_ser3){
    SC_METHOD(prc_recser);
    sensitive << sig <<status_in;
  }

};

SC_MODULE(tran_pro3){
  sc_in<bool> control;
  sc_in<sc_uint<4> > status_in;
  sc_out<sc_uint<4> > status_r3;
  sc_out<bool> sig;

  bool ctr;
  sc_uint<4> status;

  void prc_tranpro(){
    ctr = control.read();
    status = status_in.read();

    if(ctr == true){
      sig.write(true);
      status_r3.write(status);
    }
    else{
      sig.write(false);
   status_r3.write(0);
    }
   //cout <<"qqqqqq" <<status_r1<<endl;
  }

  SC_CTOR(tran_pro3){
    SC_METHOD(prc_tranpro);
    sensitive << control<<status_in;
  }

};

SC_MODULE(inout3){
  sc_fifo_in<int> path3;
  sc_fifo_in<int> speed3;
  sc_fifo_out<int> path_r3;
  sc_fifo_out<int> speed_r3;

  int a;
  int val1,val2;

  void prc_inout31(){
    for (a = 0; a <= 5; a++)
    {
    path3.read(val1);
    path_r3.write(val1);
    }
  }
  void prc_inout32(){
    speed3.read(val2);
    speed_r3.write(val2);
 }

 SC_CTOR(inout3){
   SC_THREAD(prc_inout31);
   SC_THREAD(prc_inout32);
 }

};
