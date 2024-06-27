#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include "enums.hpp"


// #define TEMPLATE_USING_CPP_11_FEATURES
// #define TEMPLATE_CLASS
// #define SIMPLIFIED_IMPLEMENTATION_OF_STD_UNIQUE_PTR


#ifdef TEMPLATE_USING_CPP_11_FEATURES
template <typename T>
class Buffer
{
private:
    int
        _rowsNumber,
        _columnsNumber;
    std::unique_ptr <T[]>
        _bufferPtr;
public:
    Buffer ()                                                                   // DEFAULT CONSTRUCTOR
    {}
    Buffer (                                                                    // CONSTRUCTOR
            int numberOfRows,
            int numberOfColumn
        )
        :   _rowsNumber    (numberOfRows),
            _columnsNumber (numberOfColumn),
            _bufferPtr     (
                new T[_rowsNumber * _columnsNumber]
            )
    { }
    Buffer (const Buffer & other)                                               // COPY CONSTRUCTOR
        :   _rowsNumber    (other._rowsNumber),
            _columnsNumber (other._columnsNumber),
            _bufferPtr     (
                new T[_rowsNumber * _columnsNumber]
            )
    {
        std::copy (
            other._bufferPtr.get (),
                other._bufferPtr.get ()
            +   _rowsNumber
            *   _columnsNumber,
            _bufferPtr.get ()
        );
    }
    Buffer (Buffer && other) noexcept                                           // MOVE CONSTRUCTOR
        :   _rowsNumber    (other._rowsNumber),
            _columnsNumber (other._columnsNumber),
            _bufferPtr     (
                std::move (other._bufferPtr)
            )
    { }
    ~Buffer () = default;                                                       // DESTRUCTOR


    Buffer & operator = (const Buffer & other)                                  // COPY ASSIGNMENT OPERATOR
    {
        if (this != & other)
        {
            this -> _rowsNumber    = other._rowsNumber;
            this -> _columnsNumber = other._columnsNumber;

            this -> _bufferPtr.reset (
                    new T[this -> _rowsNumber * this -> _columnsNumber]
                );

            std::copy (
                other._bufferPtr.get (),
                    other._bufferPtr.get ()
                +   _rowsNumber
                *   _columnsNumber,
                _bufferPtr.get ()
            );
        }

        return
            * this;
    }
    Buffer & operator = (Buffer && other) noexcept                              // MOVE ASSIGNMENT OPERATOR
    {
        if (this != & other)
        {
            this -> _rowsNumber    = other._rowsNumber;
            this -> _columnsNumber = other._columnsNumber;

            this -> _bufferPtr      =
                std::move (
                    other._bufferPtr
                );
        }

        return
            * this;
    }

    // SETTERS
    T & operator () (
            int rowIndex,
            int columnIndex
        )
    {
        return
            this -> _bufferPtr[
                    rowIndex
                *   _columnsNumber
                +   columnIndex
            ];
    }

    // GETTERS
    const T & operator () (
            int rowIndex,
            int columnIndex
        ) const
    {
        return
            this -> _bufferPtr[
                    rowIndex
                *   _columnsNumber
                +   columnIndex
            ];
    }
    int getNumberOfRows () const
    {
        return
            this -> _rowsNumber;
    }
    int getNumberOfColumns () const
    {
        return
            this -> _columnsNumber;
    }
};
#endif  // TEMPLATE_USING_CPP_11_FEATURES







#ifdef TEMPLATE_CLASS
template <typename T>
class Buffer
{
private:
    int
        _rowsNumber,
        _columnsNumber;
    T *
        _bufferPtr;
public:
    Buffer (                                                                    // CONSTRUCTOR
            int numberOfRows,
            int numberOfColumn
        )
    {
        this -> _rowsNumber    = numberOfRows;
        this -> _columnsNumber = numberOfColumn;
        this -> _bufferPtr     = new T [_rowsNumber * _columnsNumber];
    }

    Buffer(const Buffer & other)                                                // COPY CONSTRUCTOR
    {
        this -> _rowsNumber    = other._rowsNumber;
        this -> _columnsNumber = other._columnsNumber;
        this -> _bufferPtr     = new T [_rowsNumber * _columnsNumber];

        for (int i = 0;
                    i < _rowsNumber * _columnsNumber;
                ++i
            ) 
            this -> _bufferPtr[i] = other._bufferPtr[i];
    }
    ~Buffer ()                                                                  // DESTRUCTOR
    {
        if (this -> _bufferPtr)
            delete [] this -> _bufferPtr;
    }

    Buffer & operator = (const Buffer & other)                                  // COPY ASSIGNMENT OPERATOR
    {
        if (this != & other)
        {
            delete [] _bufferPtr;

            this -> _rowsNumber    = other._rowsNumber;
            this -> _columnsNumber = other._columnsNumber;
            this -> _bufferPtr     = new T[_rowsNumber * _columnsNumber];

            for (int i = 0;
                     i < _rowsNumber * _columnsNumber;
                     ++i
                )
                _bufferPtr[i] = other._bufferPtr[i];
        }

        return
            * this;
    }

    // SETTERS
    T & operator () (
            int numberOfRows,
            int numberOfColumn
        )
    {
        return
            _bufferPtr[
                    numberOfRows
                *   _columnsNumber
                +   numberOfColumn
            ];
    }

    // GETTERS
    const T & operator () (
            int numberOfRows,
            int numberOfColumn
        ) const
    {
        return
            this -> data[
                    numberOfRows
                *   _columnsNumber
                +   numberOfColumn
            ];
    }
    int getNumberOfRows () const
    {
        return
            this -> _rowsNumber;
    }
    int getNumberOfColumns () const
    {
        return
            this -> _columnsNumber;
    }
};
#endif  // TEMPLATE_CLASS


template <typename T>
class Buffer
{
private:
    const T   * _bufferPtr;
          int   _rowCapacity;
          int   _columnCapacity;
          int   _occupiedPlacesInRow;
          int   _occupiedPlacesInColumn;
public:
    // Buffer ()
    // {
    //     this -> _bufferPtr              = new T [1][1];
    //     this -> _rowCapacity            = 1;
    //     this -> _columnCapacity         = 1;
    //     this -> _occupiedPlacesInRow    = 0;
    //     this -> _occupiedPlacesInColumn = 0;
    // }
    Buffer ()
    {
        this -> _bufferPtr              =
            new T [Default::KINDS_OF_SPORT_LENGTH]
                  [Default::MAX_NUMBER_OF_ITEMS];
        this -> _rowCapacity            =
            Default::KINDS_OF_SPORT_LENGTH;
        this -> _columnCapacity         =
            Default::MAX_NUMBER_OF_ITEMS;
        this -> _occupiedPlacesInRow    = 0;
        this -> _occupiedPlacesInColumn = 0;
    }
    ~Buffer ()
    {
        if (this -> _bufferPtr)
            delete [] this -> _bufferPtr;
    }

    // SETTERS
    T & operator () (
            int rowNumber,
            int columnNumber
        )
    {
        return
            this -> _bufferPtr[rowNumber][columnNumber];
    }

    void fill (
            Buffer & arr,
            int      value
        )
    {
        int ** A = arr._bufferPtr; 
    
        for (int row = 0;
                 row < arr._rowCapacity;
                 ++row
            )
            for (int column = 0;
                     column < arr._columnCapacity;
                     ++column
                )
                A[row][column] = value;
    }
};


#endif  // ! BUFFER_H



#ifdef SIMPLIFIED_IMPLEMENTATION_OF_STD_UNIQUE_PTR
template <
        typename T,
        typename D = std::default_delete <T>
    >
class unique_ptr
{
private:
    D
        deleter;
    T *
        ptr;
public:
    explicit unique_ptr (                                                       // CONSTRUCTOR
                  T * p = nullptr,
            const D & d = D ()
        )
        :   ptr     (p),
            deleter (d)
    { }
    {
        if (ptr)
            deleter (ptr);
    }
    unique_ptr (const unique_ptr &) = delete;                                   // DELETE COPY CONSTRUCTOR
    unique_ptr (unique_ptr && other) noexcept                                   // MOVE CONSTRUCTOR
        :   ptr     (other.ptr),
            deleter (
                std::move (
                    other.deleter
                )
            )
    {
        other.ptr = nullptr;
    }
    ~unique_ptr ()                                                              // DESTRUCTOR


    unique_ptr & operator = (const unique_ptr &) = delete;                      // DELETE COPY ASSIGNMENT OPERATOR
    unique_ptr & operator = (unique_ptr && other) noexcept                      // MOVE ASSIGNMENT OPERATOR
    {
        if (this != & other)
        {
            reset ();

            ptr     = other.ptr;
            deleter =
                std::move (
                    other.deleter
                );

            other.ptr = nullptr;
        }

        return
            * this;
    }

    T & operator * () const                                                     // An operator * that dereferences the managed object
    {
        return
            * ptr;
    }
    T * operator -> () const                                                    // An operator -> that returns the raw pointer to the managed object
    {
        return
            ptr;
    }

    T * get () const                                                            // A get() function that returns the raw pointer to the managed object
    {
        return
            ptr;
    }
    T * release ()                                                              // A release() function that releases the ownership of the managed object and returns the raw pointer
    {
        T * tmp = ptr;
        ptr = nullptr;

        return
            tmp;
    }
    void reset (T * p = nullptr)                                                // A reset() function that deletes the managed object and makes the unique_ptr point to another object or nullptr
    {
        if (ptr)
            deleter (ptr);

        ptr = p;
    }
    explicit operator bool () const                                             // An operator bool that returns true if the unique_ptr is not empty, false otherwise
    {
        return
            ptr != nullptr;
    }
    void swap     (unique_ptr & other) noexcept                                 // A swap() function that swaps the managed objects and deleters of two unique_ptrs
    {
        exchange (
            other
        );
    }
    void exchange (unique_ptr & other) noexcept                                 // An exchange() function (since C++20) that swaps the managed objects and deleters of two unique_ptrs
    {
        using std::swap;

        swap (
            ptr,
            other.ptr
        );
        swap (
            deleter,
            other.deleter
        );
    }
};
#endif  // SIMPLIFIED_IMPLEMENTATION_OF_STD_UNIQUE_PTR
