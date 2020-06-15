/* CSPOTRUN                                   BY ANDRES NELSON */
main(){
 int Range,Heading,Direction,i,d;
 Heading=0;
 Direction=90;
br = 0;
 while(1){
i=0;
  drive(Direction,100);
  if((Heading==0&&loc_y()>505)||(Heading==1&&loc_x()<200)||
  (Heading==2&&loc_y()<250)||(Heading==3&&loc_x()>850)){
   drive(Direction,50);
   Heading=(Heading+1)%4;
   Direction+=90;}
  else{
while(i<=330){
	if(Range=scan(i,10)) {
		if(br>Range && d==0)  {
			Heading=(Heading+2)%4;
  			 Direction=(Direction+180)%360;
			drive(Direction,50);	
			d=1;	
			continue;
		}
		else{d=0;}
		cannon(i,Range);
		drive(Direction,100);
		br = Range;
		break;
	}
	i+=30;

	}
  }
 }
}

/*     CCCC   SSSS   PPPP   OOOO   TTTT   RRRR   U  U   N  N
       C       S     PP P   O  O    TT    R  R   U  U   NN N
       C        S    P P    O  O    TT    R R    U  U   N NN 
       CCCC   SSSS   P      OOOO    TT    R  R   UUUU   N  N

                                             BY ANDRES NELSON */