#include "MyVector.h"
#include <../gtest/gtest.h>


TEST(Matrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(Matrix<int> m(5));
}

TEST(Matrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(Matrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(Matrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(Matrix<int> m(-5));
}

TEST(Matrix, can_create_copied_matrix)
{
	Matrix<int> m(5);

	ASSERT_NO_THROW(Matrix<int> m1(m));
}

TEST(Matrix, copied_matrix_is_equal_to_source_one)
{
	Matrix<int> m(5);
	Matrix<int> m1(m);
	EXPECT_EQ(m==m1, 1);
}

TEST(Matrix, can_get_size)
{
    Matrix<int> m(5);
	EXPECT_EQ(5,m.Length());
}

TEST(Matrix, can_set_and_get_element)
{
	Matrix<int> m1(5);
    m1[3][2] = 11;
	EXPECT_EQ(m1[3][2], 11);
}

TEST(Matrix, throws_when_set_element_with_negative_index)
{
	Matrix<int> m(4);
	ASSERT_ANY_THROW(m[-1]);
}

TEST(Matrix, throws_when_set_element_with_too_large_index)
{
	Matrix<int> m(4);
	ASSERT_ANY_THROW(m[5]);
}

TEST(Matrix, can_assign_matrix_to_itself)
{
	Matrix<int> m(4);
	ASSERT_NO_THROW(m = m);
}

TEST(Matrix, can_assign_matrices_of_equal_size)
{
	Matrix<int> m1(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
			m1[i][j] = j;
	Matrix<int>m2(5);
	m2 = m1;
	EXPECT_EQ(m1 == m2, 1);

}


TEST(Matrix, can_assign_matrices_of_different_size)
{
	Matrix<int> m1(10);
	Matrix<int> m2(5);
	m2 = m1;
	EXPECT_EQ(m1==m2,1);
	
}

TEST(Matrix, compare_equal_matrices_return_true)
{
	Matrix<int> m1(5);
    Matrix<int>m2(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
		{
			m1[i][j] = j;
			m2[i][j] = j;
		}
	EXPECT_EQ(1, m1==m2);
}

TEST(Matrix, compare_matrix_with_itself_return_true)
{
	Matrix<int> m1(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
		{
			m1[i][j] = j;
		}
	EXPECT_EQ(1, m1==m1);
}

TEST(Matrix, matrices_with_different_size_are_not_equal)
{
		Matrix<int> m1(10);
	Matrix<int> m2(5);
	EXPECT_EQ(m1==m2,0);
}

TEST(Matrix, can_add_matrices_with_equal_size)
{
	Matrix<int> m1(5);
	Matrix<int> m2(5);
	Matrix<int> m3(5);
	Matrix<int> m4(5);
	for (int i = 0; i < m1.Length(); i++)
		for (int j = 0; j < m1[i].Length(); j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 2;
			m3[i][j] = 3;
		}
	m4 = m1 + m2;
	EXPECT_EQ(1, m4==m3);
}

TEST(Matrix, cant_add_matrices_with_not_equal_size)
{
	Matrix<int> m1(4);
	Matrix<int> m2(8);
	ASSERT_ANY_THROW(m1+m2);
}

