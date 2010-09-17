/* Copyright (C) 2009, 2010 HANG Feifei.
   This file is part of the GNUer Library.

   The GNUer Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNUer Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNUer Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/* The definations for string arraylist of GNUer Library. */

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include <stdio.h>

typedef char* value_type;

struct arraylist {
  int size;
  value_type* data;
};


extern void arraylist_initial(struct arraylist *list);
/* Initialize/reset an arraylist.
 * list : the arraylist to be initialized with.
 */

extern int arraylist_get_size(const struct arraylist list);
/* Get the size of an arraylist.
 * list : the target arraylist.
 */

extern value_type* arraylist_get_data_collection(const struct arraylist list);
/* Get a data collection from an arraylist.
 * list : the arraylist to be obtained with.
 */

extern void arraylist_set_data_collection(struct arraylist *list, value_type* data);
/* Set/Change/Update the data collection of an arraylist.
 * list : the arraylist to be changed/updated.
 * data : a new data collection.
 */

extern void arraylist_add(struct arraylist *list, value_type value);
/* Add an element into an arraylist.
 * list : the target arraylist.
 * value : the value to be added with.
 */

extern value_type arraylist_get(const struct arraylist list, int index);
/* Get an element at a specific location/index from an arraylist.
 * list : the target arraylist.
 * index : the index number of the expected element.
 */

extern void arraylist_set(struct arraylist *list, int index, value_type value);
/* Set/Change/Update an element inside of an arraylist.
 * list : the target arraylist.
 * index : the index number of the element, which await to be updated.
 * value : the new value of the element in arraylist.
 */

extern int arraylist_indexof(const struct arraylist list, value_type value);
/* Get the first index number of elements, whose values are equal to the given value.
 * list : the target arrraylist.
 * value : the value of an element, which await to be searched with inside of arraylist.
 */


#endif
