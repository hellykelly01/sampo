#include "LogStreamMgr.h"

LogStreamMgr::LogStreamMgr(const std::string& source, ServiceHandle<ILogSvc>& svc):
  m_source(source),
  m_logsvc(svc)
{
  MSG::Level outputLevel = intToLevel(logSvc()->outputLevel(m_source));
  m_streams[MSG::INFO] = LogStream(this, MSG::INFO, outputLevel);
  m_streams[MSG::DEBUG] = LogStream(this, MSG::DEBUG, outputLevel);
  m_streams[MSG::WARNING] = LogStream(this, MSG::WARNING, outputLevel);
  m_streams[MSG::ERROR] = LogStream(this, MSG::ERROR, outputLevel);
  m_streams[MSG::FATAL] = LogStream(this, MSG::FATAL, outputLevel);
  m_logger = logSvc()->getLogger(getSource());
  m_msgFormat = logSvc()->getMsgFormat();
  m_timeFormat = logSvc()->getTimeFormat();
}

MSG::Level LogStreamMgr::intToLevel(int level)
{
  level   = (level >= MSG::NUM_LEVELS) ? MSG::ALWAYS : (level < MSG::NIL) ? MSG::NIL : level;
  return MSG::Level(level);
}

void LogStreamMgr::reportMessage(const Message& message)
{
  message.setFormat(m_msgFormat);
  message.setTimeFormat(m_timeFormat);
  m_logger->log(message);
}