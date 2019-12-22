// hw16.cpp
// to illustrate stl algorithms & function objects

/*************************************************************************
 * AUTHOR     : Aaron Geesink
 * hw16       : stl algorithms & function objects
 * CLASS      : CS 1C
 * SECTION    : M T W Th - 3:00 PM
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

using std::exception;
using std::length_error;
using std::vector;
using std::list;

// function & class definitions go into hw16.cpp:

// hw16.cpp

namespace hw16 {

//
// algorithm, function object example code adapted from Chapter 21
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//--Q#1-------------------------------------------------------------------------

template<typename InputIterator, typename EqualityComparable>
InputIterator find(InputIterator first,InputIterator last, const EqualityComparable& val) 
    // find the first element in [first,last) that equals value
{
    for (InputIterator p = first; p!=last; ++p)
        if (*p==val) return p;
    return last;
}

template<typename InputIterator, typename EqualityComparable>
InputIterator find_improved(InputIterator first,InputIterator last, const EqualityComparable& val) 
    // find the first element in [first,last) that equals value
{
	while (first != last && first != val)
	{
		first++;
	}
    return first; // included so that incomplete lab code will compile
}

//--Q#2-------------------------------------------------------------------------

template<typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred)
    // find the first element in [first,last) that satisfies predicate
{
	while (first != last && !pred(*first))
	{
		++first;
	}

    return first;
}

//--Q#2-------------------------------------------------------------------------

bool even(int x) 
{ 
	return x % 2 == 0; 
} // test for even ints via modulo

//------------------------------------------------------------------------------

bool less_than_31(int x) 
{
	return x < 31;
}

//------------------------------------------------------------------------------

int global_value; // the value to which less_than_v() compares its argument
bool less_than_v(int x)
{
	return x < global_value;
}

//--Q#3-------------------------------------------------------------------------

class Less_than
{
private:
	int v;

public:
	Less_than(int v) : v{ v }
	{ }
	bool operator()(int x) const
	{
		return x < v;
	}
};

//--Q#4-------------------------------------------------------------------------

struct Shape
{
    Shape(int id) : id{id} { }
    virtual ~Shape() { }
    virtual int calc_perimeter() const = 0;
    virtual int calc_area() const { return -1; }
    int id; // shape id
};

std::ostream& operator<<(std::ostream& os, const Shape& s)
{
    return os << s.id;
}

//------------------------------------------------------------------------------

struct Line : public Shape
{
    Line(int id, int p, int a) : Shape{id}, perimeter{p}, area{a} { }
    int calc_perimeter() const override { return perimeter; }
    int calc_area() const override { return area; }
    int perimeter; // shape type perimeter
    int area;      // shape type area
};

//------------------------------------------------------------------------------

struct Square : public Shape
{
    Square(int id, int p, int a) : Shape{id}, perimeter{p}, area{a} { }
    int calc_perimeter() const override { return perimeter; }
    int calc_area() const override { return area; }
    int perimeter; // shape type perimeter
    int area;      // shape type area
};

//--Q#4-------------------------------------------------------------------------

// comparisons for Shape* objects:

struct Cmp_by_id {
    bool operator()(const Shape* s1, const Shape* s2) const
    {
		return s1->id < s2->id;;
	} // dereference pointer, compare ids
};

//------------------------------------------------------------------------------

// Cmp_by_perimeter function object struct definition goes here
// ... dereference pointer, compare perimeters
struct Cmp_by_perimeter {
	bool operator()(const Shape* s1, const Shape* s2) const
	{
		return s1->calc_perimeter() < s2->calc_perimeter();
	}
};

//------------------------------------------------------------------------------

// Cmp_by_area function object struct definition goes here
// ... dereference pointer, compare areas
struct Cmp_by_area {
	bool operator()(const Shape* s1, const Shape* s2) const
	{
		return s1->calc_area() < s2->calc_area();
	}
};

//--Q#5-------------------------------------------------------------------------

template<typename In, typename Out>
    // requires Input_iterator<In> and Output_iterator<Out>
Out copy(In first, In last, Out result)
    // copy elements from [first,last) to result
{
    while (first!=last) {
        *result = *first; // copy element
        ++result;
        ++first;
    }
    return result;
}

//------------------------------------------------------------------------------

template<typename In, typename Out, typename Pred>
    // requires Input_iterator<In> and Output_iterator<Out> and
    //          Predicate<Pred, Value_type<In>>
Out copy_if(In first, In last, Out result, Pred pred)
    // copy elements from [first,last) to result that satisfy predicate
{
	while (first != last)
	{
		if (pred(*first)) // copy element if predicate satisfied
		{
			*result = *first;
			result++;
		}
		++first;
	}

    return result;
}

//--Q#5-------------------------------------------------------------------------

template<typename Val>
    // requires LessThan_comparable<Val>
class Range_low_to_high 
{
private:
	Val v_low;
	Val v_high;

public:
	Range_low_to_high(Val low, Val high) : v_low{ low }, v_high{ high } // store the arguments
	{ }
	bool operator()(Val x) const 
	{
		return !(x < v_low) && !(v_high < x);	// compare to range
	}											// (v_low <= x <= v_high)
												// tests if x is between low and high
												// this is a unary predicate (the last argument of an algorithm)
};

//------------------------------------------------------------------------------

} // hw16

//------------------------------------------------------------------------------

using namespace hw16;

//
// algorithm, function object example code adapted from Chapter 21
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

int func();

int main()
{
    // console header
	cout << endl;
	cout << "************************************** " << endl;
	cout << "*            Running hw16            * " << endl;
	cout << "*      Programmed by Aaron Geesink   * " << endl;
	cout << "*          CS1C M T W Th 3:00 PM     * " << endl;
	cout << "************************************** " << endl;
	cout << endl;

    // NOTE: uncomment code below once algorithm definitions Q#1-5 are complete

	// Q#1 - find algorithm

    vector<int> v = {40,5,4,3,2,-99,100,10,500,5}; // init stl vector of ints using initializer list

    // print vector v
    cout << "vector v: ";
	{
		for (const auto& x : v) cout << x << " ";	// use auto type deduction (x is an int),
													// range-for-loop to print v
	}
	cout << endl << endl;                     

    int x = 5;
    vector<int>::iterator p = hw16::find(v.begin(),v.end(),x); // find value of 5 in v
     if (p!=v.end())
         cout << "find alg: found value of in vector v " << *p << endl << endl;
     else
         cout << "find alg: can't find value in vector v" << endl << endl;

	 // Q#2 - find_if algorithm with predicates
                                                     // find first even int in v
     auto q = hw16::find_if(v.begin(),v.end(),even); // use auto-type deduction for output iterator q
     if (q!=v.end())                                 // (q is a vector<int>::iterator)
         cout << "find_if alg: found even value of in vector v " << *q << endl;
     else
         cout << "find_if alg: can't find even value in vector v" << endl;

     p = hw16::find_if(v.begin(),v.end(),less_than_31); // find first int in v less than 31
     if (p!=v.end())
         cout << "find_if alg: found less_than_31 value of in vector v " << *p << endl;
     else
         cout << "find_if alg: can't find less_than_31 value in vector v" << endl;

     global_value = -100;
     p = hw16::find_if(v.begin(),v.end(),less_than_v); // find first int in v less than -100
     if (p!=v.end())
         cout << "find_if alg: found less_than_v value of in vector v " << *p << endl << endl;
     else
         cout << "find_if alg: can't find less_than_v value in vector v" << endl << endl;

	// Q#3 - find_if algorithm with function objects

    p = hw16::find_if(v.begin(),v.end(),Less_than(4)); // find first int in v less than 4
    if (p!=v.end())
        cout << "find_if alg: found Less_than(4) value of in vector v " << *p << endl << endl;
    else
        cout << "find_if alg: can't find Less_than(4) value in vector v" << endl << endl;

	// Q#4 - sort algorithm + Shape class, function objects

     vector<Shape*> vs;
     vs.push_back(new Line{10,5,-1});       // store pointer to line1 in vs
     vs.push_back(new Line{5,10,-1});       // store pointer to line2 in vs
     vs.push_back(new Line{1,15,-1});       // store pointer to line3 in vs
     vs.push_back(new Square{100,400,625}); // store pointer to square1 in vs
     vs.push_back(new Square{101,40,100});  // store pointer to square2 in vs
     vs.push_back(new Square{102,60,225});  // store pointer to square3 in vs

     std::sort(vs.begin(),vs.end(),Cmp_by_id()); // sort shapes by id (using std sort algorithm)
     cout << "shapes sorted by id: ";
     for (const auto x : vs) cout << *x << " "; // use auto type deduction (x is a Shape*),
     cout << endl << endl;                      // range-for-loop to print vs

     std::sort(vs.begin(),vs.end(),Cmp_by_perimeter()); // sort shapes by perimeter
     cout << "shapes sorted by perimeter: " << endl;
     for (const auto x : vs)
     {
         cout << "id " << *x;
         cout << ", perimeter " << x->calc_perimeter() << endl;
     }
     cout << endl;

     std::sort(vs.begin(),vs.end(),Cmp_by_area()); // sort shapes by area
     cout << "shapes sorted by area: " << endl;
     for (const auto x : vs)
     {
         cout << "id " << *x;
         cout << ", area " << x->calc_area() << endl;
     }
     cout << endl;

     // free all shapes
     for (Shape* pS : vs) delete pS; // delete all shape objects, otherwise memory will leak

	// // Q#5 - copy_if algorithm with function objects

    try
    {
        list<int> l(v.size()); // create a stl list with size = v size

		if (l.size() < v.size()) throw length_error("target container too small"); // throw exceptoin when
        // copy elements from vector v to list l within range 5 <= elem <= 50          // target container too small
			hw16::copy_if(v.begin(), v.end(), l.begin(), Range_low_to_high<int>(5,50));
        
        // print list l
        cout << "list l: ";
        for (const auto& x : l) cout << x << " ";
        cout << endl << endl;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << endl; 
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!" << endl; 
        return 2;
    }

	system("pause");
    return 0;
}

//------------------------------------------------------------------------------

// WRITTEN ANSWERS

// Q#1
/* 
The input iterator must support pre-increment, post-increment, dereference, and postincrement and dereference operations.
It must also support the inequality operator to be able to compare to the equalityComparable iterator.
The equalityComparable iterator must support the equality and inequality operators.
*/


// Q#5
/*
The input iterator must support pre-increment, post-increment, dereference, and postincrement and dereference operations.
The output iterator must support pre-increment, post-increment, dereference, and postincrement and dereference operations.
the output operator must also support assignment operators.
The predicate function object must have overloaded function call operator () support to return a bool.
Value_type<In> must support less than, greater than, and equality operators to be able to be used in any predicate it is passsed into.
In this function, we only need the less than comparison operator in to be overloaded in Value_type<In>for the Range_low_to_high predicate to work.
*/