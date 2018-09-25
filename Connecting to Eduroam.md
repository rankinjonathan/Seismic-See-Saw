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

```
sudo nano /etc/network/interfaces
```
Make sure the following lines are there
```
allow-hotplug wlan0
iface wlan0 inet manual
wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf
```
Update the spa supplicant file
```
sudo nano /etc/wpa_supplicant/wpa_supplicant.conf
```
By default it should have this in, but if not add it
```
ctrl_interface = DIR = / var / run / wpa_supplicant GROUP = netdev
update_config = 1
country = GB
```
Then add this at the bottom 
```
network = {
   ssid = "eduroam"
   proto = RSN
   key_mgmt = WPA-EAP
   eap = PEAP
   identity = "USER @ HOST"
   password = "PASSWORD"
   phase1 = "peaplabel = 0"
   phase2 = "auth = MSCHAPV2"
}
```
Replace the identity with your username and password with your password

Close and save the file, then type 
```
sudo wpa_supplicant -i wlan0 -c /etc/wpa_supplicant/wpa_supplicant.conf
```
You should get a success message back. Finally reboot the Pi with 
```
sudo reboot
```

