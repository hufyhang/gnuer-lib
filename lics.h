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

/* The definations for "lics"(auto-licenser) of GNUer Library. */

#ifndef _LICS_H
#define _LICS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 10240000
#define FILE_NAME_MAX 1024
#define FALSE 0
#define TRUE 1

int counter = 0, all_flag = FALSE, subDir = TRUE;
char *license;

extern void getFiles(const char*, const char*);
extern int getFileContents(char*, const char*);
extern void beginProcess(const char*, const char*);
extern void process(const char*, const char*);

#endif

