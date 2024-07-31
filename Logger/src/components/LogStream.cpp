#include "LogStreamMgr.h"

LogStream::LogStream(LogStreamMgr* mgr, MSG::Level level, MSG::Level outputLevel):
  m_level(level)
{
  m_logStreamMgr = mgr;
  m_active = level >= outputLevel ? true : false;
}

LogStream& endmsg(LogStream& stream)
{
  if(stream.isActive())
  {
    const Message msg(stream.m_logStreamMgr->getSource(), stream.m_level, stream.m_stream.str());
    try
    {
      stream.m_logStreamMgr->reportMessage(msg);
    } catch(...) {}
    stream.m_stream.str("");
  }
  return stream;
}

LogStream& operator<<(LogStream& lhs, const char* arg){
  if (lhs.isActive()){
    try 
    {
      lhs.stream() << arg;
    } catch (...) {}  
  }
  return lhs;
}
