#undef NDEBUG
#include <assert.h>
#include "libimagequant.h"
#include <stdio.h>
#include <string.h>

static void test_histogram() {
    liq_attr *attr = liq_attr_create();
    liq_histogram *hist = liq_histogram_create(attr);
    assert(hist);

    const unsigned char dummy1[4] = {255,0,255,255};
    liq_image *const img1 = liq_image_create_rgba(attr, dummy1, 1, 1, 0);
    assert(img1);

    const liq_error err1 = liq_histogram_add_image(hist, attr, img1);
    assert(LIQ_OK == err1);

    liq_result *res;
    liq_error err = liq_histogram_quantize(hist, attr, &res);
    assert(LIQ_OK == err);
}

void run_liq_tests() {
    test_histogram();
}