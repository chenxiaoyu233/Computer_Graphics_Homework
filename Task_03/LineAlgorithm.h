#ifndef LINE_ALGORITHM_H_
#define LINE_ALGORITHM_H_

template <class Pen>
class LineAlgorithm{
	private:
		int flag;
		Pen pen;
		Point <int> c;
		void BresenhamSetPixel(Point <int> p);
		void WuXiaoLinSetPixel(int x, int y, int grayScale);

	public:
		LineAlgorithm(Pen pen):pen(pen){ }
		void LineBresenhamAlgorithm(int x1, int y1, int x2, int y2);
		void LineWuXiaoLinAlgorithm(int x1, int y1, int x2, int y2);
};

template <class Pen>
void LineAlgorithm <Pen> :: BresenhamSetPixel(Point <int> p){
	switch(flag){
		case 0: pen.drawPoint(c.x + p.x, c.y + p.y); break;
		case 1: pen.drawPoint(c.x + p.y, c.y + p.x); break;
		case 2: pen.drawPoint(c.x + p.x, c.y + -p.y); break;
		case 3: pen.drawPoint(c.x + p.y, c.y + -p.x); break;
	}
}

template <class Pen>
void  LineAlgorithm <Pen> :: LineBresenhamAlgorithm(int x1, int y1, int x2, int y2){
	Point<int> p1(x1, y1), p2(x2, y2);
	int dx = x1 - x2 > 0 ? x1 - x2 : x2 - x1;
	int dy = y1 - y2 > 0 ? y1 - y2 : y2 - y1;
	if(p1.x > p2.x) swap(p1, p2);
	p2 = p2 - p1; c = p1, p1 = Point <int> (0, 0);
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

template <class Pen>
void LineAlgorithm <Pen> :: WuXiaoLinSetPixel(int x, int y, int grayScale){
	/*switch(flag){
		case 0: pen.drawPoint(c.x + x, c.y + y, grayScale); break;
		case 1: pen.drawPoint(c.x + y, c.y + x, grayScale); break;
		case 2: pen.drawPoint(c.x + x, c.y - y, grayScale); break;
		case 3: pen.drawPoint(c.x + y, c.y - x, grayScale); break;
	}*/
	//加入了混色，但是测试出来的效果并不太好
	switch(flag){
		case 0: pen.mixPoint(c.x + x, c.y + y, grayScale); break;
		case 1: pen.mixPoint(c.x + y, c.y + x, grayScale); break;
		case 2: pen.mixPoint(c.x + x, c.y - y, grayScale); break;
		case 3: pen.mixPoint(c.x + y, c.y - x, grayScale); break;
	}
}

template <class Pen>
void LineAlgorithm <Pen> :: LineWuXiaoLinAlgorithm(int x1, int y1, int x2, int y2){
	Point <int> p1(x1, y1), p2(x2, y2);
	int dx = x1 - x2 > 0 ? x1 - x2 : x2 - x1;
	int dy = y1 - y2 > 0 ? y1 - y2 : y2 - y1;
	if(p1.x > p2.x) swap(p1, p2);
	p2 = p2 - p1; c = p1; p1 = Point <int> (0, 0);
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
	typedef unsigned int ui;
	ui D = 0, d = double(dy)/double(dx) * (ui(1) << 31) + 0.5;
	WuXiaoLinSetPixel(p1.x, p1.y, 255), WuXiaoLinSetPixel(p2.x, p2.y, 255);
	int n = 31, m = 8, mask = 255;
	while(1){
		++p1.x, --p2.x;
		if(p1.x > p2.x) break;
		D += d;
		if((D >> 31) & 1){ // overflow
			D ^= (ui(1) << 31);
			++p1.y, --p2.y;
		}
		ui I = D >> (n-m);
		WuXiaoLinSetPixel(p1.x, p1.y, I^mask), WuXiaoLinSetPixel(p2.x, p2.y, I^mask);
		WuXiaoLinSetPixel(p1.x, p1.y+1, I), WuXiaoLinSetPixel(p2.x, p2.y-1, I);
	}
}

#endif
