/** \file
 *  Game Develop
 *  2008-2012 Florian Rival (Florian.Rival@gmail.com)
 */
/**
 * \brief File containing tools to manipulate objects easier.
 */

#ifndef OBJECTHELPERS_H
#define OBJECTHELPERS_H
#include "GDL/Object.h"
#include <boost/shared_ptr.hpp>
#include <vector>
class Object;

/**
 * An object list is a vector containing (smart) pointers to objects.
 */
typedef std::vector < boost::shared_ptr<Object> > ObjList;

/**
 * Objects are usually managed thanks to (smart) pointers.
 */
typedef boost::shared_ptr<Object> ObjSPtr;

/**
 * Functor testing object name
 */
struct ObjectHasName : public std::binary_function<boost::shared_ptr<Object>, std::string, bool> {
    bool operator()(const boost::shared_ptr<Object> & object, const std::string & name) const { return object->GetName() == name; }
};

/**
 * Functor for sorting an ObjList by ZOrder
 */
struct SortByZOrder
{
   bool operator ()(ObjSPtr o1, ObjSPtr o2) const
   {
      return o1->GetZOrder() < o2->GetZOrder();
   }
};

#endif // OBJECTHELPERS_H
