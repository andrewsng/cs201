#pragma once

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

bool ReadLine(std::string& str);

unsigned StringToTokensWS(std::vector<std::string>& tokens, std::string& str);

void AnalyzeTokens(const std::vector<std::string>& tokens);

#endif