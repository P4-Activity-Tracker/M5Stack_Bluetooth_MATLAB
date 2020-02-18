clc
clear all
close all


%instrhwinfo('Bluetooth')
b = Bluetooth('M5Stack',1);

fopen(b)
pause(5)
%fwrite(b,uint8([077 101 032 104 097 114 100 032 121 111]))

%fread(b,20)  
%fclose(b)
disp ("beginning read")
while b.status == "open"
   pause (2)
    if b.BytesAvailable > 0
        buffer = fread(b,b.BytesAvailable);
        message = char(buffer);
        message= string(message');
        message = strcat(message{:});  %string(message);
        disp(message)     
    end
end
