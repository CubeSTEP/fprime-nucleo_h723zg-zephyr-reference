// ======================================================================
// \title  MPU6050Monitor.cpp
// \author josho
// \brief  cpp file for MPU6050Monitor component implementation class
// ======================================================================

#include "Components/MPU6050Monitor/MPU6050Monitor.hpp"
#include "Fw/Logger/Logger.hpp"

namespace Components {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  MPU6050Monitor ::
    MPU6050Monitor(const char* const compName) :
      MPU6050MonitorComponentBase(compName)
  {

  }

  MPU6050Monitor ::
    ~MPU6050Monitor()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void MPU6050Monitor ::
    TODO_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq
    )
  {
    // TODO
    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
