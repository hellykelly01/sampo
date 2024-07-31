#include <sstream>

#include "P7Logger.h"


P7Logger::P7Logger(const std::string& name, IP7_Client *pClient)
{
  m_pTrace = P7_Create_Trace(pClient, TM(name.c_str()));
}

void P7Logger::log(const Message& message)
{
  std::ostringstream oss;
  oss << message;
  m_pTrace->P7_TRACE(0, TM(oss.str().c_str()), 0);
}