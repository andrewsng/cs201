#pragma once

#ifndef NAMEFUNCTIONS_H
#define NAMEFUNCTIONS_H

void InputNames(std::vector<std::string>& names);

bool DoesNameExist(const std::string& nameToFind, const std::vector<std::string>& names);

void PrintNames(const std::vector<std::string>& names);

#endif