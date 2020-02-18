% Startup
clc
clear
close all
% Global variables
deviceName = 'M5Stack';
channel = 0;
% Create bluetooth object
b = Bluetooth(deviceName, channel);
% Open bluetooth connection
output = fopen(b);

