#include<stdio.h>
#include<math.h>

//Given 8 verticies, find the volume and surface area of a rectangular prism
//Mario d'Andrea, 2016

double get_dist(double firstPoint[3], double secondPoint[3]) {
    //find the distance between two points
    double distance = 0;
    double xDist = 0;
    double yDist = 0;
    double zDist = 0;

    //First, find the component differences
    xDist = firstPoint[0] - secondPoint[0];
    yDist = firstPoint[1] - secondPoint[1];
    zDist = firstPoint[2] - secondPoint[2];

    //Pythagorean thm for distance
    distance = sqrt((xDist * xDist) + (yDist * yDist) + (zDist * zDist));

    return distance;
}

double get_rect_area(double length, double width) {
    //Find the area of a rectangle
    double area = 0;
    area = length * width;

    return area;
}

double get_surface_area(double length, double width, double height) {
    //Find the surface area of a rectangular prism given length width and height
    double surfaceArea = 0;

    surfaceArea = 2*(get_rect_area(length, width) + get_rect_area(width, height) + get_rect_area(height, length));

    return surfaceArea;

}

double get_volume(double length, double width, double height) {
    //Find the volume of a rectangular prism
    double volume = 0;
    volume = length * width * height;

    return volume;
}


int main(void) {
    //store the 8 verticies
    double point1[3];
    double point2[3];
    double point3[3];
    double point4[3];
    double point5[3];
    double point6[3];
    double point7[3];
    double point8[3];
    double surfaceArea = 0;
    double volume = 0;

    //get user input
    printf("Enter the first coordinate in the form x y z: "); //first
    scanf("%lf %lf %lf", &point1[0], &point1[1], &point1[2]);
    printf("Enter the second coordinate in the form x y z: "); //second
    scanf("%lf %lf %lf", &point2[0], &point2[1], &point2[2]);
    printf("Enter the third coordinate in the form x y z: "); //third
    scanf("%lf %lf %lf", &point3[0], &point3[1], &point3[2]);
    printf("Enter the fourth coordinate in the form x y z: "); //fourth
    scanf("%lf %lf %lf", &point4[0], &point4[1], &point4[2]);
    printf("Enter the fifth coordinate in the form x y z: "); //fifth
    scanf("%lf %lf %lf", &point5[0], &point5[1], &point5[2]);
    printf("Enter the sixth coordinate in the form x y z: "); //sixth
    scanf("%lf %lf %lf", &point6[0], &point6[1], &point6[2]);
    printf("Enter the seventh coordinate in the form x y z: "); //seventh
    scanf("%lf %lf %lf", &point7[0], &point7[1], &point7[2]);
    printf("Enter the eighth coordinate in the form x y z: "); //eighth
    scanf("%lf %lf %lf", &point8[0], &point8[1], &point8[2]);

    //We need only 3 edges to find the volume. We'll use <0,1>, <1,2> <3,4>
    surfaceArea = get_surface_area(get_dist(point1, point2), get_dist(point2, point3), get_dist(point4, point5));
    printf("The surface area of the prism is %.2f", surfaceArea);

    volume = get_volume(get_dist(point1, point2), get_dist(point2, point3), get_dist(point4, point5));
    printf("The volume of the prism is %.2f", volume);

    return 0;
}