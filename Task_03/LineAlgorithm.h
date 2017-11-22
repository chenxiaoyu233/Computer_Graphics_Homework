#ifndef LINE_ALGORITHM_H_
#define LINE_ALGORITHM_H_

template <class Pen>
class LineAlgorithm{
	private:
		int flag;
		Pen pen;
		Point c;
		void BresenhamSetPixel(Point p);

	public:
		LineAlgorithm(Pen pen):pen(pen){ }
		void LineBresenhamAlgorithm(int x1, int y1, int x2, int y2);
};

template <class Pen>
void LineAlgorithm <Pen> :: BresenhamSetPixel(Point p){
	switch(flag){
		case 0: pen.drawPoint(c.x + p.x, c.y + p.y); break;
		case 1: pen.drawPoint(c.x + p.y, c.y + p.x); break;
		case 2: pen.drawPoint(c.x + p.x, c.y + -p.y); break;
		case 3: pen.drawPoint(c.x + p.y, c.y + -p.x); break;
	}
}

template <class Pen>
void  LineAlgorithm <Pen> :: LineBresenhamAlgorithm(int x1, int y1, int x2, int y2){
	Point p1(x1, y1), p2(x2, y2);
	int dx = x1 - x2 > 0 ? x1 - x2 : x2 - x1;
	int dy = y1 - y2 > 0 ? y1 - y2 : y2 - y1;
	if(p1.x > p2.x) swap(p1, p2);
	p2 = p2 - p1; c = p1, p1 = Point(0, 0);
	if(0 <= p2.y) {
		if(dy <= dx) flag = 0;
		else {
			swap(p2.x, p2.y), swap(dy, dx);
			flag = 1;
		}
	} else{
		p2.y *= -1;
		if(dy <= dx) flag = 2;
		else {
			swap(p2.x, p2.y), swap(dy, dx);
			flag = 3;
		}
	}
	int p = 2*dy - dx, dy2 = dy * 2, dy2mdx2 = dy2 - 2*dx;
	for(;p1.x <= p2.x; ++p1.x){
		BresenhamSetPixel(p1);
		if(p < 0) p += dy2;
		else  p += dy2mdx2, ++p1.y; 
	}
}

#endif
