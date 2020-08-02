#include"systemc.h"

SC_MODULE(rec2){
   sc_in<sc_uint<14> > index_r1;
   sc_in<sc_uint<14> > index_r2;
   sc_in<sc_uint<14> > index_r3;
   sc_in<sc_uint<14> > index_r4;
   sc_in<bool> ctr_r1;
   sc_in<bool> ctr_r2;
   sc_in<bool> ctr_r3;
   sc_in<bool> ctr_r4;

   sc_out<sc_uint<14> > index_1;
   sc_out<sc_uint<14> > index_2;
   sc_out<sc_uint<14> > index_3;
   sc_out<sc_uint<14> > index_4;
   sc_out<bool> flag1;
   sc_out<bool> flag2;
   sc_out<bool> flag3;
   sc_out<bool> flag4;

   sc_uint<14> index1;
   sc_uint<14> index2;
   sc_uint<14> index3;
   sc_uint<14> index4;

   void prc_rec1(){
     if(ctr_r1==true){
       index1 = index_r1.read();
       index_1.write(index1);
       flag1.write(true);
     }
     else{
       flag1.write(false);
     }
   }
   //r1 index_rec
   void prc_rec2(){
     if(ctr_r2==true){
       index2 = index_r2.read();
       index_2.write(index2);
       flag2.write(true);
     }
     else{
       flag2.write(false);
     }
   }
   //r2 index_rec
   void prc_rec3(){
     if(ctr_r3==true){
       index3 = index_r3.read();
       index_3.write(index3);
       flag3.write(true);
     }
     else{
       flag3.write(false);
     }
   }
   //r3 index_rec
   void prc_rec4(){
     if(ctr_r4==true){
       index4 = index_r4.read();
       index_4.write(index4);
       flag4.write(true);
     }
     else{
       flag4.write(false);
     }
   }
   //r4 index_rec
   SC_CTOR(rec2){
     SC_METHOD(prc_rec1);
     sensitive << ctr_r1<<index_r1;
     SC_METHOD(prc_rec2);
     sensitive << ctr_r2<<index_r2;
     SC_METHOD(prc_rec3);
     sensitive << ctr_r3<<index_r3;
     SC_METHOD(prc_rec4);
     sensitive << ctr_r4<<index_r4;
   }

};

SC_MODULE(update2){
  sc_in<sc_uint<14> > r1_index;
  sc_in<sc_uint<14> > r2_index;
  sc_in<sc_uint<14> > r3_index;
  sc_in<sc_uint<14> > r4_index;
  sc_in<bool> ctr1;
  sc_in<bool> ctr2;
  sc_in<bool> ctr3;
  sc_in<bool> ctr4;
  sc_out<sc_uint<4> > r1_status;
  sc_out<sc_uint<4> > r2_status;
  sc_out<sc_uint<4> > r3_status;
  sc_out<sc_uint<4> > r4_status;

  sc_uint<14> index1;
  sc_uint<2> stat1;
  sc_uint<6> cur_grid1;
  sc_uint<6> nxt_grid1;
  sc_uint<14> index2;
  sc_uint<2> stat2;
  sc_uint<6> cur_grid2;
  sc_uint<6> nxt_grid2;
  sc_uint<1> node2;
  sc_uint<14> index3;
  sc_uint<2> stat3;
  sc_uint<6> cur_grid3;
  sc_uint<6> nxt_grid3;
  sc_uint<1> node3;
  sc_uint<14> index4;
  sc_uint<2> stat4;
  sc_uint<6> cur_grid4;
  sc_uint<6> nxt_grid4;


  void prc_update(){

    index1 = r1_index.read();
    index2 = r2_index.read();
    index3 = r3_index.read();
    index4 = r4_index.read();
    stat1 = index1.range(13,12);
    stat2 = index2.range(13,12);
    stat3 = index3.range(13,12);
    stat4 = index4.range(13,12);
    cur_grid1 = index1.range(11,6);
    nxt_grid1 = index1.range(5,0);
    cur_grid2 = index2.range(11,6);
    nxt_grid2 = index2.range(5,0);
    cur_grid3 = index3.range(11,6);
    nxt_grid3 = index3.range(5,0);
    cur_grid4 = index4.range(11,6);
    nxt_grid4 = index4.range(5,0);
    node2 = index2.range(0,0);
    node3 = index3.range(0,0);

    if(ctr1.read()==true){
    if(stat1==2){
      r1_status.write(2);
    }
    else if(stat1==1){
      if(nxt_grid1 != cur_grid2){
      r1_status.write(3);
     }
      else{
      r1_status.write(4);
}
    }
    else if(stat1==3){
      r1_status.write(1);
    }
}
    else{
     r1_status.write(0);
   }
   //r1 server update

    if(ctr2.read()==true){
    if(stat2==2){
      if(node2==1 && cur_grid1>13 && nxt_grid1<16){
      r2_status.write(2);
      r1_status.write(2);
    }
    else{
      r2_status.write(2);
    }
    }
    else if(stat2==1){
      if(nxt_grid2 != cur_grid1 && nxt_grid2 != cur_grid3){
      r2_status.write(3);
     }
      else{
      r2_status.write(4);
}
    }
    else if(stat2==3){
      r2_status.write(1);
      r1_status.write(1);
    }
}
    else{
     r2_status.write(0);
   }
   //r2 server update

    if(ctr3.read()==true){
   if(stat3==2){
     if(node3==1 && cur_grid1>17){
     r3_status.write(2);
     r1_status.write(2);
   }
   else{
     r3_status.write(2);
   }
   }
   else if(stat3==1){
     if(nxt_grid3 != cur_grid2){
     r3_status.write(3);
    }
     else{
     r3_status.write(4);
}
   }
   else if(stat3==3){
     r3_status.write(1);
     r1_status.write(1);
   }
}
    else{
    r3_status.write(0);
  }
   //r3 server update

    if(ctr4.read()==true){
  if(stat4==2){ 
    r4_status.write(2);
  }
  else if(stat4==1){
    r4_status.write(4);
  }
  else if(stat4==3){
    r4_status.write(1);
  }
}
    else{
   r4_status.write(0);
 }
   //r4 server update

  }

  SC_CTOR(update2){
    SC_METHOD(prc_update);
    sensitive << ctr1 << ctr2<<r1_index<<r2_index <<ctr3<<ctr4<<r3_index<<r4_index;
  }

};

SC_MODULE(tran2){
  sc_in<sc_uint<4> > status_r1;
  sc_in<sc_uint<4> > status_r2;
  sc_in<sc_uint<4> > status_r3;
  sc_in<sc_uint<4> > status_r4;
  sc_out<sc_uint<4> > status1_out;
  sc_out<sc_uint<4> > status2_out;
  sc_out<sc_uint<4> > status3_out;
  sc_out<sc_uint<4> > status4_out;
  sc_out<bool> sig_r1;
  sc_out<bool> sig_r2;
  sc_out<bool> sig_r3;
  sc_out<bool> sig_r4;

  sc_fifo_out<int> path_r1;
  sc_fifo_out<int> path_r2;
  sc_fifo_out<int> path_r3;
  sc_fifo_out<int> path_r4;
  sc_fifo_out<int> speed_r1;
  sc_fifo_out<int> speed_r2;
  sc_fifo_out<int> speed_r3;
  sc_fifo_out<int> speed_r4;

  sc_uint<4> status1;
  sc_uint<4> status2;
  sc_uint<4> status3;
  sc_uint<4> status4;

  void prc_tran1(){
    status1 = status_r1.read();
    if(status1==1){
      sig_r1.write(true);
      status1_out.write(status1);
    }
    else if(status1==2){
      sig_r1.write(true);
      status1_out.write(status1);
    }
    else if(status1==3){
      sig_r1.write(true);
      status1_out.write(status1);
    }
    else if(status1==4){
      sig_r1.write(true);
      status1_out.write(status1);
     }
    else{
      sig_r1.write(false);
    }
  }
  // status_tran1
  void prc_tran2(){
    status2 = status_r2.read();
    if(status2==1){
      sig_r2.write(true);
      status2_out.write(status2);
    }
    else if(status2==2){
      sig_r2.write(true);
      status2_out.write(status2);
    }
    else if(status2==3){
      sig_r2.write(true);
      status2_out.write(status2);
    }
    else if(status2==4){
      sig_r2.write(true);
      status2_out.write(status2);
    }
    else{
      sig_r2.write(false);
    }
  }
  // status_tran2
  void prc_tran3(){
    status3 = status_r3.read();
    if(status3==1){
      sig_r3.write(true);
      status3_out.write(status3);
    }
    else if(status3==2){
      sig_r3.write(true);
      status3_out.write(status3);
    }
    else if(status3==3){
      sig_r3.write(true);
      status3_out.write(status3);
    }
    else if(status3==4){
      sig_r3.write(true);
      status3_out.write(status3);
     }
    else{
      sig_r3.write(false);
    }
  }
  // status_tran3
  void prc_tran4(){
    status4 = status_r4.read();
    if(status4==1){
      sig_r4.write(true);
      status4_out.write(status4);
    }
    else if(status4==2){
      sig_r4.write(true);
      status4_out.write(status4);
    }
    else if(status4==3){
      sig_r4.write(true);
      status4_out.write(status4);
    }
    else if(status4==4){
      sig_r4.write(true);
      status4_out.write(status1);
     }
    else{
      sig_r4.write(false);
    }
  }
  // status_tran4

  void r1_path()
  {
      path_r1.write(1);
      path_r1.write(13);
      path_r1.write(18);
      path_r1.write(31);
      path_r1.write(26);
      path_r1.write(39);

  }
  //r1 path
  void r2_path()
  {
      path_r2.write(10);
      path_r2.write(22);
      path_r2.write(18);
      path_r2.write(31);
      path_r2.write(35);
      path_r2.write(23);

  }
  //r2 path
  void r3_path()
  {
      path_r3.write(49);
      path_r3.write(26);
      path_r3.write(32);
      path_r3.write(45);
      path_r3.write(48);
      path_r3.write(38);

  }
  //r3 path
  void r4_path()
  {
      path_r4.write(60);
      path_r4.write(48);
      path_r4.write(39);
      path_r4.write(51);
      path_r4.write(55);

  }
  //r4 path
  void r1_speed()
  {
    speed_r1.write(2);
    speed_r1.write(1);
  }
  //r1 speed
  void r2_speed()
  {
    speed_r2.write(2);
  }
  //r2 speed
  void r3_speed()
  {
    speed_r3.write(2);
  }
  //r3 speed
  void r4_speed()
  {
    speed_r4.write(2);
  }
  //r4 speed
  
  SC_CTOR(tran2){
    SC_METHOD(prc_tran1);
    sensitive << status_r1;
    SC_METHOD(prc_tran2);
    sensitive << status_r2;
    SC_METHOD(prc_tran3);
    sensitive << status_r3;
    SC_METHOD(prc_tran4);
    sensitive << status_r4;

    SC_THREAD(r1_path);
    SC_THREAD(r2_path);
    SC_THREAD(r3_path);
    SC_THREAD(r4_path);
    SC_THREAD(r1_speed);
    SC_THREAD(r2_speed);
    SC_THREAD(r3_speed);
    SC_THREAD(r4_speed);
  }

};
