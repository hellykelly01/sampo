#include "LogSvc.h"

LogSvc::LogSvc(const std::string& name, ISvcLocator* svcloc) : base_class(name, svcloc) {}

StatusCode LogSvc::initialize()
{
  StatusCode sc = Service::initialize();
  if (sc.isFailure())
  {
    return sc;
  } 
  setupLoggedSources();
  setupSourcesThresholds();
  return StatusCode::SUCCESS;
}

StatusCode LogSvc::reinitialize() 
{
  m_state = Gaudi::StateMachine::OFFLINE;
  StatusCode sc = initialize();
  if (sc.isSuccess())
  {
    m_state = Gaudi::StateMachine::INITIALIZED;
  }
  return sc;
}

StatusCode LogSvc::finalize()
{
  StatusCode sc = Service::finalize();
  if (sc.isFailure()) 
  {
    return sc;
  }
  return StatusCode::SUCCESS;
}

std::shared_ptr<ILogger> LogSvc::getLogger(const std::string& source)
{
  auto logIt = m_loggedSources.find(source);
  if (logIt != m_loggedSources.end()) 
  {
    return logIt->second;
  } 
  else 
  {
    std::shared_ptr<ILogger> logger = createLoggerForSink("default");
    m_loggedSources[source] = logger;
    return logger;
  }
}

void LogSvc::setupSourcesThresholds()
{
  const std::map<std::string, MSG::Level> tbl{{{"setFatal", MSG::FATAL},
                                               {"setError", MSG::ERROR},
                                               {"setWarning", MSG::WARNING},
                                               {"setInfo", MSG::INFO},
                                               {"setDebug", MSG::DEBUG},
                                               {"setVerbose", MSG::VERBOSE},
                                               {"setAlways", MSG::ALWAYS}
                                              }};
  for(const Gaudi::Property<std::vector<std::string>> & prop : m_sourcesThresholdsProp){
    for (const std::string& source : prop.value()){
      try{
        m_sourcesThresholds[source] = tbl.at(prop.name());
      } catch(...){}
    }
  }
}

void LogSvc::setupLoggedSources()
{
  for (auto it = m_loggedSourcesProp.begin(); it != m_loggedSourcesProp.end(); ++it)
  {
    if(!m_loggedSources[it->first])
    {
      m_loggedSources[it->first] = createLoggerForSink(it->second);
    }
  }
}

int LogSvc::outputLevel(const std::string& source) const
{
  auto it = m_sourcesThresholds.find(source);
  return it == m_sourcesThresholds.end() ? m_outputLevel.value() : it->second;
}

