#include <string>

#include "P7LogSvc.h"
#include "P7Logger.h"

DECLARE_COMPONENT(P7LogSvc);

StatusCode P7LogSvc::finalize()
{ 
  for(IP7_Trace* trace : m_traceRegistry)
  {
    trace->Release();
  }

  for(auto it = m_SinkClients.begin(); it != m_SinkClients.end(); ++it)
  {
    it->second->Release();
  }

  return LogSvc::finalize();
}

std::shared_ptr<ILogger> P7LogSvc::createLoggerForSink(const std::string& sink)
{
  std::string name = sink + std::to_string(m_SinkCount[sink]++);
  std::shared_ptr<P7Logger> logger;
  auto sinkIt = m_SinkClients.find(sink);
  if (sinkIt != m_SinkClients.end()) 
  {
    logger = std::make_shared<P7Logger>(name, sinkIt->second);
  } 
  else 
  {
    std::string initParams = "/P7.Sink=FileTxt /P7.Format=\"%ms\" /P7.Dir=log/" + sink;
    IP7_Client* client = P7_Create_Client(TM(initParams.c_str()));
    m_SinkClients[sink] = client;
    logger = std::make_shared<P7Logger>(name, client);
  }
  m_traceRegistry.push_back(logger->getTrace());
  return logger;
}



