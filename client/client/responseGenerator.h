#ifndef RESPONSEGENERATOR_H
#define RESPONSEGENERATOR_H

#include "DataType.h"
#include "dataParser.h"

constexpr int RESPONSE_GENERATOR_FLAG_SIMPLE = (1<<0);
constexpr int RESPONSE_GENERATOR_FLAG_NO_TITLE = (1<<1);
namespace responseGenerator {

QString getResponseGenerally(Type type, QString title, QString data,int flag);
} // namespace responseGenerator
#endif
