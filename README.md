# clAPT-0.1
A simple utility that combines features from APT and ClamAV. Written specifically for Ubuntu.

<h3>HOW TO INSTALL:</h3>
	1. Open terminal and download clAPT to your home directory: 
		- $ git clone https://github.com/greencloud/clAPT-0.1.git
	2. CD to the clAPT-0.1 folder where we have our autogen bash file: 
		- $ cd ~/clAPT-0.1
	3. Then start installation by typing in:
		- $ ./autogen.sh
	4. Once autogen is done, type in:
		- $ ./configure
	5. Then finally, compile and install by typing in:
		- $ sudo make install
	
<h3>BASH PROBLEM:</h3>
	In case you'll be getting an error such as:
		- bash: ./autogen.sh: Permission denied
	Just CHMOD autogen like this: 
		- $ chmod +x autogen.sh
	Then try it again :)
