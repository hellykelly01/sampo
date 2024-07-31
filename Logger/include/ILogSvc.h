#ifndef ILOGSVC_H
#define ILOGSVC_H

#include <string>
#include <memory>

#include "GaudiKernel/IInterface.h"
#include "ILogger.h"

class ILogSvc : virtual public IInterface{
public:
  DeclareInterfaceID(ILogSvc, 1, 0);
  virtual std::shared_ptr<ILogger> getLogger(const std::string& source) = 0;
  virtual int outputLevel(const std::string& source) const = 0;
  virtual std::string getMsgFormat() const = 0;
  virtual std::string getTimeFormat() const = 0;
};

#endif // ILOGSVC_H