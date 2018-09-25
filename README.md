# Seismic See Saw setup guide

You will need to have a Raspberry Pi and an Arduino connected to each other in some way

## Install node onto the Pi.

Update your system package list:
```
sudo apt-get update
```
Upgrade all your installed packages
```
sudo apt-get dist-upgrade
```
To download and install newest version of Node.js, use the following command:

```
curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
```
Now install it by running:
```
sudo apt-get install -y nodejs
```
Check that the installation was successful, and the version number of Node.js with:

```
node -v
```

## Downloading the code onto the Raspberry Pi

In a terminal window type the following commands

1. Clone the repo ```(`git clone https://github.com/rankinjonathan/Seismic-See-Saw`)```
2. ```cd Raspberry Pi code for Seismic See Saw```
3. ```npm install```
4. ```node src```

## Running the code on startup
To have the Seismic See Saw start on startup you can use the forever scrip in a crontab. From a terminal window type:
```
sudo crontab -e
```
And add at the bottom 
```
@reboot /usr/local/bin/forever start -c yourNodeJSAppStartFile.js 
```


