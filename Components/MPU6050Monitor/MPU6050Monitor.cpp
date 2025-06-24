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
  // Handler implementations for typed input ports
  // ----------------------------------------------------------------------

  void MPU6050Monitor ::
    run_handler(
        FwIndexType portNum,
        U32 context
    )
  {
    Fw::ParamValid isValid = Fw::ParamValid::INVALID;
    U32 interval = this->paramGet_DATA_RATE(isValid);
    FW_ASSERT((isValid != Fw::ParamValid::INVALID) && (isValid != Fw::ParamValid::UNINIT), static_cast<FwAssertArgType>(isValid));

    if (this->m_polling && (interval != 0)) {
      if(this->m_toggleCounter == 0) {
        this->m_state = (this->m_state == Fw::On::ON) ? Fw::On::OFF : Fw::On::ON;
        this->m_transitions++;

        uint8_t reg_addr = 0x3B;
            uint8_t buf[6];
            Fw::Buffer writeBuffer;
            writeBuffer.setData(&reg_addr);
            writeBuffer.setSize(1);
            Fw::Buffer readBuffer;
            readBuffer.setData(buf);
            readBuffer.setSize(6);

          // This calls the *output* port, which routes to the ZephyrI2CDriver's handler
          Drv::I2cStatus status = this->i2cWriteRead_out(0, 0, writeBuffer, readBuffer);

          if (status == Drv::I2cStatus::I2C_OK) {
              int16_t accel_x = (buf[0] << 8) | buf[1];
              int16_t accel_y = (buf[2] << 8) | buf[3];
              int16_t accel_z = (buf[4] << 8) | buf[5];
              // this->tlmWrite_ACCEL_X(accel_x);
              // this->tlmWrite_ACCEL_Y(accel_y);
              // this->tlmWrite_ACCEL_Z(accel_z);
              Fw::Logger::log("Acceleration X: %u\n", accel_x);
              Fw::Logger::log("Acceleration X: %u\n", accel_y);
              Fw::Logger::log("Acceleration X: %u\n", accel_z);
          } else {
              // this->log_WARNING_HI_MPU6050_I2C_ERROR(status);
              Fw::Logger::log("Error polling MPU6050. Status: %u\n", status);

          }
      }
    }
  }

  // ----------------------------------------------------------------------
  // Handler implementations for commands
  // ----------------------------------------------------------------------

  void MPU6050Monitor ::
    MPU6050_ON_OFF_cmdHandler(
        FwOpcodeType opCode,
        U32 cmdSeq,
        Fw::On onOff
    )
  {
    // TODO
    this->m_toggleCounter = 0;
    this->m_polling = Fw::On::ON == onOff;

    this->log_ACTIVITY_LO_MonitorState(onOff);

    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
  }

}
