#ifndef CIRCLE_ALGORITHM_H_
#define CIRCLE_ALGORITHM_H_

template <class Pen>
class CircleAlgorithm{
	private:
		Pen pen;
		void midPointSetPixel(Point c, Point pt);
	public:
		CircleAlgorithm(Pen pen):pen(pen){ }
		void CircleMidPoint(int cx, int cy, int R);
};

template <class Pen>
void CircleAlgorithm <Pen>::midPointSetPixel(Point c, Point pt){
	pen.drawPoint(c.x + pt.x, c.y + pt.y);
	pen.drawPoint(c.x - pt.x, c.y + pt.y);
	pen.drawPoint(c.x + pt.x, c.y - pt.y);
	pen.drawPoint(c.x - pt.x, c.y - pt.y);
	pen.drawPoint(c.x + pt.y, c.y + pt.x);
	pen.drawPoint(c.x - pt.y, c.y + pt.x);
	pen.drawPoint(c.x + pt.y, c.y - pt.x);
	pen.drawPoint(c.x - pt.y, c.y - pt.x);
}

template <class Pen>
void CircleAlgorithm <Pen>::CircleMidPoint(int cx, int cy, int R){
	Point c(cx, cy), pt(0, R);
	int p = 1 - R;
	while(pt.x <= pt.y){
		midPointSetPixel(c, pt);
		++ pt.x;
		if(p < 0) p = p + 2 * pt.x + 1;
		else -- pt.y, p = p + 2 * pt.x + 1 - 2 * pt.y;
	}
}

#endif
