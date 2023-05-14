#include "ugly.h"
#include "bad.h"

struct SplineImpl {
    double Interpolate(double e) {
        double y_answer = 0;
        std::vector<double> answer(x.size());
        mySplineSnd(&x[0], &y[0], x.size(), a, b, &answer[0]);
        mySplintCube(&x[0], &y[0], &answer[0], x.size(), e, &y_answer);
        return y_answer;
    }
    double a, b;
    std::vector<double> x, y;
};
Spline::Spline(const std::vector<double>& x, const std::vector<double>& y, double a, double b)
    : impl_(new SplineImpl{a, b, x, y}) {
}
double Spline::Interpolate(double x) {
    return impl_->Interpolate(x);
}