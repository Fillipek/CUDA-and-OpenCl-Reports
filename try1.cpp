#include <iostream>
#include <math.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int count = 10;           //number of samples
    int size = 500;            //number of x points
    double resolution = 0.1;    //distance between x points
    double result = 0;          //helper value temporarily holds result
    double samples[count];      //random points
    double x[size];             //result array

    // pick random samples
    for (int i=0; i<count; i++) {
        samples[i] = (double)rand()/RAND_MAX*size*resolution;
        //std::cout << samples[i] << "s ";
    }

    //fill results with 0s
    for (int i=0; i<size; i++) {
        x[i] = 0;
    }

    //calculate partial sum for every sample
    for (int i = 0; i<count; i++) { //for every sample
        
        for(int j=0; j<size; j++) { // for every x point
            if(abs(samples[i] - j*resolution) < 1) {
                x[j] += 0.75*(1-pow(samples[i] - j*resolution,2));
            }     
        }
    }

    for (int i=0; i<size; i++) {
        x[i] /= count;
        std::cout << x[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}