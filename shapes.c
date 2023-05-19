#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"

int next_id= 1; // initialize the id counter to 1

const char *shape_type_str[] = {
        "POINT",
        "LINE",
        "SQUARE",
        "RECTANGLE",
        "CIRCLE",
        "POLYGON"
};

// Function to create a new Point object
Point *create_point(int px, int py) {
    Point *new_point = (Point *)malloc(sizeof(Point)); // Allocate memory for a new Point object
    if (new_point != NULL) {
        new_point->pos_x = px; // Set x coordinate
        new_point->pos_y = py; // Set y coordinate
    }
    return new_point;
}

// Function to free the memory of a Point object
void delete_point(Point *point) {
    free(point); // Free the memory allocated to the Point object
}


void print_point(Point *p) {
    printf("POINT [p(%d, %d)]\n", p->pos_x, p->pos_y); // Print formatted string with x and y coordinates
}

Line *create_line(Point *p1, Point *p2) {
    Line *new_line = (Line *)malloc(sizeof(Line)); // Allocate memory for a new Line object
    if (new_line != NULL) {
        new_line->p1 = p1; // Set first point
        new_line->p2 = p2; // Set second point
    }
    return new_line;
}

void delete_line(Line *line) {
    free(line); // Free the memory allocated to the Line object
}

void print_line(Line *line) {
    printf("LINE [%d, %d, %d, %d]\n", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y); // Print formatted string with coordinates of the two points
}


Square *create_square(Point *point, int length) {
    Square *new_square = (Square *)malloc(sizeof(Square)); // Allocate memory for a new Square object
    if (new_square != NULL) {
        new_square->upper_left = point; // Set the upper left corner of the square
        new_square->length = length; // Set the length of the square
    }
    return new_square;
}


void delete_square(Square *square) {
    free(square->upper_left); // Free the memory allocated to the Point object
    free(square); // Free the memory allocated to the Square object
}


void print_square(Square *square) {
    int x1 = square->upper_left->pos_x;
    int y1 = square->upper_left->pos_y;
    int x2 = x1 + square->length;
    int y2 = y1 + square->length;
    printf("SQUARE [(%d, %d), %d, (%d, %d), (%d, %d), (%d, %d)]\n",
           x1, y1, square->length, x1, y2, x2, y2, x2, y1);
}

Rectangle *create_rectangle(Point * point, int width, int height) {
    Rectangle *new_rectangle = (Rectangle *)malloc(sizeof(Rectangle));
    if (new_rectangle != NULL) {
        new_rectangle->upper_left = point;
        new_rectangle->width = width;
        new_rectangle->height = height;

    }
    return new_rectangle;
}

Circle *create_circle(Point * center, int radius) {
    Circle *new_circle = (Circle *)malloc(sizeof(Circle));
    if (new_circle != NULL) {
        new_circle->center = center;
        new_circle->radius = radius;
    }
    return new_circle;
}

void delete_circle(Circle *circle) {
    free(circle->center);
    free(circle);
}

void print_circle(Circle *circle) {
    int x1 = circle->center->pos_x;
    int y1 = circle->center->pos_y;

    printf("CIRCLE [center : (%d, %d), radius : %d]\n",x1, y1, circle->radius);
}

void delete_rectangle(Rectangle * rectangle) {
    free(rectangle->upper_left);
    free(rectangle);
}

void print_rectangle(Rectangle *rectangle) {
    int x1 = rectangle->upper_left->pos_x;
    int y1 = rectangle->upper_left->pos_y;
    int x2 = x1 + rectangle->height;
    int y2 = y1 + rectangle->height;
    int x3 = x1 + rectangle->width;
    int y3 = y1 + rectangle->width;
    int x4 = x3 + rectangle->height;
    int y4 = y3 + rectangle->height;
    printf("RECTANGLE [ Left_corner : (%d, %d), Height : %d, (%d, %d), Width : %d, Down-Right Corner : (%d, %d), (%d, %d), ]\n",x1, y1, rectangle->height, x2, y2, rectangle->width, x3, x4, y4);
}

Polygon *create_polygon( int **tab, int n) {
    Polygon *polygon = malloc(sizeof(Polygon));
    polygon->n = n;
    polygon->points = malloc(sizeof(Point*) * n);
    for (int i = 0; i < n; i++) {
        polygon->points[i] = malloc(sizeof(Point));
        polygon->points[i]->pos_x = tab[i][0];
        polygon->points[i]->pos_y = tab[i][1];
    }
    return polygon;
}

void delete_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->n; i++) {
        free(polygon->points[i]);
    }
    free(polygon->points);
    free(polygon);
}

void print_polygon(Polygon *polygon) {
    printf("Polygon with %d vertices:\n", polygon->n);
    for (int i = 0; i < polygon->n; i++) {
        printf("(%d, %d)\n", polygon->points[i]->pos_x, polygon->points[i]->pos_y);
    }
}









Shape *create_empty_shape(SHAPE_TYPE type)
{
    Shape *shp = (Shape *)malloc(sizeof(Shape));
    shp->id = ++next_id;
    shp->shape_type = type;
    shp->ptrShape = NULL;
    global_id2 +=1;
    return shp;
}

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    global_id2+=1;
    return shp;
}


Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *l = create_line(p1, p2);
    shp->ptrShape = l;
    global_id2+=1;
    return shp;
}


Shape *create_square_shape(int px, int py, int length)
{
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square *s = create_square(p, length);
    shp->ptrShape = s;
    global_id2+=1;
    return shp;
}


Shape *create_rectangle_shape(int px, int py, int width, int height)
{
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point(px, py);
    Rectangle *r = create_rectangle(p, width, height);
    shp->ptrShape = r;
    global_id2+=1;
    return shp;
}


Shape *create_circle_shape(int px, int py, int radius)
{
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point(px, py);
    Circle *c = create_circle(p, radius);
    shp->ptrShape = c;
    global_id2+=1;
    return shp;
}


Shape *create_polygon_shape(int lst[], int n)
{
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *p = create_polygon( lst, 4);
    shp->ptrShape = p;
    global_id2+=1;
    return shp;
}

void delete_specific_shape(void *ptrShape) {
    switch (((Shape *)ptrShape)->shape_type) {
        case POINT:
            delete_point((Point *)ptrShape);
            break;
        case LINE:
            delete_line((Line *)ptrShape);
            break;
        case SQUARE:
            delete_square((Square *)ptrShape);
            break;
            // add cases for other shape types here
        default:
            printf("Error: Unknown shape type.\n");
            break;
    }
}




// Delete the given shape object and free its memory
void delete_shape(Shape *shape)
{
    if (shape->ptrShape != NULL) {
        // Delete the specific shape object
        delete_specific_shape(shape->ptrShape);
    }
    // Free the memory of the Shape object
    free(shape);
}


// Print the details of the given shape object
void print_shape(Shape *shape)
{
    const char *shape_names[] = {"POINT", "LINE", "SQUARE", "RECTANGLE", "CIRCLE", "POLYGON"};
    printf("ID: %d\n", shape->id);
    printf("Shape Type: %s\n", shape_names[shape->shape_type]);

    switch (shape->shape_type) {
        case POINT:
            printf("Point: (%d, %d)\n", ((Point *) shape->ptrShape)->pos_x, ((Point *) shape->ptrShape)->pos_y);
            break;
        case LINE:
            printf("Line: (%d, %d) to (%d, %d)\n", ((Line *) shape->ptrShape)->p1->pos_x, ((Line *) shape->ptrShape)->p1->pos_y, ((Line *) shape->ptrShape)->p2->pos_x, ((Line *) shape->ptrShape)->p2->pos_y);
            break;
        case SQUARE:
            printf("Square: (%d, %d) with length %d\n", ((Square *) shape->ptrShape)->upper_left->pos_x, ((Square *) shape->ptrShape)->upper_left->pos_y, ((Square *) shape->ptrShape)->length);
            break;
        case POLYGON :
            printf("Polygon with %d vertices:\n", ((Polygon *)shape->ptrShape)->n);
            for (int b = 0; b < ((Polygon *)shape->ptrShape)->n; b++) {
                printf("(%d, %d)\n", ((Polygon *)shape->ptrShape)->points[b]->pos_x, ((Polygon *)shape->ptrShape)->points[b]->pos_y);
            }
            break;
        default:
            printf("Unknown Shape Type\n");
            break;
    }
    printf("\n");
}
unsigned int get_next_id()
{
return next_id++;
}
