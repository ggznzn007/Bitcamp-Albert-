/* CSPOTRUN                                   BY ANDRES NELSON */
main(){
 int Range,Heading,Direction;
 Heading=0;
 Direction=90;
 while(1){
  drive(Direction,100);
  if((Heading==0&&loc_y()>750)||(Heading==1&&loc_x()<150)||
  (Heading==2&&loc_y()<325)||(Heading==3&&loc_x()>850)){
   drive(Direction,50);
   Heading=(Heading+1)%4;
   Direction+=90;}
  else{
   if(Range=scan(0,10))cannon(0,Range);
   else if(Range=scan(20,10))cannon(20,Range);
   else if(Range=scan(40,10))cannon(40,Range);   
   else if(Range=scan(60,10))cannon(60,Range);
   else if(Range=scan(80,10))cannon(80,Range);
   else if(Range=scan(100,10))cannon(100,Range);
   else if(Range=scan(120,10))cannon(120,Range);
   else if(Range=scan(140,10))cannon(140,Range);
   else if(Range=scan(160,10))cannon(160,Range);
   else if(Range=scan(200,10))cannon(200,Range);
   else if(Range=scan(240,10))cannon(240,Range);
   else if(Range=scan(330,10))cannon(330,Range);}}}

/*     CCCC   SSSS   PPPP   OOOO   TTTT   RRRR   U  U   N  N
       C       S     PP P   O  O    TT    R  R   U  U   NN N
       C        S    P P    O  O    TT    R R    U  U   N NN 
       CCCC   SSSS   P      OOOO    TT    R  R   UUUU   N  N

                                             BY ANDRES NELSON */