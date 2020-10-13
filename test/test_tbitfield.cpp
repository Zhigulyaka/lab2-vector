
#include "MyVector.h"
#include <../gtest/gtest.h>

TEST(MyVector, can_create_vector_with_default_constructor)
{
    ASSERT_NO_THROW(Vector<int> v1);
}

TEST(MyVector, can_create_vector_with_size_one)
{
    Vector<double> v1(5,10);
    EXPECT_EQ(5, v1.Length());
    for (int i = 0; i < v1.Length(); i++)
        EXPECT_EQ(10, v1[i]);
}

TEST(MyVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(MyVector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(Vector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(MyVector, can_create_vector_with_max_size)
{
    ASSERT_NO_THROW(Vector<int> v(MAX_VECTOR_SIZE));
}

TEST(MyVector, can_create_vector_with_zero_size)
{
    ASSERT_NO_THROW(Vector<int> v(0));
}

TEST(MyVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(MyVector, can_create_copied_vector)
{
    Vector<int> v(10);

    ASSERT_NO_THROW(Vector<int> v1(v));
}

TEST(MyVector, copied_vector_is_equal_to_source_one)
{
    Vector<int> v1(5, 10);
    Vector<int> v2(v1);
    EXPECT_EQ(v1.Length(), v2.Length());
    for (int i = 0; i < v1.Length(); i++)
        EXPECT_EQ(v2[i], v1[i]);
}

TEST(MyVector, can_get_size)
{
    Vector<int> v(4,0);

    EXPECT_EQ(4, v.Length());
}

TEST(MyVector, can_get_start_index)
{
    Vector<int> v(4, 2);

    EXPECT_EQ(2, v[0]);
}

TEST(MyVector, can_set_and_get_element)
{
    Vector<int> v(1,4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(MyVector, can_assign_vector_to_itself)
{
    Vector<int> v(1,4);
    ASSERT_NO_THROW(v = v);
    
}

TEST(MyVector, can_assign_vectors_of_equal_size)
{
    Vector<int> v1(5, 10);
    Vector<int> v2(5,0);
    v2 = v1;
    EXPECT_EQ(v1.Length(), v2.Length());
    for (int i = 0; i < v1.Length(); i++)
        EXPECT_EQ(v2[i], v1[i]);
}

TEST(MyVector, can_assign_vectors_of_different_size)
{
    Vector<int> v1(10, 10);
    Vector<int> v2(5, 0);
    v2 = v1;
    EXPECT_EQ(v1.Length(), v2.Length());
    for (int i = 0; i < v1.Length(); i++)
        EXPECT_EQ(v2[i], v1[i]);
}

TEST(MyVector, compare_equal_vectors_return_true)
{
    Vector<int> v1(5, 0);
    Vector<int> v2(5, 0);
    bool f;
    f = (v1 == v2);
    EXPECT_EQ(1, f);
}

TEST(MyVector, compare_vector_with_itself_return_true)
{
    Vector<int> v(5, 0);
    bool f;
    f = (v == v);
    EXPECT_EQ(1, f);
}

TEST(MyVector, vectors_with_different_size_are_not_equal)
{
    Vector<int> v1(5, 0);
    Vector<int> v2(10, 0);
    bool f;
    f = (v1 == v2);
    EXPECT_EQ(0, f);
}

TEST(MyVector, can_add_vectors_with_equal_size)
{
    Vector<int> v1(5, 3);
    Vector<int> v2(5, 8);
    Vector<int> v3(5, 11);
    Vector<int> v4;
    v4 = v1 + v2;
    bool f;
    f = (v3 == v4);
    EXPECT_EQ(1, f);
}

TEST(MyVector, cant_add_vectors_with_not_equal_size)
{
    Vector<int> v1(10, 3);
    Vector<int> v2(5, 8);
    Vector<int> v3(5, 11);
    Vector<int> v4;
    v4 = v1 + v2;
    bool f;
    f = (v3 == v4);
    EXPECT_EQ(1, f);
}

TEST(MyVector, can_subtract_vectors_with_equal_size)
{
    Vector<int> v1(5, 3);
    Vector<int> v2(5, 8);
    Vector<int> v3(5, 5);
    Vector<int> v4;
    v4 = v2-v1;
    bool f;
    f = (v3 == v4);
    EXPECT_EQ(1, f);
}

TEST(MyVector, cant_subtract_vectors_with_not_equal_size)
{
    Vector<int> v1(10, 3);
    Vector<int> v2(5, 8);
    Vector<int> v3(5, 5);
    Vector<int> v4;
    v4 = v2 - v1;
    bool f;
    f = (v3 == v4);
    EXPECT_EQ(1, f);
}

TEST(MyVector, can_multiply_vectors_with_equal_size)
{
    Vector<int> v1(5, 1);
    Vector<int> v2(5, 2);
    int res;
    res = v1 * v2;
    EXPECT_EQ(10, res);
}

TEST(MyVector, cant_multiply_vectors_with_not_equal_size)
{
    Vector<int> v1(10, 1);
    Vector<int> v2(5, 2);
    ASSERT_ANY_THROW(v1*v2);
}
