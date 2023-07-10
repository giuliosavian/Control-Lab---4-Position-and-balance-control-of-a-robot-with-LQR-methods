clear all

% packet specifier (must match the specifier in the "Packet Send" block)
packetSpec = {'2*uint8', '2*int32', '2*single', 'single'};

% interactive data−logging
data = serial_datalog( 'COM3', ... % serial port name
packetSpec, ... % packet specifier
'BaudRate', 38400, ... % serial port baud rate
'TxSampleTime', 0.01, ... % TX sample time
'TxStartCmd', 65, ... % TX start cmd (default)
'TxStopCmd', 66, ... % TX stop cmd (default)
'BufferSize', 10000, ... % RX buffer size
'PlotWidth', 5, ... % time−axis width (default)
'PlotRefreshRatio', 10, ... % plot refresh ratio
'PlotList', [1,2,3,4]); % plot list