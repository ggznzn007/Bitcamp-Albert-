int xflag, yflag;

main()
{
  int dir, x, y, range, dirFlag, lastx, lasty;
  dir=rand(360);

  calcDir(dir);

  dirFlag=1;
  
  x=loc_x();
  y=loc_y();
  
  while (1)
  {		
    x=loc_x();
    y=loc_y();
    if (lastx==x && lasty==y)
    {
      dir = dir+90;
      calcDir(dir);
      drive(dir, 100);
    }

    drive(dir, 100);
    if (dirFlag)
    {
      if (range=scan(5, 5)) cannon(7, range);
      else if (range=scan(15,5)) cannon(15, range);
      else if (range=scan(25,5)) cannon(25, range);
      else if (range=scan(35,5)) cannon(25, range);
      else if (range=scan(45,5)) cannon(45, range);
      else if (range=scan(55,5)) cannon(55, range);
      else if (range=scan(65,5)) cannon(65, range);
      else if (range=scan(75,5)) cannon(75, range);
      else if (range=scan(85,5)) cannon(85, range);
      else if (range=scan(95,5)) cannon(95, range);
      else if (range=scan(105,5)) cannon(105, range);
      else if (range=scan(115,5)) cannon(115, range);
      else if (range=scan(125,5)) cannon(125, range);
      else if (range=scan(135,5)) cannon(135, range);
      else if (range=scan(145,5)) cannon(145, range);
      else if (range=scan(155,5)) cannon(155, range);
      else if (range=scan(165,5)) cannon(165, range);
    }
    else
    {
      if (range=scan(355,5)) cannon(355, range);
      else if (range=scan(345,5)) cannon(345, range);
      else if (range=scan(335,5)) cannon(335, range);
      else if (range=scan(335,5)) cannon(335, range);
      else if (range=scan(325,5)) cannon(325, range);
      else if (range=scan(315,5)) cannon(315, range);
      else if (range=scan(305,5)) cannon(305, range);
      else if (range=scan(295,5)) cannon(295, range);
      else if (range=scan(285,5)) cannon(285, range);
      else if (range=scan(275,5)) cannon(275, range);
      else if (range=scan(265,5)) cannon(265, range);
      else if (range=scan(255,5)) cannon(255, range);
      else if (range=scan(245,5)) cannon(245, range);
      else if (range=scan(235,5)) cannon(235, range);
      else if (range=scan(225,5)) cannon(225, range);
      else if (range=scan(215,5)) cannon(215, range);
      else if (range=scan(205,5)) cannon(205, range);
      else if (range=scan(195,5)) cannon(195, range);
      else if (range=scan(185,5)) cannon(185, range);
      else if (range=scan(175,5)) cannon(175, range);
    }
    
    dirFlag = !dirFlag;

    x=loc_x();
    y=loc_y();
    lastx = x;
    lasty = y;
    if (!xflag && x<200 || xflag && x>800) 
    {
      drive(dir, 50);
      dir = clipDir(180-dir);
      xflag = !xflag;
    }
    if (!yflag && y<200 || yflag && y>800)
    {
      drive(dir, 50);
      dir = clipDir(-dir);
      yflag=!yflag;
    }
  }
}

calcDir(dir)
int dir;
{
  if (dir<90)
  {
    xflag=1;
    yflag=1;
  }
  else if (dir<180)
  {
    xflag=0;
    yflag=1;
  }
  else if (dir<270)
  {
    xflag=0;
    yflag=0;
  }
  else 
  {
    xflag=1;
    yflag=0;
  }
}

clipDir(dir)
int dir;
{
  while (dir<0) dir+=360;
  while (dir>360) dir-=360;

  return dir;
}
