#include "pch.h"
#include "../List/List.h"


TEST(ListTest, DefaultConstructorTest) {
    auto ll1 = List<int>();

    ASSERT_EQ(ll1.getSize(), 0);
    ASSERT_EQ(ll1.getHead(), nullptr);
}

TEST(ListTest, ListGrowsAndShrinks) {
    List<int> ll1;

    ll1.push_back(5);
    ll1.push_front(6);
    ll1.push_back(7);
    ll1.push_front(8);
    ll1.push(9, 2);

    ASSERT_EQ(ll1.getSize(), 5);

    ll1.pop_back();
    ll1.pop_front();

    ASSERT_EQ(ll1.getSize(), 3);
}

TEST(ListTest, CopyConstructorTest) {
    List<int> ll1;
    ll1.push_back(5);
    ll1.push_front(6);
    ll1.push_back(7);
    ll1.push_front(8);
    ll1.push(9, 2);

    ASSERT_EQ(ll1.getSize(), 5);

    List<int> ll2 = List<int>(ll1);

    ASSERT_EQ(ll1.getHead()->data, ll1.getHead()->data);
    ASSERT_EQ(ll1.getSize(), ll1.getSize());
}

TEST(ListTest, CopyAssignTest) {
    List<int> ll1;
    ll1.push_back(5);
    ll1.push_front(6);
    ll1.push_back(7);
    ll1.push_front(8);
    ll1.push(9, 2);

    ASSERT_EQ(ll1.getSize(), 5);

    List<int> ll2 = ll1;

    ASSERT_EQ(ll1.getHead()->data, ll1.getHead()->data);
    ASSERT_EQ(ll1.getSize(), ll1.getSize());
}

TEST(ListTest, MoveConstructorTest) {
    List<int> ll1;
    ll1.push_back(5);
    ll1.push_front(6);
    ll1.push_back(7);
    ll1.push_front(8);
    ll1.push(9, 2);

    const auto ll1Size = ll1.getSize();
    ASSERT_EQ(ll1Size, 5);

    List<int> ll2 = List<int>(std::move(ll1));

    ASSERT_EQ(ll2.getSize(), ll1Size);
    ASSERT_NE(ll2.getHead(), nullptr);
}

TEST(ListTest, MoveAssignmentTest) {
    List<int> ll1;
    ll1.push_back(5);
    ll1.push_front(6);
    ll1.push_back(7);
    ll1.push_front(8);
    ll1.push(9, 2);

    const auto ll1Size = ll1.getSize();
    ASSERT_EQ(ll1Size, 5);

    List<int> ll2 = std::move(ll1);

    ASSERT_EQ(ll2.getSize(), ll1Size);
    ASSERT_NE(ll2.getHead(), nullptr);
}

TEST(ListTest, OverloadOutOperator) {
    List<int> ll1;
    ll1.push_back(5);
    ASSERT_EQ(ll1.getSize(), 1);

    std::stringstream stream;
    stream << ll1;
    ASSERT_EQ(stream.str().compare("5"), 1);
}

TEST(ListTest, TestGetByIndex) {
    List<int> ll1;
    int found1 = 5;
    int found2 = 5;

    ll1.push_back(found1);
    ll1.push_back(1);
    ll1.push_back(found2);
    ll1.push_back(3);
    ASSERT_EQ(ll1.getSize(), 4);


    ASSERT_EQ(ll1.get_by_index(0)->data, found1);
    ASSERT_EQ(ll1.get_by_index(INT32_MAX), nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
