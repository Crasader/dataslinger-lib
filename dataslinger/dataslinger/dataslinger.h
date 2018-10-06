#pragma once

#include <memory>

#include <boost/signals2/signal.hpp>

namespace dataslinger
{

class DataSlinger
{
public:
    DataSlinger();
    ~DataSlinger();
    DataSlinger(const DataSlinger&) = delete;
    DataSlinger& operator=(const DataSlinger&) = delete;

    boost::signals2::signal<void()> signal_beforeSend;
    boost::signals2::signal<void()> signal_afterSend;

    boost::signals2::signal<void()> signal_beforeReceive;
    boost::signals2::signal<void()> signal_afterReceive;

private:
    class DataSlingerImpl;
    std::unique_ptr<DataSlingerImpl> d;
};

}