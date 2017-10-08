//
// Created by kirill on 06.10.17.
//

#include <gtest/gtest.h>
#include <memory>
#include "timers/CommonTimer.h"
#include "timers/ClockTimer.h"
#include "timers/ChronoTimer.h"
#include "timers/RdtscTimer.h"
#include "timers/OmpTimer.h"
#include "algorithms/Sort.h"
#include "algorithms/Matrix.h"

class SpeedTest : public ::testing::Test {
public:

    void setAlgorithm(std::shared_ptr<Algorithm> algorithm){
        this->algorithm = algorithm;
    }

    void setTimer(std::shared_ptr<Timer> timer){
        this->timer = timer;
    }

    virtual void SetUp() { }

    virtual void TearDown() {
        LOG(INFO) << "Start testing...";
        timer->start();
        algorithm->execute();
        timer->end();
        LOG(INFO) << "Time: " << timer->show();
    }

    std::shared_ptr<Algorithm> algorithm;
    std::shared_ptr<Timer> timer;
};

void getSystemTimeFromAddress(){
    time_t time = (time_t)0x7FFFFFFF;
    tm* systemTime = gmtime(&time);
    LOG(INFO) << systemTime->tm_sec;
    LOG(INFO) << systemTime->tm_min;
    LOG(INFO) << systemTime->tm_hour;
    LOG(INFO) << systemTime->tm_mday;
    LOG(INFO) << systemTime->tm_mon;
    LOG(INFO) << systemTime->tm_year;
}

TEST(TimeTest, GetSystemTime){
    getSystemTimeFromAddress();
}

template<typename T>
void MatrixTestF(std::shared_ptr<Timer> timer, size_t size){
    Matrix<T> m1(size);
    Matrix<T> m2(size);
    timer->start();
    Matrix<T> res = m1 * m2;
    timer->end();
    LOG(INFO) << timer->show();
}

TEST(MatrixTest, UsePrime){
    int **mass1 = randomMatrix<int>(3);
    int **mass2 = randomMatrix<int>(3);
    int** res = multiply<int>(mass1, 2, mass2, 2);
    showMatrix<int>(res, 2);
}

TEST(MatrixTest, UseObject){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<int>(timer, 100);
}

TEST(MatrixTest, UseObject512){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<int>(timer, 512);
}

TEST(MatrixTestType, UseObject1024int8){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<int8_t>(timer, 1024);
}

TEST(MatrixTestType, UseObject1024int16){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<int16_t>(timer, 1024);
}

TEST(MatrixTestType, UseObject1024int32){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<int32_t>(timer, 1024);
}

TEST(MatrixTestType, UseObject1024int64){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<int64_t>(timer, 1024);
}

TEST(MatrixTestType, UseObject1024float){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<float>(timer, 1024);
}

TEST(MatrixTestType, UseObject1024double){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<double>(timer, 1024);
}


TEST(MatrixTest, UseObject2048){
    auto timer = std::make_shared<ChronoTimer>();
    MatrixTestF<int>(timer, 2048);
}

TEST_F(SpeedTest, SumArrayRdtscTimer) {
    setAlgorithm(std::make_shared<SumArray>(1000));
    setTimer(std::make_shared<RdtscTimer>());
}

TEST_F(SpeedTest, SumArrayOmp) {
    setAlgorithm(std::make_shared<SumArray>(100000));
    setTimer(std::make_shared<OmpTimer>());
}

TEST_F(SpeedTest, ClockTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<ClockTimer>());
}

TEST_F(SpeedTest, CommonTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<CommonTimer>());
}

TEST_F(SpeedTest, ChronoTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<ChronoTimer>());
}

TEST_F(SpeedTest, RdtscTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<RdtscTimer>());
}

TEST_F(SpeedTest, OmpTimerSort) {
    setAlgorithm(std::make_shared<Sort>(100000));
    setTimer(std::make_shared<OmpTimer>());
}