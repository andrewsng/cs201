/*
	namefunctions.h
	Andrew Ng
	Sep 22 2019
	Header file for name functions for hw2
*/

#pragma once

#ifndef NAMEFUNCTIONS_H
#define NAMEFUNCTIONS_H

void InputNames(std::vector<std::string>& names);

bool DoesNameExist(const std::string& nameToFind, const std::vector<std::string>& names);

void PrintNames(const std::vector<std::string>& names);

void CountCharacters(const std::vector<std::string>& names);

#endif