//
// Created by Michał Oleniacz on 05/06/2023.
//

#ifndef PROJEKT_FILE_H
#define PROJEKT_FILE_H

#include <stdio.h>

FILE* readFile(const char *filename, const char *mode);
bool checkIfFileExists(const char *filename);
void writeFile(const char *filename, const void* buff);

#endif //PROJEKT_FILE_H
