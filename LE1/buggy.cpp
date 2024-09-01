#include <iostream>
#include <vector>
#include <cstring>

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    private: 
        int vertices;
        Point* points;

    public: 
        Shape (int _vertices) {
            vertices = _vertices;
            points = new Point[vertices];
        }

        ~Shape () {
            delete[] points;
        }

        void addPoints (const std::vector<Point>& pts) {
            if (vertices != int(pts.size())) throw int(0);
            std::memcpy(&points[0], &pts[0], vertices * sizeof(Point)); 
            
        }

        double area () {
            int temp = 0;
            for (int i = 0; i < vertices; i++) {
                // FIXME: there are two methods to access members of pointers
                //        use one to fix lhs and the other to fix rhs
                int lhs = points[i].x * points[(i+1)%vertices].y;
                int rhs = points[(i+1)%vertices].x * points[i].y;
                temp += (lhs - rhs);
            }
            double area = double( abs(temp)/2.0);
            return area;
        }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)
    Point tri1; 
    tri1.x = 0;
    tri1.y = 0; 
    Point tri2{1, 2};
    Point tri3(2,0);

    // adding points to tri
    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    std::vector<Point> triPts_v(std::begin(triPts), std::end(triPts));
    tri->addPoints(triPts_v);

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)
    Point quad1(0,0);
    Point quad2(0,2);
    Point quad3(2,2);
    Point quad4(2,0);

    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    std::vector<Point> quadPts_v(std::begin(quadPts), std::end(quadPts));
    quad->addPoints(quadPts_v);

    // FIXME: print out area of tri and area of quad
    std::cout << tri->area() <<std::endl; 
    std::cout << quad->area() << std::endl;

    //tri and quad are allocated on heap, so we have to destroy them
    delete tri; 
    delete quad;

}