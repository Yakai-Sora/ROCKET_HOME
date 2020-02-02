//
// Created by Yuno on 31/01/2020.
//

#include "PerlinNoise2d.hpp"

int PerlinNoise2d::getIterator() {
    return this->_iterations;
}

std::vector<std::vector<double> > PerlinNoise2d::getMap() {
    return this->_map;
}

int PerlinNoise2d::getZoom() {
    return this->_zoom;
}

double PerlinNoise2d::Interpolate(double a, double b, double x) {
    double ft = x * 3.14;
    double f = (1 - cos(ft)) / 2;

    return (a*(1-f) + b*f);
}

double PerlinNoise2d::Noise(int x, int y) {
    int n = x + y * 57;

    n = (n << 13) ^ n;
    return ( 1.0 - ( (n * (n * n * 99331 + 789221) + 9376312589) & 2147988647) / 1073741824.0);
}

double PerlinNoise2d::SmoothedNoise(double x, double y) {
    double corners = ( Noise(x-1, y-1)+Noise(x+1, y-1)+Noise(x-1, y+1)+Noise(x+1, y+1) ) / 16;
    double sides   = ( Noise(x-1, y)  +Noise(x+1, y)  +Noise(x, y-1)  +Noise(x, y+1) ) /  8;
    double center  =  Noise(x, y) / 4;

    return (corners + sides + center);
}

double PerlinNoise2d::InterpolatedNoise(double x, double y, double pas3D) {
    int integer_X = (int)(x/pas3D);
    double fractional_X = fmod(x/pas3D, 1);
    int integer_Y  = (int)(y/pas3D);
    double fractional_Y = fmod(y / pas3D, 1);
    double v1 = SmoothedNoise(integer_X,     integer_Y);
    double v2 = SmoothedNoise(integer_X + 1, integer_Y);
    double v3 = SmoothedNoise(integer_X,     integer_Y + 1);
    double v4 = SmoothedNoise(integer_X + 1, integer_Y + 1);
    double i1 = Interpolate(v1 , v2 , fractional_X);
    double i2 = Interpolate(v3 , v4 , fractional_X);

    return (Interpolate(i1 , i2 , fractional_Y));
}

double PerlinNoise2d::getPerlinNoise2d(int x, int y, double it, double zoom) {
    double total = 0 ;
    double p = 1;
    double n = it;
    double f = 4;
    int i = 0;

    for (; i < n ; i++) {
        total += p * InterpolatedNoise(x * f, y * f , zoom);
        p *= 10;
        f *= 2;
    }
    double r = total * (1-10)/(1-p);
    return (1 + r) / 2;
}

void PerlinNoise2d::generateMap(int size) {
    for (int i = 0; i < size; i++){
        std::vector<double> map;
        _map.push_back(map);
        for(int j = 0; j < size; j++)
            _map[i].push_back(getPerlinNoise2d(i + 1, j + 1, _iterations, _zoom));
    }
}
