#ifndef BESS_HOOKS_TCPDUMP_
#define BESS_HOOKS_TCPDUMP_

#include "../message.h"
#include "../module.h"

// TcpDump dumps copies of the packets seen by a gate. Useful for debugging.
class TcpDump final : public bess::GateHook {
 public:
  TcpDump();

  ~TcpDump();

  CommandResponse Init(const bess::Gate *, const bess::pb::TcpdumpRequest &);

  int fifo_fd() const { return fifo_fd_; }
  void set_fifo_fd(int fifo_fd) { fifo_fd_ = fifo_fd; }

  void ProcessBatch(const bess::PacketBatch *batch);

  static constexpr uint16_t kPriority = 1;
  static const std::string kName;

 private:
  int fifo_fd_;
};

#endif  // BESS_HOOKS_TCPDUMP_
