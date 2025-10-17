#include "dotc/io/fs.h"
#include "dotc/string.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


bool is_file(const char *path) {
	struct stat path_stat;

	if (stat(path, &path_stat) != 0)
		return false;

	return S_ISREG(path_stat.st_mode);
}

bool is_dir(const char *path) {
	struct stat path_stat;
	
	if (stat(path, &path_stat) != 0)
		return false;

	return S_ISDIR(path_stat.st_mode);
}

bool exists(const char *path) {
	struct stat path_stat;

	if (stat(path, &path_stat) != 0)
		return false;

	return S_ISDIR(path_stat.st_mode);
}

string_t read_file(const char *path) {
	FILE* file = fopen(path, "r");

	if (!file) {
		fprintf(stderr, "Failed to open file '%s'\n", path);
		exit(-1);
		return str("");
	}

	fseek(file, 0, SEEK_END);
	long length = ftell(file);
	fseek(file, 0, SEEK_SET);

	char* content = malloc(length + 1);

	if (!content) {
		fclose(file);
		return str("");
	}
	
	fread(content, 1, length, file);
	content[length] = 0;
	
	fclose(file);
	
	string_t result = str(content);

	free(content);

	return result;
}
