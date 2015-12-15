/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced. Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#ifndef VERSION_TEST_H
#define VERSION_TEST_H

/* As of the first printing of C++ Primer, 5th Edition (July 2012), 
 * the Microsoft Complier did not yet support a number of C++ 11 features.  
 *
 * The code we distribute contains both normal C++ code and 
 * workarounds for missing features.  We use a series of CPP variables to
 * determine whether a given features is implemented in a given release
 * of the MS compiler.  The base version we used to test the code in the book
 * is Compiler Version 17.00.50522.1 for x86.
 *
 * When new releases are available we will update this file which will
 * #define the features implmented in that release.
*/

#if _MSC_FULL_VER == 170050522 || _MSC_FULL_VER == 170050727 
// base version, future releases will #define those features as they are
// implemented by Microsoft

/* Code in this delivery use the following variables to control compilation

   Variable tests           C++ 11 Feature 
CONSTEXPR_VARS            constexpr variables
CONSTEXPR_FCNS            constexpr functions
CONSTEXPR_CTORS           constexpr constructors and other member functions
DEFAULT_FCNS              = default 
DELETED_FCNS              = delete  
FUNC_CPP                  __func__ local static
FUNCTION_PTRMEM           function template with pointer to member function
IN_CLASS_INITS            in class initializers 
INITIALIZER_LIST          library initializer_list<T> template
LIST_INIT                 list initialization of ordinary variables
LROUND                    lround function in cmath
NOEXCEPT                  noexcept specifier and noexcept operator
SIZEOF_MEMBER             sizeof class_name::member_name
TEMPLATE_FCN_DEFAULT_ARGS default template arguments for function templates
TYPE_ALIAS_DECLS          type alias declarations
UNION_CLASS_MEMS          unions members that have constructors or copy control
VARIADICS                 variadic templates
*/
#endif  // ends compiler version check

#ifndef LROUND
inline long lround(double d)
{
    return (d >= 0) ?  long(d + 0.5) : long(d - 0.5);
}
#endif

#endif  // ends header guard

