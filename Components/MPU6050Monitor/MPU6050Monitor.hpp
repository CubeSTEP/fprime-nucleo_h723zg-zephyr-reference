// ======================================================================
// \title  MPU6050Monitor.hpp
// \author josho
// \brief  hpp file for MPU6050Monitor component implementation class
// ======================================================================

#ifndef Components_MPU6050Monitor_HPP
#define Components_MPU6050Monitor_HPP

#include "Components/MPU6050Monitor/MPU6050MonitorComponentAc.hpp"

namespace Components {

  class MPU6050Monitor final :
    public MPU6050MonitorComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct MPU6050Monitor object
      MPU6050Monitor(
          const char* const compName //!< The component name
      );

      //! Destroy MPU6050Monitor object
      ~MPU6050Monitor();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for run
      //!
      //! Port for receiving calls from the rate group ticks
      void run_handler(
          FwIndexType portNum, //!< The port number
          U32 context //!< The call order
      ) override;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command MPU6050_ON_OFF
      //!
      //! TODO
      void MPU6050_ON_OFF_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq, //!< The command sequence number
          Fw::On onOff //!< Indicates whether the monitor should be on or off
      ) override;

      Fw::On m_state = Fw::On::OFF; //! Keeps track if MPU6050 is on or off
      U64 m_transitions = 0; //! The number of on/off transitions that have occurred from FSW boot up
      U32 m_toggleCounter = 0; //! Keeps track of how many ticks the MPU6050 has been on for
      bool m_polling = false; //! Flag: if true then the host will poll the MPU6050 for data

  };

}

#endif
