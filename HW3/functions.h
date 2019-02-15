#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>
#include <iostream>

void serialize(bool, std::ostream &);
void serialize(short, std::ostream &);
void serialize(int, std::ostream &);
void serialize(long, std::ostream &);
void serialize(char, std::ostream &);
void serialize(const std::string &, std::ostream &);

void unserialize(std::istream &, bool &);
void unserialize(std::istream &, short &);
void unserialize(std::istream &, int &);
void unserialize(std::istream &, long &);
void unserialize(std::istream &, char &);
void unserialize(std::istream &, std::string &);

#endif
