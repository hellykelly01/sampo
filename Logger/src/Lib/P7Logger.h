#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "ILogger.h"
#include "P7_Trace.h"

class P7Logger : public ILogger{
public:
  P7Logger(const std::string& name, IP7_Client *pClient);
  void log(const Message& message) override;
  IP7_Trace* getTrace() const { return m_pTrace; }
private:
  IP7_Trace* m_pTrace;
};

#endif