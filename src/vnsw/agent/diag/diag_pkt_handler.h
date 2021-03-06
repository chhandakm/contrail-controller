/*
 *  * Copyright (c) 2014 Juniper Networks, Inc. All rights reserved.
 *   */
#ifndef vnsw_agent_diag_diag_pkt_handler_hpp
#define vnsw_agent_diag_diag_pkt_handler_hpp

#include <base/logging.h>
#include <net/address.h>
#include <base/timer.h>
#include "boost/date_time/posix_time/posix_time.hpp"

struct AgentDiagPktData;

class DiagPktHandler : public ProtoHandler {
public:
    DiagPktHandler(Agent *agent, boost::shared_ptr<PktInfo> info,
                   boost::asio::io_service &io):
        ProtoHandler(agent, info, io), diag_table_(agent->diag_table()) {}
    virtual bool Run();
    void SetReply();
    void SetDiagChkSum();
    void Reply();
    AgentDiagPktData* GetData() {
        return (AgentDiagPktData *)(pkt_info_->data);
    }

private:
    DiagTable *diag_table_;
};

#endif
