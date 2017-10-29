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
#include "Polynom.h"


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
        ASSERT_TRUE(algorithm->check());
        LOG(INFO) << "Time: " << timer->show();
    }

    std::shared_ptr<Algorithm> algorithm;
    std::shared_ptr<Timer> timer;
};

TEST_F(SpeedTest, OmpTimerSort) {
    setAlgorithm(std::make_shared<Sort>(1000));
    setTimer(std::make_shared<OmpTimer>());
}

TEST(PossitiveCountTest, PossitiveCount) {
    const int size = 1000;
    int* array = new int[size];
    initRandomArray(array, size);
    LOG(INFO) << sievePositives(array, size);
}


TEST(VeriableTest, VeriableTestToString) {
    Veriable veriable("s", 4);
    ASSERT_TRUE(veriable.toString() == "s^4");
}

TEST(MonomialTest, MonomialTestVeriables) {
    Monomial polynom(-4 ,"abs^4g^5");
    LOG(INFO) << polynom.toString();
    ASSERT_TRUE(polynom.toString() == "-4abs^4g^5");
}

TEST(PolynomTest, PolynomTestVeriables) {
    Monomial polynom1(1 ,"abas^4s^1");
    Monomial polynom2(2 ,"afdg^4u^4");
    Monomial polynom3(6 ,"ahgs^4c^2");
    Polynom polynom;
    polynom.addMonomial(polynom1);
    polynom.addMonomial(polynom2);
    polynom.addMonomial(polynom3);

    LOG(INFO) << polynom.toString();
}

