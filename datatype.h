//
// Created by Michał Oleniacz on 06/06/2023.
//

#ifndef PROJEKT_DATATYPE_H
#define PROJEKT_DATATYPE_H


enum Datatype {
    INT,
    FLOAT,
    CHAR,
    STRING,
    STRUCT
};

Datatype evaluateDatatype(const char *buffer);

#endif //PROJEKT_DATATYPE_H
