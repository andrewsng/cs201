/*
	tokenizertest.cpp
	Andrew Ng
	Oct 15 2019
	header for string/token functions for hw 4
*/

#pragma once

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

bool ReadLine(std::string& str);

unsigned StringToTokensWS(std::vector<std::string>& tokens, std::string& str);

void AnalyzeTokens(const std::vector<std::string>& tokens);

#endif