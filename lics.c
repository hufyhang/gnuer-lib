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

/* The implementations for "lics"(auto-licenser) of GNUer Library. */

#include "lics.h"

extern void getFiles(const char *extension, const char *root)
{
	DIR *dir;
	struct dirent *ptr;
	char path[FILE_NAME_MAX], current_file[FILE_NAME_MAX], *current_ext;

	if((dir = opendir(root)) == NULL)
	{
		perror("Fail to open dir.");
		exit(EXIT_FAILURE);
	}

	errno = 0;

	while((ptr = readdir(dir)) != NULL)
	{
		if(strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
			continue;

		if(ptr->d_type == DT_DIR)
		{
			sprintf(path, "%s/%s", root, ptr->d_name);
			getFiles(extension, path);
		}
		else if(ptr->d_type == DT_REG)
		{
			if((current_ext = rindex(ptr->d_name, '.')) == NULL)
				continue;
			if(strcmp(current_ext, extension) == 0)
			{
				sprintf(current_file, "%s/%s", root, ptr->d_name);
				printf("UPDATING %d: [%s]\n", counter + 1, current_file);
				process(current_file, license);
			}
		}
	}

	if(errno != 0)
	{
		perror("Fail to read dir.");
		exit(EXIT_FAILURE);
	}

	closedir(dir);
}

extern void process(const char *file, const char *licContents)
{
	FILE *fptr;
	char *fileContents = malloc(BUF_SIZE * sizeof(char));
	if(getFileContents(fileContents, file) == -1)
	{
		perror("Fail to read contents.");
		exit(EXIT_FAILURE);
	}

	char *contents = malloc(BUF_SIZE * sizeof(char));
	if(remove(file) ==  -1)
	{
		perror("Fail to remove file.");
		printf("%s\n", file);
		exit(EXIT_FAILURE);
	}
	sprintf(contents, "%s\n%s", licContents, fileContents);
	if((fptr = fopen(file, "wb+")) == NULL)
	{
		perror("Fail to open file.");
		exit(EXIT_FAILURE);
	}
	fwrite(contents, sizeof(char), strlen(contents), fptr);
	free(contents);
	free(fileContents);
	fclose(fptr);
	++counter;
}

extern int getFileContents(char *string, const char* path)
{
	FILE *fptr;
	char buf[BUF_SIZE];

	if((fptr = fopen(path, "r")) == NULL)
	{
		perror("Fail to open.");
		printf("%s\n", path);
		return -1;
	}

	if(fread(buf, sizeof(char), BUF_SIZE, fptr) == EOF)
	{
		perror("Fail to read.");
		return -1;
	}

	fclose(fptr);
	strcpy(string, buf);
	return 0;
}


int main(int argc, char *argv[])
{
	if(argc < 4)
	{
		printf("Usage: lics <copyright info> <extension> <root>\n");
		exit(EXIT_FAILURE);
	}
	license = malloc(BUF_SIZE * sizeof(char));
	if(getFileContents(license, argv[1]) == -1)
	{
		perror("Fail to gether.");
	}
	getFiles(argv[2], argv[3]);
	free(license);
	printf("--- %d files have been updated ---\n", counter);
	exit(EXIT_SUCCESS);
}
