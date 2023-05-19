#ifndef UNTITLED_SHAPES_H
#define UNTITLED_SHAPES_H

unsigned int global_id2 = 0;
unsigned int get_next_id();

typedef struct {
    int pos_x;
    int pos_y;
}Point;

typedef struct line {
    Point *p1;
    Point *p2;
}Line;

typedef struct {
    Point *upper_left;
    int length;
}Square;

typedef struct {
    Point *upper_left;
    int height;
    int width;
}Rectangle;

typedef struct {
    Point *center;
    int radius;
}Circle;

typedef struct polygon {
    int n;
    Point **points;
} Polygon;



typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;

typedef struct shape {
    int id; // unique identifier of the shape
    SHAPE_TYPE shape_type; // type of the shape pointed
    void *ptrShape; // pointer to any shape
}Shape;



Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

Polygon *create_polygon(int **tab, int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(int lst[], int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);

void print_specific_shape(void *ptrShape);
void delete_specific_shape(void *ptrShape);



#endif //UNTITLED_SHAPES_H