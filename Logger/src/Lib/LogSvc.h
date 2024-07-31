#ifndef LOGSVC_H
#define LOGSVC_H

#include "ILogSvc.h"
#include "GaudiKernel/Service.h"

#include <map>
#include <string>
#include <vector>

class LogSvc : public extends<Service, ILogSvc>{
public:
  LogSvc(const std::string& name, ISvcLocator* svcloc);
  StatusCode initialize() override;
  StatusCode reinitialize() override;
  StatusCode finalize() override;
  std::shared_ptr<ILogger> getLogger(const std::string& source) override;
  int outputLevel(const std::string& source) const override;
  std::string getMsgFormat() const override { return m_msgFormatProp.value(); };
  std::string getTimeFormat() const override { return m_timeFormatProp.value(); };
private:
  void setupLoggedSources();
  void setupSourcesThresholds();
  virtual std::shared_ptr<ILogger> createLoggerForSink(const std::string& sink) = 0;
  std::map<std::string, std::shared_ptr<ILogger>> m_loggedSources;
  std::map<std::string, int>  m_sourcesThresholds;  

  // map source -> sink
  Gaudi::Property<std::map<std::string, std::string>> m_loggedSourcesProp{
      this, "loggedSources", {}, "Sources to record into separate logfiles"};
  Gaudi::Property<std::string>  m_msgFormatProp{this, "msgFormat", Message::getDefaultFormat(), ""};
  Gaudi::Property<std::string>  m_timeFormatProp{this, "timeFormat", Message::getDefaultTimeFormat(), ""};
  std::array<Gaudi::Property<std::vector<std::string>>, 7> m_sourcesThresholdsProp{{
                                                                        {this, "setVerbose"},
                                                                        {this, "setDebug"},
                                                                        {this, "setInfo"},
                                                                        {this, "setWarning"},
                                                                        {this, "setError"},
                                                                        {this, "setFatal"},
                                                                        {this, "setAlways"}
                                                                      }};
};

#endif // LOGSVC_H