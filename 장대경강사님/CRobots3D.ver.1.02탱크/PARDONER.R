main ()
  {
    int dam, dis, dir, res, num;

    dam = damage ();
    dir = closest ();
    dis = scan (dir, 2);

    while (1)
      {
        if ((dam + 10 < damage ()) ||  (dis == 0))
          {
            dam = damage ();
            move_rand ();
            dir = closest ();
            dis = scan (dir, 2);
          }
        else
          {
            if (dis < 700)
              {
                cannon (dir, dis);
              }
            if (dis > 100)
              {
                drive (dir, 40);
              }
            else if (dis > 20)
              {
                drive (dir, 20);
              }
            else
              {
                drive (dir, 0);
              }

            res = 5;

            while (res > 1)
              {

                res /= 2;
                dir -= res;
                num = scan (dir, res);
                if (num == 0)
                  {
                    dir += res * 2;
                  }
              }

            dis = scan (dir, 2);

            if (dis == 0)
              {
                dir = closest;
                dis = scan (dir, 2);
              }
          }
      }
  }

int
closest () /*return the angle to the 'closest' robot*/
  {
    int temp, search, angle, resolution, number, shortest;

    search     = 0;
    resolution = 10;
    number   = 0;
    shortest = 10000;
    angle    = 0;

    while (search < 360)
      {
        temp = scan (search, resolution);
        if (temp > 0 && temp < shortest)
          {
            shortest = temp;
            angle = search;
          }
        search += resolution * 2;
      }

    while (resolution > 1)
      {

        resolution /= 2;
        angle -= resolution;
        number = scan (angle, resolution);
        if (number == 0)
          {
            angle += resolution * 2;
          }
      }

    return (angle);
  }

move_rand () /*move to a random location on the screen*/
  {
    int dir,x,y;

    x = rand (970) + 15;
    y = rand (970) + 15;

    dir = plot_course (x,y);
    drive (dir, 100);

    while (distance (loc_x(), loc_y(), x, y) > 200 && speed () > 0)
      ;
    drive (dir, 50);
    while (distance (loc_x(), loc_y(), x, y) > 100 && speed () > 0)
      ;
    drive (dir, 0);
  }

int
distance (x1, y1, x2, y2) /*the distance between the two points*/
  int x1,y1, x2, y2;
  {
    int x,y;

    x = x1-x2;
    y = y1-y2;
    return (sqrt ((x*x) + (y*y)));
  }

int
plot_course (xx,yy) /*the angle to get to the new point*/
  int xx,yy;
  {
    int d;
    int x,y;
    int scale;
    int curx,cury;

    scale = 100000;
    curx = loc_x ();
    cury = loc_y ();
    x = curx - xx;
    y = cury - yy;

    if (x==0)
      {
        if (yy > cury)
          {
            d = 90;
          }
        else
          {
            d = 270;
          }
      }
    else
      {
        if (yy < cury)
          {
            if (xx > curx)
              {
                d = 360 - atan ((scale * y) / x);
              }
            else
              {
                d = 180 + atan ((scale * y) / x);
              }
          }
        else
          {
            if (xx > curx)
              {
                d = atan ((scale * y) / x);
              }
            else
              {
                d = 180 + atan ((scale * y) / x);
              }
          }
      }
    return (d);
  }