#pragma once

#include <string_view>
// const char* -> string -> const string& -> string_view(Read Only) : googling
void save(std::string_view);