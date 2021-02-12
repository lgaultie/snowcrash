# Level02

```bash
level02@SnowCrash:~$ ls -l
----r--r-- 1 flag02 level02 8302 Aug 30  2015 level02.pcap
```

### What is a pcap file ?

`PCAP is a valuable resource for file analysis and to monitor your network traffic. Packet collection tools like Wireshark allow you to collect network traffic and translate it into a format that’s human-readable. There are many reasons why PCAP is used to monitor networks. Some of the most common include monitoring bandwidth usage, identifying rogue DHCP servers, detecting malware, DNS resolution, and incident response.`
https://www.comparitech.com/net-admin/pcap-guide/

### Inspect level02.pcap

Used Wireshark to inspect level02.pcap:

We can see a SYN connection, lot of PSH/ACK and a closing SYN in the end.

------------
Documentation: 
`Short for synchronize, SYN is a TCP packet sent to another computer requesting that a connection be established between them. If the SYN is received by the second machine, an SYN/ACK is sent back to the address requested by the SYN. Lastly, if the original computer receives the SYN/ACK, a final ACK is sent.` <br/>
https://www.computerhope.com/jargon/s/syn.htm
`PSH or PUSH flag is an option provided by TCP that allows the sending application to start sending the data even when the buffer is not full`
https://www.quora.com/What-is-the-significance-of-PSH-flag-in-TCP-header
`ACK means that the machine sending the packet with ACK is acknowledging data that it had received from the other machine. In TCP, once the connection is established, all packets sent by either side will contain an ACK, even if it's just re-acknowledging data that it's already acknowledged.`
https://osqa-ask.wireshark.org/questions/20423/pshack-wireshark-capture

-----------

It seems someone connected somewhere, sent some data and close the connection.

Right click on any package --> `Follow` --> `TCP Stream`<br/>
In red is the Client part, and in blue the server response. <br/>
We can clearly see someone tried to login and failed, we also see the password, however it doesn't work as flag02 password. Maybe the dots stands for unprintable characters.

Below, click on `Show and save data as` and put `Hex Dump`.

We can see each dot stands for F7 which in hexadecimal stands for 127 in ASCII, meaning the character `DEL`, so let's replace each dot by a delete.

Found `ft_waNDReL0L`
