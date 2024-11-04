#include <iostream>
using namespace std;

// runtime polymorphism -> achivied by using virtual keyword -> Late Binding

// Final keyword: 
// - with classes(prevent inheritance)
// - with virtual keyword: prevent overriding in derived classes

class Shape{
  public:
    // virtual void draw() final{
    virtual void draw(){
        cout << "Generic drawing..." << endl;
    }
};

class Circle : public Shape{
  public:
    void draw() override{ // override is not necessary to write
        cout << "Circle drawing..." << endl;
    }
};

class Rectangle : public Shape{
  public:
    void draw(){
        cout << "Rectangle drawing..." << endl;
    }
};

class Triangle : public Shape{
  public:
    void draw() override{
        cout << "Triangle drawing..." << endl;
    }
};

void ShapeDrawing(Shape *s){
    s->draw(); // draw is polymorphic -> calls relevant draw function
}

int main(){
    Circle c1;
    // c.draw();
    Rectangle r;

    ShapeDrawing(&c1);
    ShapeDrawing(&r);

    Triangle *t = new Triangle();
    ShapeDrawing(t);

    Circle *c = new Circle();
    c->draw();


    // virtual keyword
    Shape *s = new Shape();
    s->draw();

    // UPCASTING: object of child class but holding it in parent
    Shape *s1 = new Circle();
    s1->draw();

    // DOWNCASTING: object of parent but holding it in child
    Shape *s2 = new Shape();
    Circle *c2 = (Circle *)s2;
    c2->draw();
    return 0;
}