`ls -l` <br/>
----r--r-- 1 flag02 level02 8302 Aug 30  2015 level02.pcap <br/>

`PCAP is a valuable resource for file analysis and to monitor your network traffic. Packet collection tools like Wireshark allow you to collect network traffic and translate it into a format that’s human-readable. There are many reasons why PCAP is used to monitor networks. Some of the most common include monitoring bandwidth usage, identifying rogue DHCP servers, detecting malware, DNS resolution, and incident response.`
https://www.comparitech.com/net-admin/pcap-guide/

Let's use Wireshark to inspect level02.pcap:<br/>

We can see a SYN connection with PSH and a closing SYN in the end.<br/>
Right click on package, follow stream, show in hexdump. <br/>
We can see someone tried to login but failed, we also can see the password. <br/>
In hexa F7 stands for 127 in ASCII wich is del, so let's replace the dots by a delete.<br/>
Found `ft_waNDReL0L`
