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
      // Handler implementations for commands
      // ----------------------------------------------------------------------

      //! Handler implementation for command TODO
      //!
      //! TODO
      void TODO_cmdHandler(
          FwOpcodeType opCode, //!< The opcode
          U32 cmdSeq //!< The command sequence number
      ) override;

  };

}

#endif
