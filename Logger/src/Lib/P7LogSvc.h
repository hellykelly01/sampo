#ifndef P7LOGSVC_H
#define P7LOGSVC_H

#include <vector>
#include <map>
#include <stdlib.h>
#include <stdio.h>

#include "P7_Trace.h"
#include "LogSvc.h"

class P7LogSvc : public LogSvc{
public:
  using LogSvc::LogSvc;
  StatusCode finalize() override;
private:
  std::shared_ptr<ILogger> createLoggerForSink(const std::string& sink) override;
  std::map<std::string, IP7_Client*> m_SinkClients;
  std::map<std::string, int> m_SinkCount;
  std::vector<IP7_Trace*> m_traceRegistry;
};

#endif // P7LOGSVC_H