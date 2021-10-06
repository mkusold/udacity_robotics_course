#include <iostream>
#include <math.h>
#include <tuple>
#include "Core" // Eigen Library
#include "LU"   // Eigen Library

using namespace std;
using namespace Eigen;

float measurements[3] = {1, 2, 3};

tuple<MatrixXf, MatrixXf> kalman_filter(MatrixXf x, MatrixXf P, MatrixXf u, MatrixXf F, MatrixXf H, MatrixXf R, MatrixXf I)
{
    for (int n = 0; n < sizeof(measurements) / sizeof(measurements[0]); n++)
    {
        // get the current measurement
        MatrixXf z(1, 1);
        z << measurements[n];

        // y is the difference between measurement and the expected measurement
        // based on the prediction.
        // (where we are and where the prediction says we should be)
        // Where z is a new measurement, H is the previous predicted measurement change
        // and x was the previous measurement itself
        // y = z - Hx'
        MatrixXf y(1, 1);
        y << z - (H * x);

        // Measurement Update (what the new measurement will be)
        // where H is the previous predicted measurement change,
        // P is state covariance (spread), and R is the measurement noise
        // S = HP'H^T + R
        MatrixXf S(1, 1);
        S << H * P * H.transpose() + R;

        // Kalman Gain
        // how much weight should be placed on the state prediction,
        // and how much on the measurement update.
        // where P is the state covariance, H is the previous predicted
        // measurement change, and S is the measurement update
        // K = P'*(H^T)*(S^-1)
        MatrixXf K(2, 1);
        K << P * H.transpose() * S.inverse();

        // Prediction
        // posterior state prediction.
        // where x' is the previous value, K is how much weight to
        // be put on the state prediction & measurement update,
        // and y is the difference between the actual measurement and the previous prediction
        // x = x' + Ky
        x << x + (K * y);
        // posterior covariance prediction
        // where I is the identity matrix, K is how much weight to
        // put on the state prediction & measurement update,
        // H is the previous predicted measurement change and P is the previous covariance
        // P = (I-K*H)*P'
        P << (I - (K * H)) * P;

        // F is the state update function, x is the previous position, u is the previous covariance
        x << (F * x) + u;
        // F is the state update function, P is the previous covariance, F is the state update function
        P << F * P * F.transpose();
    }

    return make_tuple(x, P);
}

int main()
{

    MatrixXf x(2, 1); // Initial state (location and velocity)
    x << 0,
        0;
    MatrixXf P(2, 2); //Initial Uncertainty
    P << 100, 0,
        0, 100;
    MatrixXf u(2, 1); // External Motion
    u << 0,
        0;
    MatrixXf F(2, 2); //Next State Function
    F << 1, 1,
        0, 1;
    MatrixXf H(1, 2); //Measurement Function
    H << 1,
        0;
    MatrixXf R(1, 1); //Measurement Uncertainty
    R << 1;
    MatrixXf I(2, 2); // Identity Matrix
    I << 1, 0,
        0, 1;

    tie(x, P) = kalman_filter(x, P, u, F, H, R, I);
    cout << "x= " << x << endl;
    cout << "P= " << P << endl;

    return 0;
}