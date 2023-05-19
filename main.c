#include <stdlib.h>
#include "shapes.h"



int main() {
    int n = 4;
    int tab[4][2] = {{0, 0}, {0, 1}, {1, 1}, {1, 0}};
    int **tab_ptr = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        tab_ptr[i] = tab[i];
    }
    int m = 4;
    Polygon * p = create_polygon_shape(tab_ptr, m );
    print_shape(p);
    //Polygon *polygon = create_polygon(n, tab_ptr);
    //print_polygon(polygon);
    //delete_polygon(polygon);
    //free(tab_ptr);
    return 0;}