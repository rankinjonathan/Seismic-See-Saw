# Seismic See Saw setup guide

You will need to have a Raspberry Pi and an Arduino connected to each other in some way

You will need to install node onto the Pi.

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





1. Clone the repo ```(`git clone https://github.com/rankinjonathan/Seismic-See-Saw`)```
2. ```cd Raspberry Pi code for Seismic See Saw```
3. ```npm install```
4. ```node src```

