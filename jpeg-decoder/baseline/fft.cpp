#include <fft.h>

#include <fftw3.h>
#include <valarray>

class DctCalculator::Impl {
public:
    size_t width_;
    std::vector<double> *input_;
    std::vector<double> *output_;
    fftw_plan plan_;
};

DctCalculator::DctCalculator(size_t width, std::vector<double> *input, std::vector<double> *output)
    : impl_(std::make_unique<Impl>()) {
    if (!input || !output) {
        throw std::invalid_argument("input/output ptr");
    }
    if (input->size() != width * width || output->size() != width * width) {
        throw std::invalid_argument("input/output size");
    }
    impl_->width_ = width;
    impl_->input_ = input;
    impl_->output_ = output;
    impl_->plan_ =
        fftw_plan_r2r_2d(impl_->width_, impl_->width_, impl_->input_->data(),
                         impl_->output_->data(), FFTW_REDFT01, FFTW_REDFT01, FFTW_MEASURE);
    if (!impl_->plan_) {
        throw std::invalid_argument("");
    }
}

void DctCalculator::Inverse() {
    for (size_t i = 0; i < impl_->width_ * impl_->width_; ++i) {
        impl_->input_->at(i) /= 8.0;
        impl_->input_->at(i) *= ((i % impl_->width_ != 0) ? sqrt(2) : 1) *
                                ((i >= impl_->width_) ? sqrt(2) : 1);
    }
    fftw_execute(impl_->plan_);
}

DctCalculator::~DctCalculator() {
    fftw_destroy_plan(impl_->plan_);
}
