#ifndef ILOGGER_H
#define ILOGGER_H

#include "GaudiKernel/Message.h"

class ILogger{
public:
  virtual void log(const Message& message) = 0;
  virtual ~ILogger(){}
};

#endif // ILOGGER_H