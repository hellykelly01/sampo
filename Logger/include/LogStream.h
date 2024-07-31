#ifndef LOGSTREAM_H
#define LOGSTREAM_H

#include <sstream>
#include <string>
#include <iomanip>

class LogStreamMgr;

class LogStream{
public:
  LogStream(){}

  LogStream(LogStreamMgr* mgr, MSG::Level level, MSG::Level outputLevel);

  friend LogStream& endmsg(LogStream&);

  LogStream& operator<<(LogStream& (*f)(LogStream&)){ return f(*this); }
  
  LogStream& operator<<(std::ios& (*f)(std::ios&)) 
  {
    if (isActive()) f(m_stream);
    return *this;
  }

  bool isActive() { return m_active; }
  std::ostringstream& stream() { return m_stream; }
private:
  std::ostringstream m_stream;
  LogStreamMgr* m_logStreamMgr;
  MSG::Level m_level;
  bool m_active;
};

LogStream& operator<<(LogStream& lhs, const char* arg);

LogStream& endmsg(LogStream&);

template <typename T>
LogStream& operator<<(LogStream& lhs, const T& arg) 
{
  if (lhs.isActive()) {
    try 
    {
      lhs.stream() << arg;
    } catch (...) {}
  }
  return lhs;
}


#endif // LOGSTREAM_H
