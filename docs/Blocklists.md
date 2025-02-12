A Blocklist is third-party list of peer addresses to block.  This can be used to block peers whose addresses are believed to belong to spyware or malware manufacturers.

## What blocklist does Transmission Use? ##

Transmission supports the [P2P Plaintext Format](http://en.wikipedia.org/wiki/PeerGuardian), which is used by PeerGuardian, Bluetack, Vuze, ProtoWall, and KTorrent, and the DAT format, which was originally made popular by eMule.

The Transmission Project does not evaluate or endorse any specific blocklists.  If you do not know what blocklist to use, you might [read about some third-party blocklists](http://www.google.com/search?q#blocklist+url) and evaluate them on your own.

If "Enable automatic updates" is enabled, Transmission will periodically refresh its copy of your blocklist from your specified URL.

When you press the "Update Blocklist" button, Transmission will download a new copy of your blocklist.

## Adding Other Blocklists ##

Transmission stores blocklists in a folder named `blocklists` in its [configuration folder](Configuration-Files.md).

In that directory, files ending in ".bin" are blocklists that Transmission has parsed into a binary format suitable for quick lookups.  When transmission starts, it scans this directory for files not ending in ".bin" and tries to parse them.  So to add another blocklist, all you have to do is put it in this directory and restart Transmission. Text and gzip formats are supported.

## Using Blocklists in transmission-daemon ##

transmission-daemon doesn't have an "update blocklist" button, so its users have two options. They can either copy blocklists from transmission-gtk's directory to transmission-daemon's directory, or they can download a blocklist by hand, uncompress it, and place it in the daemon's `blocklists` folder. In both cases, the daemon's [settings.json file](Configuration-Files.md) will need to be edited to set "blocklist-enabled" to "true".

Also in both cases, the daemon is unaware of blocklist updates.  Only when it starts it creates new .bin files.

There is a third option: add the blocklist URL in settings.json (only one blocklist is allowed), and use transmission-remote to tell the daemon to update it periodically.

settings.json snippet:

```json
"blocklist-enabled": true,
"blocklist-url": "http://www.example.com/blocklist",
```

update by hand example:

```console
$ transmission-remote -n admin:password --blocklist-update
localhost:9091/transmission/rpc/ responded: "success"
```
