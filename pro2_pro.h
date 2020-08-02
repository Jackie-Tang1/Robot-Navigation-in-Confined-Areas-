#include"systemc.h"
#include"pro2_pro.cpp"

SC_MODULE(processing){
   sc_in<bool> clock1;
   sc_in<sc_uint<4> > re_stat1;
   sc_in<bool> re_sig1;
   sc_in<sc_uint<4> > re_stat2;
   sc_in<bool> re_sig2;
   sc_in<sc_uint<4> > re_stat3;
   sc_in<bool> re_sig3;
   sc_in<sc_uint<4> > re_stat4;
   sc_in<bool> re_sig4;

   sc_fifo_in<int> path11;
   sc_fifo_in<int> path21;
   sc_fifo_in<int> path31;
   sc_fifo_in<int> path41;
   sc_fifo_in<int> speed11;
   sc_fifo_in<int> speed21;
   sc_fifo_in<int> speed31;
   sc_fifo_in<int> speed41;

   sc_out<sc_uint<14> > tr_stat1;
   sc_out<bool> tr_sig1;
   sc_out<sc_uint<14> > tr_stat2;
   sc_out<bool> tr_sig2;
   sc_out<sc_uint<14> > tr_stat3;
   sc_out<bool> tr_sig3;
   sc_out<sc_uint<14> > tr_stat4;
   sc_out<bool> tr_sig4;

   sc_out<double> x11;
   sc_out<double> x21;
   sc_out<double> y11;
   sc_out<double> y21;
   sc_out<double> x31;
   sc_out<double> x41;
   sc_out<double> y31;
   sc_out<double> y41;
   sc_out<double> o1x11;
   sc_out<double> o1y11;
   sc_out<double> o1x21;
   sc_out<double> o1y21;
   sc_out<double> o2x11;
   sc_out<double> o2y11;
   sc_out<double> o2x21;
   sc_out<double> o2y21;
   sc_out<double> o3x11;
   sc_out<double> o3y11;
   sc_out<double> o3x21;
   sc_out<double> o3y21;
   sc_out<double> o4x11;
   sc_out<double> o4y11;
   sc_out<double> o4x21;
   sc_out<double> o4y21;
   sc_out<double> o5x11;
   sc_out<double> o5y11;
   sc_out<double> o5x21;
   sc_out<double> o5y21;
   sc_out<double> o6x11;
   sc_out<double> o6y11;
   sc_out<double> o6x21;
   sc_out<double> o6y21;


   sc_signal<sc_uint<4> > st1upd;
   sc_signal<sc_uint<4> > st2upd;
   sc_signal<sc_uint<4> > st3upd;
   sc_signal<sc_uint<4> > st4upd;
   sc_signal<sc_uint<16> > flag11;
   sc_signal<sc_uint<16> > flag21;
   sc_signal<sc_uint<16> > flag31;
   sc_signal<sc_uint<16> > flag41;

   sc_signal<double> r1p11;
   sc_signal<double> r1p21;
   sc_signal<double> r1p31;
   sc_signal<double> r1p41;
   sc_signal<double> r1p51;
   sc_signal<double> r1p61;
   sc_signal<double> r2p11;
   sc_signal<double> r2p21;
   sc_signal<double> r2p31;
   sc_signal<double> r2p41;
   sc_signal<double> r2p51;
   sc_signal<double> r2p61;
   sc_signal<double> r3p11;
   sc_signal<double> r3p21;
   sc_signal<double> r3p31;
   sc_signal<double> r3p41;
   sc_signal<double> r3p51;
   sc_signal<double> r3p61;
   sc_signal<double> r4p11;
   sc_signal<double> r4p21;
   sc_signal<double> r4p31;
   sc_signal<double> r4p41;
   sc_signal<double> r4p51;
   sc_signal<double> sp1_r1;
   sc_signal<double> sp2_r1;
   sc_signal<double> sp1_r2;
   sc_signal<double> sp1_r3;
   sc_signal<double> sp1_r4;
   sc_signal<int> timer11;



   update1* update11;
   tran1* tran11;
   rec1* rec11;
   timer* timer1;

   SC_CTOR(processing){

      update11 = new update1("update1");
      tran11 = new tran1("tran1");
      rec11 = new rec1("rec1");
      timer1 = new timer("timer1");

      timer1->clock(clock1);
      timer1->t(timer11);

      rec11->ctr_r1(re_sig1);
      rec11->ctr_r2(re_sig2);
      rec11->ctr_r3(re_sig3);
      rec11->ctr_r4(re_sig4);
      rec11->status_r1(re_stat1);
      rec11->status_r2(re_stat2);
      rec11->status_r3(re_stat3);
      rec11->status_r4(re_stat4);
      rec11->status_t1(st1upd);
      rec11->status_t2(st2upd);
      rec11->status_t3(st3upd);
      rec11->status_t4(st4upd);
      rec11->path1(path11);
      rec11->path2(path21);
      rec11->path3(path31);
      rec11->path4(path41);
      rec11->speed1(speed11);
      rec11->speed2(speed21);
      rec11->speed3(speed31);
      rec11->speed4(speed41);
      rec11->r1p1(r1p11);
      rec11->r1p2(r1p21);
      rec11->r1p3(r1p31);
      rec11->r1p4(r1p41);
      rec11->r1p5(r1p51);
      rec11->r1p6(r1p61);
      rec11->r2p1(r2p11);
      rec11->r2p2(r2p21);
      rec11->r2p3(r2p31);
      rec11->r2p4(r2p41);
      rec11->r2p5(r2p51);
      rec11->r2p6(r2p61);
      rec11->r3p1(r3p11);
      rec11->r3p2(r3p21);
      rec11->r3p3(r3p31);
      rec11->r3p4(r3p41);
      rec11->r3p5(r3p51);
      rec11->r3p6(r3p61);
      rec11->r4p1(r4p11);
      rec11->r4p2(r4p21);
      rec11->r4p3(r4p31);
      rec11->r4p4(r4p41);
      rec11->r4p5(r4p51);
      rec11->sp11(sp1_r1);
      rec11->sp12(sp2_r1);
      rec11->sp2(sp1_r2);
      rec11->sp3(sp1_r3);
      rec11->sp4(sp1_r4);

      update11->clock(clock1);
      update11->timer(timer11);
      update11->status_r1(st1upd);
      update11->status_r2(st2upd);
      update11->status_r3(st3upd);
      update11->status_r4(st4upd);
      update11->robot1_x(x11);
      update11->robot1_y(y11);
      update11->robot2_x(x21);
      update11->robot2_y(y21);
      update11->robot3_x(x31);
      update11->robot3_y(y31);
      update11->robot4_x(x41);
      update11->robot4_y(y41);
      update11->obstacle1_x1(o1x11);
      update11->obstacle1_y1(o1y11);
      update11->obstacle1_x2(o1x21);
      update11->obstacle1_y2(o1y21);
      update11->obstacle2_x1(o2x11);
      update11->obstacle2_y1(o2y11);
      update11->obstacle2_x2(o2x21);
      update11->obstacle2_y2(o2y21);
      update11->obstacle3_x1(o3x11);
      update11->obstacle3_y1(o3y11);
      update11->obstacle3_x2(o3x21);
      update11->obstacle3_y2(o3y21);
      update11->obstacle4_x1(o4x11);
      update11->obstacle4_y1(o4y11);
      update11->obstacle4_x2(o4x21);
      update11->obstacle4_y2(o4y21);
      update11->obstacle5_x1(o5x11);
      update11->obstacle5_y1(o5y11);
      update11->obstacle5_x2(o5x21);
      update11->obstacle5_y2(o5y21);
      update11->obstacle6_x1(o6x11);
      update11->obstacle6_y1(o6y11);
      update11->obstacle6_x2(o6x21);
      update11->obstacle6_y2(o6y21);
      update11->r1p1(r1p11);
      update11->r1p2(r1p21);
      update11->r1p3(r1p31);
      update11->r1p4(r1p41);
      update11->r1p5(r1p51);
      update11->r1p6(r1p61);
      update11->r2p1(r2p11);
      update11->r2p2(r2p21);
      update11->r2p3(r2p31);
      update11->r2p4(r2p41);
      update11->r2p5(r2p51);
      update11->r2p6(r2p61);
      update11->r3p1(r3p11);
      update11->r3p2(r3p21);
      update11->r3p3(r3p31);
      update11->r3p4(r3p41);
      update11->r3p5(r3p51);
      update11->r3p6(r3p61);
      update11->r4p1(r4p11);
      update11->r4p2(r4p21);
      update11->r4p3(r4p31);
      update11->r4p4(r4p41);
      update11->r4p5(r4p51);
      update11->sp11(sp1_r1);
      update11->sp12(sp2_r1);
      update11->sp2(sp1_r2);
      update11->sp3(sp1_r3);
      update11->sp4(sp1_r4);
      update11->flag1(flag11);
      update11->flag2(flag21);
      update11->flag3(flag31);
      update11->flag4(flag41);

      tran11->flag1(flag11);
      tran11->flag2(flag21);
      tran11->flag3(flag31);
      tran11->flag4(flag41);
      tran11->r1_ctr(tr_sig1);
      tran11->r2_ctr(tr_sig2);
      tran11->r3_ctr(tr_sig3);
      tran11->r4_ctr(tr_sig4);
      tran11->r1_index(tr_stat1);
      tran11->r2_index(tr_stat2);
      tran11->r3_index(tr_stat3);
      tran11->r4_index(tr_stat4);

   }


};