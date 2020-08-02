#include"systemc.h"

SC_MODULE(rec_pro4){
  sc_in<bool> ctr;
  sc_in<sc_uint<14> > index_r4;
  sc_out<sc_uint<14> > index_out;
  sc_out<bool> flag;
  //sc_in<bool> clock1;

  bool ctr4;
  //sc_uint<14> index;


  void prc_recpro(){
    ctr4 = ctr.read();
//    index = index_r1.read();

    if(ctr4 == true){
      flag.write(true);
      index_out.write(index_r4.read());
    }
    else{
      flag.write(false);
    }
//cout <<"!!!" <<index_r1<<"   "<<index_out <<endl;
  //cout<<"**" <<flag;
  }

  SC_CTOR(rec_pro4){
    SC_METHOD(prc_recpro);
sensitive <<ctr << index_r4;
  }

};

SC_MODULE(tran_ser4){
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

  SC_CTOR(tran_ser4){
    SC_METHOD(prc_transer);
    sensitive <<flag<<index_in;
  }

};

SC_MODULE(rec_ser4){
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

  SC_CTOR(rec_ser4){
    SC_METHOD(prc_recser);
    sensitive << sig <<status_in;
  }

};

SC_MODULE(tran_pro4){
  sc_in<bool> control;
  sc_in<sc_uint<4> > status_in;
  sc_out<sc_uint<4> > status_r4;
  sc_out<bool> sig;

  bool ctr;
  sc_uint<4> status;

  void prc_tranpro(){
    ctr = control.read();
    status = status_in.read();

    if(ctr == true){
      sig.write(true);
      status_r4.write(status);
    }
    else{
      sig.write(false);
   status_r4.write(0);
    }
  }

  SC_CTOR(tran_pro4){
    SC_METHOD(prc_tranpro);
    sensitive << control<<status_in;
  }

};

SC_MODULE(inout4){
  sc_fifo_in<int> path4;
  sc_fifo_in<int> speed4;
  sc_fifo_out<int> path_r4;
  sc_fifo_out<int> speed_r4;

  int a;
  int val1,val2;

  void prc_inout41(){
    for (a = 0; a <= 5; a++)
    {
    path4.read(val1);
    path_r4.write(val1);
    }
  }
  void prc_inout42(){
    speed4.read(val2);
    speed_r4.write(val2);
 }

 SC_CTOR(inout4){
   SC_THREAD(prc_inout41);
   SC_THREAD(prc_inout42);
 }

};
