class Rectangle
{
private:
	int width;
	int length;
public:
	void setwidth(int w);
	void setlength(int l);
	int getwidth()const{return width;}
	int getlength()const{return length;}
	int getarea()const{return length*width;}
	void rotaterectangle();
	void draw();
};