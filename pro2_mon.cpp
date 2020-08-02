#include"systemc.h"

SC_MODULE(monitor){
  sc_in<double> x1;
  sc_in<double> x2;
  sc_in<double> y1;
  sc_in<double> y2;
  sc_in<double> x3;
  sc_in<double> x4;
  sc_in<double> y3;
  sc_in<double> y4;

  sc_in<double> o1x1;
  sc_in<double> o1y1;
  sc_in<double> o1x2;
  sc_in<double> o1y2;
  sc_in<double> o2x1;
  sc_in<double> o2y1;
  sc_in<double> o2x2;
  sc_in<double> o2y2;

  sc_in<double> o3x1;
  sc_in<double> o3y1;
  sc_in<double> o3x2;
  sc_in<double> o3y2;
  sc_in<double> o4x1;
  sc_in<double> o4y1;
  sc_in<double> o4x2;
  sc_in<double> o4y2;

  sc_in<double> o5x1;
  sc_in<double> o5y1;
  sc_in<double> o5x2;
  sc_in<double> o5y2;
  sc_in<double> o6x1;
  sc_in<double> o6y1;
  sc_in<double> o6x2;
  sc_in<double> o6y2;
  //sc_in<sc_uint<14> > index;
  sc_in<sc_uint<14> > index1;
  sc_in<sc_uint<4> > status1;
  sc_in<sc_uint<14> > index2;
  sc_in<sc_uint<4> > status2;
  sc_in<sc_uint<14> > index3;
  sc_in<sc_uint<4> > status3;
  sc_in<sc_uint<14> > index4;
  sc_in<sc_uint<4> > status4;
  sc_in<sc_uint<4> > s1;
  sc_in<bool> clock;

  const char* instr1;
  const char* instr2;
  const char* instr3;
  const char* instr4;

  const char* instr5;
  const char* instr6;
  const char* instr7;
  const char* instr8;

  sc_uint<14> index11;
  sc_uint<14> index21;
  sc_uint<14> index31;
  sc_uint<14> index41;
  sc_uint<2> in_s1;
  sc_uint<2> in_s2;
  sc_uint<2> in_s3;
  sc_uint<2> in_s4;
  sc_uint<4> status11;
  sc_uint<4> status21;
  sc_uint<4> status31;
  sc_uint<4> status41;


  void prc_mon(){
    index11 = index1.read();
    in_s1 = index11.range(13,12);
    status11 = status1.read();
    index21 = index2.read();
    in_s2 = index21.range(13,12);
    status21 = status2.read();
    index31 = index3.read();
    in_s3 = index31.range(13,12);
    status31 = status3.read();
    index41 = index4.read();
    in_s4 = index41.range(13,12);
    status41 = status4.read();

    if(in_s1==1){
      instr1 = "CROSSING";
}
    else if(in_s1==2){
      instr1 = "OBSTACLE";
//      instr2 = "STOP";
    }
    else if(in_s1==3){
      instr1 = "MOVING";
  //    instr2 = "RESUMING";
    }
    else{
      instr1 = "NO REQUEST";
    //  instr2 = "NO OPERATION";
    }

    if(status11 == 3){
    instr2 = "OK";
}
    else if(status11 == 1){
    instr2 = "RESUMING";
}
    else if(status11 == 2){
    instr2 = "STOP";
}
    else if(status11 == 4){
    instr2 = "STOP AT BOUNDARY";
}
    else{
    instr2 = "NO ANSWER";
}

    if(in_s2==1){
      instr3 = "CROSSING";
    }
    else if(in_s2==2){
      instr3 = "OBSTACLE";
   //   instr4 = "STOP";
    }
    else if(in_s2==3){
      instr3 = "MOVING";
 //     instr4 = "RESUMING";
    }
    else{
      instr3 = "NO REQUEST";
     // instr4 = "NO OPERATION";
    }

     if(status21 ==3){
    instr4 = "OK";
}
    else if(status21 == 1){
    instr4 = "RESUMING";
}
    else if(status21 == 2){
    instr4 = "STOP";
}
    else if(status21 == 4){
    instr4 = "STOP AT BOUNDARY";
}
    else{
    instr4 = "NO ANSWER";
}


if(in_s3==1){
  instr5 = "CROSSING";
}
else if(in_s3==2){
  instr5 = "OBSTACLE";
//      instr2 = "STOP";
}
else if(in_s3==3){
  instr5 = "MOVING";
//    instr2 = "RESUMING";
}
else{
  instr5 = "NO REQUEST";
//  instr2 = "NO OPERATION";
}

if(status31 == 3){
instr6 = "OK";
}
else if(status31 == 1){
instr6 = "RESUMING";
}
else if(status31 == 2){
instr6 = "STOP";
}
else if(status31 == 4){
instr6 = "STOP AT BOUNDARY";
}
else{
instr6 = "NO ANSWER";
}

if(in_s4==1){
  instr7 = "CROSSING";
}
else if(in_s4==2){
  instr7 = "OBSTACLE";
//   instr4 = "STOP";
}
else if(in_s4==3){
  instr7 = "MOVING";
//     instr4 = "RESUMING";
}
else{
  instr7 = "NO REQUEST";
 // instr4 = "NO OPERATION";
}

 if(status41 ==3){
instr8 = "OK";
}
else if(status41 == 1){
instr8 = "RESUMING";
}
else if(status41 == 2){
instr8 = "STOP";
}
else if(status41 == 4){
instr8 = "STOP AT BOUNDARY";
}
else{
instr8 = "NO ANSWER";
}
    cout << sc_time_stamp()<<endl;
    cout << "robot1 is" << "("<<x1<<","<<y1<<")"<<"           ";
    cout << "robot2 is" << "("<<x2<<","<<y2<<")"<<"           ";
    cout << "robot3 is" << "("<<x3<<","<<y3<<")"<<"           ";
    cout << "robot4 is" << "("<<x4<<","<<y4<<")"<<endl;
    cout << "obstacle1" << "("<<o1x1<<","<<o1y1<<")"<<"to"<<"("<<o1x2<<","<<o1y2<<")"<<"  ";
    cout << "obstacle2" << "("<<o2x1<<","<<o2y1<<")"<<"to"<<"("<<o2x2<<","<<o2y2<<")"<<"  ";
    cout << "obstacle3" << "("<<o3x1<<","<<o3y1<<")"<<"to"<<"("<<o3x2<<","<<o3y2<<")"<<endl;
    cout << "obstacle4" << "("<<o4x1<<","<<o4y1<<")"<<"to"<<"("<<o4x2<<","<<o4y2<<")"<<"  ";
    cout << "obstacle5" << "("<<o5x1<<","<<o5y1<<")"<<"to"<<"("<<o5x2<<","<<o5y2<<")"<<"  ";
    cout << "obstacle6" << "("<<o6x1<<","<<o6y1<<")"<<"to"<<"("<<o6x2<<","<<o6y2<<")"<<endl;
    //cout << "control2ser:  " << ctr<<"   ";
   //cout << "ser2robot1:  " << ctr1 <<"  "<<"status1:  " <<status2<<"   ";
    //cout << "robot2pro:   " << ctr2<<"  "<<"s1topro:   " <<s1<<endl;
    // cout << "index" << "  "<<index <<"control"<<"    "<<ctr<<"next index"<<" " <<index1<<endl;
    cout << "Request(R1):    "<< instr1 << "    ";
    cout << "Answer(R1):     " << instr2 << endl;
    cout << "Request(R2):    "<< instr3 << "    ";
    cout << "Answer(R2):     " << instr4 <<"    "<<endl;
    cout << "Request(R3):    "<< instr5 << "    ";
    cout << "Answer(R3):     " << instr6 << endl;
    cout << "Request(R4):    "<< instr7 << "    ";
    cout << "Answer(R4):     " << instr8 <<"    "<<endl;
  //   cout << s1 <<endl;
  }

  SC_CTOR(monitor){
    SC_METHOD(prc_mon);
    sensitive << clock.pos();
  }
};
