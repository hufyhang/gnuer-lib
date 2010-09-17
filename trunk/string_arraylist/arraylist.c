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

/* The implementations for string arraylist of GNUer Library. */

#include "arraylist.h"

void arraylist_initial(struct arraylist *list) {
  list->size = 0;
  list->data = NULL;
}

int arraylist_get_size(const struct arraylist list) {
  return list.size;
}

value_type* arraylist_get_data_collection(const struct arraylist list) {
  return list.data;
}

void arraylist_set_data_collection(struct arraylist *list, value_type* data) {
  list->data = data;
}

void arraylist_add(struct arraylist *list, value_type value) {
  int size = arraylist_get_size(*list);
  value_type *new_data;
  new_data = realloc(list->data, (size + 1) * sizeof(value_type));

  if(new_data) {
    new_data[size] = value;
    arraylist_set_data_collection(list, new_data);
    ++list->size;
  }
}

value_type arraylist_get(const struct arraylist list, int index) {
  if(index < arraylist_get_size(list)) {
    return list.data[index];
  }
  else {
    return NULL;
  }
}

void arraylist_set(struct arraylist *list, int index, value_type value) {
  list->data[index] = value;
}

int arraylist_indexof(const struct arraylist list, value_type value) {
  int index = 0;
  for(; index != arraylist_get_size(list); ++index) {
    if(strcmp(list.data[index], value) == 0) {
      return index;
    }
  }

  return -1;
}
