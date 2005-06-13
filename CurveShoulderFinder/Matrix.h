/**
 * @file Matrix.h
 * @author Austin Hartman
 *
 * $Id: Matrix.h,v 1.3 2005/06/10 21:52:23 ahartman Exp $
 */

#ifndef AUSTIN_MATRIX_H
#define AUSTIN_MATRIX_H

#include <iostream>
#include <fstream>

#include "MyVector.h"



template<class T>
class Matrix;

template<class T>
std::ostream& 
operator<<(std::ostream& os, const Matrix<T>& m);

template<class T>
std::ofstream& 
operator<<(std::ofstream& ofs, const Matrix<T>& m);

template<class T>
std::istream& 
operator>>(std::istream& is, Matrix<T>& m);



template<class T>
class Matrix
{
public:
	virtual ~Matrix() = 0;

	/**
	 * Multiplies a matrix by a vector.
	 * Pre: The number of columns in the matrix must equal the number
	 * of elements in the vector
	 * Post: returns a vector that is the result of multiplying this
	 * matrix by the vector v
	 */
	virtual MyVector<T> operator*(const MyVector<T>& v) const = 0;

	/**
	 * Note: it doesn't make sense to have operator+=, operator-=,
	 * or operator*= here, because the results of these operations
	 * might be different than the type of object that was originally
	 * on the left-hand side.  For example, adding any generic matrix 
	 * to a tridiagonal matrix doesn't necessarily produce a 
	 * tridiagonal matrix.
	 */

	class RowProxy;
	class ConstRowProxy;

	/**
	 * operators used for the first bracket in the operation
	 * matrix[row][column]
	 */
	RowProxy operator[](const size_t& r);
	ConstRowProxy operator[](const size_t& r) const;

	/**
	 * Pre: None
	 * Post: returns the number of rows in the matrix.
	 */
	virtual const size_t& getNumRows() const = 0;

	/**
	 * Pre: None
	 * Post: returns the number of columns in the matrix.
	 */
	virtual const size_t& getNumCols() const = 0;

	/**
	 * Proxy classes to implement access with matrix[row][column].  The
	 * two different classes are used so that const-correctness 
	 * is maintained.
	 */
	class RowProxy
	{
	public:
		RowProxy(Matrix<T>& mat, const size_t& r);

		/**
		 * Implements the second [] in matrix[row][column]
		 * Pre: c is < the number of columns in matrix.
		 * Returns the element in the matrix in the row row
		 * and the c column.  Throws ColumnRangeError if
		 * c >= the number of columns in the matrix.
		 */
		T& operator[](const size_t& c) const;
	private:
		Matrix<T>& matrix;
		size_t row;

	};
	friend class RowProxy;

	class ConstRowProxy
	{
	public:
		ConstRowProxy(const Matrix<T>& mat, const size_t& r);

		/**
		 * Implements the second [] in matrix[row][column]
		 * Pre: c is < the number of columns in matrix.
		 * Returns the element in the matrix in the row row
		 * and the c column.  Throws ColumnRangeError if
		 * c >= the number of columns in the matrix.
		 */
		const T& operator[](const size_t& c) const;
	private:
		const Matrix<T>& matrix;
		size_t row;
	};
	friend class ConstRowProxy;

	/**
	 * Exception class used when the user tries to access an invalid row.
	 */
	class RowRangeError
	{
	public:
		/**
		 * Constructor that takes an argument to indicate the
		 * invalid row that the user tried to access.
		 */
		RowRangeError(const size_t& r);

		/**
		 * Returns the row that the user tried to access that was
		 * invalid.
		 */
		const size_t& getRow() const;
	private:
		size_t row;
	};


	/**
	 * Exception class used when the user tries to access an invalid 
	 * column.
	 */
	class ColumnRangeError
	{
	public:
		/**
		 * Constructor that takes an argument to indicate the
		 * invalid column that the user tried to access.
		 */
		ColumnRangeError(const size_t& c);

		/**
		 * Returns the column that the user tried to access that was
		 * invalid.
		 */
		const size_t& getColumn() const;
	private:
		size_t column;
	};


	/**
	 * Exception class used when the user tries to perform a matrix
	 * operation on matrices that have sizes that are undefined for
	 * that operation.
	 */
	class IncompatibleMatrixSizes
	{
	public:
		/**
		 * Constructor that takes the number of rows and columns
		 * in both of the matrices on the left- and right-hand of
		 * the operation that was invalid.
		 */
		IncompatibleMatrixSizes(const size_t& lhsNumRows,
		                        const size_t& lhsNumCols, 
		                        const size_t& rhsNumRows,
		                        const size_t& rhsNumCols);

		/**
		 * Pre: None
		 * Post: Returns the number of rows in the matrix that
		 * was on the left-hand side of the operation.
		 */
		const size_t& getLhsRows() const;

		/**
		 * Pre: None
		 * Post: Returns the number of columns in the matrix that
		 * was on the left-hand side of the operation.
		 */
		const size_t& getLhsColumns() const;

		/**
		 * Pre: None
		 * Post: Returns the number of rows in the matrix that
		 * was on the right-hand side of the operation.
		 */
		const size_t& getRhsRows() const;

		/**
		 * Pre: None
		 * Post: Returns the number of columns in the matrix that
		 * was on the right-hand side of the operation.
		 */
		const size_t& getRhsColumns() const;
	private:
		size_t lhsRows;
		size_t lhsCols;
		size_t rhsRows;
		size_t rhsCols;
	};

protected:
	/**
	 * These getElement functions are used to get the element at 
	 * row, column in the matrix.  They should be overridden 
	 * by derived classes.
	 * They will be automatically called when the user does
	 *   matrix[row][column]
	 */
	virtual T& getElement(const size_t& row, const size_t& col) = 0;
	virtual const T& getElement(const size_t& row, 
	                            const size_t& col) const = 0;

	/**
	 * The printOn function is called by operator<<, because
	 * operator<< is outside the class and thus cannot be made virtual
	 * It should output the matrix in a form suited for viewing on
	 * the screen.
	 */
	virtual void printOn(std::ostream& os) const = 0;
	friend std::ostream& operator<< <>(std::ostream& os, const Matrix<T>& m);

	/**
	 * The printOnFile function is called by operator<< for ofstreams,
	 * because operator<< is outside the class and thus cannot be made
	 * virtual.  It should output the matrix in a form suited for storing
	 * in a file.  
	 */
	virtual void printOnFile(std::ofstream& ofs) const = 0;
	friend std::ofstream& operator<< <>(std::ofstream& ofs, const Matrix<T>& m);

	/**
	 * The readIn function is called by operator>>, because operator>>
	 * is outside the class and thus cannot be made virtual.  It should
	 * read in the matrix in the same format that printOnFile outputted
	 * it in.
	 */
	virtual void readIn(std::istream& is) = 0;
	friend std::istream& operator>> <>(std::istream& is, Matrix<T>& m);
};

#include "Matrix.hpp"

#endif
