/*
	scorefunctions.h
	Andrew Ng
	Sep 22 2019
	Header file for score functions for hw2
*/

#pragma once

#ifndef SCOREFUNCTIONS_H
#define SCOREFUNCTIONS_H

void InputScores(std::vector<std::string>& names, std::vector<int>& scores, int& numScores);

void PrintScores(const std::vector<std::string>& names, const std::vector<int>& scores, const int& numScores);

void SearchName(const std::vector<std::string>& names, const std::vector<int>& scores, const int& numScores);

void SearchScore(const std::vector<std::string>& names, const std::vector<int>& scores, const int& numScores);

#endif