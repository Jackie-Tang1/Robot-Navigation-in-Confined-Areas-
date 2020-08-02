#include"systemc.h"

SC_MODULE(timer){
  sc_out<int> t;
  sc_in<bool> clock;

  int t1 = 0;

  void prc_timer(){
    t.write(t1);
    t1 = t1 + 1;
  }

  SC_CTOR(timer){
    SC_METHOD(prc_timer);
    sensitive << clock.pos();
  }
};

SC_MODULE(update1){
   sc_in<sc_uint<4> > status_r1;
   sc_in<sc_uint<4> > status_r2;
   sc_in<sc_uint<4> > status_r3;
   sc_in<sc_uint<4> > status_r4;
   sc_in<int> timer;
   sc_in<double> r1p1;
   sc_in<double> r1p2;
   sc_in<double> r1p3;
   sc_in<double> r1p4;
   sc_in<double> r1p5;
   sc_in<double> r1p6;
   sc_in<double> r2p1;
   sc_in<double> r2p2;
   sc_in<double> r2p3;
   sc_in<double> r2p4;
   sc_in<double> r2p5;
   sc_in<double> r2p6;
   sc_in<double> r3p1;
   sc_in<double> r3p2;
   sc_in<double> r3p3;
   sc_in<double> r3p4;
   sc_in<double> r3p5;
   sc_in<double> r3p6;
   sc_in<double> r4p1;
   sc_in<double> r4p2;
   sc_in<double> r4p3;
   sc_in<double> r4p4;
   sc_in<double> r4p5;

   sc_in<double> sp11;
   sc_in<double> sp12;
   sc_in<double> sp2;
   sc_in<double> sp3;
   sc_in<double> sp4;

   sc_in<bool> clock;

   sc_out<double> robot1_x;
   sc_out<double> robot1_y;
   sc_out<double> robot2_x;
   sc_out<double> robot2_y;
   sc_out<double> robot3_x;
   sc_out<double> robot3_y;
   sc_out<double> robot4_x;
   sc_out<double> robot4_y;

   sc_out<double> obstacle1_x1;
   sc_out<double> obstacle1_y1;
   sc_out<double> obstacle1_x2;
   sc_out<double> obstacle1_y2;
   sc_out<double> obstacle2_x1;
   sc_out<double> obstacle2_y1;
   sc_out<double> obstacle2_x2;
   sc_out<double> obstacle2_y2;
   sc_out<double> obstacle3_x1;
   sc_out<double> obstacle3_y1;
   sc_out<double> obstacle3_x2;
   sc_out<double> obstacle3_y2;
   sc_out<double> obstacle4_x1;
   sc_out<double> obstacle4_y1;
   sc_out<double> obstacle4_x2;
   sc_out<double> obstacle4_y2;
   sc_out<double> obstacle5_x1;
   sc_out<double> obstacle5_y1;
   sc_out<double> obstacle5_x2;
   sc_out<double> obstacle5_y2;
   sc_out<double> obstacle6_x1;
   sc_out<double> obstacle6_y1;
   sc_out<double> obstacle6_x2;
   sc_out<double> obstacle6_y2;

   sc_out<sc_uint<16> > flag1;
   sc_out<sc_uint<16> > flag2;
   sc_out<sc_uint<16> > flag3;
   sc_out<sc_uint<16> > flag4;

   double x1 = 1.00;
   double y1 = 17.00;
   double x2 = 19.00;
   double y2 = 17.00;
   double x3 = 1.00;
   double y3 = 3.00;
   double x4 = 19.00;
   double y4 = 1.00;

   double o1x1 = 0.01;
   double o1y1 = 16.01;
   double o1x2 = 1.99;
   double o1y2 = 17.99;

   double o2x1 = 0.01;
   double o2y1 = 12.01;
   double o2x2 = 1.99;
   double o2y2 = 13.99;

   double o3x1 = 10.01;
   double o3y1 = 12.01;
   double o3x2 = 11.99;
   double o3y2 = 13.99;

   double o4x1 = 0.01;
   double o4y1 = 8.01;
   double o4x2 = 1.99;
   double o4y2 = 9.99;

   double o5x1 = 12.01;
   double o5y1 = 8.01;
   double o5x2 = 13.99;
   double o5y2 = 9.99;

   double o6x1 = 0.01;
   double o6y1 = 4.01;
   double o6x2 = 1.99;
   double o6y2 = 5.99;

   double x1_max;
   double x1_min;
   double x2_max;
   double x2_min;
   double x3_max;
   double x3_min;
   double x4_max;
   double x4_min;
   double x5_max;
   double x5_min;
   double x6_max;
   double x6_min;

   double r11,r12,r13,r14,r15,r16;
   double r21,r22,r23,r24,r25,r26;
   double r31,r32,r33,r34,r35,r36;
   double r41,r42,r43,r44,r45;
   double speed11,speed12,speed2,speed3,speed4;


   bool status1;
   bool status2;
   bool status3;
   bool status4;

   int a = 0;
   int i = 0;
   int j = 0;
   int k = 0;
   int t;

void prc_update1(){

  x1_max = o1x2 + 3.00;
  x1_min = o1x1 - 3.00;
  x2_max = o2x2 + 3.00;
  x2_min = o2x1 - 3.00;
  x3_max = o3x2 + 3.00;
  x3_min = o3x1 - 3.00;
  x4_max = o4x2 + 3.00;
  x4_min = o4x1 - 3.00;
  x5_max = o5x2 + 3.00;
  x5_min = o5x1 - 3.00;
  x6_max = o6x2 + 3.00;
  x6_min = o6x1 - 3.00;

  r11 = r1p1.read();
  r12 = r1p2.read();
  r13 = r1p3.read();
  r14 = r1p4.read();
  r15 = r1p5.read();
  r16 = r1p6.read();
  r21 = r2p1.read();
  r22 = r2p2.read();
  r23 = r2p3.read();
  r24 = r2p4.read();
  r25 = r2p5.read();
  r26 = r2p6.read();
  r31 = r3p1.read();
  r32 = r3p2.read();
  r33 = r3p3.read();
  r34 = r3p4.read();
  r35 = r3p5.read();
  r36 = r3p6.read();
  r41 = r4p1.read();
  r42 = r4p2.read();
  r43 = r4p3.read();
  r44 = r4p4.read();
  r45 = r4p5.read();

  speed11 = sp11.read();
  speed12 = sp12.read();
  speed2 = sp2.read();
  speed3 = sp3.read();
  speed4 = sp4.read();

  t = timer.read();

 if(t>99){
  if(status_r1.read()==2){
       x1 = x1 ;
       y1 = y1 ;
       robot1_x.write(x1);
       robot1_y.write(y1);
}
  else if(status_r1.read()==4){
    if((y1>11.99 & y1<12.01)||(y1>9.99 & y1<10.01)){
    x1 = x1;
    y1 = y1;
    robot1_x.write(x1);
    robot1_y.write(y1);
  }
  else{
    x1 = x1;
    y1 -= speed12;
    robot1_x.write(x1);
    robot1_y.write(y1);
  }
  }
  else{
     if(x1 > r11-0.001 & x1 < r11+0.001 & y1 > r12+0.01){
       x1 = x1;
       y1 -= speed11;
       robot1_x.write(x1);
       robot1_y.write(y1);
     }
     else if(x1 < r13-0.001 & y1 < r12+0.001 & y1 > r12-0.01){
       x1 += speed12;
       y1 = y1;
       robot1_x.write(x1);
       robot1_y.write(y1);
     }
     else if(x1 > r13-0.01 & x1 < r13+0.01 & y1 > r14+0.01){
       x1 = x1;
       y1 -= speed12;
       robot1_x.write(x1);
       robot1_y.write(y1);
     }
     else if(y1 < r14+0.01  & y1 > r14-0.01  & x1 > r15+0.01){
       x1 -= speed11;
       y1 = y1;
       robot1_x.write(x1);
       robot1_y.write(y1);
     }
     else if(x1 < r15+0.01 & x1 > r15-0.01 & y1 > r16+0.01){
       x1 = x1;
       y1 -= speed11;
       robot1_x.write(x1);
       robot1_y.write(y1);
     }
     else{
       x1 = x1;
       y1 = y1;
       robot1_x.write(x1);
       robot1_y.write(y1);
   }
 }
}
 else{
   x1 = x1;
   y1 = y1;
   robot1_x.write(x1);
   robot1_y.write(y1);
 }
  //r1 path

 if(t>499){
  if(status_r2.read()==2){
     x2 = x2 ;
     y2 = y2 ;
     robot2_x.write(x2);
     robot2_y.write(y2);
   }
  else if(status_r2.read() == 4){
     if((y2>9.99 & y2<10.01) ||(y2>11.99 & y2<12.01)){
       x2 = x2;
       y2 = y2;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
     else{
       x2 = x2;
       y2 += speed2;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
   }
  else{
     if( x2 > r21-0.01 & x2 < r21+0.01 & y2 > r22+0.01){
       x2 = x2;
       y2 -= speed2;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
     else if(y2 < r22+0.01 & x2 > r23+0.01 & y2 > r22-0.01){
       x2 -= speed2;
       y2 = y2;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
     else if(x2 < r23+0.01 & y2 > r24+0.01){
       x2 = x2;
       y2 -= speed2;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
     else if(y2 < r24+0.01 & y2 > r24-0.01 & x2 < r25-0.01){
       x2 += speed2;
       y2 = y2;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
     else if(x2 > r25-0.01 & x2 < r25+0.01 & y2 < r26-0.01){
       x2 = x2;
       y2 += speed2;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
     else{
       x2 = x2 ;
       y2 = y2 ;
       robot2_x.write(x2);
       robot2_y.write(y2);
     }
   }
 }
 else{
   x2 = x2 ;
   y2 = y2 ;
   robot2_x.write(x2);
   robot2_y.write(y2);
 }
  //r2 path

 if(t>699){
  if(status_r3.read()==2){
     x3 = x3;
     y3 = y3;
     robot3_x.write(x3);
     robot3_y.write(y3);
   }
  else if(status_r3.read() == 4){
  if((x3>11.99 & x3<12.01)){
       x3 = x3;
       y3 = y3;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
     else{
       x3 = x3;
       y2 += speed3;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
   }
  else{
     if( x3 > r31-0.01 & x3 < r31+0.01 & y3 < r32-0.01){
       x3 = x3;
       y3 += speed3;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
     else if(y3 > r32-0.01 & y3 < r32+0.01 & x3 < r33-0.01){
       x3 += speed3;
       y3 = y3;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
     else if(x3 > r33-0.01 & x3 < r33+0.01 & y3 > r34+0.01){
       x3 = x3;
       y3 -= speed3;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
     else if(y3 < r34+0.01 & y3 > r34-0.01 & x3 < r35-0.01){
       x3 += speed3;
       y3 = y3;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
     else if(x3 > r35-0.01 & x3 < r35+0.01 & y3 < r36-0.01){
       x3 = x3;
       y3 += speed3;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
     else{
       x3 = x3 ;
       y3 = y3 ;
       robot3_x.write(x3);
       robot3_y.write(y3);
     }
   }
  }
 else{
    x3 = x3 ;
    y3 = y3 ;
    robot3_x.write(x3);
    robot3_y.write(y3);
  }
  //r3 path

 if(t>199){
  if(status_r4.read()==2){
     x4 = x4;
     y4 = y4;
     robot4_x.write(x4);
     robot4_y.write(y4);
   }
   else{
     if( x4 > r41-0.01 & x4 < r41+0.01 & y4 < r42-0.01){
       x4 = x4;
       y4 += speed4;
       robot4_x.write(x4);
       robot4_y.write(y4);
     }
     else if(y4 > r42-0.01 & y4 < r42+0.01 & x4 > r43+0.01){
       x4 -= speed4;
       y4 = y4;
       robot4_x.write(x4);
       robot4_y.write(y4);
     }
     else if(x4 > r43-0.01 & x4 < r43+0.01 & y4 > r44+0.01){
       x4 = x4;
       y4 -= speed4;
       robot4_x.write(x4);
       robot4_y.write(y4);
     }
     else if(y4 < r44+0.01 & y4 > r44-0.01 & x4 < r45-0.01){
       x4 += speed4;
       y4 = y4;
       robot4_x.write(x4);
       robot4_y.write(y4);
     }
     else{
       x4 = x4 ;
       y4 = y4 ;
       robot4_x.write(x4);
       robot4_y.write(y4);
     }
   }
 }
 else{
   x4 = x4 ;
   y4 = y4 ;
   robot4_x.write(x4);
   robot4_y.write(y4);
 }
  //r4 path

   if((o1x2< 19.97) & (o1y1< 16.03) & (o1y1 > 15.97)){
       o1x1 += 0.05;
       o1y1 = o1y1;
       o1x2 += 0.05;
       o1y2 = o1y2;
       obstacle1_x1.write(o1x1);
       obstacle1_y1.write(o1y1);
       obstacle1_x2.write(o1x2);
       obstacle1_y2.write(o1y2);
     }
   else if((o1x2>19.97) & (o1y1 > 12.03) ){
       o1x1 = o1x1;
       o1y1 -= 0.05;
       o1x2 = o1x2;
       o1y2 -= 0.05;
       obstacle1_x1.write(o1x1);
       obstacle1_y1.write(o1y1);
       obstacle1_x2.write(o1x2);
       obstacle1_y2.write(o1y2);
     }
   else if((o1x2 > 2.02) & (o1y1 < 12.03) & (o1y1 > 11.97)){
       o1x1 -= 0.05;
       o1y1 = o1y1;
       o1x2 -= 0.05;
       o1y2 = o1y2;
       obstacle1_x1.write(o1x1);
       obstacle1_y1.write(o1y1);
       obstacle1_x2.write(o1x2);
       obstacle1_y2.write(o1y2);
     }
   else{
       o1x1 = o1x1;
       o1y1 += 0.05;
       o1x2 = o1x2;
       o1y2 += 0.05;
       obstacle1_x1.write(o1x1);
       obstacle1_y1.write(o1y1);
       obstacle1_x2.write(o1x2);
       obstacle1_y2.write(o1y2);
       obstacle1_x2.write(o1x2);
       obstacle1_y2.write(o1y2);
    }
   // obstacle1 path

    if((o2x2< 11.97) & (o2y1< 12.03) & (o2y1 > 11.97)){
        o2x1 += 0.05;
        o2y1 = o2y1;
        o2x2 += 0.05;
        o2y2 = o2y2;
        obstacle2_x1.write(o2x1);
        obstacle2_y1.write(o2y1);
        obstacle2_x2.write(o2x2);
        obstacle2_y2.write(o2y2);
      }
    else if((o2x2>11.97) & (o2y1 > 8.03) ){
        o2x1 = o2x1;
        o2y1 -= 0.05;
        o2x2 = o2x2;
        o2y2 -= 0.05;
        obstacle2_x1.write(o2x1);
        obstacle2_y1.write(o2y1);
        obstacle2_x2.write(o2x2);
        obstacle2_y2.write(o2y2);
      }
    else if((o2x2 > 2.02) & (o2y1 < 8.03) & (o2y1 > 7.97)){
      o2x1 -= 0.05;
      o2y1 = o2y1;
      o2x2 -= 0.05;
      o2y2 = o2y2;
      obstacle2_x1.write(o2x1);
      obstacle2_y1.write(o2y1);
      obstacle2_x2.write(o2x2);
      obstacle2_y2.write(o2y2);
      }
    else{
        o2x1 = o2x1;
        o2y1 += 0.05;
        o2x2 = o2x2;
        o2y2 += 0.05;
        obstacle2_x1.write(o2x1);
        obstacle2_y1.write(o2y1);
        obstacle2_x2.write(o2x2);
        obstacle2_y2.write(o2y2);
     }
    //obstacle2 path

    if((o3x2< 19.97) & (o3y1< 12.03) & (o3y1 > 11.97)){
         o3x1 += 0.05;
         o3y1 = o3y1;
         o3x2 += 0.05;
         o3y2 = o3y2;
         obstacle3_x1.write(o3x1);
         obstacle3_y1.write(o3y1);
         obstacle3_x2.write(o3x2);
         obstacle3_y2.write(o3y2);
       }
    else if((o3x2>19.97) & (o3y1 > 8.03) ){
         o3x1 = o3x1;
         o3y1 -= 0.05;
         o3x2 = o3x2;
         o3y2 -= 0.05;
         obstacle3_x1.write(o3x1);
         obstacle3_y1.write(o3y1);
         obstacle3_x2.write(o3x2);
         obstacle3_y2.write(o3y2);
       }
    else if((o3x2 > 12.02) & (o3y1 < 8.03) & (o3y1 > 7.97)){
       o3x1 -= 0.05;
       o3y1 = o3y1;
       o3x2 -= 0.05;
       o3y2 = o3y2;
       obstacle3_x1.write(o3x1);
       obstacle3_y1.write(o3y1);
       obstacle3_x2.write(o3x2);
       obstacle3_y2.write(o3y2);
       }
    else{
         o3x1 = o3x1;
         o3y1 += 0.05;
         o3x2 = o3x2;
         o3y2 += 0.05;
         obstacle3_x1.write(o3x1);
         obstacle3_y1.write(o3y1);
         obstacle3_x2.write(o3x2);
         obstacle3_y2.write(o3y2);
       }
    //obstacle3 path

    if((o4x2 < 13.97) & (o4y1 < 8.03) & (o4y1 > 7.97)){
           o4x1 += 0.05;
           o4y1 = o4y1;
           o4x2 += 0.05;
           o4y2 = o4y2;
           obstacle4_x1.write(o4x1);
           obstacle4_y1.write(o4y1);
           obstacle4_x2.write(o4x2);
           obstacle4_y2.write(o4y2);
         }
    else if((o4x2 > 13.97) & (o4y1 > 4.03) ){
           o4x1 = o4x1;
           o4y1 -= 0.05;
           o4x2 = o4x2;
           o4y2 -= 0.05;
           obstacle4_x1.write(o4x1);
           obstacle4_y1.write(o4y1);
           obstacle4_x2.write(o4x2);
           obstacle4_y2.write(o4y2);
         }
    else if((o4x2 > 2.02) & (o4y1 < 4.03) & (o4y1 > 3.97)){
         o4x1 -= 0.05;
         o4y1 = o4y1;
         o4x2 -= 0.05;
         o4y2 = o4y2;
         obstacle4_x1.write(o4x1);
         obstacle4_y1.write(o4y1);
         obstacle4_x2.write(o4x2);
         obstacle4_y2.write(o4y2);
         }
    else{
           o4x1 = o4x1;
           o4y1 += 0.05;
           o4x2 = o4x2;
           o4y2 += 0.05;
           obstacle4_x1.write(o4x1);
           obstacle4_y1.write(o4y1);
           obstacle4_x2.write(o4x2);
           obstacle4_y2.write(o4y2);
         }
    //obstacle4 path

    if((o5x2 < 19.97) & (o5y1 < 8.03) & (o5y1 > 7.97)){
             o5x1 += 0.05;
             o5y1 = o5y1;
             o5x2 += 0.05;
             o5y2 = o5y2;
             obstacle5_x1.write(o5x1);
             obstacle5_y1.write(o5y1);
             obstacle5_x2.write(o5x2);
             obstacle5_y2.write(o5y2);
           }
    else if((o5x2 > 19.97) & (o5y1 > 4.03) ){
             o5x1 = o5x1;
             o5y1 -= 0.05;
             o5x2 = o5x2;
             o5y2 -= 0.05;
             obstacle5_x1.write(o5x1);
             obstacle5_y1.write(o5y1);
             obstacle5_x2.write(o5x2);
             obstacle5_y2.write(o5y2);
           }
    else if((o5x2 > 14.02) & (o5y1 < 4.03) & (o5y1 > 3.97)){
           o5x1 -= 0.05;
           o5y1 = o5y1;
           o5x2 -= 0.05;
           o5y2 = o5y2;
           obstacle5_x1.write(o5x1);
           obstacle5_y1.write(o5y1);
           obstacle5_x2.write(o5x2);
           obstacle5_y2.write(o5y2);
           }
    else{
             o5x1 = o5x1;
             o5y1 += 0.05;
             o5x2 = o5x2;
             o5y2 += 0.05;
             obstacle5_x1.write(o5x1);
             obstacle5_y1.write(o5y1);
             obstacle5_x2.write(o5x2);
             obstacle5_y2.write(o5y2);
           }
    //obstacle5 path

    if((o6x2< 19.97) & (o6y1< 4.03) & (o6y1 > 3.97)){
         o6x1 += 0.05;
         o6y1 = o6y1;
         o6x2 += 0.05;
         o6y2 = o6y2;
         obstacle6_x1.write(o6x1);
         obstacle6_y1.write(o6y1);
         obstacle6_x2.write(o6x2);
         obstacle6_y2.write(o6y2);
       }
    else if((o6x2>19.97) & (o6y1 > 0.03) ){
         o6x1 = o6x1;
         o6y1 -= 0.05;
         o6x2 = o6x2;
         o6y2 -= 0.05;
         obstacle6_x1.write(o6x1);
         obstacle6_y1.write(o6y1);
         obstacle6_x2.write(o6x2);
         obstacle6_y2.write(o6y2);
       }
    else if((o6x2 > 2.02) & (o6y1 < 0.03) & (o6y1 > 0.00)){
       o6x1 -= 0.05;
       o6y1 = o6y1;
       o6x2 -= 0.05;
       o6y2 = o6y2;
       obstacle6_x1.write(o6x1);
       obstacle6_y1.write(o6y1);
       obstacle6_x2.write(o6x2);
       obstacle6_y2.write(o6y2);
       }
    else{
         o6x1 = o6x1;
         o6y1 += 0.05;
         o6x2 = o6x2;
         o6y2 += 0.05;
         obstacle6_x1.write(o6x1);
         obstacle6_y1.write(o6y1);
         obstacle6_x2.write(o6x2);
         obstacle6_y2.write(o6y2);
      }
    //obstacle6 path

   if(x1_max < 20.05){
     x1_max = x1_max;
   }
   else{
     x1_max = 20.00;
   }
   if(x1_min > 0.00){
     x1_min = x1_min;
   }
   else{
     x1_min = 0.00;
   }
   //ob1_extend

   if(x2_max < 12.05){
     x2_max = x2_max;
   }
   else{
     x2_max = 12.00;
   }
   if(x2_min > 0.00){
     x2_min = x2_min;
   }
   else{
     x2_min = 0.00;
   }
   //ob2_extend

   if(x3_max < 20.05){
     x3_max = x3_max;
   }
   else{
     x3_max = 20.00;
   }
   if(x3_min > 10.00){
     x3_min = x3_min;
   }
   else{
     x3_min = 10.00;
   }
   //ob3_extend

   if(x4_max < 14.05){
     x4_max = x4_max;
   }
   else{
     x4_max = 14.00;
   }
   if(x4_min > 0.00){
     x4_min = x4_min;
   }
   else{
     x4_min = 0.00;
   }
   //ob4_extend
   if(x5_max < 20.05){
     x5_max = x5_max;
   }
   else{
     x5_max = 20.00;
   }
   if(x5_min > 12.00){
     x5_min = x5_min;
   }
   else{
     x5_min = 12.00;
   }
   //ob5_extend

   if(x6_max < 20.05){
     x6_max = x6_max;
   }
   else{
     x6_max = 20.00;
   }
   if(x6_min > 0.00){
     x6_min = x6_min;
   }
   else{
     x6_min = 0.00;
   }
   //ob6_extend

   if((y1<o1y2 & y1 >o1y1 & x1 < x1_max & x1 > o1x1)||
   (y1<o2y2 & y1 >o2y1 & x1 < x2_max & x1 > o2x1) ||
   (y1<o1y2 & y1 >o1y1 & x1< o1x2 & x1 > x1_min)||
   (y1<o2y2 & y1 >o2y1 & x1< o2x2 & x1 > x2_min) ||
   (y1<o4y2 & y1 >o4y1 & x1 < x4_max & x1 > o4x1) ||
   (y1<o4y2 & y1 >o4y1 & x1< o4x2 & x1 > x4_min))
  // (y1 < 16.99 & y1 > 13.01 & x1>o1x1 & x1 <o1x2) ||
   //(y1 < 12.99 & y1 > 9.01 & x1>o2x1 & x1 <o2x2) ||
   //y1 < 12.99 & y1 > 9.01 & x1>o3x1 & x1 <o3x2 ))
   //(y1 < 8.99 & y1 > 5.01 & x1>o4x1 & x1 <o4x2) ||
   //(y1 < 4.99 & y1 > 1.01 & x1>o6x1 & x1 <o6x2))
   {
     flag1.write(50);
     j = 1;
   }
   else{
     if(j==0){
     if(y1 > 16.49 & y1 < 16.51 & x1 < 1.01 & x1 > 0.99){ //1-11
       flag1.write(1);
     }
     else if(y1 > 14.49 & y1 < 14.51 & x1 < 1.01 & x1 > 0.99){ //11-13
       flag1.write(2);
     }
     else if(x1 > 1.49 & x1 < 1.51 & y1 > 12.99 & y1 < 13.01){ //13-14
       flag1.write(3);
     }
     else if(x1 > 3.49 & x1 < 3.51 & y1 > 12.99 & y1 < 13.01){ //14-15
       flag1.write(4);
     }
     else if(x1 > 5.49 & x1 < 5.51 & y1 > 12.99 & y1 < 13.01){ //15-16
       flag1.write(5);
     }
     else if(x1 > 7.49 & x1 < 7.51 & y1 > 12.99 & y1 < 13.01){ //16-17
       flag1.write(6);
     }
     else if(x1 > 9.49 & x1 < 9.51 & y1 > 12.99 & y1 < 13.01){ //17-18
       flag1.write(7);
     }
     else if(y1 > 11.99 & y1 < 12.51 & x1 > 10.99 & x1 < 11.01){ //18-24
       flag1.write(8);
     }
     else if(y1 > 9.99 & y1 < 10.51 & x1 > 10.99 & x1 < 11.01){ //24-31
       flag1.write(9);
     }
     else if(x1 > 10.49 & x1 < 10.51 & y1 > 8.99 & y1 < 9.01){ //31-30
       flag1.write(10);
     }
     else if(x1 > 8.49 & x1 < 8.51 & y1 > 8.99 & y1 < 9.01){ //30-29
       flag1.write(11);
     }
     else if(x1 > 6.49 & x1 < 6.51 & y1 > 8.99 & y1 < 9.01){ //29-28
       flag1.write(12);
     }
     else if(x1 > 4.49 & x1 < 4.51 & y1 > 8.99 & y1 < 9.01){ //28-27
       flag1.write(13);
     }
     else if(x1 > 2.49 & x1 < 2.51 & y1 > 8.99 & y1 < 9.01){ //27-26
       flag1.write(14);
     }
     else if(y1 > 8.49 & y1 < 8.51 & x1 < 1.01 & x1 > 0.99){ //26-36
       flag1.write(15);
     }
     else if(y1 > 6.49 & y1 < 6.51 & x1 < 1.01 & x1 > 0.99){ //36-39
       flag1.write(16);
     }
    else{
      flag1.write(200);
}
}
     else {
       flag1.write(100);
       j = 0;
     }
   }
   //robot1_flag

   if((y2<o1y2 & y2 >o1y1 & x2 < x1_max & x2 > o1x1)||
   (y2<o3y2 & y2 >o3y1 & x2 < x3_max & x2 > o3x1 ) ||
   (y2<o3y2 & y2 >o3y1 & x2 < x3_max & x2 > o3x1 ) ||
   (y2<o1y2 & y2 >o1y1 & x2< o1x2 & x2 > x1_min) ||
   (y2<o3y2 & y2 >o3y1 & x2< o3x2 & x2 > x3_min) ||
   (y2<o5y2 & y2 >o5y1 & x2 < x5_max & x2 > o5x1) ||
   (y2<o5y2 & y2 >o5y1 & x2< o5x2 & x2 > x5_min) ||
   (y2<o4y2 & y2 >o4y1 & x2 < x4_max & x2 > o4x1) ||
   (y2<o4y2 & y2 >o4y1 & x2< o4x2 & x2 > x4_min) ||
   (y2 < 16.99 & y2 > 13.01 & x2>o1x1 & x2 <o1x2) ||
   (y2 < 12.99 & y2 > 9.01 & x2>o2x1 & x2 <o2x2) ||
   (y2 < 12.99 & y2 > 9.01 & x2>o3x1 & x2 <o3x2 ))
   {
     if((y2<o3y2 & y2 >o3y1 & x2 < x3_max & x2 > o3x1) ||
     (y2<o1y2 & y2 >o1y1 & x2< o1x2 & x2 > x1_min)){
    flag2.write(51);
     a = 1;
}
   else{
     flag2.write(50);
     a = 1;
   }
   }
   else{
     if(a==0){
     if(y2 > 16.49 & y2 < 16.51 & x2 > 18.99 & x2 < 19.01){ //10-12
       flag2.write(1);
     }
     else if(y2 > 14.49 & y2 < 14.51 & x2 > 18.99 & x2 < 19.01){ //12-22
       flag2.write(2);
     }
     else if(y2 > 12.99 & y2 < 13.01 & x2 > 18.49 & x2 < 18.51){ //22-21
       flag2.write(3);
     }
     else if(y2 > 12.99 & y2 < 13.01 & x2 > 16.49 & x2 < 16.51){ //21-20
       flag2.write(4);
     }
     else if(y2 > 12.99 & y2 < 13.01 & x2 > 14.49 & x2 < 14.51){ //20-19
       flag2.write(5);
     }
     else if(y2 > 12.99 & y2 < 13.01 & x2 > 12.49 & x2 < 12.51){ //19-18
       flag2.write(6);
     }
     else if(y2 > 12.49 & y2 < 12.51 & x2 > 10.99 & x2 < 11.01){ //18-24
       flag2.write(7);
     }
     else if(y2 > 10.49 & y2 < 10.51 & x2 > 10.99 & x2 < 11.01){ //24-31
       flag2.write(8);
     }
     else if(y2 > 8.99 & y2 < 9.01 & x2 > 11.49 & x2 < 11.51){ //31-32
      flag2.write(9);
     }
     else if(y2 > 8.99 & y2 < 9.01 & x2 > 13.49 & x2 < 13.51){ //32-33
     flag2.write(10);
     }
     else if(y2 > 8.99 & y2 < 9.01 & x2 > 15.49 & x2 < 15.51){ //33-34
     flag2.write(11);
     }
     else if(y2 > 8.99 & y2 < 9.01 & x2 > 17.49 & x2 < 17.51){ //34-35
     flag2.write(12);
     }
     else if(y2 > 9.49 & y2 < 9.51 & x2 > 18.99 & x2 < 19.01){ //35-25
     flag2.write(13);
     }
     else{
    flag2.write(200);
     }
}
else{
    flag2.write(100);
      a = 0;
     }
  }
  //robot2_flag

  if((y3 < o4y2  & y3 > o4y1 & x3 < x4_max & x3 > o4x1)||
  (y3 < o5y2  & y3 > o5y1 & x3 < x5_max & x3 > o5x2)||
  (y3<o4y2 & y3 >o4y1 & x3< o4x2 & x3 > x4_min) ||
  (y3<o5y2 & y3 >o5y1 & x3< o5x2 & x3 > x5_min)||
  (y3<o2y2 & y3 >o2y1 & x3< o2x2 & x3 > x2_min) ||
  (y3 < o2y2  & y3 > o2y1 & x3 < x2_max & x3 > o2x1) ||
  (y3 < 8.99 & y3 > 5.01 & x3>o4x1 & x3 <o4x2) ||
  (y3 < 8.99 & y3 > 5.01 & x3>o5x1 & x3 <o5x2) ||
  (y3 < 5.99 & y3 > 5.01 & x3>o6x1 & x3<o6x2))
  {
    if((y3<o2y2 & y3 >o2y1 & x3< o2x2 & x3 > x2_min) || 
    (y3 < o4y2  & y3 > o4y1 & x3 < x4_max & x3 > o4x1)){
      flag3.write(51);
      i = 1;
    }
    else{
    flag3.write(50);
    i = 1;
   }
  }
  else{
    if(i==0){
    if(y3 > 3.49 & y3 < 3.51 & x3 > 0.99 & x3 < 1.01){ // 49-39
      flag3.write(1);
    }
    else if(y3 > 5.49 & y3 < 5.51 & x3 > 0.99 & x3 < 1.01){ //39-36
      flag3.write(2);
    }
    else if(y3 > 7.49 & y3 < 7.51 & x3 > 0.99 & x3 < 1.01){ //36-26
      flag3.write(3);
    }
    else if(y3 > 8.99 & y3 < 9.01 & x3 > 1.49 & x3 < 1.51){ //26-27
      flag3.write(4);
    }
    else if(y3 > 8.99 & y3 < 9.01 & x3 > 3.49 & x3 < 3.51){ //27-28
      flag3.write(5);
    }
    else if(y3 > 8.99 & y3 < 9.01 & x3 > 5.49 & x3 < 5.51){ //28-29
      flag3.write(6);
    }
    else if(y3 > 8.99 & y3 < 9.01 & x3 > 7.49 & x3 < 7.51){ //29-30
      flag3.write(7);
    }
    else if(y3 > 8.99 & y3 < 9.01 & x3 > 9.49 & x3 < 9.51){ //30-31
      flag3.write(8);
    }
    else if(y3 > 8.99 & y3 < 9.01 & x3 > 11.49 & x3 < 11.51){ //31-32
      flag3.write(9);
    }
    else if(y3 > 8.49 & y3 < 8.51 & x3 > 12.99 & x3 < 13.01){ //32-37
     flag3.write(10);
    }
    else if(y3 > 6.49 & y3 < 6.51 & x3 > 12.99 & x3 < 13.01){ //37-45
    flag3.write(11);
    }
    else if(y3 > 4.99 & y3 < 5.01 & x3 > 13.49 & x3 < 13.51){ //45-46
    flag3.write(12);
    }
    else if(y3 > 4.99 & y3 < 5.01 & x3 > 15.49 & x3 < 15.51){ //46-47
    flag3.write(13);
    }
    else if(y3 > 4.99 & y3 < 5.01 & x3 > 17.49 & x3 < 17.51){ //47-48
    flag3.write(14);
    }
    else if(y3 > 5.49 & y3 < 5.51 & x3 > 18.99 & x3 < 19.01){ //48-38
    flag3.write(15);
    }
    else{
   flag3.write(200);
    }
}
else{
   flag3.write(100);
     i = 0;
    }
 }
  //robot3_flag

 if((y4 < o4y2  & y4 > o4y1 & x4 < x4_max & x4 > o4x1) ||
 (y4 < o5y2  & y4 > o5y1 & x4 < x5_max & x4 > o5x2)||
 (y4<o4y2 & y4 >o4y1 & x4< o4x2 & x4 > x4_min) ||
 (y4<o5y2 & y4 >o5y1 & x4< o5x2 & x4 > x5_min) ||
 (y4 < o6y2  & y4 > o6y1 & x4 < x6_max & x4 > o6x2)||
 (y4<o6y2 & y4 >o6y1 & x4< o6x2 & x4 > x6_min) ||
 (y4 < 4.99 & y4 > 1.01 & x4>o6x1 & x4 <o6x2) )
 {
   flag4.write(50);
   k = 1;
 }
 else{
   if(k==0){
   if(y4 > 1.49 & y4 < 1.51 & x4 > 18.99 & x4 < 19.01){ //60-50
     flag4.write(1);
   }
   else if(y4 > 3.49 & y4 < 3.51 & x4 > 18.99 & x4 < 19.01){ //50-48
     flag4.write(2);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 18.49 & x4 < 18.51){ //48-47
     flag4.write(3);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 16.49 & x4 < 16.51){ //47-46
     flag4.write(4);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 14.49 & x4 < 14.51){ //46-45
     flag4.write(5);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 12.49 & x4 < 12.51){ //45-44
     flag4.write(6);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 10.49 & x4 < 10.51){ //44-43
     flag4.write(7);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 8.49 & x4 < 8.51){ //43-42
     flag4.write(8);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 6.49 & x4 < 6.51){ //42-41
    flag4.write(9);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 4.49 & x4 < 4.51){ //41-40
   flag4.write(10);
   }
   else if(y4 > 4.99 & y4 < 5.01 & x4 > 2.49 & x4 < 2.51){ //40-39
   flag4.write(11);
   }
   else if(y4 > 4.49 & y4 < 4.51 & x4 > 0.99 & x4 < 1.01){ //39-49
   flag4.write(12);
   }
   else if(y4 > 2.49 & y4 < 2.51 & x4 > 0.99 & x4 < 1.01){ //49-51
   flag4.write(13);
   }
   else if(y4 > 0.99 & y4 < 1.01 & x4 > 1.49 & x4 < 1.51){ //51-52
   flag4.write(14);
   }
   else if(y4 > 0.99 & y4 < 1.01 & x4 > 3.49 & x4 < 3.51){ //52-53
   flag4.write(15);
   }
   else if(y4 > 0.99 & y4 < 1.01 & x4 > 5.49 & x4 < 5.51){ //53-54
   flag4.write(16);
   }
   else if(y4 > 0.99 & y4 < 1.01 & x4 > 7.49 & x4 < 7.51){ //54-55
   flag4.write(17);
   }
   else{
  flag4.write(200);
   }
}
else{
  flag4.write(100);
    i = 0;
   }
}
 //robot4_flag

}
  SC_CTOR(update1){
    SC_METHOD(prc_update1);
    sensitive << clock.pos();
  }

};





SC_MODULE(tran1){
  sc_in<sc_uint<16> > flag1;
  sc_in<sc_uint<16> > flag2;
  sc_in<sc_uint<16> > flag3;
  sc_in<sc_uint<16> > flag4;

  sc_out<bool> r1_ctr;
  sc_out<sc_uint<14> > r1_index;
  sc_out<bool> r2_ctr;
  sc_out<sc_uint<14> > r2_index;
  sc_out<bool> r3_ctr;
  sc_out<sc_uint<14> > r3_index;
  sc_out<bool> r4_ctr;
  sc_out<sc_uint<14> > r4_index;

  sc_uint<16> flag_r1;
  sc_uint<16> flag_r2;
  sc_uint<16> flag_r3;
  sc_uint<16> flag_r4;

  bool ctr1 = false;
  bool ctr2 = false;
  bool ctr3 = false;
  bool ctr4 = false;

  void prc_tran1(){
    flag_r1 = flag1.read();

      if(flag_r1 == 50){ //STOP
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b10000000000000);
      }
      else if(flag_r1 == 1){ //1-11
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01000001001011);
      }
      else if(flag_r1 == 2){ //11-13
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01001011001101);
      }
      else if(flag_r1 == 3){ //13-14
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01001101001110);
      }
      else if(flag_r1 == 4){ //14-15
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01001110001111);
      }
      else if(flag_r1 == 5){ //15-16
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01001111010000);
      }
      else if(flag_r1 == 6){ //16-17
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01010000010001);
      }
      else if(flag_r1 == 7){ //17-18
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01010001010010);
      }
      else if(flag_r1 == 8){ //18-24
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01010010011000);
      }
      else if(flag_r1 == 9){ //24-31
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01011000011111);
      }
      else if(flag_r1 == 10){ //31-30
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01011111011110);
      }
      else if(flag_r1 == 11){ //30-29
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01011110011101);
      }
      else if(flag_r1 == 12){ //29-28
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01011101011100);
      }
      else if(flag_r1 == 13){ //28-27
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01011100011011);
      }
      else if(flag_r1 == 14){ //27-26
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01011011011010);
      }
      else if(flag_r1 == 15){ //26-36
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b01011010100100);
      }
      else if(flag_r1 == 16){ //36-39
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b010100100100111);
      }

      else if(flag_r1 == 100){ //RESUMING
        ctr1 = true;
        r1_ctr.write(ctr1);
        r1_index.write(0b110000000000000);
      }
      else{ //NO OPERATION
        ctr1 = false;
        r1_ctr.write(ctr1);
      }
}
  //tran_r1

  void prc_tran2(){

    flag_r2 = flag2.read();

      if(flag_r2 == 50){  //STOP
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b10000000000000);
      }
      if(flag_r2 == 51){  //STOP
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b10000000000001);
      }
      else if(flag_r2 == 1){ //11-12
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01001011001100);
      }
      else if(flag_r2 == 2){ //12-22
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01001100010110);
      }
      else if(flag_r2 == 3){ //22-21
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01010110010101);
      }
      else if(flag_r2 == 4){ //21-20
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01010101010100);
      }
      else if(flag_r2 == 5){ //20-19
        ctr2 = true;
        r2_ctr.write(ctr1);
        r2_index.write(0b01010100010011);
      }
      else if(flag_r2 == 6){ //19-18
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01010011010010);
      }
      else if(flag_r2 == 7){ //18-24
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01010010011000);
      }
      else if(flag_r2 == 8){ //24-31
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01011000011111);
      }
      else if(flag_r2 == 9){ //31-32
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01011111100000);
      }
      else if(flag_r2 == 10){ //32-33
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01100000100001);
      }
      else if(flag_r2 == 11){ //33-34
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01100001100010);
      }
      else if(flag_r2 == 12){ //34-35
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01100010100011);
      }
      else if(flag_r2 == 13){ //35-25
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01100011011001);
      }
      else if(flag_r2 == 100){ //RESUMING
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b11000000000000);
      }
      else{
        ctr2 = false;
        r2_ctr.write(ctr2);
      }
  }
  //tran_r2

  void prc_tran3(){
    flag_r3 = flag3.read();

      if(flag_r3 == 50){ //STOP
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b10000000000000);
      }
      else if(flag_r3 == 51){ //STOP
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b10000000000001);
      }
      else if(flag_r3 == 1){ //49-39
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01110001100111);
      }
      else if(flag_r3 == 2){ //39-36
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01100111100100);
      }
      else if(flag_r3 == 3){ //36-26
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01100100011010);
      }
      else if(flag_r3 == 4){ //26-27
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01011010011011);
      }
      else if(flag_r3 == 5){ //27-28
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01011011011100);
      }
      else if(flag_r3 == 6){ //28-29
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01011100011101);
      }
      else if(flag_r3 == 7){ //29-30
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01011101011110);
      }
      else if(flag_r3 == 8){ //30-31
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01011110011111);
      }
      else if(flag_r3 == 9){ //31-32
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01011111100000);
      }
      else if(flag_r3 == 10){ //32-37
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01100000100101);
      }
      else if(flag_r3 == 11){ //37-45
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01100101101101);
      }
      else if(flag_r3 == 12){ //45-46
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01101101101110);
      }
      else if(flag_r3 == 13){ //46-47
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01101110101111);
      }
      else if(flag_r3 == 14){ //47-48
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01101111110000);
      }
      else if(flag_r3 == 15){ //48-38
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b01110000100110);
      }

      else if(flag_r3 == 100){ //RESUMING
        ctr3 = true;
        r3_ctr.write(ctr3);
        r3_index.write(0b110000000000000);
      }
      else{ //NO OPERATION
        ctr3 = false;
        r3_ctr.write(ctr3);
      }
}
  //tran_r3

  void prc_tran4(){

    flag_r4 = flag4.read();

      if(flag_r4 == 50){  //STOP
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b10000000000000);
      }
      else if(flag_r4 == 1){ //60-50
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01111100110010);
      }
      else if(flag_r2 == 2){ //50-48
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01110010110000);
      }
      else if(flag_r2 == 3){ //48-47
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01110000101111);
      }
      else if(flag_r2 == 4){ //47-46
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101111101110);
      }
      else if(flag_r2 == 5){ //46-45
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101110101101);
      }
      else if(flag_r2 == 6){ //45-44
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101101101100);
      }
      else if(flag_r2 == 7){ //44-43
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101100101011);
      }
      else if(flag_r2 == 8){ //43-42
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101011101010);
      }
      else if(flag_r2 == 9){ //42-41
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101010101001);
      }
      else if(flag_r2 == 10){ //41-40
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101001101000);
      }
      else if(flag_r2 == 11){ //40-39
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01101000100111);
      }
      else if(flag_r2 == 12){ //39-49
        ctr2 = true;
        r2_ctr.write(ctr2);
        r2_index.write(0b01100111110001);
      }
      else if(flag_r2 == 13){ //49-51
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01110001110011);
      }
      else if(flag_r2 == 14){ //51-52
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01110011110100);
      }
      else if(flag_r2 == 15){ //52-53
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01110100110101);
      }
      else if(flag_r2 == 16){ //53-54
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01110101110110);
      }
      else if(flag_r2 == 17){ //54-55
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b01110110110111);
      }
      else if(flag_r2 == 100){ //RESUMING
        ctr4 = true;
        r4_ctr.write(ctr4);
        r4_index.write(0b11000000000000);
      }
      else{
        ctr4 = false;
        r4_ctr.write(ctr4);
      }
  }
  //tran_r4

  SC_CTOR(tran1){
    SC_METHOD(prc_tran1);
    sensitive << flag1;
    SC_METHOD(prc_tran2);
    sensitive << flag2;
    SC_METHOD(prc_tran3);
    sensitive << flag3;
    SC_METHOD(prc_tran4);
    sensitive << flag4;
  }

};

SC_MODULE(rec1){
  sc_in<bool> ctr_r1;
  sc_in<sc_uint<4> > status_r1;
  sc_in<bool> ctr_r2;
  sc_in<sc_uint<4> > status_r2;
  sc_in<bool> ctr_r3;
  sc_in<sc_uint<4> > status_r3;
  sc_in<bool> ctr_r4;
  sc_in<sc_uint<4> > status_r4;

  sc_fifo_in<int> path1;
  sc_fifo_in<int> path2;
  sc_fifo_in<int> path3;
  sc_fifo_in<int> path4;
  sc_fifo_in<int> speed1;
  sc_fifo_in<int> speed2;
  sc_fifo_in<int> speed3;
  sc_fifo_in<int> speed4;

  sc_out<sc_uint<4> > status_t1;
  sc_out<sc_uint<4> > status_t2;
  sc_out<sc_uint<4> > status_t3;
  sc_out<sc_uint<4> > status_t4;

  sc_out<double> r1p1;
  sc_out<double> r1p2;
  sc_out<double> r1p3;
  sc_out<double> r1p4;
  sc_out<double> r1p5;
  sc_out<double> r1p6;
  sc_out<double> r2p1;
  sc_out<double> r2p2;
  sc_out<double> r2p3;
  sc_out<double> r2p4;
  sc_out<double> r2p5;
  sc_out<double> r2p6;
  sc_out<double> r3p1;
  sc_out<double> r3p2;
  sc_out<double> r3p3;
  sc_out<double> r3p4;
  sc_out<double> r3p5;
  sc_out<double> r3p6;
  sc_out<double> r4p1;
  sc_out<double> r4p2;
  sc_out<double> r4p3;
  sc_out<double> r4p4;
  sc_out<double> r4p5;
  
  sc_out<double> sp11;
  sc_out<double> sp12;
  sc_out<double> sp2;
  sc_out<double> sp3;
  sc_out<double> sp4;

  sc_uint<4> status1;
  sc_uint<4> status2;
  sc_uint<4> status3;
  sc_uint<4> status4;



  int p1,r1tp1,r1tp2,r1tp3,r1tp4,r1tp5;
  int p2,r2tp1,r2tp2,r2tp3,r2tp4,r2tp5;
  int p3,r3tp1,r3tp2,r3tp3,r3tp4,r3tp5;
  int p4,r4tp1,r4tp2,r4tp3,r4tp4;
  int speed11,speed12,speed21,speed31,speed41;


  void prc_rec1(){
    if(ctr_r1.read()==true){
      status1 = status_r1.read();
      status_t1.write(status1);
    }
    else{
      status_t1.write(0);
    }
}
  //rec_r1

  void prc_rec2(){
    if(ctr_r2.read()==true){
      status2 = status_r2.read();
      status_t2.write(status2);
    }
    else{
      status_t2.write(0);
    }
  }
  //rec_r2

  void prc_rec3(){
    if(ctr_r3.read()==true){
      status3 = status_r3.read();
      status_t3.write(status3);
    }
    else{
      status_t3.write(0);
    }
  }
  //rec_r3

  void prc_rec4(){
    if(ctr_r4.read()==true){
      status4 = status_r4.read();
      status_t4.write(status4);
    }
    else{
      status_t4.write(0);
    }
  }
  //rec_r4

  void rec_path1(){
     path1.read(p1);
     path1.read(r1tp1);
     path1.read(r1tp2);
     path1.read(r1tp3);
     path1.read(r1tp4);
     path1.read(r1tp5);
    if(p1==1){
      r1p1.write(1.00);
    }
    else{
      r1p1.write(0.00);
    }
    if(r1tp1==13){
      r1p2.write(13.00);
    }
    else{
      r1p2.write(0.00);
    }
    if(r1tp2==18){
      r1p3.write(11.00);
    }
    else{
      r1p3.write(0.00);
    }
    if(r1tp3==31){
      r1p4.write(9.00);
    }
    else{
      r1p4.write(0.00);
    }
    if(r1tp4==26){
      r1p5.write(1.00);
    }
    else{
      r1p5.write(0.00);
    }
    if(r1tp5==39){
      r1p6.write(5.00);
    }
    else{
      r1p6.write(0.00);
    }

  }
  //r1_path

  void rec_path2(){
     path2.read(p2);
     path2.read(r2tp1);
     path2.read(r2tp2);
     path2.read(r2tp3);
     path2.read(r2tp4);
     path2.read(r2tp5);

    if(p2==10){
      r2p1.write(19.00);
    }
    else{
      r2p1.write(0.00);
    }
    if(r2tp1==22){
      r2p2.write(13.00);
    }
    else{
      r2p2.write(0.00);
    }
    if(r2tp2==18){
      r2p3.write(11.00);
    }
    else{
      r2p3.write(0.00);
    }
    if(r2tp3==31){
      r2p4.write(9.00);
    }
    else{
      r2p4.write(0.00);
    }
    if(r2tp4==35){
      r2p5.write(19.00);
    }
    else{
      r2p5.write(0.00);
    }
    if(r2tp5==23){
      r2p6.write(11.00);
    }
    else{
      r2p6.write(0.00);
    }

   }
  //r2_path

  void rec_path3(){
      path3.read(p3);
      path3.read(r3tp1);
      path3.read(r3tp2);
      path3.read(r3tp3);
      path3.read(r3tp4);
      path3.read(r3tp5);

     if(p3==49){
       r3p1.write(1.00);
     }
     else{
       r3p1.write(0.00);
     }
     if(r3tp1==26){
       r3p2.write(9.00);
     }
     else{
       r3p2.write(0.00);
     }
     if(r3tp2==32){
       r3p3.write(13.00);
     }
     else{
       r3p3.write(0.00);
     }
     if(r3tp3==45){
       r3p4.write(5.00);
     }
     else{
       r3p4.write(0.00);
     }
     if(r3tp4==48){
       r3p5.write(19.00);
     }
     else{
       r3p5.write(0.00);
     }
     if(r3tp5==38){
       r3p6.write(7.00);
     }
     else{
       r3p6.write(0.00);
     }

  }
  //r3_path

  void rec_path4(){
     path4.read(p4);
     path4.read(r4tp1);
     path4.read(r4tp2);
     path4.read(r4tp3);
     path4.read(r4tp4);

    if(p4==60){
      r4p1.write(19.00);
    }
    else{
      r4p1.write(0.00);
    }
    if(r4tp1==48){
      r4p2.write(5.00);
    }
    else{
      r4p2.write(0.00);
    }
    if(r4tp2==39){
      r4p3.write(1.00);
    }
    else{
      r4p3.write(0.00);
    }
    if(r4tp3==51){
      r4p4.write(1.00);
    }
    else{
      r4p4.write(0.00);
    }
    if(r4tp4==55){
      r4p5.write(9.00);
    }
    else{
      r4p5.write(0.00);
    }

 }
  //r4_path

  void rec_speed1(){
   speed1.read(speed11);
   speed1.read(speed12);
   if(speed11 == 0){
   sp11.write(0.00);
  }
   else if(speed11 ==1){
     sp11.write(0.01);
   }
   else if(speed11 == 2){
     sp11.write(0.02);
   }
   else{
     sp11.write(0.00);
   }

   if(speed12 == 0){
   sp12.write(0.00);
  }
   else if(speed12 ==1){
     sp12.write(0.01);
   }
   else if(speed12 == 2){
     sp12.write(0.02);
   }
   else{
     sp12.write(0.00);
   }
 }
  //r1_speed

  void rec_speed2(){
   speed2.read(speed21);
   if(speed21 == 0){
   sp2.write(0.00);
 }
   else if(speed21 == 2){
     sp2.write(0.02);
   }
   else{
     sp2.write(0.00);
   }
 }
  //r2_speed

  void rec_speed3(){
   speed3.read(speed31);
   if(speed31 == 0){
   sp3.write(0.00);
 }
   else if(speed31 == 2){
     sp3.write(0.02);
   }
   else{
     sp3.write(0.00);
   }
 }
  //r3_speed

  void rec_speed4(){
   speed4.read(speed41);
   if(speed41 == 0){
   sp4.write(0.00);
 }
   else if(speed41 == 2){
     sp4.write(0.02);
   }
   else{
     sp4.write(0.00);
   }
 }
  //r4_speed

  SC_CTOR(rec1){
    SC_METHOD(prc_rec1);
    sensitive << ctr_r1 << status_r1;
    SC_METHOD(prc_rec2);
    sensitive << ctr_r2 << status_r2;
    SC_METHOD(prc_rec3);
    sensitive << ctr_r3 << status_r3;
    SC_METHOD(prc_rec4);
    sensitive << ctr_r4 << status_r4;
    SC_THREAD(rec_path1);
    SC_THREAD(rec_path2);
    SC_THREAD(rec_path3);
    SC_THREAD(rec_path4);
    SC_THREAD(rec_speed1);
    SC_THREAD(rec_speed2);
    SC_THREAD(rec_speed3);
    SC_THREAD(rec_speed4);
  }

};
