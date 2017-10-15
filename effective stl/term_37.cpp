#include <iostream>
#include <string>
#include <numeric>
#include <set>
#include <vector>
#include <list>

using namespace std;
string::size_type stringLengthSum(string::size_type sumSoFar, const string &s)
{
	return sumSoFar + s.size();
}

struct Point
{
	Point(double initX, double initY) :x(initX), y(initY) {}
	double x, y;
};

class PointAverage :public binary_function<Point, Point, Point>
{
public:
	PointAverage() :numPoints(0), xSum(0), ySum(0) {}
	const Point operator()(const Point & avgSoFar, const Point & p)
	{
		++numPoints;
		xSum += p.x;
		ySum += p.y;
		return  Point(xSum / numPoints, ySum / numPoints);
	}
private:
	size_t numPoints;
	double xSum;
	double ySum;
};


int main()
{
	set<string> ss;
	ss.insert("hello");
	ss.insert("world");
	ss.insert("hi");
	string::size_type lengthSum = accumulate(ss.begin(), ss.end(), 0, stringLengthSum);
	cout << lengthSum << endl;

	vector<float> vf{1.0f, 2.0f, 3.0f};
	float product = accumulate(vf.begin(), vf.end(), 1.0f, multiplies<float>());
	cout << product << endl;

	list<Point> lp;
	lp.push_back(Point(1,2));
	lp.push_back(Point(2,3));
	lp.push_back(Point(3,4));
	Point avg = accumulate(lp.begin(), lp.end(), Point(0,0),PointAverage());
	cout << avg.x <<" "<<avg.y << endl;

	return 0;
}

