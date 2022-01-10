#include "Shapes.h"

using namespace std;

int 
main()
{
	Screen s(20, 22);
	cout << s << endl;
	s.fill('o');
	cout << s <<endl;
	s.clear();
	cout << s <<endl;
	
	Point p = Point(5,8);
  if (p.draw(s, 'o'))
	{
		cout << "point at (5, 8)\n" << s <<endl;
	}

  double y = 1.4;
	cout << (size_t)y << endl;
	y = 1.99;
	cout << (size_t)y << endl;
	y = 2.0;
	cout << (size_t)y << endl;

	s.clear();

	//Line l = Line(20, 10, 2, 5);
	Line l = Line(2, 5, 20, 10);
  l.draw(s, '#');
	cout << "line (2, 5) (20, 10)) by x\n" << s <<endl;


	s.clear();
	//Line l2 = Line(3, 10, 0, 1);
	Line l2 = Line(0, 1, 3, 10);
  l2.draw(s, '+');
	cout << "line (0, 1) (3, 10)) by y\n" << s <<endl;

	s.clear();
	Quadrilateral q = Quadrilateral(2,3, 4, 8, 15, 7, 13, 4);
	q.draw(s, '#');
	cout << "Quadrilateral (2,3) (4,8) (15,7) (13, 4) \n" << s << endl;

	s.clear();
	Upright_Rectangle uq = Upright_Rectangle(4, 2, 8, 7);
	uq.draw(s, '#');
	cout << "Upright_Rectangle(4, 2, 8, 7) \n" << s << endl;
	s.clear();

  Stick_Man sm = Stick_Man (5, 1, 9, 20);
//  Stick_Man sm = Stick_Man (0, 0, 5, 10);
	sm.draw(s, '#');
	cout << "stick man (5, 1, 9, 20) \n" << s << endl;

	return 0; 
}
