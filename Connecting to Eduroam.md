# Instructions to connect Raspberry Pi to Eduroam

Open a terminal window
```
sudo nano /boot/cmdline.txt
```
With a leading space add
```
net.ifnames=0
```
Save and exit
