//
// Created by Yuno on 31/01/2020.
//

#ifndef GAME_JAM_PERLINNOISE2D_HPP
#define GAME_JAM_PERLINNOISE2D_HPP

#include "math.h"
#include <vector>
#include <iostream>


class PerlinNoise2d {
public:
    PerlinNoise2d(int nb, int it): _zoom(nb), _iterations(it){};
    PerlinNoise2d(){};

    void setZoom(const int zoom);
    void setIterator(const int it);

    int getZoom();
    int getIterator();

    void generateMap(int size);
    std::vector<std::vector<double> > getMap();

    double getPerlinNoise2d(int x, int y, double it, double zoom);

    void reset();
private:

    double Interpolate(double a, double b, double x);
    double Noise(int x, int y);
    double SmoothedNoise(double x, double y);
    double InterpolatedNoise(double x, double y , double pas3D);
    std::vector<std::vector<double> > _map;
    int _zoom;
    int _iterations;
};


#endif //GAME_JAM_PERLINNOISE2D_HPP
