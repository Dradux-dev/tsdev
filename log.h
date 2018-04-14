#ifndef TSDEV_LOG_H
#define TSDEV_LOG_H

namespace tsdev
{
  namespace LogLevel
  {
    enum Values
    {
      CRITICAL,
      ERROR,
      WARNING,
      INFO,
      FINE,
      FINER,
      FINEST
    };
  }

  typedef ELogLevel LogLevel::Values;
}

#endif // TSDEV_LOG_H
