#ifndef LOGSTREAMMGR_H
#define LOGSTREAMMGR_H

#include <map>
#include <string>
#include <memory>

#include "ILogSvc.h"
#include "ILogger.h"
#include "GaudiKernel/ServiceHandle.h"
#include "LogStream.h"


class LogStreamMgr{
public:
  LogStreamMgr(const std::string& source, ServiceHandle<ILogSvc>& svc);
  LogStream& info() { return m_streams[MSG::INFO]; }
  LogStream& debug() { return m_streams[MSG::DEBUG]; }
  LogStream& warning() { return m_streams[MSG::WARNING]; }
  LogStream& error() { return m_streams[MSG::ERROR]; }
  LogStream& fatal() { return m_streams[MSG::FATAL]; }
  std::string getSource() { return m_source; }
  ServiceHandle<ILogSvc>& logSvc() { return m_logsvc; }
  void reportMessage(const Message& message);
private:
  MSG::Level intToLevel(int i);
  std::string m_msgFormat;
  std::string m_timeFormat;
  std::string m_source;
  std::map<MSG::Level, LogStream> m_streams;
  ServiceHandle<ILogSvc>& m_logsvc;
  std::shared_ptr<ILogger> m_logger;
};


#endif // LOGSTREAMMGR_H