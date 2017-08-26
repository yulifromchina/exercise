//term 37:绝不重新定义继承而来的缺省参数值


//缺省参数值是静态绑定的，virtual函数是动态绑定的


//bad:
class Shape
{
public:
	enum ShapeColor {Red, Green, Blue};
	virtual void draw(ShapeColor color = Red) const = 0;
};
class Rectangle :public Shape
{
public:
	virtual void draw(ShapeColor color = Green) const ;
};
Shape * pc = new Rectangle;
pc->draw();//缺省值color是Red而不是Green!!


 //bad, too
class Shape
{
public:
	enum ShapeColor { Red, Green, Blue };
	virtual void draw(ShapeColor color = Red) const = 0;
};
class Rectangle :public Shape
{
public:
	virtual void draw(ShapeColor color = Red) const;//与base class保持一致，但维护量大
};


//better
class Shape
{
public:
	enum ShapeColor { Red, Green, Blue };
	void draw(ShapeColor color = Red) const
	{
		doDraw(color);
	}
private:
	virtual void doDraw(ShapeColor color) const = 0;
};
class Rectangle :public Shape
{
public:
	virtual void  doDraw(ShapeColor color) const;
};