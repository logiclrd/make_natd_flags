# make_natd_flags

This little utility poops out command-line switches for natd to configure port forwarding. If you have any number of ports being forwarded, then storing these statically in `rc.conf` as one giant command-line becomes unwieldy. With this utility, this particular server has this line in `rc.conf`:

```
natd_flags=`/root/make_natd_flags/make_natd_flags`
```

Configuration should be relatively self-explanatory. The table in `make_natd_flags.c` specifies one forwarded port per row. Each row has 4 paramaters:

* The IP address to which the traffic should be forwarded.
* The protocol for the traffic, either `tcp` or `udp`.
* The port number on which the inside machine expects to receive traffic.
* The external port number to be mapped to this inside machine.

This solves a specific problem for me. It only really applies if you have a FreeBSD NAT gateway to a network with a number of inside machines, and different inside machines need to provide different Internet services on the external IP that the gateway holds.
