#pragma once
#include <stdexcept>

template<typename T>
class SquareMatrix
{
public:
    SquareMatrix(); // default constructor

    // the big five
    ~SquareMatrix(); // destructor
    SquareMatrix(const SquareMatrix<T>& matrix); // copy constructor
    SquareMatrix(SquareMatrix&& matrix); // move constructor
    SquareMatrix& operator=(const SquareMatrix<T>& rhs_matrix); // copy assignment
    SquareMatrix& operator=(SquareMatrix<T>&& rhs_matrix); // move assignment
    
    void resize(int new_size); // resize; destroy all prev memory and allocate anew
    int size() const; // get mtx sz
    T& at( int givenRow,  int givenColumn); // get reference at given col and row
    /**
        * check whether two matrices are equivalent
    */
    bool operator==(const SquareMatrix<T>& rhs) const
    {
        if(this->size() != rhs.size())
        {
            return false;
        }
        for(int i = 0; i < rhs.size(); i++)
        {
            for (int j = 0; j < rhs.size(); j++)
            {
                if(this->item[i][j] != rhs.item[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    /**
        * add two matrices and return one with the values of the other two added
    */
    SquareMatrix operator+(const SquareMatrix<T> & rhs) const
    {
        // create new matrix and resize it
        SquareMatrix<T> newMatrix;
        newMatrix.resize(rhs.size());

        // add new values to new matrix
        for(int i = 0; i < rhs.size(); i++)
        {
            for (int j = 0; j < rhs.size(); j++)
            {
                newMatrix.item[i][j] = this->item[i][j] + rhs.item[i][j];
            }
        }

        return newMatrix;
    }


private:
    // item = array itself
    T** item = nullptr;
    // store the size of the arrat
    int _size = 0;
};

// default constructor
template<typename T>
SquareMatrix<T>::SquareMatrix(): item(nullptr), _size(0)
{}

/**
     copy constructor
    takes care of the a = b = c
*/
template<typename T>
SquareMatrix<T>::SquareMatrix(const SquareMatrix<T>& matrix)
    : _size(matrix._size), item(matrix.item)
{
    // no copying if there is nothing to copy
    if(matrix.item == nullptr)
    {
        return;
    }

    item = new T*[matrix._size];

    // loop through new array to add columns
    for(int i = 0; i < _size; i++)
    {
        item[i] = new T[_size];
    }

    // set the array values equal to the array values of the matrix being copied from
    for(int i = 0; i < _size; i++)
    {
        for(int j = 0; j < _size; j++)
        {
            item[i][j] = matrix.item[i][j];
        }
    }
}

/**
    move constructor
    moves ownership by changing reference
*/
template<typename T>
SquareMatrix<T>::SquareMatrix(SquareMatrix<T>&& matrix)
    : item(matrix.item), _size(matrix._size)
{
    matrix.item = nullptr;
}

/** 
    copy assignment
    allows for a = b = c
    allows for copying of matrices using  "="
    no action performed if current and rhs matrix == same
*/
template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(const SquareMatrix<T> & rhs_matrix)
{
    if(this == &rhs_matrix)
    {
        return *this;
    }
    if(this->size() != rhs_matrix.size())
    {
        // deallocate/delete
        for(int i = 0; i < this->size(); i++)
        {
            delete[] item[i];
        }
        delete[] item;
        // manage dangling ptr
        item = nullptr;
    
        // allocate new memory and change the object
        item = new T*[rhs_matrix._size]; // create rows
        
        // loop through and create columns
        for(int i = 0; i < rhs_matrix._size; i++)
        {
            item[i] = new T[rhs_matrix._size];
        }
    
        // update variables 
        _size = rhs_matrix._size;
    }

    // copy items frm rhs
    for(int x = 0; x < _size; x++)
    {
        for(int k = 0; k < _size; k++)
        {
            item[x][k] = rhs_matrix.item[x][k];
        }
    }

    return *this;
}

/** 
    move assignment
    move ownership of obj
 */
template<typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(SquareMatrix<T>&& rhs_matrix)
{
    if(this == &rhs_matrix)
    {
        return *this;
    }
    if(item != nullptr)
    {
        for(int i = 0; i < this->size(); i++)
        {
            delete[] item[i];
        }
        delete[] item;
    }

    item = rhs_matrix.item;

    _size = rhs_matrix._size;
    
    rhs_matrix.item = nullptr;
    
    return *this;
}

/**
    destructor
    deallocate columns and then rows
    set nullptr to handle dangling ptr
*/
template<typename T>
SquareMatrix<T>::~SquareMatrix()
{
    if(item != nullptr)
    {
        for(int i = 0; i < this->size(); i++)
        {
            delete[] item[i];
        }
        // delete the remaining rows
        delete[] item;
        item = nullptr;
        _size = 0;
    }
}

/**
 *  at function
 *  validate given row and col before returning item at location
 *  allow modification of item at location
*/
template<typename T>
T& SquareMatrix<T>::at(int givenRow, int givenColumn)
{
    if(this->size() == 0)
    {
        throw std::out_of_range("matrix size is 0-- no values");
    }
    // validate the input 
    if(((givenColumn < _size) && (givenRow < _size) )&& (givenRow > -1) && (givenColumn > -1))
    {
        // if valid return item at pos
        return item[givenRow][givenColumn];
    }
    // otherwise throw error
    else
    {
        throw std::out_of_range("row or col out of range");
    }
}

// #include <cmath>
// return current size of matrix
template<typename T>
int SquareMatrix<T>::size() const
{
    return _size;
}

/** 
 *  resize the matrix
 *  first deallocate memory
 *  reallocate memory
 *  update vars
*/
template<typename T>
void SquareMatrix<T>::resize(int new_size)
{
    if(item != nullptr)
    {
        for(int i = 0; i < this->size(); i++)
        {
            delete[] item[i];
        }
        delete[] item;
        item = nullptr;
        _size = 0;

        item = new T*[new_size]; // create rows

        for(int i = 0; i < new_size; i++)
        {
            item[i] = new T[new_size];
        }

        _size = new_size;

        // set the array values equal to the array values of the matrix being copied from
        for(int i = 0; i < new_size; i++)
        {
            for(int j = 0; j < new_size; j++)
            {
                // reset the values
                item[i][j] = T();
            }
        }
    }
    else
    {
        item = new T*[new_size]; // create rows
        _size = new_size;

        for(int i = 0; i < new_size; i++)
        {
            item[i] = new T[new_size];
        }

        // set the array values equal to the array values of the matrix being copied from
        for(int i = 0; i < new_size; i++)
        {
            for(int j = 0; j < new_size; j++)
            {
                // reset the values
                item[i][j] = T();
            }
        }
    }
    
}