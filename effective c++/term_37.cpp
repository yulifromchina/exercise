//term 37:�������¶���̳ж�����ȱʡ����ֵ


//ȱʡ����ֵ�Ǿ�̬�󶨵ģ�virtual�����Ƕ�̬�󶨵�


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
pc->draw();//ȱʡֵcolor��Red������Green!!


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
	virtual void draw(ShapeColor color = Red) const;//��base class����һ�£���ά������
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