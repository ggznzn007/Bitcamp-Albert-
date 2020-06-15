pinpoint(head)
{
if (range = scan(head+3,6))
   head += 3;
else if (range = scan(head-3,6))
   head -= 3;
else 
   return 0;
if (range = scan(head+2,4))
   head += 2;
else if (range = scan(head-2,4))
   return head -= 2;
else
   return 0;
if (range = scan(head+1,3))
   return head+1;
else if (range = scan(head-1,3))
   return head-1;
else 
   return 0;
 
}


main()
  {
  head = 0;
  pts = 0;
  miss=0;
  bear = 0;
  while (1)
     {
     if (pts && bear)
        drive(bear,50);
 
     if (range = scan(head,10))
        if (bear = pinpoint(head))
           {
           ++pts;
           miss=-1;
           if (pts < 2)
              cannon(bear,range);
           else
              {
              rdif = (range - pr) * range /300;
              tdif = (bear - pt) * range /425;
/*              if (pts > 2)
                 {
                 rdifdif = rdif - prdif;
                 tdifdif = tdif - ptdif;
                 while (! cannon(head+tdif+tdifdif,range+rdif+rdifdif))
                    ;
                 }
              else
 */          
              cannon(bear+tdif,range+rdif);
              }
           pr = range;
           pt = bear;
           if (bear)
              head = bear - 50;
           }
     head += 10;
     ++miss;
     if (miss > 4)
        pts = 0;
     }
     
  }

              

