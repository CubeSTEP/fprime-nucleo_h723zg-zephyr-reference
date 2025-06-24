module Components {
    @ Monitors data from the MPU6050.
    active component MPU6050Monitor {

        # One async command/port is required for active components
        # This should be overridden by the developers with a useful command/port
        @ TODO
        async command MPU6050_ON_OFF(
            onOff: Fw.On @< Indicates whether the monitor should be on or off
        )

        event SetMonitorState($state: Fw.On) \
            severity activity high \
            format "Set MPU6050 monitor to {}."

        event DataRateSet(interval: U32) \
            severity activity high \
            format "MPU6050 data rate set to {}."

        event MonitorState(onOff: Fw.On) \
            severity activity low \
            format "MPU6050 is {}."


        @ Data rate interval in rate group ticks
        param DATA_RATE: U32 default 1

        @ Port for receiving calls from the rate group ticks
        async input port run: Svc.Sched

        @ Port sending calls to the I2C driver
        output port i2cWriteRead: Drv.I2cWriteRead

        ##############################################################################
        #### Uncomment the following examples to start customizing your component ####
        ##############################################################################

        # @ Example async command
        # async command COMMAND_NAME(param_name: U32)

        # @ Example telemetry counter
        # telemetry ExampleCounter: U64

        # @ Example event
        # event ExampleStateEvent(example_state: Fw.On) severity activity high id 0 format "State set to {}"

        # @ Example port: receiving calls from the rate group
        # sync input port run: Svc.Sched

        # @ Example parameter
        # param PARAMETER_NAME: U32

        ###############################################################################
        # Standard AC Ports: Required for Channels, Events, Commands, and Parameters  #
        ###############################################################################
        @ Port for requesting the current time
        time get port timeCaller

        @ Port for sending command registrations
        command reg port cmdRegOut

        @ Port for receiving commands
        command recv port cmdIn

        @ Port for sending command responses
        command resp port cmdResponseOut

        @ Port for sending textual representation of events
        text event port logTextOut

        @ Port for sending events to downlink
        event port logOut

        @ Port for sending telemetry channels to downlink
        telemetry port tlmOut

        @ Port to return the value of a parameter
        param get port prmGetOut

        @Port to set the value of a parameter
        param set port prmSetOut

    }
}