//
// Created by kirill on 06.10.17.
//

#include "timers/CommonTimer.h"
#include "timers/ClockTimer.h"
#include "timers/ChronoTimer.h"
#include "timers/RdtscTimer.h"
#include "timers/OmpTimer.h"
#include "CustomArray.h"

#include <functional>
#include <gtest/gtest.h>

#include <timers/Timer.h>

template<typename T, typename A>
void CustomArrayTestF(size_t size){
    auto timer = std::make_shared<T>();
    CustomArray<A> a1(size);
    a1.randInit();
    CustomArray<A> a2(size);
    a2.randInit();
    timer->start();
    auto res = a1 + a2;
    timer->end();
    LOG(INFO) << timer->show();
}

TEST(Testa, OmpTimerSorta) {
    CustomArrayTestF<OmpTimer, int16_t >(4096*4096);
}

TEST(Testa, OmpTimerSorta2) {
    CustomArrayTestF<OmpTimer, int32_t>(4096*4096);
}

TEST(Testa, OmpTimerSorta23) {
    CustomArrayTestF<OmpTimer, uint64_t >(4096*4096);
}

TEST(Testa, OmpTimerSorta231) {
    CustomArrayTestF<OmpTimer, uint_least64_t >(4096*4096);
}

TEST(SSETest, DoubleAddition) {
    auto timer = std::make_shared<OmpTimer>();
    CustomArray<double> a1(4096);
    a1.randInit();
    CustomArray<double> a2(4096);
    a2.randInit();
    timer->start();
    auto res = a1.SIMDAddition<__m128d>(a2, [](__m128d a, __m128d b){
        return _mm_add_pd(a,b);
    });
    timer->end();
    LOG(INFO) << timer->show();
    auto expect = a1.getSum() + a2.getSum();
    auto actual = res->getSum();
    ASSERT_TRUE(expect == actual);
}

template<typename T>
T add(T a , T b){
    return _mm_add_epi64(a, b);
}


/*Note: It can be slowed if we use std::function instead of function pointer*/
TEST(SSETest, Uint64Addition) {
    auto timer = std::make_shared<OmpTimer>();
    CustomArray<uint64_t> a1(4096 * 4096);
    a1.randInit();
    CustomArray<uint64_t> a2(4096 * 4096);
    a2.randInit();
    timer->start();
    auto res = a1.SIMDAddition<__m128i>(a2, add<__m128i>);
    timer->end();
    LOG(INFO) << timer->show();
    auto expect = a1.getSum() + a2.getSum();
    auto actual = res->getSum();
    ASSERT_TRUE(expect == actual);
}

TEST(SSETest, Uint64Addition1) {
    auto timer = std::make_shared<OmpTimer>();
    CustomArray<uint64_t> a1(4096 * 4096);
    a1.randInit();
    CustomArray<uint64_t> a2(4096 * 4096);
    a2.randInit();
    timer->start();
    auto res = a1.fastSIMDAddition(a2);
    timer->end();
    LOG(INFO) << timer->show();
    auto expect = a1.getSum() + a2.getSum();
    auto actual = res->getSum();
    ASSERT_TRUE(expect == actual);
}


TEST(SqrtTests, CommonWithFloat) {
    CustomArray<float> a1(4096 * 4096);
    a1.randInit();
    auto res = a1.Sqrt();
}

TEST(SqrtTests, CommonWithDouble) {
    CustomArray<double> a1(4096 * 4096);
    a1.randInit();
    auto res = a1.Sqrt();
}

template<typename T>
T sqrt_mm_f(T a){
    return _mm_sqrt_ps(a);
}

TEST(SqrtTests, SIMDSqrtFloat) {
    CustomArray<float> a1(4096 * 4096);
    a1.randInit();
    auto res = a1.SIMDSqrt(sqrt_mm_f<__m128>);
}

template<typename T>
T sqrt_mm_d(T a){
    return _mm_sqrt_pd(a);
}

TEST(SqrtTests, SIMDSqrtDouble) {
    CustomArray<double> a1(4096 * 4096);
    a1.randInit();
    //_mm_shl_epi16() - move
    auto res = a1.SIMDSqrt(sqrt_mm_d<__m128d>);
}

TEST(MoveTests, SIMDMove) {
   /* int *a = new int[4] { 1,2, 3, 4};
    int *b = new int[4] { 1,2, 3, 4};

    __m128i ma = _mm_load_si128((__m128i*)a);
    __m128i mb = _mm_load_si128((__m128i*)b);

    __m128i res = _mm_shl_epi32(ma, mb);

    int* r = (int*)&res;

    LOG(INFO) << r[1];
    LOG(INFO) << r[2];
    LOG(INFO) << r[3];*/

    //__m128d di = (__m128d)i;

//    _mm_shl_epi32
    //_mm_shl_epi16() - move
}

TEST(MoveTests, CommonMove) {
    __m128i va = _mm_setr_epi8(0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f);
    __m128i vb, vc;

    vb = SHL128(va, 4);
    vc = SHR128(va, 4);

    int *resa = (int*)&va;
    LOG(INFO) << "-----------";
    LOG(INFO) << (resa[0] << 63);
    LOG(INFO) << resa[1];
    LOG(INFO) << resa[2];
    LOG(INFO) << resa[3];
    LOG(INFO) << "-----------";
    int *resb = (int*)&vb;
    LOG(INFO) << resb[0];
    LOG(INFO) << resb[1];
    LOG(INFO) << resb[2];
    LOG(INFO) << resb[3];
}